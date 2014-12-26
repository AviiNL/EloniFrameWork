#include "SecurityManager.h"

/**
 * Encrypt a string in DG Standard encryption
 * 
 * @returns string
 */
std::string SecurityManager::Encrypt(std::string str) {
  return crypt(str.c_str(), "$6$Eh1R3E/K2kD");
}

/**
 * Add a user
 */
void SecurityManager::addUser(std::string username, std::string password) {
  if(this->isUser(username))
    return; // user already exists
    
  EloniFramework::Database()->Query("INSERT INTO `users` (`username`,`password`,`email`,`role`) VALUES ('" + username + "','" + password + "','N/A','')");
}

/**
 * Remove a user
 */
void SecurityManager::deleteUser(std::string username) {
  if(!this->isUser(username))
    return; // user does not exists
    
  EloniFramework::Database()->Query("DELETE FROM `users` WHERE `username`='"+username+"'");
}

/**
 * Set user properties
 */
void SecurityManager::setUser(std::string username, std::string var, std::string val) {
  if(!this->isUser(username))
    return; // user does not exists
  
  EloniFramework::Database()->Query("UPDATE `users` SET `"+var+"`='"+val+"' WHERE `username`='"+username+"'");
}

/**
 * Check if a user exists
 * 
 * @return bool
 */
bool SecurityManager::isUser(std::string username) {
  auto user = EloniFramework::Database()->Query("SELECT `username` FROM `users` WHERE `username`='" + username + "'");
  if(user.size() > 0)
    return true;
  
  return false;
}

/**
 * Get all users from the database
 * 
 * @return std::vector
 */
std::vector<std::string> SecurityManager::getUsers() {
  std::vector<std::string> _users;
  
  auto users = EloniFramework::Database()->Query("SELECT `username` FROM `users`");
  for (auto user : users) {
    _users.push_back(user["username"]);
  }

  return _users;
}

/**
 * Get all roles from the database
 * 
 * @return std::map<std::string, int>
 */
std::map<std::string, int> SecurityManager::getRoles() {
  auto roles = EloniFramework::Database()->Query("SELECT * FROM `roles`");
  std::map<std::string, int> _roles;
  
  for (auto role : roles) {
    _roles.insert(std::pair<std::string, int>(role["name"], (atoi(role["id"].c_str())-1)));
  }
  
  return _roles;
}

/**
 * Check if a user has a specific role
 * 
 * @return bool
 */
bool SecurityManager::hasRole(std::string username, std::string role) {
  if(!this->isUser(username)) return false;
  auto user = EloniFramework::Database()->Query("SELECT * FROM `users` WHERE `username`='" + username + "'")[0];
  auto roles = this->getRoles();
  int userRole = atoi(user["role"].c_str());
  int roleToCheck = roles[role];
  std::bitset<32> user_role_bits(userRole);
  return user_role_bits.test(roleToCheck);
}

/**
 * Assign a role to a user
 */
void SecurityManager::addRole(std::string username, std::string role){
  if(!this->isUser(username)) return;
  if(this->hasRole(username, role))
    return;
  
  EloniFramework::Database()->Query("UPDATE `users` SET `role`=`role`+'" + std::to_string(1 << (this->getRoles()[role])) + "' WHERE `username`='" + username + "'");
}

/**
 * Remove a role from a user
 */
void SecurityManager::removeRole(std::string username, std::string role){
  if(!this->isUser(username)) return;
  if(!this->hasRole(username, role))
    return;
  
  EloniFramework::Database()->Query("UPDATE `users` SET `role`=`role`-'" + std::to_string(1 << (this->getRoles()[role])) + "' WHERE `username`='" + username + "'");
}

/**
 * Authenticate a uer
 * 
 * @return bool
 */
bool SecurityManager::Authenticate(std::string username, std::string password) {
  if(!this->isUser(username)) return false;
  
  auto user = EloniFramework::Database()->Query("SELECT * FROM `users` WHERE `username`='" + username + "'")[0];
  if(user["password"] == password)
    return true;
  
  
  return false;
}
