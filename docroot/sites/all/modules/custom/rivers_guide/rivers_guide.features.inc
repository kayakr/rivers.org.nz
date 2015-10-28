<?php
/**
 * @file
 * rivers_guide.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rivers_guide_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function rivers_guide_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function rivers_guide_node_info() {
  $items = array(
    'gauge' => array(
      'name' => t('Gauge'),
      'base' => 'node_content',
      'description' => t('River flow gauge.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'section' => array(
      'name' => t('Section'),
      'base' => 'node_content',
      'description' => t('A kayakable stretch of a river.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
