<?php

/**
 * Implements hook_rules_action_info().
 */
function commerce_add_to_cart_confirmation_rules_action_info() {
  return array(
    'commerce_add_to_cart_confirmation_message' => array(
      'label' => t('Add to Cart message'),
      'parameter' => array(
        'commerce_line_item' => array(
          'type' => 'commerce_line_item',
          'label' => t('Product added to the cart'),
        ),
        'commerce_atcc_message' => array(
          'type' => 'text',
          'label' => t('Successfully added person to registration'),
          'sanitize' => TRUE,
          'translatable' => TRUE,
          'default value' => t('Successfully added person to registration'),
          'optional' => TRUE,
        ),
        'commerce_atcc_checkout' => array(
          'type' => 'text',
          'label' => t('Go to checkout'),
          'sanitize' => TRUE,
          'translatable' => TRUE,
          'default value' => t('Go to checkout'),
          'optional' => TRUE,
        ),
        'commerce_atcc_continue' => array(
          'type' => 'text',
          'label' => t('Register more'),
          'sanitize' => TRUE,
          'translatable' => TRUE,
          'default value' => t('Register more'),
          'optional' => TRUE,
        ),
      ),
      'group' => t('VIH Commerce'),
      'callbacks' => array(
        'execute' => 'commerce_add_to_cart_confirmation_rules_add_to_cart_message',
      ),
    )
  );
}

/**
 * Rules action: displays a custom Add to Cart message.
 */
function commerce_add_to_cart_confirmation_rules_add_to_cart_message($line_item, $message, $checkout, $continue) {

  $message = '<div class="added-product-title clearfix">' . filter_xss_admin($message) . '</div>';
  $message .= '<div class="button-wrapper">';
  $message .= '<div class="button checkout">' . l(filter_xss_admin($checkout), 'checkout') . '</div>';
  $message .= '<div class="button continue"><span class="commerce-add-to-cart-confirmation-close">' . filter_xss_admin($continue) . '</span></div>';
  $message .= '</div>';
  $close = t('Close');

  drupal_set_message('<div class="message-inner">' . filter_xss_admin($message) . '<a class="commerce-add-to-cart-confirmation-close" href="#add-to-cart-form-registration"><span class="element-invisible">' . $close . '</span></a></div>', 'commerce-add-to-cart-confirmation');
}
