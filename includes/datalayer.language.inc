<?php
/**
 * @file
 * DataLayer classes.
 */

/**
 * Class DataLayer.
 */
class DataLayerLanguage {

  /**
   * @var array
   */
  protected $data = array();

  /**
   * @var object
   */
  protected $language;

  /**
   * @var object
   */
  protected $user;

  /**
   * Get data.
   *
   * @return array
   *   The data array.
   */
  public function getData() {
    return $this->data;
  }

  /**
   * Set data.
   *
   * @param array $data
   *   Set the data array.
   */
  public function setData(array $data) {
    $this->data = $data;
  }

  /**
   * Get language.
   *
   * @return object
   *   Should be the Drupal language global variable.
   */
  public function getLanguage() {
    return $this->language;
  }

  /**
   * Set language.
   *
   * @param object $language
   *   Should be the Drupal language global variable.
   */
  public function setLanguage($language) {
    $this->language = $language;
  }

  /**
   * Get user.
   *
   * @return object
   *   Should be the Drupal user global variable.
   */
  public function getUser() {
    return $this->user;
  }

  /**
   * Set user.
   *
   * @param object $user
   *   Should be the Drupal user global variable.
   */
  public function setUser($user) {
    $this->user = $user;
  }

  /**
   * Get Defaults.
   *
   * @return array
   *   An array of default values.
   */
  public function getDefaults() {
    $output = array();
    if (isset($this->getLanguage()->language)) {
      $output['drupalLanguage'] = $this->getLanguage()->language;
    }
    return $output;
  }

  /**
   * Allow adding to the data layer easy on the fly, similar to drupal_add_js().
   *
   * Passing empty params will return current dataLayer output.
   *
   * @param array $data
   *   An array of dataLayer data keyed by variable name (optional).
   * @param bool $overwrite
   *   If data should overwrite existing dataLayer vars of same name (optional).
   *
   * @return array
   *   All data layer data added thus far.
   */
  public function add(array $data = array(), $overwrite = FALSE) {
    if (!empty($data)) {
      if ($overwrite) {
        $this->data = array_merge($this->data, $data);
      }
      else {
        $this->data += $data;
      }
    }
    return $this->data;
  }

}
