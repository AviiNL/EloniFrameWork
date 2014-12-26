#include "ConfigurationManager.h"

/**
 * Get a configuration value from the database
 * 
 * @returns string
 */
std::string ConfigurationManager::getConfig(std::string var) {
  std::string ret = EloniFramework::Database()->Query("SELECT * FROM `configuration` WHERE `var`='" + var + "'")[0]["val"];
  return ret;
}

/**
 * Store a value in the configuration database
 */
void ConfigurationManager::setConfig(std::string var, std::string val) {
  EloniFramework::Database()->Query("CREATE TABLE IF NOT EXISTS configuration(var TEXT PRIMARY KEY, val TEXT)");
  EloniFramework::Database()->Query("INSERT OR REPLACE INTO `configuration` (var, val) values ('"+var+"','"+val+"');");
}
