#include "EloniFrameWork.h"

ConfigurationManager* EloniFrameWork::_configuration = NULL;
DatabaseManager* EloniFrameWork::_database = NULL;
SecurityManager* EloniFrameWork::_security = NULL;
ShellManager* EloniFrameWork::_shell = NULL;

/**
 * Returns the instance of ConfigurationManager
 * 
 * @return ConfigurationManager
 */
ConfigurationManager *EloniFrameWork::Configuration() {
  if(EloniFrameWork::_configuration == NULL)
    EloniFrameWork::_configuration = new ConfigurationManager();
    
  return EloniFrameWork::_configuration;
}

/**
 * Returns the instance of DatabaseManager
 * 
 * @return DatabaseManager
 */
DatabaseManager *EloniFrameWork::Database() {
  if(EloniFrameWork::_database == NULL)
    EloniFrameWork::_database = new DatabaseManager();
    
  return EloniFrameWork::_database;
}

/**
 * Returns the instance of SecurityManager
 * 
 * @return SecurityManager
 */
SecurityManager *EloniFrameWork::Security() {
  if(EloniFrameWork::_security == NULL)
    EloniFrameWork::_security = new SecurityManager();
    
  return EloniFrameWork::_security;
}

/**
 * Returns the instance of ShellManager
 * 
 * @return ShellManager
 */
ShellManager *EloniFrameWork::Shell() {
  if(EloniFrameWork::_shell == NULL)
    EloniFrameWork::_shell = new ShellManager();
    
  return EloniFrameWork::_shell;
}

/**
 * Returns the application directory
 * 
 * @return string
 */
std::string EloniFrameWork::Path() {
  char buff[1024];
  int len = readlink("/proc/self/exe", buff, sizeof(buff)-1);
  buff[len] = '\0';
  std::string path = buff;
  std::string::size_type i = path.find_last_of("/");
  return path.substr(0,i);
}

