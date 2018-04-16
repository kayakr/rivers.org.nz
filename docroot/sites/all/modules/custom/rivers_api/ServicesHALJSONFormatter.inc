<?php
/**
 * Implement ServicesFormatterInterface to enable HAL+JSON responses.
 */
class ServicesHALJSONFormatter implements ServicesFormatterInterface {

  public function render($data) {
    xdebug_break();
    $data['version'] = '0.1';
    // json_encode doesn't give valid json with data that isn't an array/object.
    if (is_scalar($data)) {
      $data = array($data);
    }
    return str_replace('\\/', '/', json_encode($data));
  }

}
