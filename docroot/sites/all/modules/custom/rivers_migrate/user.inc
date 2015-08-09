<?php

class RiversDrupalUser6Migration extends DrupalUser6Migration {

  public function __construct(array $arguments) {
    //$this->dependencies[] = 'Role';

    parent::__construct($arguments);

    $this->addFieldMapping('roles', 'roles')
      ->sourceMigration('RiversRole');

      $this->addFieldMapping('is_new')->defaultvalue(TRUE);
      $this->addFieldMapping('uid', 'uid');
      $this->addFieldMapping('field_first_name', 'profile_firstname');
      //$this->addfieldMapping('field_first_name:language')->defaultValue('en');
      $this->addFieldMapping('field_last_name', 'profile_lastname');
      //$this->addfieldMapping('field_last_name:language')->defaultValue('en');
      $this->addFieldMapping('field_person_region', 'profile_region');
      $this->addFieldMapping('field_mobile', 'profile_mobile');
      $this->addFieldMapping('field_bio', 'profile_bio');

      $this->addFieldMapping('signature', 'signature')
        ->callbacks(array($this, 'truncateSignature'));

/*      $this->addFieldMapping('field_twitter', 'field_contact_twitter');
      $this->addFieldMapping('field_alternate_phone', 'field_contact_alternate_phone');
      $this->addfieldMapping('field_alternate_phone:language')
        ->defaultValue('en');
      $this->addFieldMapping('field_user_linkedin', 'field_contact_linkedin');
      $this->addfieldMapping('field_user_linkedin:title')->defaultValue('');
      $this->addfieldMapping('field_user_linkedin:attributes')->defaultValue('');
      $this->addfieldMapping('field_user_linkedin:language')->defaultValue('en');
      $this->addFieldMapping('field_user_phone', 'field_phone');
      $this->addfieldMapping('field_user_phone:language')->defaultValue('en');
      $this->addFieldMapping('field_user_title', 'field_title');
      $this->addfieldMapping('field_user_title:language')->defaultValue('en');
      $this->addFieldMapping('field_user_department', 'field_department');
      $this->addfieldMapping('field_user_department:language')
        ->defaultValue('en');
      $this->addFieldMapping('field_user_contact_type', 'field_contact_type');
      $this->addFieldMapping('field_primary_contact', 'field_contact_primary_cont');


      $this->addUnmigratedSources(array(
        'field_contact_image',
        'field_contact_image:list',
        'field_contact_member_company',
        'field_contact_linkedin:title',
        'field_contact_linkedin:attributes',
        'field_contact_twitter:title',
        'field_contact_twitter:attributes'
      ), t('Do Not Migrate'));*/

  }

  public function truncateSignature($value) {
    return substr($value, 0, 255);
  }

  public function prepareRow($row) {
    //flog_it(__CLASS__ .'->'. __FUNCTION__ . ': row=' . print_r($row, TRUE));
    //drush_print_r($row);

    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // We need to populate profile fields from legacy db.
    $profile_fields = Database::getConnection('default', 'legacy')
      ->select('profile_values', 'pv')
      ->fields('pv', array('fid', 'value'))
      ->condition('uid', $row->uid)
      ->execute()
      ->fetchAllKeyed();
    $row->profile_lastname = $profile_fields[1];
    $row->profile_firstname = $profile_fields[2];
    $row->profile_region = $profile_fields[3];
    $row->profile_mobile = $profile_fields[4];
    if (!empty($profile_fields[5])) {
      $row->profile_bio = $profile_fields[5];
    }

    return TRUE;
  }
}
