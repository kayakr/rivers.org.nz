<?php
/**
 * Settings common to each instance of this site.
 */
$conf['locale_custom_strings_en'][''] = array(
  'You are not authorized to access this page.' => 'You are not authorised to access this page.',
);

// Set environment based on host.
switch ($_SERVER['HTTP_HOST']) {
  case '3rivers.local':
    $conf['environment'] = 'development';
    break;

  case 'd7.rivers.org.nz':
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
    ini_set('memory_limit', '128M');
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

  case 'staging':
    ini_set('error_reporting', E_ALL);
    ini_set('display_errors', TRUE);
    ini_set('memory_limit', '128M');
    // c/- PreviousNext
    // Memory allocation to be 256MB. This is to cover cron etc.
    if (isset($_GET['q']) && (strpos($_GET['q'], 'admin') === 0 || strpos($_GET['q'], 'en/admin') === 0)) {
      ini_set('memory_limit', '156M');
    }
    // Node edit pages are memory heavy too.
    if (isset($_GET['q']) && preg_match('@^node\/([0-9]+)\/edit$@', $_GET['q'])) {
      ini_set('memory_limit', '156M');
    }

    // Memory allocation to be 256MB. This is to cover cron etc.
    if (isset($_GET['q']) && (strpos($_GET['q'], 'batch') === 0)) {
      ini_set('memory_limit', '156M');
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
