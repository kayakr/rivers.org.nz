<?php
/**
 * @file
 * rivers_accounts.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rivers_accounts_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer masquerade'.
  $permissions['administer masquerade'] = array(
    'name' => 'administer masquerade',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'masquerade as admin'.
  $permissions['masquerade as admin'] = array(
    'name' => 'masquerade as admin',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'masquerade as any user'.
  $permissions['masquerade as any user'] = array(
    'name' => 'masquerade as any user',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'masquerade as user'.
  $permissions['masquerade as user'] = array(
    'name' => 'masquerade as user',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'masquerade',
  );

  return $permissions;
}
