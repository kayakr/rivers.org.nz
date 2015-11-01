<?php

class RiversMediaReleaseDrupalNode6Migration extends DrupalNode6Migration {

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

    $this->addFieldMapping('field_release_date', 'field_release_date');
    $this->addFieldMapping('field_date:timezone')
      ->defaultValue(variable_get('date_default_timezone'));

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

    return TRUE;
  }

}
