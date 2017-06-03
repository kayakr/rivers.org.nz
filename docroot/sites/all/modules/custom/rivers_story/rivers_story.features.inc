<?php
/**
 * @file
 * rivers_story.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rivers_story_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function rivers_story_image_default_styles() {
  $styles = array();

  // Exported image style: story_highlight_full.
  $styles['story_highlight_full'] = array(
    'label' => 'Story Highlight Full',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 175,
          'height' => 175,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function rivers_story_node_info() {
  $items = array(
    'rivers_story' => array(
      'name' => t('Story'),
      'base' => 'node_content',
      'description' => t('Shorter, timely news items.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
