<?php

class RiversPageDrupalNode6Migration extends DrupalNode6Migration {

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
      if ($path = 'whitewaternz') {
        $path = 'about';
        // add redirect.
      }


      $node->path['alias'] = $path;
    }
  }

  // Change private file paths to public.
  public function mapBody($value) {
    $value = str_replace('/system/files/', '/sites/default/files/', $value);
    return $value;
  }

  public function prepareRow($row) {

    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // NZ Canoeing image path.
    if ($row->nid == 1004) {
      $row->body = str_replace('/sites/rivers.org.nz/themes/rivers_theme', '/sites/all/themes/riversorgnz', $row->body);
    }

    return TRUE;
  }

  // Add redirect from /whitewaternz to /about.
  public function complete($node, $row) {
    if ($node->nid = 1207) {
      $redirect = new stdClass();
      redirect_object_prepare($redirect);
      $redirect->source = 'whitewaternz';
      $redirect->redirect = 'node/' . $node->nid;
      $redirect->language = LANGUAGE_NONE;
      redirect_save($redirect);
    }
  }

}
