<?php

function bbsite_sns_buttons_setup() {
  $destination = drupal_get_destination();

  $form['line'] = array(
    '#type' => 'fieldset',
    '#title' => t('LINE button'),
    '#weight' => 10,
  );
  $form['line']['show_line'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Send to LINE button'),
    '#default_value' => variable_get('bbsite_sns_buttons_show_line', 1),
  );
  $form['line']['line_for_pc'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show for PC'),
    '#default_value' => variable_get('bbsite_sns_buttons_line_for_pc', 1),
  );

  $form['hatena'] = array(
    '#type' => 'fieldset',
    '#title' => t('Hatena Bookmark button'),
    '#weight' => 20,
  );
  $form['hatena']['show_hatena'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Hatena Bookmark button'),
    '#default_value' => variable_get('bbsite_sns_buttons_show_hatena', 1),
  );
  $form['hatena']['hatena_show_balloon'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show balloon'),
    '#default_value' => variable_get('bbsite_sns_buttons_hatena_show_balloon', 1),
  );

  $form['twitter'] = array(
    '#type' => 'fieldset',
    '#title' => t('Twitter button'),
    '#weight' => 30,
  );
  $form['twitter']['show_twitter'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Twitter button'),
    '#default_value' => variable_get('bbsite_sns_buttons_show_twitter', 1),
  );
  $form['twitter']['twitter_show_count'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show count'),
    '#default_value' => variable_get('bbsite_sns_buttons_twitter_show_count', 1),
  );
  $form['twitter']['twitter_via'] = array(
    '#type' => 'textfield',
    '#size' => 20,
    '#title' => t('Via account'),
    '#default_value' => variable_get('bbsite_sns_buttons_twitter_via', ''),
    '#element_validate' => array('_bbsite_sns_buttons_validate_twitter_account'),
  );
  $form['twitter']['twitter_related'] = array(
    '#type' => 'textfield',
    '#size' => 20,
    '#title' => t('Related account'),
    '#default_value' => variable_get('bbsite_sns_buttons_twitter_related', ''),
    '#element_validate' => array('_bbsite_sns_buttons_validate_twitter_account'),
  );
  $form['twitter']['twitter_hashtags'] = array(
    '#type' => 'textfield',
    '#title' => t('Hashtags'),
    '#default_value' => variable_get('bbsite_sns_buttons_twitter_hashtags', ''),
  );

  $form['facebook'] = array(
    '#type' => 'fieldset',
    '#title' => t('Facebook LIKE button'),
    '#weight' => 40,
  );
  $form['facebook']['show_facebook'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show LIKE button'),
    '#default_value' => variable_get('bbsite_sns_buttons_show_facebook', 1),
  );
  $form['facebook']['facebook_show_send'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Send button'),
    '#description' => t('Include a Send button.'),
    '#default_value' => variable_get('bbsite_sns_buttons_facebook_show_send', 1),
  );
  $form['facebook']['facebook_show_faces'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show faces'),
    '#description' => t('Show profile pictures when two or more friends like this.'),
    '#default_value' => variable_get('bbsite_sns_buttons_facebook_show_send', 1),
  );
  $styles = array('standard' => 'standard', 'button_count' => 'button_count');
  $form['facebook']['facebook_style'] = array(
    '#type' => 'select',
    '#title' => t('Layout style'),
    '#options' => $styles,
    '#default_value' => variable_get('bbsite_sns_buttons_facebook_style', 'standard'),
  );
  $form['facebook']['facebook_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#size' => 10,
    '#default_value' => variable_get('bbsite_sns_buttons_facebook_width', 450),
    '#element_validate' => array('_bbsite_sns_buttons_validate_numeric_element'),
  );
  $form['facebook']['facebook_appid'] = array(
    '#type' => 'textfield',
    '#title' => t('Application ID'),
    '#size' => 10,
    '#default_value' => variable_get('bbsite_sns_buttons_facebook_appid', ''),
  );

  $form['gplus'] = array(
    '#type' => 'fieldset',
    '#title' => t('Google+ +1 button'),
    '#weight' => 50,
  );
  $form['gplus']['show_googleplus'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show +1 button'),
    '#default_value' => variable_get('bbsite_sns_buttons_show_googleplus', 1),
  );
  $annotations = array('none' => 'none', 'bubble' => 'bubble', 'inline' => 'inline');
  $form['gplus']['googleplus_annotation'] = array(
    '#type' => 'select',
    '#title' => t('Annotation'),
    '#options' => $annotations,
    '#default_value' => variable_get('bbsite_sns_buttons_googleplus_annotation', 'bubble'),
  );
  $form['gplus']['googleplus_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#size' => 10,
    '#default_value' => variable_get('bbsite_sns_buttons_googleplus_width', 450),
    '#element_validate' => array('_bbsite_sns_buttons_validate_numeric_element'),
  );

  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

function bbsite_sns_buttons_setup_submit($form, &$form_state) {
  $values = $form_state['values'];

  variable_set('bbsite_sns_buttons_show_hatena', $values['show_hatena']);
  variable_set('bbsite_sns_buttons_hatena_show_balloon', $values['hatena_show_balloon']);
  variable_set('bbsite_sns_buttons_show_twitter', $values['show_twitter']);
  variable_set('bbsite_sns_buttons_twitter_show_count', $values['twitter_show_count']);
  variable_set('bbsite_sns_buttons_twitter_via', $values['twitter_via']);
  variable_set('bbsite_sns_buttons_twitter_related', $values['twitter_related']);
  variable_set('bbsite_sns_buttons_twitter_hashtags', $values['twitter_hashtags']);
  variable_set('bbsite_sns_buttons_show_line', $values['show_line']);
  variable_set('bbsite_sns_buttons_line_for_pc', $values['line_for_pc']);
  variable_set('bbsite_sns_buttons_show_facebook', $values['show_facebook']);
  variable_set('bbsite_sns_buttons_facebook_show_send', $values['facebook_show_send']);
  variable_set('bbsite_sns_buttons_facebook_style', $values['facebook_style']);
  variable_set('bbsite_sns_buttons_facebook_width', $values['facebook_width']);
  variable_set('bbsite_sns_buttons_facebook_appid', $values['facebook_appid']);
  variable_set('bbsite_sns_buttons_show_googleplus', $values['show_googleplus']);
  variable_set('bbsite_sns_buttons_googleplus_annotation', $values['googleplus_annotation']);
  variable_set('bbsite_sns_buttons_googleplus_width', $values['googleplus_width']);

  drupal_set_message(t('SNS buttons settings has been saved.'));
}

/**
 * Validate a form element that should have an numeric value.
 */
function _bbsite_sns_buttons_validate_numeric_element($element, &$form_state) {
  $value = $element['#value'];

  if (!is_numeric($value)) {
    form_error($element, t('The field %name is not a valid number.', array('%name' => $element['#title'])));
  }
  elseif (isset($element['#max_value']) && $value > $element['#max_value']) {
    form_error($element, t('The field %name cannot be greater than @max.', array('%name' => $element['#title'], '@max' => $element['#max_value'])));
  }
  elseif (isset($element['#min_value']) && $value < $element['#min_value']) {
    form_error($element, t('The field %name cannot be less than @min.', array('%name' => $element['#title'], '@min' => $element['#min_value'])));
  }
}

/**
 * Validate a form element that should have an twitter account.
 */
function _bbsite_sns_buttons_validate_twitter_account($element, &$form_state) {
  $value = $element['#value'];

  if ($value == '') {
    return;
  }
  elseif (preg_match('/^[a-z0-9_]+$/i', $value) == false) {
    form_error($element, t('The field %name only use letters, numbers and "_".', array('%name' => $element['#title'])));
  }
}
