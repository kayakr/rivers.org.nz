<?php

class RiversForumTopicDrupalComment6Migration extends DrupalComment6Migration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Preserve the cids from D6.
/*    $this->addFieldMapping('cid', 'cid');
    $this->addFieldMapping('pid', 'pid');
    $this->addFieldMapping('is_new')->defaultvalue(TRUE);
*/
    //$this->addFieldMapping('body:format', NULL, FALSE)
    //  ->defaultValue('filtered_html');

    // Preserve the paths from D6.
    //$this->addFieldMapping('path', 'path');

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
    //$this->addFieldMapping('field_files:description', 'upload:description');
    //$this->addFieldMapping('field_files:display', 'upload:list');

    //$this->addFieldMapping('field_files:language')
    //  ->defaultValue(LANGUAGE_NONE);
  }

  /**
   * Override parent query to include comment_upload files in incoming rows.
   * @return \SelectQueryInterface
   */
  /*public function query() {
    $query = parent::query();
    $query->leftJoin('comment_upload','cu', 'c.cid = cu.cid');
    $query->addExpression("GROUP_CONCAT(cu.fid SEPARATOR ',')", 'comment_upload_fid');
    $query->addExpression("GROUP_CONCAT(cu.description SEPARATOR ',')", 'comment_upload_description');
    $query->addExpression("GROUP_CONCAT(cu.list SEPARATOR ',')", 'comment_upload_list');
    $query->addExpression("GROUP_CONCAT(cu.weight SEPARATOR ',')", 'comment_upload_weight');
    $query->groupBy('c.cid');
    return $query;
  }*/

  public function prepareRow($row) {

    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Get comment_upload files.
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('comment_upload', 'cu')
      ->fields('cu', array('fid'));
    $query->condition('cu.cid', $row->cid);
    $result = $query->execute();
    $files = $result->fetchAll();

    if (!empty($files)) {
      foreach ($files as $file) {
        $row->upload[] = $file->fid;
      }
    }
    //xdebug_break();
      //->orderBy($this->newOnly ? 'c.cid' : 'c.timestamp');

    //flog_it(__CLASS__ .'->'. __FUNCTION__ . ': row=' . print_r($row, TRUE));

    return TRUE;
  }

}

