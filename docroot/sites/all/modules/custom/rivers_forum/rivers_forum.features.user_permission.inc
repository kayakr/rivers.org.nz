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

  // Exported permission: 'administer comment notify'.
  $permissions['administer comment notify'] = array(
    'name' => 'administer comment notify',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment_notify',
  );

  // Exported permission: 'administer forums'.
  $permissions['administer forums'] = array(
    'name' => 'administer forums',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'forum',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create forum content'.
  $permissions['create forum content'] = array(
    'name' => 'create forum content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any forum content'.
  $permissions['delete any forum content'] = array(
    'name' => 'delete any forum content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own forum content'.
  $permissions['delete own forum content'] = array(
    'name' => 'delete own forum content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any forum content'.
  $permissions['edit any forum content'] = array(
    'name' => 'edit any forum content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own forum content'.
  $permissions['edit own forum content'] = array(
    'name' => 'edit own forum content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'subscribe to comments'.
  $permissions['subscribe to comments'] = array(
    'name' => 'subscribe to comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment_notify',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'CRM Admin' => 'CRM Admin',
      'Editor' => 'Editor',
      'Exec' => 'Exec',
      'Member' => 'Member',
      'Officer' => 'Officer',
      'River database editor' => 'River database editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'phorum' => 'phorum',
    ),
    'module' => 'file_entity',
  );

  return $permissions;
}
