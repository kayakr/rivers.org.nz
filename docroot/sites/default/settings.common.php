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


  default:
    $conf['environment'] = 'production';
    $conf['environment'] = 'development'; // for site install...
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
    //ini_set('xdebug.remote_autostart', 1);
    //ini_set('xdebug.remote_mode', 'jit');

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
    break;

  // Simplehost 'staging'
  case 'uat':
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
    ini_set('error_reporting', E_ALL ^E_NOTICE);
    ini_set('display_errors', FALSE);

    $conf['file_private_path'] = '/home/rivers.org.nz';

    // Flog.
    $conf['flog_path'] = $conf['file_directory_path'];
    $conf['flog_enabled'] = TRUE;
    $conf['flog_file'] = 'drupal-de53477a4016158f6a16ec9c919f60c31c8e26d0.log';

    $conf['environment_indicator_overwritten_name'] = 'LIVE';
    $conf['environment_indicator_overwrite'] = FALSE;
    break;
}
