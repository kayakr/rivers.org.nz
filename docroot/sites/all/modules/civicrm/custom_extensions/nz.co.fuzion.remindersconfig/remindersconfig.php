<?php

require_once 'remindersconfig.civix.php';

/**
 * Implementation of hook_civicrm_config
 */
function remindersconfig_civicrm_config(&$config) {
  _remindersconfig_civix_civicrm_config($config);
}

/**
 * Implementation of hook_civicrm_xmlMenu
 *
 * @param $files array(string)
 */
function remindersconfig_civicrm_xmlMenu(&$files) {
  _remindersconfig_civix_civicrm_xmlMenu($files);
}

/**
 * Implementation of hook_civicrm_install
 */
function remindersconfig_civicrm_install() {
  return _remindersconfig_civix_civicrm_install();
}

/**
 * Implementation of hook_civicrm_uninstall
 */
function remindersconfig_civicrm_uninstall() {
  return _remindersconfig_civix_civicrm_uninstall();
}

/**
 * Implementation of hook_civicrm_enable
 */
function remindersconfig_civicrm_enable() {
  return _remindersconfig_civix_civicrm_enable();
}

/**
 * Implementation of hook_civicrm_disable
 */
function remindersconfig_civicrm_disable() {
  return _remindersconfig_civix_civicrm_disable();
}

/**
 * Implementation of hook_civicrm_upgrade
 *
 * @param $op string, the type of operation being performed; 'check' or 'enqueue'
 * @param $queue CRM_Queue_Queue, (for 'enqueue') the modifiable list of pending up upgrade tasks
 *
 * @return mixed  based on op. for 'check', returns array(boolean) (TRUE if upgrades are pending)
 *                for 'enqueue', returns void
 */
function remindersconfig_civicrm_upgrade($op, CRM_Queue_Queue $queue = NULL) {
  return _remindersconfig_civix_civicrm_upgrade($op, $queue);
}

/**
 * Implementation of hook_civicrm_managed
 *
 * Generate a list of entities to create/deactivate/delete when this module
 * is installed, disabled, uninstalled.
 */
function remindersconfig_civicrm_managed(&$entities) {
  return _remindersconfig_civix_civicrm_managed($entities);
}

/**
 * Implementation of entity setting hook_civicrm_alterEntitySettingsFolders
 * declare folders with entity settings
 */

function remindersconfig_civicrm_alterEntitySettingsFolders(&$folders) {
  static $configured = FALSE;
  if ($configured) return;
  $configured = TRUE;

  $extRoot = dirname( __FILE__ ) . DIRECTORY_SEPARATOR;
  $extDir = $extRoot . 'settings';
  if(!in_array($extDir, $folders)){
    $folders[] = $extDir;
  }
}

function remindersconfig_civicrm_alterMailParams(&$params) {
  if(CRM_Utils_Array::value('entity', $params) == 'action_schedule') {
    try {
      $fromValue = civicrm_api3('entity_setting', 'get', array(
        'key' => 'nz.co.fuzion.remindersconfig',
        'name' => 'from_name',
        'entity_id' => $params['entity_id'],
        'entity_type' => 'action_schedule',
      ));
      if(!empty($fromValue['values'][$params['entity_id']]['from_name'])) {
         $params['from'] = $params['replyTo'] = $params['returnPath'] = civicrm_api3('option_value', 'getvalue', array(
          'option_group_name' => 'from_email_address',
          'value' => $fromValue['values'][$params['entity_id']]['from_name'],
          'return' => 'name',
        ));
      }
    }
    catch(Exception $e) {
      echo $e->getMessage();
    }
  }
}