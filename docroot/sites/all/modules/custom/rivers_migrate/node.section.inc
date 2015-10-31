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
    $this->addFieldMapping('field_portage', 'field_portage');
    $this->addFieldMapping('field_put_in', 'field_put_in');
    $this->addFieldMapping('field_take_out', 'field_take_out');
    $this->addFieldMapping('field_river_name', 'field_river_name');
    $this->addFieldMapping('field_shuttle', 'field_shuttle');
    $this->addFieldMapping('field_time', 'field_time');


    $this->addFieldMapping('body:format', NULL, FALSE)
      ->defaultValue('full_html');
    // Add redirect based on https://www.drupal.org/node/1116408.
    $this->addFieldMapping('migrate_redirects', 'path');

    // Migrate region from admin/content/taxonomy/4
    $this->addFieldMapping('field_region', 'field_region');
//    $this->addFieldMapping('field_region', '4')
//      ->sourceMigration('RiversVocabRegion');
//    $this->addFieldMapping('field_topic:source_type');
//      ->defaultValue('tid');
    //$this->addFieldMapping('field_topic:create_term')
    //  ->defaultValue(FALSE);
    //$this->addFieldMapping('field_topic:ignore_case')
    //  ->defaultValue(TRUE);

    // Migrate region from admin/content/taxonomy/4
    /*$this->addFieldMapping('field_tags', '3')
      ->sourceMigration('RiversVocabTags');
    $this->addFieldMapping('field_topic:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_topic:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_topic:ignore_case')
      ->defaultValue(TRUE);
    */

    $this->addUnmigratedDestinations(array(
      'path', // Don't want original path as we regenerate & redirect.
      'field_fill', // Measure of number of fields completed.
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
      flog_it(__FUNCTION__ . ': key='. $key . ', value=' . print_r($value, TRUE));
      // We need to populate region field from legacy db Region taxonomy.
      // Do we have a term in Region taxonomy?
      if ($key == 4) {
        $tid = current($value);
        flog_it(__FUNCTION__ . ': tid=' . print_r($tid, TRUE));
        $region = Database::getConnection('default', 'legacy')
          ->select('term_data', 't')
          ->fields('t', array('name'))
          ->condition('tid', $tid)
          ->execute()
          ->fetchField();
        flog_it(__FUNCTION__ . ': region=' . print_r($region, TRUE));
        $row->field_region = $region;
      }
      // Migrate from Tag term to checkbox.
      if ($key == 3) {
        $tags = array();
        foreach ($value as $tag_tid) {
          //$tid = current($value);
          flog_it(__FUNCTION__ . ': tag_tid=' . print_r($tag_tid, TRUE));
          $tag = Database::getConnection('default', 'legacy')
            ->select('term_data', 't')
            ->fields('t', array('name'))
            ->condition('tid', $tag_tid)
            ->execute()
            ->fetchField();
          flog_it(__FUNCTION__ . ': tag=' . print_r($tag, TRUE));
          $tags[] = $tag;
        }
        $row->field_tags = $tags;
        //$row->field_tags = implode(',', $tags);
      }
    }

    flog_it(__FUNCTION__ . ': row=' . print_r($row, TRUE));

    return TRUE;
  }

  function convertToFloat($value) {
    return (float)$value . '.0';
  }

}
