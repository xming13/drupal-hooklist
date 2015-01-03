<?php

/**
 * @file
 * This file implements only one function {get_hooklist_items}
 * which returns an array of commonly used hooks. This serves as a cheat sheet
 * for beginners.
 * 
 * Feel free to add more contents/comments!
 */

/**
 * Return an array of commonly used hooks 
 */
function get_hooklist_items() {
  $items = array();
  
  $items[] = array(
    'data' => array(
      '#theme' => 'hooklist_block_item',
      '#hook_name' => 'hook_help()',
      '#url' => 'https://api.drupal.org/api/drupal/modules/system/system.api.php/function/hook_help/7',
      '#description' => 'Provides online user help.',
      '#category' => 'System',
      '#tags_array' => array('optional', 'info'),
      '#sample_code' => check_plain(
        "function first_help(\$path, \$arg) { \n" .
        "  if (\$path == 'admin/help#first') { \n" . 
        "    return t('A demonstration module.'); \n" .
        "  } \n" .
        "}"
      ),
    ),
    'class' => array('hook'),
  );
  
  $items[] = array(
    'data' => array(
      '#theme' => 'hooklist_block_item',
      '#hook_name' => 'hook_block_info()',
      '#url' => 'https://api.drupal.org/api/drupal/modules/block/block.api.php/function/hook_block_info/7',
      '#description' => 'Define all blocks provided by the module.',
      '#category' => 'Block',
      '#tags_array' => array('required'),
      '#sample_code' => check_plain(
        "function first_block_info() { \n" .
        "  \$blocks = array(); \n\n" .
        "  \$blocks['list_modules'] = array( \n" .
        "    'info' => t('A listing of all of the enabled modules.'), \n" .
        "    'cache' => DRUPAL_NO_CACHE, \n" .
        "  ); \n\n" .
        "  return \$blocks; \n" .
        "}"
      ),
    ),
    'class' => array('hook'),
  );
  
  $items[] = array(
    'data' => array(
      '#theme' => 'hooklist_block_item',
      '#hook_name' => 'hook_block_view()',
      '#url' => 'https://api.drupal.org/api/drupal/modules/block/block.api.php/function/hook_block_view/7',
      '#description' => 'Return a rendered or renderable view of a block.',
      '#category' => 'Block',
      '#tags_array' => array('required'),
      '#sample_code' => check_plain(
        "function first_block_view(\$block_name = '') { \n" .
        "  if (\$block_name == 'list_modules') { \n" .
        "    \$list = module_list(); \n\n" .
        "    \$theme_args = array('items' => \$list, 'type' => 'ol'); \n" .
        "    \$content = theme('item_list', \$theme_args); \n\n" .
        "    \$block = array( \n" .
        "      'subject' => t('Enabled Modules'), \n" .
        "      'content' => \$content, \n" .
        "    ); \n\n" .
        "    return \$block; \n" .
        "  } \n" .
        "}"
       ),
     ),
    'class' => array('hook'),
  );
  
  // append css class hook-[tag] to the item
  foreach ($items as &$item) {
    foreach ($item['data']['#tags_array'] as $key => $value) {
      array_push($item['class'], 'hook-' . $value);
    }
  }
  
  return $items;
}
