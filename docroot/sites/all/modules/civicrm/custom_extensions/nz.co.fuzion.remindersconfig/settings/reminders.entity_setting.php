<?php

return array (
  array(
    'key' => 'nz.co.fuzion.remindersconfig',
    'entity' => 'action_schedule',
    'name' => 'from_name',
    'type' => 'String',
    'html_type' => 'select',
    'pseudoconstant' => array(
      'optionGroupName' => 'from_email_address',
      'all_domains' => TRUE,
    ),
   // 'default_callback' => '_remindersconfig_civicrm_',
    'add' => '1.0',
    'title' => 'From Email',
    'description' => null,
    'help_text' => null,
    'add_to_setting_form' => TRUE,
    'form_child_of_id' => 'email-field-table',
  ),
);