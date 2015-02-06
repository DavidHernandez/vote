<?php

/**
 * @file
 * Contains the entity VoteType.
 */

namespace Drupal\Vote\Entity\Vote;

use \Entity;

class VoteType extends Entity {

  public function __construct($values = array()) {
    parent::__construct($values, 'vote_type');
  }

  public function get($field, $defaultValue = '') {
    if (isset($this->{$field}) && !empty($this->{$field})) {
      $defaultValue = $this->{$field};
    }
    return $defaultValue;
  }
}

