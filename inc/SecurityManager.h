/**
 * @author Yme-Jan Iedema <yj.iedema@gmail.com>
 * @file SecurityManager.h
 * @dependency DatabaseManager
 * 
 * SecurityManager
 * 
 * This class will handle everything related to security
 * extracting users from the database and assigning roles
 * Also allow sertain pages for specific roles
 * 
 */
 
#ifndef DG2_SECURITYMANAGER_H
#define DG2_SECURITYMANAGER_H

#include "Includes.h"

#include <climits>
#include <crypt.h>
#include <bitset>

class SecurityManager {
  private:
  public:
    std::string Encrypt(std::string str);
    std::map<std::string, int> getRoles();
    bool hasRole(std::string username, std::string role);
    void addRole(std::string username, std::string role);
    void removeRole(std::string username, std::string role);
    void addUser(std::string username, std::string password);
    void setUser(std::string username, std::string var, std::string val);
    void deleteUser(std::string username);
    bool isUser(std::string username);
    std::vector<std::string> getUsers();
    bool Authenticate(std::string username, std::string password);
};

#endif
