<?php

class RiversArticleDrupalNode6Migration extends DrupalNode6Migration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    //$this->destination = new MigrateDestinationNodeRevision($arguments['destination_type']);

    // Preserve the nids from D6.
    $this->addFieldMapping('field_legacy_nid', 'nid');


    // Migrate from User reference field to Entity Reference field,
    // taking into account remapped user ids.
    //$this->addFieldMapping('field_authorised', 'field_authorised')
    //  ->sourceMigration('EquitasUser');

    $this->addFieldMapping('field_date', 'field_date');
    $this->addFieldMapping('field_date:timezone')
      ->defaultValue(variable_get('date_default_timezone'));

    $this->addFieldMapping('field_review_date', 'field_review');
    $this->addFieldMapping('field_review_date:timezone')
      ->defaultValue(variable_get('date_default_timezone'));

    // Note that we map migrated terms by the vocabulary ID.
    $this->addFieldMapping('field_category', '3')
      ->callbacks(array($this, 'mapTermToTextKey'));

    $this->addFieldMapping('field_tags', '2')
      ->sourceMigration('Tags');
    $this->addFieldMapping('field_tags:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_tags:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_tags:ignore_case')
      ->defaultValue(TRUE);

    // D6 Attachments (upload) to File field.
    $this->addFieldMapping('field_file', 'upload')
      ->sourceMigration('RiversFile');
    $this->addFieldMapping('field_file:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_file:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_file:description', 'upload:description');
    $this->addFieldMapping('field_file:display', 'upload:list');
    /* $this->addFieldMapping('field_my_image:title', 'image_copyright')
       ->defaultValue(t('(c) 2012 My Site'));
     $this->addFieldMapping('field_my_image:alt', 'image_description')
       ->defaultValue('');*/
    $this->addFieldMapping('field_file:language')
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

  public function prepareRow($row) {
    flog_it(__CLASS__ .'->'. __FUNCTION__ . ': row=' . print_r($row, TRUE));
    //drush_print_r($row);

    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Dates are off-by-one.
    //[field_date] => 2013-08-28T12:00:00
    //$row->field_date = str_replace('T12', 'T13', $row->field_date);

    return TRUE;
  }

}

/*
class EquitasDrupalNodeRevision6Migration extends EquitasDrupalNode6Migration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->destination = new MigrateDestinationNodeRevision($arguments['destination_type']);

    //  $this->addFieldMapping('nid', 'nid');
    $this->addFieldMapping('nid', 'nid')
      ->description('Reuse the old NIDs');
    $this->addFieldMapping('vid', 'vid')
      ->description('Reuse the old VIDs');
    $this->addFieldMapping('revision')
      ->defaultValue(TRUE);

  }

  public function prepareRow($row) {
    flog_it(__CLASS__ .'->'. __FUNCTION__ . ': row=' . print_r($row, TRUE));

    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    return TRUE;
  }
}
*/
