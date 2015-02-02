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

