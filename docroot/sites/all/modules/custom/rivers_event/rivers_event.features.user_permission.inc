<?php
/**
 * @file
 * rivers_event.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rivers_event_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create rivers_event content'.
  $permissions['create rivers_event content'] = array(
    'name' => 'create rivers_event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any rivers_event content'.
  $permissions['delete any rivers_event content'] = array(
    'name' => 'delete any rivers_event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own rivers_event content'.
  $permissions['delete own rivers_event content'] = array(
    'name' => 'delete own rivers_event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any rivers_event content'.
  $permissions['edit any rivers_event content'] = array(
    'name' => 'edit any rivers_event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own rivers_event content'.
  $permissions['edit own rivers_event content'] = array(
    'name' => 'edit own rivers_event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
