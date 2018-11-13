<?php

/**
 * @file
 * rivers_issue.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rivers_issue_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create rivers_issue content'.
  $permissions['create rivers_issue content'] = array(
    'name' => 'create rivers_issue content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any rivers_issue content'.
  $permissions['delete any rivers_issue content'] = array(
    'name' => 'delete any rivers_issue content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own rivers_issue content'.
  $permissions['delete own rivers_issue content'] = array(
    'name' => 'delete own rivers_issue content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any rivers_issue content'.
  $permissions['edit any rivers_issue content'] = array(
    'name' => 'edit any rivers_issue content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own rivers_issue content'.
  $permissions['edit own rivers_issue content'] = array(
    'name' => 'edit own rivers_issue content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
