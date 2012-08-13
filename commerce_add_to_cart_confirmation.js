(function ($) {
  // Add background overlay to add to cart popin.
  Drupal.behaviors.commerce_add_to_cart_confirmation_overlay = {
    attach:function (context, settings) {
      if ($('.commerce-add-to-cart-confirmation').length > 0) {
        $('body').append("<div class=\"commerce_add_to_cart_confirmation_overlay\"></div>");
        $('.commerce-add-to-cart-confirmation-close').live('click', function () {
          $('.commerce-add-to-cart-confirmation').remove();
        });
      }
    }
  }
})(jQuery);
