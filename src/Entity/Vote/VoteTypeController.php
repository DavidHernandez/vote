<?php

/**
 * @file
 * The controller for the VoteType entity.
 */

namespace Drupal\Vote\Entity\Vote;

class VoteTypeController extends \EntityAPIControllerExportable {

  /**
   * {@inheritdoc}
   */
  public function create(array $values = array()) {
    $values += array(
       'label' => '',
       'description' => '',
       'available_values' => '',
    );
    return parent::create($values);
  }

  /**
   * {@inheritdoc}
   */
  public function save($entity, \DatabaseTransaction $transaction = NULL) {
    parent::save($entity, $transaction);
    variable_set('menu_rebuild_needed', TRUE);
  }
}

