<?php
/**
 * @file
 * rivers_event.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rivers_event_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function rivers_event_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function rivers_event_node_info() {
  $items = array(
    'rivers_event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('An event can be a release, rodeo, race, meeting, etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
