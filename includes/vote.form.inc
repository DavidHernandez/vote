<?php

/**
 * @file
 *  Forms for the Vote and VoteType entities.
 */

/**
 * Page callback for the vote add page. Displays a list of links to add votes
 * of that type.
 */
function vote_add_page() {
  $items = array();
  foreach (vote_types() as $type => $info) {
    $items[] = l(entity_label('vote_type', $info), 'admin/structure/votes/add/' . $type);
  }

  if (!empty($items)) {
    return array(
      'list' => array(
        '#theme' => 'item_list',
        '#items' => $items,
        '#title' => t('Select a VoteType to add.'),
      ),
    );
  }
  else {
    return t('You need to create a VoteType before manually adding a vote.');
  }
}

function vote_entity_add($type) {
  $vote_type = vote_types($type);
  $vote = entity_create('vote', array('bundle' => $type));

  $output = drupal_get_form('vote_entity_form', $vote);

  return $output;
}

/**
 * Form to add or edit a vote.
 */
function vote_entity_form($form, &$form_state, $vote, $op = 'edit') {
  $form_state['vote'] = $vote;
  $form['voting_user'] = array(
    '#type' => 'textfield',
    '#title' => t('Voting user'),
    '#default_value' => $vote->get('voting_user'),
    '#description' => t('Select an user who will appear as the user voting'),
    '#size' => 60,
    '#autocomplete_path' => 'user/autocomplete',
  );
  $form['timestamp'] = array(
    '#type' => 'textfield',
    '#title' => t('Timestamp'),
    '#default_value' => $vote->get('timestamp', time()),
    '#description' => t('A timestamp for when the vote should be registered.'),
    '#size' => 60,
  );
  $form['entity_type'] = array(
    '#type' => 'textfield',
    '#title' => t('Entity type'),
    '#description' => t('The type of the entity that will receive the vote.'),
    '#default_value' => $vote->get('entity_type'),
  );
  $form['entity_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Entity'),
    '#description' => t('Select the entity that will receive the vote.'),
    '#default_value' => $vote->get('entity_id'),
  );
  $form['bundle'] = array(
    '#type' => 'hidden',
    '#value' => $vote->get('bundle'),
  );

  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save the vote'),
  );
  if ($op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete the vote'),
      '#submit' => array('vote_form_submit_delete'),
    );
  }
  return $form;
}

/**
 * Submit callback for the VoteType form.
 */
function vote_entity_form_submit(&$form, &$form_state) {
  $vote = entity_ui_form_submit_build_entity($form, $form_state);

  vote_save($vote_type);

  $form_state['redirect'] = 'admin/structure/vote';
}

/**
 *  Vote delete submit handler.
 */
function vote_form_submit_delete($form, &$form_state) {
  $vote = $form_state['vote'];
  $vote_uri = entity_uri('vote', $vote);
  $form_state['redirect'] = $vote_uri['path'] . '/delete';
}

/**
 * Delete Vote entity confirmation form.
 */
function vote_delete_form($form, &$form_state, $vote) {
  $form_state['vote'] = $vote;
  $form['id'] = array(
    '#type' => 'value',
    '#value' => entity_id('vote', $vote),
  );
  $vote_uri = envity_uri('vote', $vote_uri);

  return confirm_form(
    $form,
    t('Are you sure you want to remove that vote?'),
    $vote_uri['path'],
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Form submit for deleting the Voteentity.
 */
function vote_delete_form_submit($form, &$form_state) {
  $vote = $form_state['vote'];
  vote_delete($vote);

  $form_state['redirect'] = 'admin/structure/vote';
}

/**
 * Form to add or edit a VoteType entity.
 */
function vote_type_entity_form($form, &$form_state, $vote_type = NULL, $op = 'edit') {
  $form['label'] = array(
    '#type' => 'textfield',
    '#title' => t('Label'),
    '#description' => t('User friendly label for the vote type.'),
    '#required' => TRUE,
    '#size' => 40,
    '#default_value' => $vote_type->get('label'),
  );
  $form['type'] = array(
    '#type' => 'machine_name',
    '#title' => t('Machine name'),
    '#description' => t('Internal machine name identifier.'),
    '#size' => 40,
    '#default_value' => $vote_type->get('type'),
    '#machine_name' => array(
      'exists' => 'vote_type_load',
      'source' => array('label'),
    ),
  );
  $form['values'] = array(
    '#type' => 'textformat',
    '#title' => t('Available values'),
    '#description' => t('All the values that will be available to use during' .
    ' the voting. '),
    '#default_value' => $vote_type->get('values'),
    '#required' => TRUE,
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save the vote type'),
  );
  if ($op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete the vote type'),
      '#submit' => array('vote_type_form_submit_delete'),
    );
  }
  return $form;
}

/**
 * Submit callback for the VoteType form.
 */
function vote_type_entity_form_submit(&$form, &$form_state) {
  $vote_type = entity_ui_form_submit_build_entity($form, $form_state);

  vote_type_save($vote_type);

  $form_state['redirect'] = 'admin/structure/vote/types';
}

/**
 *  VoteType delete submit handler.
 */
function vote_type_form_submit_delete($form, &$form_state) {
  $vote_type = $form_state['vote_type'];
  $vote_type_uri = entity_uri('vote_type', $vote_type);
  $form_state['redirect'] = $vote_type_uri['path'] . '/delete';
}

/**
 * Delete VoteType entity confirmation form.
 */
function vote_type_delete_form($form, &$form_state, $vote_type) {
  $form_state['vote_type'] = $vote_type;
  $form['id'] = array(
    '#type' => 'value',
    '#value' => entity_id('vote_type', $vote_type),
  );
  $vote_type_uri = envity_uri('vote_type', $vote_type_uri);

  return confirm_form(
    $form,
    t('Are you sure you want to remove that vote type?'),
    $vote_uri['path'],
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Form submit for deleting the VoteType entity.
 */
function vote_type_delete_form_submit($form, &$form_state) {
  $vote_type = $form_state['vote_type'];
  vote_type_delete($vote_type);

  $form_state['redirect'] = 'admin/structure/vote/type';
}
