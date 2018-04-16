<?php
/*
 +--------------------------------------------------------------------+
 | CiviCRM version 4.7                                                |
 +--------------------------------------------------------------------+
 | Copyright CiviCRM LLC (c) 2004-2017                                |
 +--------------------------------------------------------------------+
 | This file is a part of CiviCRM.                                    |
 |                                                                    |
 | CiviCRM is free software; you can copy, modify, and distribute it  |
 | under the terms of the GNU Affero General Public License           |
 | Version 3, 19 November 2007 and the CiviCRM Licensing Exception.   |
 |                                                                    |
 | CiviCRM is distributed in the hope that it will be useful, but     |
 | WITHOUT ANY WARRANTY; without even the implied warranty of         |
 | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.               |
 | See the GNU Affero General Public License for more details.        |
 |                                                                    |
 | You should have received a copy of the GNU Affero General Public   |
 | License and the CiviCRM Licensing Exception along                  |
 | with this program; if not, contact CiviCRM LLC                     |
 | at info[AT]civicrm[DOT]org. If you have questions about the        |
 | GNU Affero General Public License or the licensing of CiviCRM,     |
 | see the CiviCRM license FAQ at http://civicrm.org/licensing        |
 +--------------------------------------------------------------------+
 */

/**
 * @package CRM
 * @copyright CiviCRM LLC (c) 2004-2017
 */

/**
 * Class to represent the actions that can be performed on a group of contacts used by the search forms.
 */
abstract class CRM_Core_Task {

  /**
   * These constants are only used as enumerators for each of the batch tasks.
   */
  const
    // General (Implemented by more than one entity)
    GROUP_REMOVE = 1,
    GROUP_ADD = 2,
    PDF_LETTER = 3,
    TASK_DELETE = 4,
    TASK_PRINT = 5,
    BATCH_UPDATE = 6,
    TASK_SMS = 7,
    TASK_EXPORT = 8,
    TASK_EMAIL = 9,
    TAG_ADD = 10,
    TAG_REMOVE = 11,
    // Contact tasks
    SAVE_SEARCH = 12,
    SAVE_SEARCH_UPDATE = 13,
    CREATE_MAILING = 14,
    DELETE_PERMANENTLY = 15,
    LABEL_CONTACTS = 16;

  /**
   * The task array
   *
   * @var array
   */
  public static $_tasks = NULL;

  /**
   * @var string
   *   This must be defined in each child class.  It is passed to the searchTasks hook.
   *   Example: $objectType = 'event';
   */
  static $objectType = NULL;

  /**
   * Generates a list of batch tasks available for the current entities.
   * Each child class should populate $_tasks array and then call this parent function for shared functionality.
   *    * @return array The set of tasks for a group of contacts
   *            [ 'title' => The Task title,
   *              'class' => The Task Form class name,
   *              'result => Boolean.  FIXME: Not sure what this is for
   *            ]
   */
  public static function tasks() {
    CRM_Utils_Hook::searchTasks(self::$objectType, self::$_tasks);
    asort(self::$_tasks);

    return self::$_tasks;
  }

  /**
   * These tasks are the core set of tasks that the user can perform
   * on a contact / group of contacts
   *
   * @return array
   *   the set of tasks for a group of contacts
   */
  public static function taskTitles() {
    static::tasks();

    $titles = array();
    foreach (self::$_tasks as $id => $value) {
      $titles[$id] = $value['title'];
    }

    if (!CRM_Utils_Mail::validOutBoundMail()) {
      unset($titles[self::TASK_EMAIL]);
      unset($titles[self::CREATE_MAILING]);
    }

    // Users who do not have 'access deleted contacts' should NOT have the 'Delete Permanently' option in search result tasks
    if (!CRM_Core_Permission::check('access deleted contacts') ||
      !CRM_Core_Permission::check('delete contacts')
    ) {
      unset($titles[self::DELETE_PERMANENTLY]);
    }
    return $titles;
  }

  /**
   * Show tasks selectively based on the permission level
   * of the user
   * This function should be call parent::corePermissionedTaskTitles
   *
   * @param int $permission
   * @param array $params
   *             "ssID: Saved Search ID": If !empty we are in saved search context
   *
   * @return array
   *   set of tasks that are valid for the user
   */
  abstract public static function permissionedTaskTitles($permission, $params);

  /**
   * Show tasks selectively based on the permission level
   * of the user
   * This function should be called by permissionedTaskTitles in children
   *
   * @param array $tasks The array of tasks generated by permissionedTaskTitles
   * @param int $permission
   * @param array $params
   *             "ssID: Saved Search ID": If !empty we are in saved search context
   *
   * @return array
   *   set of tasks that are valid for the user
   */
  public static function corePermissionedTaskTitles($tasks, $permission, $params) {
    // Only offer the "Update Smart Group" task if a smart group/saved search is already in play and we have edit permissions
    if (!empty($params['ssID']) && ($permission == CRM_Core_Permission::EDIT)) {
      $tasks[self::SAVE_SEARCH_UPDATE] = self::$_tasks[self::SAVE_SEARCH_UPDATE]['title'];
    }
    else {
      unset($tasks[self::SAVE_SEARCH_UPDATE]);
    }

    asort($tasks);
    return $tasks;
  }

  /**
   * These tasks are the core set of tasks that the user can perform
   * on participants
   *
   * @param int $value
   *
   * @return array
   *   the set of tasks for a group of participants
   */
  public static function getTask($value) {
    static::tasks();

    if (!CRM_Utils_Array::value($value, self::$_tasks)) {
      // Children can specify a default task (eg. print), we don't here
      return array();
    }
    return array(
      CRM_Utils_Array::value('class', self::$_tasks[$value]),
      CRM_Utils_Array::value('result', self::$_tasks[$value]),
    );
  }

  /**
   * Function to return the task information on basis of provided task's form name
   *
   * @param string $className
   *
   * @return array [ 0 => Task ID, 1 => Task Title ]
   */
  public static function getTaskAndTitleByClass($className) {
    static::tasks();

    foreach (self::$_tasks as $task => $value) {
      if ((!empty($value['url']) || $task == self::TASK_EXPORT)
          && ((is_array($value['class']) && in_array($className, $value['class']))
          || ($value['class'] == $className))) {
        return array($task, CRM_Utils_Array::value('title', $value));
      }
    }
    return array();
  }

}
