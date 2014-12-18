#include "EloniFrameWork.h"

#define btoa(x) ((x)?"true":"false") // useful for checking bool in printf

int main() {
  
  // ==== Database Manager ====
  
  // Create tables
  EloniFrameWork::Database()->Query("CREATE TABLE IF NOT EXISTS users(id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT, password TEXT, email TEXT, role INTEGER)");
  EloniFrameWork::Database()->Query("CREATE TABLE IF NOT EXISTS roles(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");
  EloniFrameWork::Database()->Query("CREATE TABLE IF NOT EXISTS configuration(var TEXT PRIMARY KEY, val TEXT)");
  
  // Clear tables
  EloniFrameWork::Database()->Query("DELETE FROM `users`;");
  EloniFrameWork::Database()->Query("DELETE FROM `sqlite_sequence` WHERE `name`='users';");
  
  EloniFrameWork::Database()->Query("DELETE FROM `roles`;");
  EloniFrameWork::Database()->Query("DELETE FROM `sqlite_sequence` WHERE `name`='roles';");
  
  // Inert roles
  EloniFrameWork::Database()->Query("INSERT INTO `roles` (`name`) VALUES ('ROLE_USER');");
  EloniFrameWork::Database()->Query("INSERT INTO `roles` (`name`) VALUES ('ROLE_MODERATOR');");
  EloniFrameWork::Database()->Query("INSERT INTO `roles` (`name`) VALUES ('ROLE_ADMIN');");
  
  // Insert users
  EloniFrameWork::Database()->Query("INSERT INTO `users` (`username`,`password`,`email`) VALUES ('Test User','somesecurepassword','test@user.nl');");
  EloniFrameWork::Database()->Query("INSERT INTO `users` (`username`,`password`,`email`) VALUES ('Other User','somesecurepassword','test@user.nl');");
  
  // Get a single result
  auto result = EloniFrameWork::Database()->Query("SELECT * FROM `users`");
  printf("Test User's Email: %s\n", result[0]["email"].c_str());
  
  // Get multiple results
  auto users = EloniFrameWork::Database()->Query("SELECT * FROM `users`");
  for (auto user : users) {
    printf("UserID: %i\n", atoi(user["id"].c_str()));
    printf("Username: %s\n", user["username"].c_str());
    printf("Password: %s\n", user["password"].c_str());
    printf("E-Mail Address: %s\n", user["email"].c_str());
    printf("Role: %s\n", user["role"].c_str());
    printf("--------------------\n");
  }
  
  
  // ==== Configuration Manager ====
  
  // Set a value
  EloniFrameWork::Configuration()->setConfig("Test", "Value");
  
  // Get a value
  std::string value = EloniFrameWork::Configuration()->getConfig("Test");
  printf("Value for Test: %s\n", value.c_str());
  
  
  // ==== Security Manager ====
  
  // Encrypt a string
  std::string encrypted = EloniFrameWork::Security()->Encrypt("Some string that will be encrypted");
  printf("Encrypted string: %s\n", encrypted.c_str());
  
  // Create a user, set password and add a role
  EloniFrameWork::Security()->addUser("username", EloniFrameWork::Security()->Encrypt("password"));
  EloniFrameWork::Security()->setUser("username", "email", "username@example.com");
  EloniFrameWork::Security()->addRole("username", "ROLE_USER");
  
  // Add/Remove roles
  EloniFrameWork::Security()->addRole("username", "ROLE_ADMIN");
  EloniFrameWork::Security()->removeRole("username", "ROLE_ADMIN");
  
  // Authenticate user
  bool authenticated = EloniFrameWork::Security()->Authenticate("username", EloniFrameWork::Security()->Encrypt("password"));
  printf("Username: username\nPassword: password\nAuthenticated: %s\n", btoa(authenticated));
  
  // Delete user
  EloniFrameWork::Security()->deleteUser("Test User");
  
  // List users
  auto users1 = EloniFrameWork::Security()->getUsers();
  for (auto user : users1) {
    printf("Username: %s\n", user.c_str());
  }
  
  // List availible roles
  auto roles = EloniFrameWork::Security()->getRoles();
  for (std::map<std::string, int>::iterator role=roles.begin(); role!=roles.end(); ++role) {
    printf("%s : %i\n", role->first.c_str(), (1 << role->second));
  }
  
  // Check if a user has a specific role
  bool userIsAdmin = EloniFrameWork::Security()->hasRole("username", "ROLE_ADMIN");
  printf("username is admin: %s\n", btoa(userIsAdmin));
  
  
  // ==== Shell Manager ====
  
  // Set active user to www-data
  EloniFrameWork::Shell()->setUser("root");
  
  // Set working directory to /var/www
  EloniFrameWork::Shell()->setWorkingDirectory("/var/www");
  
  // Run shell commands and store output to string
  std::string whoami = EloniFrameWork::Shell()->Execute("whoami");
  std::string currentPath = EloniFrameWork::Shell()->Execute("pwd");
  
  // show the output
  printf("Output of whoami: %s\n", whoami.c_str());
  printf("Output of pwd: %s\n", currentPath.c_str());
  
  // Restricted command:
  std::string sudosomething = EloniFrameWork::Shell()->Execute("service nginx stop");
  printf("Output of service nginx stop: %s\n", sudosomething.c_str());
  
  // Clean the database
  EloniFrameWork::Database()->Query("DELETE FROM `users`;");
  EloniFrameWork::Database()->Query("DELETE FROM `sqlite_sequence` WHERE `name`='users';");
  EloniFrameWork::Database()->Query("DELETE FROM `configuration`;");
  EloniFrameWork::Database()->Query("DELETE FROM `sqlite_sequence` WHERE `name`='configuration';");
  
  return 0;
}


