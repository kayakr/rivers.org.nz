<?php
/**
 * @file
 * rivers_api.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function rivers_api_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'rivers_api';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api';
  $endpoint->authentication = array();
  $endpoint->server_settings = array(
    'formatters' => array(
      'json' => TRUE,
      'bencode' => FALSE,
      'hal+json' => TRUE,
      'jsonp' => FALSE,
      'php' => FALSE,
      'xml' => FALSE,
      'yaml' => FALSE,
    ),
    'parsers' => array(
      'application/json' => TRUE,
      'application/x-www-form-urlencoded' => FALSE,
      'application/x-yaml' => FALSE,
      'application/xml' => FALSE,
      'multipart/form-data' => FALSE,
      'text/xml' => FALSE,
    ),
  );
  $endpoint->resources = array(
    'node' => array(
      //'alias' => 'section',
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'section' => array(
      'operations' => array(
        /*'create' => array(
          'enabled' => '1',
          'settings' => array(
            'oauth2_server' => array(
              'require_authentication' => '1',
              'scope' => 'default',
            ),
          ),
        ),*/
        'retrieve' => array(
          'enabled' => '1',
          'settings' => array(
            //'oauth2_server' => array(
            //  'require_authentication' => '1',
            //  'scope' => 'default',
            //),
          ),
        ),
        'index' => array(
          'enabled' => '1',
          'settings' => array(
            //'oauth2_server' => array(
            //  'require_authentication' => '1',
            //  'scope' => 'default',
            //),
          ),
        ),
      ),
    ),
  );
  $endpoint->debug = 1;
  $export['rivers_api'] = $endpoint;

  return $export;
}
