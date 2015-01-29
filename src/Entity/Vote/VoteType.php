<?php

/**
 * @file
 * Contains the entity VoteType.
 */

namespace Drupal\Vote\Entity\Vote;

class VoteType extends \Entity {

  public function __construct($values = array()) {
    parent::__construct($values, 'vote_type');
  }

}

