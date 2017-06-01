<?php

class RiversIssueDrupalNode6Migration extends DrupalNode6Migration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    //$this->destination = new MigrateDestinationNodeRevision($arguments['destination_type']);

    // Preserve the nids from D6.
    $this->addFieldMapping('nid', 'nid');
    //$this->addFieldMapping('vid', 'vid');
    $this->addFieldMapping('is_new')->defaultvalue(TRUE);

    $this->addFieldMapping('body', 'body')
      ->callbacks(array($this, 'mapBody'));
    $this->addFieldMapping('body:format', NULL, FALSE)
      ->defaultValue('full_html');

    // Preserve the paths from D6.
    $this->addFieldMapping('path', 'path');

    $this->addFieldMapping('field_archived', 'field_archived')
      ->callbacks(array($this, 'mapToBoolean'));

    // Map Topic, e.g. Conservation, Access
    $this->addFieldMapping('field_topic', '2')
      ->sourceMigration('RiversVocabTopic');
    $this->addFieldMapping('field_topic:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_topic:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_topic:ignore_case')
      ->defaultValue(TRUE);

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
    ));
  }

  /**
   * Change embedded file links from private (system/files) to public (sites/default/files).
   * @param $value
   * @return mixed
   */
  public function mapBody($value) {
    $value = str_replace('system/files', 'sites/default/files', $value);
    $value = str_replace('http://rivers.org.nz/sites/default/files', '/sites/default/files', $value);
    return $value;
  }

  public function mapToBoolean($value) {
    if ($value == 'on') {
      return 1;
    }
    if ($value == 'off') {
      return 0;
    }
  }

  /**
   * Map from Priority term tids to keys in Priority field integer list.
   * @param $value
   * @return int
   */
  public function mapFromPriority($value) {
    switch ($value) {
      case 94: // Critical
        return 1;
      case 95: // Important
        return 2;
      case 96: // Medium
        return 3;
      case 97: // Low
        return 4;
    }
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
      // Inject Priority tid into row for mapping in mapFromPriority().
      if ($key == 12) {
        $row->event_type_tid = current($value);
      }
    }

    return TRUE;
  }

}
