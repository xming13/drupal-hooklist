<?php

/**
 * @file
 * This file implements only one function {get_hooklist_items}
 * which returns an array of commonly used hooks.
 * 
 * Available properties:
 * - #hook_name: The hook function name.
 * - #url: The url to the official Drupal documentation for the hook.
 * - #description: Description of what the hook does. Copied from the official
 *   Drupal documentation.
 * - #tips_array: Array of tips (string) related to the implementation of hook.
 *   Can include any useful information or gotchas.
 * - #category: The category of the hook. The implementation of the hook should 
 *   be in modules/{category}/{category}.api.php.
 * - #tags_array: Array of tags (string). Currently the tags include
 *   - required
 *   - optional
 *   - info
 *   - debug
 * - #sample_code: A fully working sample code to demonstrate the how to 
 *   implement the hook.
 * 
 * Use the following template to add a new hook.
 * 
 * $items[] = array(
    'data' => array(
      '#hook_name' => '',
      '#url' => '',
      '#description' => '',
      '#tips_array' => array(),
      '#category' => '',
      '#tags_array' => array(),
      '#sample_code' => '',
    ),
  );
 */

/**
 * Return an array of commonly used hooks 
 */
function get_hooklist_items() {
  $items = array();
  
  $items[] = array(
    'data' => array(
      '#hook_name' => 'hook_help()',
      '#url' => 'https://api.drupal.org/api/drupal/modules!system!system.api.php/function/hook_help/7',
      '#description' => 'Provides online user help.',
      '#tips_array' => array(
        'Provides help text for the module by checking if the <em>$path</em> '
        . 'is equal to \'admin\help<em>#MODULE_NAME</em>\', '
        . 'where <em>#MODULE_NAME</em> is the '
        . 'machine-readable name of the module.', 
        'Returns a string wrapped in '
        . '<a href="https://api.drupal.org/api/drupal/includes/bootstrap.inc/function/t/7" target="_blank">t()</a> '
        . 'for localized text.',
      ),
      '#category' => 'System',
      '#tags_array' => array('optional', 'info'),
      '#sample_code' => 
        "function first_help(\$path, \$arg) {\n" .
        "  if (\$path == 'admin/help#first') {\n" . 
        "    return t('A demonstration module.');\n" .
        "  }\n" .
        "}",
    ),
  );
  
  $items[] = array(
    'data' => array(
      '#hook_name' => 'hook_block_info()',
      '#url' => 'https://api.drupal.org/api/drupal/modules!block!block.api.php/function/hook_block_info/7',
      '#description' => 'Defines all blocks provided by the module.',
      '#tips_array' => array(
        'This hook declares to Drupal what blocks are provided by your module '
        . 'and can optionally specify initial block configuration settings.',
        'Each block your module provides is given a '
        . 'unique identifier referred to as "delta" (the array key in the '
        . 'return value). Delta values only need to be unique within your '
        . 'module',
        'Returns an associative array whose keys define the delta for each block and '
        . 'whose values contain the block descriptions. Each block description '
        . 'is itself an associative array, with the following key-value pairs: '
        . 'info (required), cache (optional), properties (optional), '
        . 'weight (optional), status (optional), region (optional), '
        . 'visibility (optional), pages (optional).'
      ),
      '#category' => 'Block',
      '#tags_array' => array('required'),
      '#sample_code' => 
        "function first_block_info() {\n" .
        "  \$blocks = array();\n\n" .
        "  \$blocks['list_modules'] = array(\n" .
        "    'info' => t('A listing of all of the enabled modules.'),\n" .
        "    'cache' => DRUPAL_NO_CACHE,\n" .
        "  );\n\n" .
        "  return \$blocks;\n" .
        "}",
    ),
  );
  
  $items[] = array(
    'data' => array(
      '#hook_name' => 'hook_block_view()',
      '#url' => 'https://api.drupal.org/api/drupal/modules!block!block.api.php/function/hook_block_view/7',
      '#description' => 'Returns a rendered or renderable view of a block.',
      '#tips_array' => array(
        'Use switch case to check <em>$delta</em> with the keys defined '
        . 'in the array returned by '
        . '<a href="#hook-block-info">hook_block_info()</a> to determine which '
        . 'block to render.',
        'Returns an empty array so the block will not be shown or an array with '
        . 'key \'subject\' and \'content\'.',
        ),
      '#category' => 'Block',
      '#tags_array' => array('required'),
      '#sample_code' => 
        "function first_block_view(\$delta = '') {\n" .
        "  \$block = array();\n\n" .
        "  switch (\$delta) {\n" .
        "    case 'list_modules':\n" .
        "      \$list = module_list();\n\n" .
        "      \$theme_args = array('items' => \$list, 'type' => 'ol');\n" .
        "      \$content = theme('item_list', \$theme_args);\n\n" .
        "      \$block['subject'] = t('Enabled Modules');\n" .
        "      \$block['content'] = \$content;\n" .
        "      break;\n" .
        "  };\n\n" .
        "  return \$block;\n" .
        "}",
     ),
  );
  
  $items[] = array(
    'data' => array(
      '#hook_name' => 'hook_library()',
      '#url' => 'https://api.drupal.org/api/drupal/modules!system!system.api.php/function/hook_library/7',
      '#description' => 'Registers JavaScript/CSS libraries associated with a module.',
      '#tips_array' => array(
        'When a module has a library or plugin it wants to use or make available'
        . ' to other libraries, it should define it as a library using '
        . 'hook_library().',
        'Returns an array of array. The key to each sub-array is '
        . 'the machine readable name of the library. Each library may contain '
        . 'the following items: \'title\', \'website\', \'version\', \'js\', '
        . '\'css\', \'dependencies\'',
      ),
      '#category' => 'System',
      '#tags_array' => array('optional'),
      '#sample_code' => 
        "function hello_world_library() {\n" .
        "  \$path = drupal_get_path('module', 'hello_world');\n" .
        "  \$libraries = array();\n" .
        "  \$libraries['hello_world_library'] = array(\n" .
        "    'title' => 'Hello World',\n" .
        "    'website' => 'http://example.com',\n" .
        "    'version' => '1.0',\n" .
        "    'js' => array(\n" .
        "      \$path . '/hello_world.js' => array(),\n" .
        "    ),\n" .
        "    'css' => array(\n" .
        "      \$path . '/hello_world.css' => array(),\n" .
        "    ),\n" .
        "    'dependencies' => array(\n" .
        "      array('system', 'ui.dialog'),\n" .
        "    ),\n" .
        "  );\n\n".
        "  return \$libraries;\n" . 
        "}",
    ),
  );
  
  foreach ($items as &$item) {
    // Set theme
    $item['data']['#theme'] = 'hooklist_block_item'; 
    
    // Set id by replacing '_' with '-' and removing '()' in #hook_name 
    $item['id'] = str_replace(
      array('_', '(', ')'), 
      array('-', '', ''), 
      $item['data']['#hook_name']
    );
    
    // Add css class
    $item['class'] = array('hook');
    
    // Append css class hook-[tag] to the item
    foreach ($item['data']['#tags_array'] as $key => $value) {
      array_push($item['class'], 'hook-' . $value);
    }
  }
  
  return $items;
}
