jQuery(document).ready(function() {
   jQuery('.toggle').click(function() {
      var isShow = this.innerHTML === '+';
      var sample = this.parentNode.nextElementSibling;
      
      if (sample) {
          if (isShow) {
              jQuery(sample).fadeIn('fast');
              this.innerHTML = '-';
          }
          else {
              jQuery(sample).fadeOut('fast');
              this.innerHTML = '+';
          }
      }
   }); 
});