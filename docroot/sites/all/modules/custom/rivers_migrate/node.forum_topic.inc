<?php

class RiversForumTopicDrupalNode6Migration extends DrupalNode6Migration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    //$this->destination = new MigrateDestinationNodeRevision($arguments['destination_type']);

    // Preserve the nids from D6.
    $this->addFieldMapping('nid', 'nid');
    //$this->addFieldMapping('vid', 'vid');
    $this->addFieldMapping('is_new')->defaultvalue(TRUE);

    $this->addFieldMapping('body:format', NULL, FALSE)
      ->defaultValue('filtered_html');

    // Preserve the paths from D6.
    $this->addFieldMapping('path', 'path');

    /*$this->addFieldMapping('body:format', 'format')
      ->defaultValue('full_html')
      ->callbacks(array($this, 'mapFormat'));*/

    // Migrate from User reference field to Entity Reference field,
    // taking into account remapped user ids.
    //$this->addFieldMapping('field_authorised', 'field_authorised')
    //  ->sourceMigration('EquitasUser');

    //$this->addFieldMapping('field_date', 'field_date');
    //$this->addFieldMapping('field_date:timezone')
    //  ->defaultValue(variable_get('date_default_timezone'));

    // Note that we map migrated terms by the vocabulary ID.
    //$this->addFieldMapping('field_category', '3')
    //  ->callbacks(array($this, 'mapTermToTextKey'));

    $this->addFieldMapping('taxonomy_forums', '5')
      ->sourceMigration('RiversVocabForums');
    $this->addFieldMapping('taxonomy_forums:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('taxonomy_forums:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('taxonomy_forums:ignore_case')
      ->defaultValue(TRUE);

    // D6 images
    //$this->addFieldMapping('field_image', 'image')
    //  ->sourceMigration('RiversFile');

    // D6 Attachments (files field) to File field.
    $this->addFieldMapping('field_files', 'upload')
      ->sourceMigration('RiversFile');
    $this->addFieldMapping('field_files:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_files:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_files:description', 'upload:description');
    $this->addFieldMapping('field_files:display', 'upload:list');

    /* $this->addFieldMapping('field_my_image:title', 'image_copyright')
       ->defaultValue(t('(c) 2012 My Site'));
     $this->addFieldMapping('field_my_image:alt', 'image_description')
       ->defaultValue('');*/
    $this->addFieldMapping('field_files:language')
      ->defaultValue(LANGUAGE_NONE);

    // Add redirect based on https://www.drupal.org/node/1116408.
    $this->addFieldMapping('migrate_redirects', 'path');

    $this->addUnmigratedDestinations(array(
      'path', // Don't want original path as we regenerate & redirect.
      'field_date:rrule',
      'field_date:to',
      'field_review_date:rrule',
      'field_review_date:to',
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

    flog_it(__CLASS__ .'->'. __FUNCTION__ . ': row=' . print_r($row, TRUE));

    return TRUE;
  }

}
