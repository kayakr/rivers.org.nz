<?php

class RiversSectionDrupalNode6Migration extends DrupalNode6Migration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    //$this->destination = new MigrateDestinationNodeRevision($arguments['destination_type']);

    // Preserve the nids from D6.
    $this->addFieldMapping('nid', 'nid');
    //$this->addFieldMapping('vid', 'vid');
    $this->addFieldMapping('is_new')->defaultvalue(TRUE);

    // D7 from D6.
    $this->addFieldMapping('field_alternate_name', 'field_alternate_name');
    $this->addFieldMapping('field_character', 'field_character');
    $this->addFieldMapping('field_class', 'field_class');
    $this->addFieldMapping('field_credits', 'field_credits');

    $this->addFieldMapping('field_gauge', 'field_gauge');

    $this->addFieldMapping('field_gradient', 'field_gradient')
      ->defaultValue('0.0')
      ->callbacks(array($this, 'convertToFloat'));

    $this->addFieldMapping('field_history', 'field_history');
    $this->addFieldMapping('field_history:format', NULL, FALSE)
      ->defaultValue('full_html');
    $this->addFieldMapping('field_hot_tip', 'field_hot_tip');

    $this->addFieldMapping('field_length', 'field_length')
      ->defaultValue('0.0')
      ->callbacks(array($this, 'convertToFloat'));

    $this->addFieldMapping('field_level', 'field_level');
    $this->addFieldMapping('field_maps', 'field_maps');
    $this->addFieldMapping('field_nzww', 'field_nzww')
      ->defaultValue(0);
    $this->addFieldMapping('field_portage', 'field_portage')
      ->callbacks(array($this, 'convertYesNoToBoolean'))
      ->defaultValue(0);
    $this->addFieldMapping('field_put_in', 'field_put_in');
    $this->addFieldMapping('field_take_out', 'field_take_out');
    $this->addFieldMapping('field_river_name', 'field_river_name');
    $this->addFieldMapping('field_shuttle', 'field_shuttle');
    $this->addFieldMapping('field_time', 'field_time');


    $this->addFieldMapping('body:format', NULL, FALSE)
      ->defaultValue('full_html');
    // Add redirect based on https://www.drupal.org/node/1116408.
    $this->addFieldMapping('migrate_redirects', 'path');

    // Migrate Region from admin/content/taxonomy/4
    // This is marked as mapped, though actual map occurs in prepareRow().
    $this->addFieldMapping('field_region', 'field_region');

    // Migrate Tags from admin/content/taxonomy/3
    // This is marked as mapped, though actual map occurs in prepareRow().
    $this->addFieldMapping('field_tags', 'field_tags');

    $this->addFieldMapping('field_upstream_of', 'ref_id');
      //->sourceMigration(array('RiversNodeSection'));

    $this->addUnmigratedDestinations(array(
      'path', // Don't want original path as we regenerate & redirect.
      'field_fill', // Measure of number of fields completed.
      'field_downstream_of', // is now field_upstream_of.
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

    $array_row = (array)$row;
    //flog_it(__FUNCTION__ . ': array_row[4]=' . print_r($array_row[4], TRUE));
    foreach ($array_row as $key => $value) {
      //flog_it(__FUNCTION__ . ': key='. $key . ', value=' . print_r($value, TRUE));
      // We need to populate region field from legacy db Region taxonomy.
      // Do we have a term in Region taxonomy?
      if ($key == 4) {
        $tid = current($value);
        //flog_it(__FUNCTION__ . ': tid=' . print_r($tid, TRUE));
        $region = Database::getConnection('default', 'legacy')
          ->select('term_data', 't')
          ->fields('t', array('name'))
          ->condition('tid', $tid)
          ->execute()
          ->fetchField();
        //flog_it(__FUNCTION__ . ': region=' . print_r($region, TRUE));
        $row->field_region = $region;
      }
      // Migrate from Tag term to checkbox.
      if ($key == 3) {
        $tags = array();
        foreach ($value as $tag_tid) {
          //$tid = current($value);
          //flog_it(__FUNCTION__ . ': tag_tid=' . print_r($tag_tid, TRUE));
          $tag = Database::getConnection('default', 'legacy')
            ->select('term_data', 't')
            ->fields('t', array('name'))
            ->condition('tid', $tag_tid)
            ->execute()
            ->fetchField();
          //flog_it(__FUNCTION__ . ': tag=' . print_r($tag, TRUE));
          $tags[] = $tag;
        }
        $row->field_tags = $tags;
        //$row->field_tags = implode(',', $tags);
      }
    }

    // handle reference to downstream section.
    //$source_id = $row->field_downstream_of;
    //$row->ref_id = $this->handleSourceMigration('SourceMigration', $source_id);
    //xdebug_break();
    //flog_it(__FUNCTION__ . ': row=' . print_r($row, TRUE));

    return TRUE;
  }

  function convertToFloat($value) {
    return (float)$value; // . '.0';
  }

  function convertYesNoToBoolean($value) {
    return $value == 'yes' ? 1 : 0;
  }

  /**
   * Override DrupalNodeMigration->createStub() to add necessary fields for stub sections.
   * Refer https://www.drupal.org/node/1013506
   */
  /*function createStub($migration, $source_key) {
    migrate_instrument_start('RiversSectionDrupalNode6Migration::createStub');
    $node = new stdClass();
    $node->title = t('Stub for @id', array('@id' => $source_key[0]));
    //$node->nid = $source_key[0]; // preserve nid.
    $node->body = array(LANGUAGE_NONE => array(array("value" => t('Stub body'))));
    $node->type = $this->destination->getBundle();
    $node->uid = 1;
    //$node->status = 1;
    $node->field_gradient = array(LANGUAGE_NONE => array(array('value' => '0.0')));
    $node->field_length = array(LANGUAGE_NONE => array(array('value' => 0)));
    $node->field_nzww = array(LANGUAGE_NONE => array(array('value' => 0)));
    $node->field_portage = array(LANGUAGE_NONE => array(array('value' => 0)));
    xdebug_break();
    node_save($node);
    migrate_instrument_stop('RiversSectionDrupalNode6Migration::createStub');
    if (isset($node->nid)) {
      return array($node->nid);
    }
    else {
      return FALSE;
    }
  } */

}
