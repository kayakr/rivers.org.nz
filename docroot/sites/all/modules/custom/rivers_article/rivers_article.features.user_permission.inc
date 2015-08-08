<?php
/**
 * @file
 * rivers_article.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rivers_article_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create rivers_article content'.
  $permissions['create rivers_article content'] = array(
    'name' => 'create rivers_article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any rivers_article content'.
  $permissions['delete any rivers_article content'] = array(
    'name' => 'delete any rivers_article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own rivers_article content'.
  $permissions['delete own rivers_article content'] = array(
    'name' => 'delete own rivers_article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any rivers_article content'.
  $permissions['edit any rivers_article content'] = array(
    'name' => 'edit any rivers_article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own rivers_article content'.
  $permissions['edit own rivers_article content'] = array(
    'name' => 'edit own rivers_article content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
