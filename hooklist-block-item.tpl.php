<?php
/**
 * @file
 * HTML for an item in the hooklist's hook listing.
 *
 * Available variables:
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - hooklist-block-item: The current template type, i.e., "theming hook".
 * - $link: A renderable array that provides a title and link to the drupal 
 *   official documentation for the hook.
 * - $description: The description of the hook.
 * - $category: The category of the hook.
 * - $sample_code: The sample code to implement the hook.
 * - $tags_array: Array of tags html.
 * 
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * Other variables:
 * The following variables are provided for contextual information.
 * - $hook_name: The hook function name.
 * - $url: The url to the official Drupal documentation for the hook.
 *
 * @see template_preprocess_hooklisst_block_item()
 */
?>
<div class="<?php print $classes; ?>">

  <h2><?php print render($link); ?></h2>

  <div class="category">
      Category: <span class="category-name"><?php print $category; ?></span>
  </div>
  
  <div class="clear"></div>
  
  <div class="description">
    <?php print $description; ?><span class="toggle">+</span>
  </div>
  
  <div class="sample-code">
    <span class="sample-code-label">Sample Code:</span>
    <pre><code><?php print $sample_code; ?></code></pre>
  </div>
  
  <div class="tags">
    <?php print render($tags); ?>
  </div>
  
</div>