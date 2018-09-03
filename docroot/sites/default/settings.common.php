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
      'civicrm_account_contact'                  => '`rivers_civicrm`.',
      'civicrm_account_invoice'                  => '`rivers_civicrm`.',
      'civicrm_acl'                              => '`rivers_civicrm`.',
      'civicrm_acl_cache'                        => '`rivers_civicrm`.',
      'civicrm_acl_contact_cache'                => '`rivers_civicrm`.',
      'civicrm_acl_entity_role'                  => '`rivers_civicrm`.',
      'civicrm_action_log'                       => '`rivers_civicrm`.',
      'civicrm_action_mapping'                   => '`rivers_civicrm`.',
      'civicrm_action_schedule'                  => '`rivers_civicrm`.',
      'civicrm_activity'                         => '`rivers_civicrm`.',
      'civicrm_activity_contact'                 => '`rivers_civicrm`.',
      'civicrm_address'                          => '`rivers_civicrm`.',
      'civicrm_address_format'                   => '`rivers_civicrm`.',
      'civicrm_batch'                            => '`rivers_civicrm`.',
      'civicrm_cache'                            => '`rivers_civicrm`.',
      'civicrm_campaign'                         => '`rivers_civicrm`.',
      'civicrm_campaign_group'                   => '`rivers_civicrm`.',
      'civicrm_case'                             => '`rivers_civicrm`.',
      'civicrm_case_activity'                    => '`rivers_civicrm`.',
      'civicrm_case_contact'                     => '`rivers_civicrm`.',
      'civicrm_case_type'                        => '`rivers_civicrm`.',
      'civicrm_component'                        => '`rivers_civicrm`.',
      'civicrm_contact'                          => '`rivers_civicrm`.',
      'civicrm_contact_type'                     => '`rivers_civicrm`.',
      'civicrm_contribution'                     => '`rivers_civicrm`.',
      'civicrm_contribution_page'                => '`rivers_civicrm`.',
      'civicrm_contribution_product'             => '`rivers_civicrm`.',
      'civicrm_contribution_recur'               => '`rivers_civicrm`.',
      'civicrm_contribution_soft'                => '`rivers_civicrm`.',
      'civicrm_contribution_widget'              => '`rivers_civicrm`.',
      'civicrm_country'                          => '`rivers_civicrm`.',
      'civicrm_county'                           => '`rivers_civicrm`.',
      'civicrm_currency'                         => '`rivers_civicrm`.',
      'civicrm_custom_field'                     => '`rivers_civicrm`.',
      'civicrm_custom_group'                     => '`rivers_civicrm`.',
      'civicrm_cxn'                              => '`rivers_civicrm`.',
      'civicrm_dashboard'                        => '`rivers_civicrm`.',
      'civicrm_dashboard_contact'                => '`rivers_civicrm`.',
      'civicrm_dedupe_exception'                 => '`rivers_civicrm`.',
      'civicrm_dedupe_rule'                      => '`rivers_civicrm`.',
      'civicrm_dedupe_rule_group'                => '`rivers_civicrm`.',
      'civicrm_discount'                         => '`rivers_civicrm`.',
      'civicrm_domain'                           => '`rivers_civicrm`.',
      'civicrm_email'                            => '`rivers_civicrm`.',
      'civicrm_entity_batch'                     => '`rivers_civicrm`.',
      'civicrm_entity_file'                      => '`rivers_civicrm`.',
      'civicrm_entity_financial_account'         => '`rivers_civicrm`.',
      'civicrm_entity_financial_trxn'            => '`rivers_civicrm`.',
      'civicrm_entity_setting'                   => '`rivers_civicrm`.',
      'civicrm_entity_tag'                       => '`rivers_civicrm`.',
      'civicrm_event'                            => '`rivers_civicrm`.',
      'civicrm_event_carts'                      => '`rivers_civicrm`.',
      'civicrm_events_in_carts'                  => '`rivers_civicrm`.',
      'civicrm_extension'                        => '`rivers_civicrm`.',
      'civicrm_file'                             => '`rivers_civicrm`.',
      'civicrm_financial_account'                => '`rivers_civicrm`.',
      'civicrm_financial_item'                   => '`rivers_civicrm`.',
      'civicrm_financial_trxn'                   => '`rivers_civicrm`.',
      'civicrm_financial_type'                   => '`rivers_civicrm`.',
      'civicrm_grant'                            => '`rivers_civicrm`.',
      'civicrm_group'                            => '`rivers_civicrm`.',
      'civicrm_group_contact'                    => '`rivers_civicrm`.',
      'civicrm_group_contact_cache'              => '`rivers_civicrm`.',
      'civicrm_group_nesting'                    => '`rivers_civicrm`.',
      'civicrm_group_organization'               => '`rivers_civicrm`.',
      'civicrm_im'                               => '`rivers_civicrm`.',
      'civicrm_job'                              => '`rivers_civicrm`.',
      'civicrm_job_log'                          => '`rivers_civicrm`.',
      'civicrm_line_item'                        => '`rivers_civicrm`.',
      'civicrm_loc_block'                        => '`rivers_civicrm`.',
      'civicrm_location_type'                    => '`rivers_civicrm`.',
      'civicrm_log'                              => '`rivers_civicrm`.',
      'civicrm_mail_settings'                    => '`rivers_civicrm`.',
      'civicrm_mailing'                          => '`rivers_civicrm`.',
      'civicrm_mailing_abtest'                   => '`rivers_civicrm`.',
      'civicrm_mailing_bounce_pattern'           => '`rivers_civicrm`.',
      'civicrm_mailing_bounce_type'              => '`rivers_civicrm`.',
      'civicrm_mailing_component'                => '`rivers_civicrm`.',
      'civicrm_mailing_event_bounce'             => '`rivers_civicrm`.',
      'civicrm_mailing_event_confirm'            => '`rivers_civicrm`.',
      'civicrm_mailing_event_delivered'          => '`rivers_civicrm`.',
      'civicrm_mailing_event_forward'            => '`rivers_civicrm`.',
      'civicrm_mailing_event_opened'             => '`rivers_civicrm`.',
      'civicrm_mailing_event_queue'              => '`rivers_civicrm`.',
      'civicrm_mailing_event_reply'              => '`rivers_civicrm`.',
      'civicrm_mailing_event_subscribe'          => '`rivers_civicrm`.',
      'civicrm_mailing_event_trackable_url_open' => '`rivers_civicrm`.',
      'civicrm_mailing_event_unsubscribe'        => '`rivers_civicrm`.',
      'civicrm_mailing_group'                    => '`rivers_civicrm`.',
      'civicrm_mailing_job'                      => '`rivers_civicrm`.',
      'civicrm_mailing_recipients'               => '`rivers_civicrm`.',
      'civicrm_mailing_spool'                    => '`rivers_civicrm`.',
      'civicrm_mailing_trackable_url'            => '`rivers_civicrm`.',
      'civicrm_managed'                          => '`rivers_civicrm`.',
      'civicrm_mapping'                          => '`rivers_civicrm`.',
      'civicrm_mapping_field'                    => '`rivers_civicrm`.',
      'civicrm_membership'                       => '`rivers_civicrm`.',
      'civicrm_membership_block'                 => '`rivers_civicrm`.',
      'civicrm_membership_log'                   => '`rivers_civicrm`.',
      'civicrm_membership_payment'               => '`rivers_civicrm`.',
      'civicrm_membership_status'                => '`rivers_civicrm`.',
      'civicrm_membership_type'                  => '`rivers_civicrm`.',
      'civicrm_menu'                             => '`rivers_civicrm`.',
      'civicrm_navigation'                       => '`rivers_civicrm`.',
      'civicrm_note'                             => '`rivers_civicrm`.',
      'civicrm_openid'                           => '`rivers_civicrm`.',
      'civicrm_option_group'                     => '`rivers_civicrm`.',
      'civicrm_option_value'                     => '`rivers_civicrm`.',
      'civicrm_participant'                      => '`rivers_civicrm`.',
      'civicrm_participant_payment'              => '`rivers_civicrm`.',
      'civicrm_participant_status_type'          => '`rivers_civicrm`.',
      'civicrm_payment_processor'                => '`rivers_civicrm`.',
      'civicrm_payment_processor_type'           => '`rivers_civicrm`.',
      'civicrm_payment_token'                    => '`rivers_civicrm`.',
      'civicrm_pcp'                              => '`rivers_civicrm`.',
      'civicrm_pcp_block'                        => '`rivers_civicrm`.',
      'civicrm_persistent'                       => '`rivers_civicrm`.',
      'civicrm_phone'                            => '`rivers_civicrm`.',
      'civicrm_pledge'                           => '`rivers_civicrm`.',
      'civicrm_pledge_block'                     => '`rivers_civicrm`.',
      'civicrm_pledge_payment'                   => '`rivers_civicrm`.',
      'civicrm_preferences_date'                 => '`rivers_civicrm`.',
      'civicrm_premiums'                         => '`rivers_civicrm`.',
      'civicrm_premiums_product'                 => '`rivers_civicrm`.',
      'civicrm_prevnext_cache'                   => '`rivers_civicrm`.',
      'civicrm_price_field'                      => '`rivers_civicrm`.',
      'civicrm_price_field_value'                => '`rivers_civicrm`.',
      'civicrm_price_set'                        => '`rivers_civicrm`.',
      'civicrm_price_set_entity'                 => '`rivers_civicrm`.',
      'civicrm_print_label'                      => '`rivers_civicrm`.',
      'civicrm_product'                          => '`rivers_civicrm`.',
      'civicrm_queue_item'                       => '`rivers_civicrm`.',
      'civicrm_recurring_entity'                 => '`rivers_civicrm`.',
      'civicrm_relationship'                     => '`rivers_civicrm`.',
      'civicrm_relationship_type'                => '`rivers_civicrm`.',
      'civicrm_report_instance'                  => '`rivers_civicrm`.',
      'civicrm_saved_search'                     => '`rivers_civicrm`.',
      'civicrm_setting'                          => '`rivers_civicrm`.',
      'civicrm_sms_provider'                     => '`rivers_civicrm`.',
      'civicrm_state_province'                   => '`rivers_civicrm`.',
      'civicrm_status_pref'                      => '`rivers_civicrm`.',
      'civicrm_subscription_history'             => '`rivers_civicrm`.',
      'civicrm_survey'                           => '`rivers_civicrm`.',
      'civicrm_system_log'                       => '`rivers_civicrm`.',
      'civicrm_tag'                              => '`rivers_civicrm`.',
      'civicrm_tell_friend'                      => '`rivers_civicrm`.',
      'civicrm_timezone'                         => '`rivers_civicrm`.',
      'civicrm_uf_field'                         => '`rivers_civicrm`.',
      'civicrm_uf_group'                         => '`rivers_civicrm`.',
      'civicrm_uf_join'                          => '`rivers_civicrm`.',
      'civicrm_uf_match'                         => '`rivers_civicrm`.',
      'civicrm_value_donation_acknowledgement_4' => '`rivers_civicrm`.',
      'civicrm_value_member_individual_info_3'   => '`rivers_civicrm`.',
      'civicrm_value_member_info_1'              => '`rivers_civicrm`.',
      'civicrm_value_member_numbers_2'           => '`rivers_civicrm`.',
      'civicrm_website'                          => '`rivers_civicrm`.',
      'civicrm_word_replacement'                 => '`rivers_civicrm`.',
      'civicrm_worldregion'                      => '`rivers_civicrm`.',
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
}
