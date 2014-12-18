/**
 * @author Yme-Jan Iedema <yj.iedema@gmail.com>
 * @file ConfigurationManager.h
 * @dependency DatabaseManager
 * 
 * ConfigurationManager
 * 
 * The configuration manager for getting configuration variables from
 * and to the database
 */
 
 
#ifndef DG2_CONFIGURATIONMANAGER_H
#define DG2_CONFIGURATIONMANAGER_H

#include "Includes.h"

class ConfigurationManager {
  private:
    
  public:
    std::string getConfig(std::string var);
    void setConfig(std::string var, std::string val);
};

#endif
