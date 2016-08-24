<?php
/**
 * @file
 * rivers_site.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rivers_site_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
