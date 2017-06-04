<?php
/**
 * @file
 * rivers_news.features.inc
 */

/**
 * Implements hook_views_api().
 */
function rivers_news_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function rivers_news_image_default_styles() {
  $styles = array();

  // Exported image style: story_highlight_landscape.
  $styles['story_highlight_landscape'] = array(
    'label' => 'Story Highlight Landscape (1:2)',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 175,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
