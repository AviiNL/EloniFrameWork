#include "EloniFramework.h"

ConfigurationManager* EloniFramework::_configuration = NULL;
DatabaseManager* EloniFramework::_database = NULL;
SecurityManager* EloniFramework::_security = NULL;
ShellManager* EloniFramework::_shell = NULL;

/**
 * Returns the instance of ConfigurationManager
 * 
 * @return ConfigurationManager
 */
ConfigurationManager *EloniFramework::Configuration() {
  if(EloniFramework::_configuration == NULL)
    EloniFramework::_configuration = new ConfigurationManager();
    
  return EloniFramework::_configuration;
}

/**
 * Returns the instance of DatabaseManager
 * 
 * @return DatabaseManager
 */
DatabaseManager *EloniFramework::Database() {
  if(EloniFramework::_database == NULL)
    EloniFramework::_database = new DatabaseManager();
    
  return EloniFramework::_database;
}

/**
 * Returns the instance of SecurityManager
 * 
 * @return SecurityManager
 */
SecurityManager *EloniFramework::Security() {
  if(EloniFramework::_security == NULL)
    EloniFramework::_security = new SecurityManager();
    
  return EloniFramework::_security;
}

/**
 * Returns the instance of ShellManager
 * 
 * @return ShellManager
 */
ShellManager *EloniFramework::Shell() {
  if(EloniFramework::_shell == NULL)
    EloniFramework::_shell = new ShellManager();
    
  return EloniFramework::_shell;
}

/**
 * Returns the application directory
 * 
 * @return string
 */
std::string EloniFramework::Path() {
  char buff[1024];
  int len = readlink("/proc/self/exe", buff, sizeof(buff)-1);
  buff[len] = '\0';
  std::string path = buff;
  std::string::size_type i = path.find_last_of("/");
  return path.substr(0,i);
}

