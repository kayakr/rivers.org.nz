<?php
/**
 * @file
 * rivers_submission.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rivers_submission_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create rivers_submission content'.
  $permissions['create rivers_submission content'] = array(
    'name' => 'create rivers_submission content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any rivers_submission content'.
  $permissions['delete any rivers_submission content'] = array(
    'name' => 'delete any rivers_submission content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own rivers_submission content'.
  $permissions['delete own rivers_submission content'] = array(
    'name' => 'delete own rivers_submission content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any rivers_submission content'.
  $permissions['edit any rivers_submission content'] = array(
    'name' => 'edit any rivers_submission content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own rivers_submission content'.
  $permissions['edit own rivers_submission content'] = array(
    'name' => 'edit own rivers_submission content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
