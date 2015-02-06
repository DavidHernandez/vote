<?php

/**
 * @file
 * Adds a controller for the Vote entity.
 */

namespace Drupal\vote\Entity\Vote;

use \EntityAPIController;

class VoteController extends EntityAPIController {

  /**
   * {@inheritdoc}
   */
  public function create(array $values = array()) {
    global $user;
    $values += array(
      'voting_user' => $user->uid,
      'timestamp' => REQUEST_TIME,
      'entity_id' => 0,
      'entity_type' => 'node',
      'bundle' => 'Vote',
    );
    return parent::create($values);
  }
}
