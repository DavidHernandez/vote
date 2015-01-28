<?php

/**
 * @file
 * Contains the entity Vote.
 */

namespace Drupal\vote\Entity\Vote;

class Vote extends \Entity {

  protected function defaultUri() {
    return array('path' => 'vote/' . $this->identifier());
  }
}

