<?php
/**
 * @file
 * rivers_guide.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rivers_guide_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function rivers_guide_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
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
  drupal_alter('node_info', $items);
  return $items;
}
