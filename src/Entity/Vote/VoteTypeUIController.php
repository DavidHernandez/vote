<?php

/**
 * @file
 * VoteTypeUIController class for the administration pages.
 */

namespace Drupal\Vote\Entity\Vote\VoteTypeUIController;

use \EntityDefaultUIController;

class VoteTypeUIController extends EntityDefaultUIController {

  /**
   * {@inheritdoc}
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage the Vote types.';
    return $items;
  }
}
