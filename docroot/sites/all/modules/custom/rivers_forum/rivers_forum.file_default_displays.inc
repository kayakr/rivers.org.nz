<?php
/**
 * @file
 * rivers_forum.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function rivers_forum_file_default_displays() {
  $export = array();

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__rivers_forum_comment__file_field_colorbox';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'colorbox_node_style' => 'square_thumbnail',
    'colorbox_node_style_first' => '',
    'colorbox_image_style' => 'large',
    'colorbox_gallery' => 'page',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'auto',
    'colorbox_caption_custom' => '',
  );
  $export['image__rivers_forum_comment__file_field_colorbox'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__rivers_forum_comment__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__rivers_forum_comment__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__rivers_forum_comment__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['image__rivers_forum_comment__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__rivers_forum_comment__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__rivers_forum_comment__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__rivers_forum_comment__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__rivers_forum_comment__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__rivers_forum_comment__file_field_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  $export['image__rivers_forum_comment__file_field_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__rivers_forum_comment__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__rivers_forum_comment__file_field_media_large_icon'] = $file_display;

  return $export;
}
