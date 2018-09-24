<?php
/**
 * Settings common to each instance of this site.
 */
$conf['locale_custom_strings_en'][''] = array(
  'You are not authorized to access this page.' => 'You are not authorised to access this page.',
);

// Enable HTTPS.
if (isset($_SERVER['HTTP_X_FORWARDED_PROTO']) &&
  $_SERVER['HTTP_X_FORWARDED_PROTO'] == 'https') {
  $_SERVER['HTTPS'] = 'on';
}

// Set environment based on host.
switch ($_SERVER['HTTP_HOST']) {
  case '3rivers.local':
    $conf['environment'] = 'development';
    break;

  case 'd7.rivers.org.nz':
    $conf['environment'] = 'uat';
    break;

  case 'rivers.catalystdemo.net.nz':
    $conf['environment'] = 'staging';
    break;

  // rivers.org.nz
  default:
    $conf['environment'] = 'production';
}

// File system
$conf['file_directory_path'] = 'sites/default/files';
$conf['file_public_path'] = $conf['file_directory_path'];

if (!ini_get('date.timezone')) {
  ini_set('date.timezone', 'Pacific/Auckland');
}

// Default configuration per environment.
switch ($conf['environment']) {

  case 'development':
    ini_set('error_reporting', E_ALL);
    ini_set('display_errors', TRUE);
    ini_set('memory_limit', '156M');

    // File system.
    $conf['file_private_path'] = '/Users/jonathan/Sites/files_rivers_dev';

    // Flog.
    $conf['flog_path'] = $conf['file_directory_path'];
    $conf['flog_enabled'] = TRUE;

    // Redirect mail to huntdesign.co.nz
    $conf['mail_redirect_domain'] = 'huntdesign.co.nz';

    // Environment & Environment Indicator.
    $conf['environment_indicator_overwrite'] = TRUE;
    $conf['environment_indicator_overwritten_name'] = strtoupper($conf['environment']);
    $conf['environment_indicator_overwritten_color'] = '#24ae43';
    $conf['environment_indicator_overwritten_drawer_color'] = '#333333';
    $conf['environment_indicator_overwritten_text_color'] = '#ffffff';
    $conf['environment_indicator_overwritten_position'] = 'top';
    $conf['environment_indicator_overwritten_fixed'] = FALSE;
    break;

  // Catalyst CHCSC staging.
  case 'staging':
    ini_set('error_reporting', E_ALL);
    ini_set('display_errors', TRUE);
    ini_set('memory_limit', '156M');
    // c/- PreviousNext
    // Memory allocation to be 256MB. This is to cover cron etc.
    if (isset($_GET['q']) && (strpos($_GET['q'], 'admin') === 0 || strpos($_GET['q'], 'en/admin') === 0)) {
      ini_set('memory_limit', '196M');
    }
    // Node edit pages are memory heavy too.
    if (isset($_GET['q']) && preg_match('@^node\/([0-9]+)\/edit$@', $_GET['q'])) {
      ini_set('memory_limit', '196M');
    }

    // Memory allocation to be 256MB. This is to cover cron etc.
    if (isset($_GET['q']) && (strpos($_GET['q'], 'batch') === 0)) {
      ini_set('memory_limit', '196M');
    }

    // File system.
    //$conf['file_private_path'] = '/home/rivers/files_rivers_dev';
    $conf['file_directory_path'] = 'sites/default/files';

    $conf['reverse_proxy'] = true;
    $conf['reverse_proxy_header'] = 'HTTP_X_FORWARDED_FOR';

    // Each element of this array is the IP address of any of your reverse proxies.
    $conf['reverse_proxy_addresses'] = array('127.0.0.1');

    // Connection details for Catalyst Squid proxies.
    $conf['proxy_server'] = 'ext-proxy-staging.catalyst.net.nz';
    $conf['proxy_port'] = '3128';
    $conf['proxy_exceptions'] = array('cat-chcsc-staging-solr.servers.catalyst.net.nz');

    $conf['omit_vary_cookie'] = true;
    
    // Flog.
    $conf['flog_path'] = $conf['file_directory_path'];
    $conf['flog_enabled'] = TRUE;

    // Redirect mail to huntdesign.co.nz
    $conf['mail_redirect_domain'] = 'huntdesign.co.nz';

    // Environment & Environment Indicator.
    $conf['environment_indicator_overwrite'] = TRUE;
    $conf['environment_indicator_overwritten_name'] = strtoupper($conf['environment']);
    $conf['environment_indicator_overwritten_color'] = '#fa630a';
    $conf['environment_indicator_overwritten_drawer_color'] = '#333333';
    $conf['environment_indicator_overwritten_text_color'] = '#ffffff';
    $conf['environment_indicator_overwritten_position'] = 'top';
    $conf['environment_indicator_overwritten_fixed'] = FALSE;

    global $databases;
    $databases['default']['default']['prefix']= array(
      'default' => '',
      'civicrm_account_contact'                  => '`drupal-site-rivers-civicrm`.',
      'civicrm_account_invoice'                  => '`drupal-site-rivers-civicrm`.',
      'civicrm_acl'                              => '`drupal-site-rivers-civicrm`.',
      'civicrm_acl_cache'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_acl_contact_cache'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_acl_entity_role'                  => '`drupal-site-rivers-civicrm`.',
      'civicrm_action_log'                       => '`drupal-site-rivers-civicrm`.',
      'civicrm_action_mapping'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_action_schedule'                  => '`drupal-site-rivers-civicrm`.',
      'civicrm_activity'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_activity_contact'                 => '`drupal-site-rivers-civicrm`.',
      'civicrm_address'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_address_format'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_batch'                            => '`drupal-site-rivers-civicrm`.',
      'civicrm_cache'                            => '`drupal-site-rivers-civicrm`.',
      'civicrm_campaign'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_campaign_group'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_case'                             => '`drupal-site-rivers-civicrm`.',
      'civicrm_case_activity'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_case_contact'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_case_type'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_component'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_contact'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_contact_type'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_contribution'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_contribution_page'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_contribution_product'             => '`drupal-site-rivers-civicrm`.',
      'civicrm_contribution_recur'               => '`drupal-site-rivers-civicrm`.',
      'civicrm_contribution_soft'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_contribution_widget'              => '`drupal-site-rivers-civicrm`.',
      'civicrm_country'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_county'                           => '`drupal-site-rivers-civicrm`.',
      'civicrm_currency'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_custom_field'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_custom_group'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_cxn'                              => '`drupal-site-rivers-civicrm`.',
      'civicrm_dashboard'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_dashboard_contact'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_dedupe_exception'                 => '`drupal-site-rivers-civicrm`.',
      'civicrm_dedupe_rule'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_dedupe_rule_group'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_discount'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_domain'                           => '`drupal-site-rivers-civicrm`.',
      'civicrm_email'                            => '`drupal-site-rivers-civicrm`.',
      'civicrm_entity_batch'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_entity_file'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_entity_financial_account'         => '`drupal-site-rivers-civicrm`.',
      'civicrm_entity_financial_trxn'            => '`drupal-site-rivers-civicrm`.',
      'civicrm_entity_setting'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_entity_tag'                       => '`drupal-site-rivers-civicrm`.',
      'civicrm_event'                            => '`drupal-site-rivers-civicrm`.',
      'civicrm_event_carts'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_events_in_carts'                  => '`drupal-site-rivers-civicrm`.',
      'civicrm_extension'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_file'                             => '`drupal-site-rivers-civicrm`.',
      'civicrm_financial_account'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_financial_item'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_financial_trxn'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_financial_type'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_grant'                            => '`drupal-site-rivers-civicrm`.',
      'civicrm_group'                            => '`drupal-site-rivers-civicrm`.',
      'civicrm_group_contact'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_group_contact_cache'              => '`drupal-site-rivers-civicrm`.',
      'civicrm_group_nesting'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_group_organization'               => '`drupal-site-rivers-civicrm`.',
      'civicrm_im'                               => '`drupal-site-rivers-civicrm`.',
      'civicrm_job'                              => '`drupal-site-rivers-civicrm`.',
      'civicrm_job_log'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_line_item'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_loc_block'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_location_type'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_log'                              => '`drupal-site-rivers-civicrm`.',
      'civicrm_mail_settings'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_abtest'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_bounce_pattern'           => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_bounce_type'              => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_component'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_bounce'             => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_confirm'            => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_delivered'          => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_forward'            => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_opened'             => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_queue'              => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_reply'              => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_subscribe'          => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_trackable_url_open' => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_unsubscribe'        => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_group'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_job'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_recipients'               => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_spool'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_trackable_url'            => '`drupal-site-rivers-civicrm`.',
      'civicrm_managed'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_mapping'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_mapping_field'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_membership'                       => '`drupal-site-rivers-civicrm`.',
      'civicrm_membership_block'                 => '`drupal-site-rivers-civicrm`.',
      'civicrm_membership_log'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_membership_payment'               => '`drupal-site-rivers-civicrm`.',
      'civicrm_membership_status'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_membership_type'                  => '`drupal-site-rivers-civicrm`.',
      'civicrm_menu'                             => '`drupal-site-rivers-civicrm`.',
      'civicrm_navigation'                       => '`drupal-site-rivers-civicrm`.',
      'civicrm_note'                             => '`drupal-site-rivers-civicrm`.',
      'civicrm_openid'                           => '`drupal-site-rivers-civicrm`.',
      'civicrm_option_group'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_option_value'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_participant'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_participant_payment'              => '`drupal-site-rivers-civicrm`.',
      'civicrm_participant_status_type'          => '`drupal-site-rivers-civicrm`.',
      'civicrm_payment_processor'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_payment_processor_type'           => '`drupal-site-rivers-civicrm`.',
      'civicrm_payment_token'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_pcp'                              => '`drupal-site-rivers-civicrm`.',
      'civicrm_pcp_block'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_persistent'                       => '`drupal-site-rivers-civicrm`.',
      'civicrm_phone'                            => '`drupal-site-rivers-civicrm`.',
      'civicrm_pledge'                           => '`drupal-site-rivers-civicrm`.',
      'civicrm_pledge_block'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_pledge_payment'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_preferences_date'                 => '`drupal-site-rivers-civicrm`.',
      'civicrm_premiums'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_premiums_product'                 => '`drupal-site-rivers-civicrm`.',
      'civicrm_prevnext_cache'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_price_field'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_price_field_value'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_price_set'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_price_set_entity'                 => '`drupal-site-rivers-civicrm`.',
      'civicrm_print_label'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_product'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_queue_item'                       => '`drupal-site-rivers-civicrm`.',
      'civicrm_recurring_entity'                 => '`drupal-site-rivers-civicrm`.',
      'civicrm_relationship'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_relationship_type'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_report_instance'                  => '`drupal-site-rivers-civicrm`.',
      'civicrm_saved_search'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_setting'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_sms_provider'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_state_province'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_status_pref'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_subscription_history'             => '`drupal-site-rivers-civicrm`.',
      'civicrm_survey'                           => '`drupal-site-rivers-civicrm`.',
      'civicrm_system_log'                       => '`drupal-site-rivers-civicrm`.',
      'civicrm_tag'                              => '`drupal-site-rivers-civicrm`.',
      'civicrm_tell_friend'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_timezone'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_uf_field'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_uf_group'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_uf_join'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_uf_match'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_value_donation_acknowledgement_4' => '`drupal-site-rivers-civicrm`.',
      'civicrm_value_member_individual_info_3'   => '`drupal-site-rivers-civicrm`.',
      'civicrm_value_member_info_1'              => '`drupal-site-rivers-civicrm`.',
      'civicrm_value_member_numbers_2'           => '`drupal-site-rivers-civicrm`.',
      'civicrm_website'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_word_replacement'                 => '`drupal-site-rivers-civicrm`.',
      'civicrm_worldregion'                      => '`drupal-site-rivers-civicrm`.',
    );
    break;

  // Simplehost 'staging'
  case 'uat':
    ini_set('error_reporting', E_ALL ^E_NOTICE ^E_WARNING);
    ini_set('display_errors', TRUE);
    ini_set('memory_limit', '164M');
    // c/- PreviousNext
    // Memory allocation to be 256MB. This is to cover cron etc.
    if (isset($_GET['q']) && (strpos($_GET['q'], 'admin') === 0 || strpos($_GET['q'], 'en/admin') === 0)) {
      ini_set('memory_limit', '196M');
    }
    // Node edit pages are memory heavy too.
    if (isset($_GET['q']) && preg_match('@^node\/([0-9]+)\/edit$@', $_GET['q'])) {
      ini_set('memory_limit', '196M');
    }

    // Memory allocation to be 256MB. This is to cover cron etc.
    if (isset($_GET['q']) && (strpos($_GET['q'], 'batch') === 0)) {
      ini_set('memory_limit', '196M');
    }

    // File system.
    $conf['file_private_path'] = '/home/rivers/files_rivers_dev';

    // Flog.
    $conf['flog_path'] = $conf['file_directory_path'];
    $conf['flog_enabled'] = TRUE;

    // Redirect mail to huntdesign.co.nz
    $conf['mail_redirect_domain'] = 'huntdesign.co.nz';

    // Environment & Environment Indicator.
    $conf['environment_indicator_overwrite'] = TRUE;
    $conf['environment_indicator_overwritten_name'] = strtoupper($conf['environment']);
    $conf['environment_indicator_overwritten_color'] = '#fa630a';
    $conf['environment_indicator_overwritten_drawer_color'] = '#333333';
    $conf['environment_indicator_overwritten_text_color'] = '#ffffff';
    $conf['environment_indicator_overwritten_position'] = 'top';
    $conf['environment_indicator_overwritten_fixed'] = FALSE;
    break;

  case 'production':
    // Define base_url for Link Checker.
    $base_url = 'https://rivers.org.nz';

    ini_set('error_reporting', E_ALL ^E_NOTICE);
    ini_set('display_errors', FALSE);

    // Define private filesystem for Backup and Migrate.
    $conf['file_private_path'] = '/home/rivers/files_rivers';

    // Flog.
    $conf['flog_path'] = $conf['file_directory_path'];
    $conf['flog_enabled'] = TRUE;

    $conf['environment_indicator_overwritten_name'] = 'LIVE';
    $conf['environment_indicator_overwrite'] = FALSE;
    break;

  case 'production-catalyst':
    // Define base_url for Link Checker.
    $base_url = 'https://rivers.org.nz';

    ini_set('error_reporting', E_ALL ^E_NOTICE);
    ini_set('display_errors', FALSE);

    // Define private filesystem for Backup and Migrate.
    $conf['file_private_path'] = '/home/rivers/files_rivers';

    // Flog.
    $conf['flog_path'] = $conf['file_directory_path'];
    $conf['flog_enabled'] = TRUE;

    $conf['environment_indicator_overwritten_name'] = 'LIVE';
    $conf['environment_indicator_overwrite'] = FALSE;

    $conf['file_directory_path'] = 'sites/default/files';

    $conf['reverse_proxy'] = true;
    $conf['reverse_proxy_header'] = 'HTTP_X_FORWARDED_FOR';

    // Each element of this array is the IP address of any of your reverse proxies.
    $conf['reverse_proxy_addresses'] = array('127.0.0.1');

    // Connection details for Catalyst Squid proxies.
    $conf['proxy_server'] = 'ext-proxy-staging.catalyst.net.nz';
    $conf['proxy_port'] = '3128';
    $conf['proxy_exceptions'] = array('cat-chcsc-staging-solr.servers.catalyst.net.nz');

    $conf['omit_vary_cookie'] = true;

    global $databases;
    $databases['default']['default']['prefix']= array(
      'default' => '',
      'civicrm_account_contact'                  => '`drupal-site-rivers-civicrm`.',
      'civicrm_account_invoice'                  => '`drupal-site-rivers-civicrm`.',
      'civicrm_acl'                              => '`drupal-site-rivers-civicrm`.',
      'civicrm_acl_cache'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_acl_contact_cache'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_acl_entity_role'                  => '`drupal-site-rivers-civicrm`.',
      'civicrm_action_log'                       => '`drupal-site-rivers-civicrm`.',
      'civicrm_action_mapping'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_action_schedule'                  => '`drupal-site-rivers-civicrm`.',
      'civicrm_activity'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_activity_contact'                 => '`drupal-site-rivers-civicrm`.',
      'civicrm_address'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_address_format'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_batch'                            => '`drupal-site-rivers-civicrm`.',
      'civicrm_cache'                            => '`drupal-site-rivers-civicrm`.',
      'civicrm_campaign'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_campaign_group'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_case'                             => '`drupal-site-rivers-civicrm`.',
      'civicrm_case_activity'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_case_contact'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_case_type'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_component'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_contact'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_contact_type'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_contribution'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_contribution_page'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_contribution_product'             => '`drupal-site-rivers-civicrm`.',
      'civicrm_contribution_recur'               => '`drupal-site-rivers-civicrm`.',
      'civicrm_contribution_soft'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_contribution_widget'              => '`drupal-site-rivers-civicrm`.',
      'civicrm_country'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_county'                           => '`drupal-site-rivers-civicrm`.',
      'civicrm_currency'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_custom_field'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_custom_group'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_cxn'                              => '`drupal-site-rivers-civicrm`.',
      'civicrm_dashboard'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_dashboard_contact'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_dedupe_exception'                 => '`drupal-site-rivers-civicrm`.',
      'civicrm_dedupe_rule'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_dedupe_rule_group'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_discount'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_domain'                           => '`drupal-site-rivers-civicrm`.',
      'civicrm_email'                            => '`drupal-site-rivers-civicrm`.',
      'civicrm_entity_batch'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_entity_file'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_entity_financial_account'         => '`drupal-site-rivers-civicrm`.',
      'civicrm_entity_financial_trxn'            => '`drupal-site-rivers-civicrm`.',
      'civicrm_entity_setting'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_entity_tag'                       => '`drupal-site-rivers-civicrm`.',
      'civicrm_event'                            => '`drupal-site-rivers-civicrm`.',
      'civicrm_event_carts'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_events_in_carts'                  => '`drupal-site-rivers-civicrm`.',
      'civicrm_extension'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_file'                             => '`drupal-site-rivers-civicrm`.',
      'civicrm_financial_account'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_financial_item'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_financial_trxn'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_financial_type'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_grant'                            => '`drupal-site-rivers-civicrm`.',
      'civicrm_group'                            => '`drupal-site-rivers-civicrm`.',
      'civicrm_group_contact'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_group_contact_cache'              => '`drupal-site-rivers-civicrm`.',
      'civicrm_group_nesting'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_group_organization'               => '`drupal-site-rivers-civicrm`.',
      'civicrm_im'                               => '`drupal-site-rivers-civicrm`.',
      'civicrm_job'                              => '`drupal-site-rivers-civicrm`.',
      'civicrm_job_log'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_line_item'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_loc_block'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_location_type'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_log'                              => '`drupal-site-rivers-civicrm`.',
      'civicrm_mail_settings'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_abtest'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_bounce_pattern'           => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_bounce_type'              => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_component'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_bounce'             => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_confirm'            => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_delivered'          => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_forward'            => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_opened'             => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_queue'              => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_reply'              => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_subscribe'          => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_trackable_url_open' => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_event_unsubscribe'        => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_group'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_job'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_recipients'               => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_spool'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_mailing_trackable_url'            => '`drupal-site-rivers-civicrm`.',
      'civicrm_managed'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_mapping'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_mapping_field'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_membership'                       => '`drupal-site-rivers-civicrm`.',
      'civicrm_membership_block'                 => '`drupal-site-rivers-civicrm`.',
      'civicrm_membership_log'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_membership_payment'               => '`drupal-site-rivers-civicrm`.',
      'civicrm_membership_status'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_membership_type'                  => '`drupal-site-rivers-civicrm`.',
      'civicrm_menu'                             => '`drupal-site-rivers-civicrm`.',
      'civicrm_navigation'                       => '`drupal-site-rivers-civicrm`.',
      'civicrm_note'                             => '`drupal-site-rivers-civicrm`.',
      'civicrm_openid'                           => '`drupal-site-rivers-civicrm`.',
      'civicrm_option_group'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_option_value'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_participant'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_participant_payment'              => '`drupal-site-rivers-civicrm`.',
      'civicrm_participant_status_type'          => '`drupal-site-rivers-civicrm`.',
      'civicrm_payment_processor'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_payment_processor_type'           => '`drupal-site-rivers-civicrm`.',
      'civicrm_payment_token'                    => '`drupal-site-rivers-civicrm`.',
      'civicrm_pcp'                              => '`drupal-site-rivers-civicrm`.',
      'civicrm_pcp_block'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_persistent'                       => '`drupal-site-rivers-civicrm`.',
      'civicrm_phone'                            => '`drupal-site-rivers-civicrm`.',
      'civicrm_pledge'                           => '`drupal-site-rivers-civicrm`.',
      'civicrm_pledge_block'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_pledge_payment'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_preferences_date'                 => '`drupal-site-rivers-civicrm`.',
      'civicrm_premiums'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_premiums_product'                 => '`drupal-site-rivers-civicrm`.',
      'civicrm_prevnext_cache'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_price_field'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_price_field_value'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_price_set'                        => '`drupal-site-rivers-civicrm`.',
      'civicrm_price_set_entity'                 => '`drupal-site-rivers-civicrm`.',
      'civicrm_print_label'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_product'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_queue_item'                       => '`drupal-site-rivers-civicrm`.',
      'civicrm_recurring_entity'                 => '`drupal-site-rivers-civicrm`.',
      'civicrm_relationship'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_relationship_type'                => '`drupal-site-rivers-civicrm`.',
      'civicrm_report_instance'                  => '`drupal-site-rivers-civicrm`.',
      'civicrm_saved_search'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_setting'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_sms_provider'                     => '`drupal-site-rivers-civicrm`.',
      'civicrm_state_province'                   => '`drupal-site-rivers-civicrm`.',
      'civicrm_status_pref'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_subscription_history'             => '`drupal-site-rivers-civicrm`.',
      'civicrm_survey'                           => '`drupal-site-rivers-civicrm`.',
      'civicrm_system_log'                       => '`drupal-site-rivers-civicrm`.',
      'civicrm_tag'                              => '`drupal-site-rivers-civicrm`.',
      'civicrm_tell_friend'                      => '`drupal-site-rivers-civicrm`.',
      'civicrm_timezone'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_uf_field'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_uf_group'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_uf_join'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_uf_match'                         => '`drupal-site-rivers-civicrm`.',
      'civicrm_value_donation_acknowledgement_4' => '`drupal-site-rivers-civicrm`.',
      'civicrm_value_member_individual_info_3'   => '`drupal-site-rivers-civicrm`.',
      'civicrm_value_member_info_1'              => '`drupal-site-rivers-civicrm`.',
      'civicrm_value_member_numbers_2'           => '`drupal-site-rivers-civicrm`.',
      'civicrm_website'                          => '`drupal-site-rivers-civicrm`.',
      'civicrm_word_replacement'                 => '`drupal-site-rivers-civicrm`.',
      'civicrm_worldregion'                      => '`drupal-site-rivers-civicrm`.',
    );
    break;
}
