<?php

class RiversEventDrupalNode6Migration extends DrupalNode6Migration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    //$this->destination = new MigrateDestinationNodeRevision($arguments['destination_type']);

    // Preserve the nids from D6.
    $this->addFieldMapping('nid', 'nid');
    //$this->addFieldMapping('vid', 'vid');
    $this->addFieldMapping('is_new')->defaultvalue(TRUE);

    $this->addFieldMapping('body:format', NULL, FALSE)
      ->defaultValue('full_html');

    // Preserve the paths from D6.
    $this->addFieldMapping('path', 'path');

    $this->addFieldMapping('field_date', 'field_date');
    $this->addFieldMapping('field_date:timezone')
      ->defaultValue(variable_get('date_default_timezone'));
    $this->addFieldMapping('field_date:to', 'field_date:value2');

    $this->addFieldMapping('field_organiser', 'field_organiser');

    // Event Type has vid=6 in D6.
    // Can't get tid, though returns 33 instead of 35
    /*$this->addFieldMapping('field_event_type', 6)
      ->sourceMigration('RiversVocabEventType')
      ->callbacks(array($this, 'mapFromEventType'));
    $this->addFieldMapping('field_event_type:source_type')
      ->defaultValue('tid');
    */

    // Set Event type (text list value) from Event type term.
    $this->addFieldMapping('field_event_type', 'event_type_tid')
      ->callbacks(array($this, 'mapFromEventType'));

    // Set Event status (text list value) from Event status term tid.
    $this->addFieldMapping('field_status', 'event_status_tid')
      ->callbacks(array($this, 'mapFromEventStatus'));

    // D6 Attachments (upload) to File field.
    $this->addFieldMapping('field_files', 'upload')
      ->sourceMigration('RiversFile');
    $this->addFieldMapping('field_files:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_files:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_files:description', 'upload:description');
    $this->addFieldMapping('field_files:display', 'upload:list');
    $this->addFieldMapping('field_files:language')
      ->defaultValue(LANGUAGE_NONE);

    // Add redirect based on https://www.drupal.org/node/1116408.
    $this->addFieldMapping('migrate_redirects', 'path');

    $this->addUnmigratedDestinations(array(
      'path', // Don't want original path as we regenerate & redirect.
      'field_date:rrule',
    ));
  }

  // Map from Event Type term tid, but looking up term name.
  public function mapFromEventType($value) {
    $event_type = Database::getConnection('default', 'legacy')
      ->select('term_data', 't')
      ->fields('t', array('name'))
      ->condition('tid', $value)
      ->execute()
      ->fetchField();

    // Change Rodeo to Freestyle.
    if ($event_type == 'Rodeo') {
      $event_type = 'Freestyle';
    }
    $value = strtolower($event_type);
    return $value;
  }

  // Map from Event Status tid.
  public function mapFromEventStatus($value) {
    switch($value) {
      case 40:
        $value = 'Normal';
        break;
      case 41:
        $value = 'Changed';
        break;
      case 42:
        $value = 'Cancelled';
        break;
    }
    $value = strtolower($value);
    return $value;
  }

  // From https://www.drupal.org/node/2195579#comment-8594703
  public function prepare($node, $row) {
    // This line was taken from migrate_d2d-7.x-2.0/node.inc, line 136
    $path = $this->version->getPath('node/' . $row->nid);
    if (!empty($path)) {
      $node->path['alias'] = $path;
    }
  }

  public function prepareRow($row) {

    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    //flog_it(__CLASS__ .'->'. __FUNCTION__ . ': row=' . print_r($row, TRUE));

    $array_row = (array)$row;
    foreach ($array_row as $key => $value) {
      // Inject Event type tid into row for mapping in mapFromEventType().
      if ($key == 6) {
        $row->event_type_tid = current($value);
      }

      // Inject Event status tid into row for mapping in mapFromEventStatus().
      if ($key == 7) {
        $row->event_status_tid = current($value);
      }
    }

    return TRUE;
  }

}
