<?php
/**
 * @file
 * rivers_civicrm.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rivers_civicrm_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
