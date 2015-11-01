<?php
/**
 * @file
 * rivers_submission.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rivers_submission_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function rivers_submission_node_info() {
  $items = array(
    'rivers_submission' => array(
      'name' => t('Submission'),
      'base' => 'node_content',
      'description' => t('A formal submission to a consultation process, e.g. Resource Management consent application.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
