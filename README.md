# Vote

This Drupal 7 module tries to be a replacement for the votingapi module with an
entity based approach. Uses the magic of Entity API, Plug and Plug Field
modules to be as much OOP as possible.

Each vote is a new entity. The different vote types are entity bundles. The
voting widget is a field you can attach to any fieldable entity. Has views
integration, so you can do lists of top voters, most voted entities, most voted
users...

## Requirements
* [Plug](https://drupal.org/project/plug)
* [Plug Field](https://drupal.org/project/plug_field)
* [Entity API](https://drupal.org/project/entity)
* [X Autoload](https://www.drupal.org/project/xautoload)
* [Composer Manager](https://www.drupal.org/project/composer_manager)
