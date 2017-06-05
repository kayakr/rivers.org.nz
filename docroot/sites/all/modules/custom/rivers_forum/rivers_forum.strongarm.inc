<?php
/**
 * @file
 * rivers_forum.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function rivers_forum_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'forum_containers';
  $strongarm->value = array();
  $export['forum_containers'] = $strongarm;

  return $export;
}
