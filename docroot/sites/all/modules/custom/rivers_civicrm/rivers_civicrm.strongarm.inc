<?php
/**
 * @file
 * rivers_civicrm.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function rivers_civicrm_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'civicrmtheme_theme_admin';
  $strongarm->value = 'seven';
  $export['civicrmtheme_theme_admin'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'civicrmtheme_theme_public';
  $strongarm->value = '0';
  $export['civicrmtheme_theme_public'] = $strongarm;

  return $export;
}
