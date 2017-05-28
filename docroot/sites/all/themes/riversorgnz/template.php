<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

/**
 * Pre-processes variables for the "block" theme hook.
 *
 * See template for list of available variables.
 *
 * @see block.tpl.php
 *
 * @ingroup theme_preprocess
 */
function riversorgnz_preprocess_block(&$variables) {
  // Override Latest news view block to add Bootstrap classes.
  switch ($variables['block_html_id']) {
    case 'block-views-rivers-calendar-block-2':
    case 'block-views-rivers-news-latest-news':
      $variables['classes_array'][] = 'col-md-6';
      break;
  }
}
