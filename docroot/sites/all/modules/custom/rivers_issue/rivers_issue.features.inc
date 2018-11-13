<?php

/**
 * @file
 * rivers_issue.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rivers_issue_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function rivers_issue_node_info() {
  $items = array(
    'rivers_issue' => array(
      'name' => t('Issue'),
      'base' => 'node_content',
      'description' => t('Issues tend to drive the work of the Whitewater NZ, e.g. a dam proposal or an access restriction.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
