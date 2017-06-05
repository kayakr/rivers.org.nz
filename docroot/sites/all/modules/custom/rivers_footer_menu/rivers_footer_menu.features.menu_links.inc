<?php
/**
 * @file
 * rivers_footer_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function rivers_footer_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-rivers-footer-menu_guide-to-the-whanganui-river:node/1022.
  $menu_links['menu-rivers-footer-menu_guide-to-the-whanganui-river:node/1022'] = array(
    'menu_name' => 'menu-rivers-footer-menu',
    'link_path' => 'node/1022',
    'router_path' => 'node/%',
    'link_title' => 'Guide to the Whanganui River',
    'options' => array(
      'attributes' => array(
        'title' => 'Guide to the Whanganui River journey',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-rivers-footer-menu_guide-to-the-whanganui-river:node/1022',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-rivers-footer-menu_media:media.
  $menu_links['menu-rivers-footer-menu_media:media'] = array(
    'menu_name' => 'menu-rivers-footer-menu',
    'link_path' => 'media',
    'router_path' => 'media',
    'link_title' => 'Media',
    'options' => array(
      'attributes' => array(
        'title' => 'Media releases & contact details.',
      ),
      'identifier' => 'menu-rivers-footer-menu_media:media',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-rivers-footer-menu_new-zealand-whitewater-5:node/3650.
  $menu_links['menu-rivers-footer-menu_new-zealand-whitewater-5:node/3650'] = array(
    'menu_name' => 'menu-rivers-footer-menu',
    'link_path' => 'node/3650',
    'router_path' => 'node/%',
    'link_title' => 'New Zealand Whitewater 5',
    'options' => array(
      'attributes' => array(
        'title' => 'NZ Whitewater 5: 180 great kayaking runs (2013), Graham Charles',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-rivers-footer-menu_new-zealand-whitewater-5:node/3650',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Guide to the Whanganui River');
  t('Media');
  t('New Zealand Whitewater 5');

  return $menu_links;
}
