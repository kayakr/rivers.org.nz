<?php
/**
 * @file
 * rivers_footer_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function rivers_footer_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-rivers-footer-menu.
  $menus['menu-rivers-footer-menu'] = array(
    'menu_name' => 'menu-rivers-footer-menu',
    'title' => 'Rivers Footer menu',
    'description' => 'Footer links like Media.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer links like Media.');
  t('Rivers Footer menu');

  return $menus;
}
