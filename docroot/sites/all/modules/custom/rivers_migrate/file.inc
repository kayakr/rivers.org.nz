<?php


class RiversDrupalFile6Migration extends DrupalFile6Migration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    //$this->destination = new MigrateDestinationNodeRevision($arguments['destination_type']);

  }

  public function prepareRow($row) {

    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    
    // $row->filename = "_original"
    // Ignore D6 derivative files.
    if (in_array($row->filename, array('tiny', 'thumbnail', 'medium', 'preview'))) {
      return FALSE;
    }

    return TRUE;
  }


  /**
   * Override DrupalFile6Migration->fixUri()
   * Field mapping callback: Get the URI relative to the file directory.
   *
   * @param $uri
   *
   * @return mixed
   */
  protected function fixUri($uri) {
    // Try the legacy path, as best we could determine it.
    $result = str_replace($this->legacyPath, '', $uri);
    if ($result == $uri) {
      // That didn't work, so assume the prefix is of the form sites/%/files.
      $result = preg_replace('|^sites/[^/]+/files/|i', '', $uri);
    }
    // strip /home/rivers/files_rivers from filepath, so we don't get deep file paths.
    $result = str_replace('/home/rivers/files_rivers', '', $result);
    return $result;
  }
}
