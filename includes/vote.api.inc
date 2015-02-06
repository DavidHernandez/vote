<?php

/**
 * @file
 * API functions for the vote entity ecosystem.
 */

/**
 * Load a Vote entity.
 */
function vote_load($id, $reset = FALSE) {
  $votes = vote_load_multiple(array($id), $reset);
  return reset($votes);
}

/**
 * Load multiple Votes based on certain conditions.
 * @see entity_load().
 */
function vote_load_multiple($ids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('vote', $ids, $conditions, $reset);
}

/**
 * Saves a Vote entity.
 */
function vote_save($vote) {
  entity_save('vote', $vote);
}

/**
 * Deletes a Vote entity.
 */
function vote_delete($vote) {
  if (is_object($vote)) {
    $id = $vote->identifier();
  }
  else {
    $id = $vote;
  }
  entity_delete('vote', $id);
}

/**
 * Load a VoteType entity.
 */
function vote_type_load($id, $reset = FALSE) {
  $vote_types = vote_type_load_multiple(array($id), $reset);
  return reset($vote_types);
}

/**
 * Load multiple VoteTypes based on certain conditions.
 * @see entity_load().
 */
function vote_type_load_multiple($ids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('vote_type', $ids, $conditions, $reset);
}

/**
 * Saves a VoteType entity.
 */
function vote_type_save($vote_type) {
  entity_save('vote_type', $vote_type);
}

/**
 * Deletes a VoteType entity.
 */
function vote_type_delete($vote_type) {
  if (is_object($vote_type)) {
    $id = $vote_type->identifier();
  }
  else {
    $id = $vote_type;
  }
  entity_delete('vote_type', $id);
}
