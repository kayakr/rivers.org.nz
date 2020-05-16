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

  // #43 Add javascript to trigger bs dropdown.
  drupal_add_js("jQuery(document).ready(function () { jQuery('.dropdown-toggle').dropdown(); });", 'inline');
}

/**
 * Override THEMENAME_menu_tree__MENUNAME().
 * @param $variables
 *
 * @return string
 */
function riversorgnz_menu_tree__user_menu($variables) {
  return '<ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
}

/**
 * Implements template_preprocess_comment().
 * @param $variables
 */
function riversorgnz_preprocess_comment(&$variables) {

  // Add bootstrap button classes to Delete, Reply, Edit links.
  foreach ($variables['content']['links']['comment']['#links'] as $key => $link) {
    $variables['content']['links']['comment']['#links'][$key]['attributes'] = array('class' => array(
      'btn',
    ));
    // Style using bootstrap https://getbootstrap.com/css/#buttons-options
    switch ($key) {
      case 'comment-delete':
        $variables['content']['links']['comment']['#links'][$key]['attributes']['class'][] = 'btn-danger';
        break;
      default:
        $variables['content']['links']['comment']['#links'][$key]['attributes']['class'][] = 'btn-default';
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
    case 'block-rivers-donate-rivers-donate':
      $variables['classes_array'][] = 'col-md-6';
      break;

    case 'block-rivers-forum-rivers-forum-summary':
    case 'block-rivers-issue-rivers-issue':
      $variables['classes_array'][] = 'col-md-3';
      break;

    case 'block-rivers-blocks-rivers-catalyst-cloud':
      $variables['classes_array'][] = 'col-xs-12 col-sm-3';
      break;
  }
}

/**
 * Override THEMENAME_menu_link__MENU_NAME() to add destination to login link.
 */
function riversorgnz_menu_link__user_menu(&$variables) {
  // Redirect login back to current page.
  if ($variables['element']['#href'] == 'user/login') {
    $variables['element']['#localized_options']['query'] = array('destination' => substr($_SERVER['REQUEST_URI'], 1));
  }

  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
