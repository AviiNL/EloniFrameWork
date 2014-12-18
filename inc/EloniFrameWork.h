/**
 * @author Yme-Jan Iedema <yj.iedema@gmail.com>
 * @file Application.h
 * 
 * DrushGui
 * 
 * Main entry point for DrushGui, this class initializes all Managers
 * and makes them available via the Application() static function
 */

#ifndef DG2_DRUSHGUI_H
#define DG2_DRUSHGUI_H

#include "Includes.h" // All the general stuff

class DatabaseManager;
class ConfigurationManager;
class SecurityManager;
class ShellManager;

class EloniFrameWork {
  private:
    static DatabaseManager       *_database;
    static ConfigurationManager  *_configuration;
    static SecurityManager       *_security;
    static ShellManager          *_shell;
    
  public:
    static DatabaseManager       *Database();
    static ConfigurationManager  *Configuration();
    static SecurityManager       *Security();
    static ShellManager          *Shell();
    static std::string           Path();
    
};

#endif
