<?php

/**
 * @file
 * Contains the entity Vote.
 */

namespace Drupal\vote\Entity\Vote;

use \Entity;

class Vote extends Entity {

  protected function defaultUri() {
    return array('path' => 'vote/' . $this->identifier());
  }

  public function get($field, $defaultValue = '') {
    if (isset($this->{$field}) && !empty($this->{$field})) {
      $defaultValue = $this->{$field};
    }
    return $defaultValue;
  }
}

