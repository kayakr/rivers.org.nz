<?php
/**
 * @file
 * rivers_media_release.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rivers_media_release_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function rivers_media_release_node_info() {
  $items = array(
    'media_release' => array(
      'name' => t('Media release'),
      'base' => 'node_content',
      'description' => t('A formal statement of Whitewater NZ\'s position on an issue for distribution to media outlets (TV, Radio, press, Scoop, etc.)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Ensure at least two Exec members have reviewed a media release before publication.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
