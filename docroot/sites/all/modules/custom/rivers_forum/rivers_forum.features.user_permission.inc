<?php
/**
 * @file
 * rivers_forum.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rivers_forum_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer forums'.
  $permissions['administer forums'] = array(
    'name' => 'administer forums',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'forum',
  );

  return $permissions;
}
