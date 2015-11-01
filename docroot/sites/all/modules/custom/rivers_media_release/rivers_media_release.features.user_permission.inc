<?php
/**
 * @file
 * rivers_media_release.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rivers_media_release_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create media_release content'.
  $permissions['create media_release content'] = array(
    'name' => 'create media_release content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any media_release content'.
  $permissions['delete any media_release content'] = array(
    'name' => 'delete any media_release content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own media_release content'.
  $permissions['delete own media_release content'] = array(
    'name' => 'delete own media_release content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any media_release content'.
  $permissions['edit any media_release content'] = array(
    'name' => 'edit any media_release content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own media_release content'.
  $permissions['edit own media_release content'] = array(
    'name' => 'edit own media_release content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
