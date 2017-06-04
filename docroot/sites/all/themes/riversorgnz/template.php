<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

/**
 * Implements template_preprocess_page().
 * @param $variables
 */
function riversorgnz_preprocess_page(&$variables) {

  // Add River name (and Alternate name) to page h1 title.
  if (isset($variables['node'])) {
    $node = $variables['node'];
    if ($node->type == 'section') {

      $river_name = $node->field_river_name[LANGUAGE_NONE][0]['value'];
      //$variables['title_prefix'] = l($river_name, 'nz/' . $alias) . ' / ';

      $variables['title'] = check_plain($river_name) . ' / ' . check_plain($node->title);

      if (!empty($node->field_alternate_name[LANGUAGE_NONE][0]['value'])) {
        $variables['title'] .= ' (' . check_plain($node->field_alternate_name[LANGUAGE_NONE][0]['value']) . ')';
      }
    }
  }
}


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
