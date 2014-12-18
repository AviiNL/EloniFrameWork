#include "ConfigurationManager.h"

/**
 * Get a configuration value from the database
 * 
 * @returns string
 */
std::string ConfigurationManager::getConfig(std::string var) {
  std::string ret = EloniFrameWork::Database()->Query("SELECT * FROM `configuration` WHERE `var`='" + var + "'")[0]["val"];
  return ret;
}

/**
 * Store a value in the configuration database
 */
void ConfigurationManager::setConfig(std::string var, std::string val) {
  EloniFrameWork::Database()->Query("CREATE TABLE IF NOT EXISTS configuration(var TEXT PRIMARY KEY, val TEXT)");
  EloniFrameWork::Database()->Query("INSERT OR REPLACE INTO `configuration` (var, val) values ('"+var+"','"+val+"');");
}
