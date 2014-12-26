#include "EloniFramework.h"

#define btoa(x) ((x)?"true":"false") // useful for checking bool in printf

int main() {
  
  // ==== Database Manager ====
  
  // Create tables
  EloniFramework::Database()->Query("CREATE TABLE IF NOT EXISTS users(id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT, password TEXT, email TEXT, role INTEGER)");
  EloniFramework::Database()->Query("CREATE TABLE IF NOT EXISTS roles(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");
  EloniFramework::Database()->Query("CREATE TABLE IF NOT EXISTS configuration(var TEXT PRIMARY KEY, val TEXT)");
  
  // Clear tables
  EloniFramework::Database()->Query("DELETE FROM `users`;");
  EloniFramework::Database()->Query("DELETE FROM `sqlite_sequence` WHERE `name`='users';");
  
  EloniFramework::Database()->Query("DELETE FROM `roles`;");
  EloniFramework::Database()->Query("DELETE FROM `sqlite_sequence` WHERE `name`='roles';");
  
  // Inert roles
  EloniFramework::Database()->Query("INSERT INTO `roles` (`name`) VALUES ('ROLE_USER');");
  EloniFramework::Database()->Query("INSERT INTO `roles` (`name`) VALUES ('ROLE_MODERATOR');");
  EloniFramework::Database()->Query("INSERT INTO `roles` (`name`) VALUES ('ROLE_ADMIN');");
  
  // Insert users
  EloniFramework::Database()->Query("INSERT INTO `users` (`username`,`password`,`email`) VALUES ('Test User','somesecurepassword','test@user.nl');");
  EloniFramework::Database()->Query("INSERT INTO `users` (`username`,`password`,`email`) VALUES ('Other User','somesecurepassword','test@user.nl');");
  
  // Get a single result
  auto result = EloniFramework::Database()->Query("SELECT * FROM `users`");
  printf("Test User's Email: %s\n", result[0]["email"].c_str());
  
  // Get multiple results
  auto users = EloniFramework::Database()->Query("SELECT * FROM `users`");
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
  EloniFramework::Configuration()->setConfig("Test", "Value");
  
  // Get a value
  std::string value = EloniFramework::Configuration()->getConfig("Test");
  printf("Value for Test: %s\n", value.c_str());
  
  
  // ==== Security Manager ====
  
  // Encrypt a string
  std::string encrypted = EloniFramework::Security()->Encrypt("Some string that will be encrypted");
  printf("Encrypted string: %s\n", encrypted.c_str());
  
  // Create a user, set password and add a role
  EloniFramework::Security()->addUser("username", EloniFramework::Security()->Encrypt("password"));
  EloniFramework::Security()->setUser("username", "email", "username@example.com");
  EloniFramework::Security()->addRole("username", "ROLE_USER");
  
  // Add/Remove roles
  EloniFramework::Security()->addRole("username", "ROLE_ADMIN");
  EloniFramework::Security()->removeRole("username", "ROLE_ADMIN");
  
  // Authenticate user
  bool authenticated = EloniFramework::Security()->Authenticate("username", EloniFramework::Security()->Encrypt("password"));
  printf("Username: username\nPassword: password\nAuthenticated: %s\n", btoa(authenticated));
  
  // Delete user
  EloniFramework::Security()->deleteUser("Test User");
  
  // List users
  auto users1 = EloniFramework::Security()->getUsers();
  for (auto user : users1) {
    printf("Username: %s\n", user.c_str());
  }
  
  // List availible roles
  auto roles = EloniFramework::Security()->getRoles();
  for (std::map<std::string, int>::iterator role=roles.begin(); role!=roles.end(); ++role) {
    printf("%s : %i\n", role->first.c_str(), (1 << role->second));
  }
  
  // Check if a user has a specific role
  bool userIsAdmin = EloniFramework::Security()->hasRole("username", "ROLE_ADMIN");
  printf("username is admin: %s\n", btoa(userIsAdmin));
  
  
  // ==== Shell Manager ====
  
  // Set active user to www-data
  EloniFramework::Shell()->setUser("root");
  
  // Set working directory to /var/www
  EloniFramework::Shell()->setWorkingDirectory("/var/www");
  
  // Run shell commands and store output to string
  std::string whoami = EloniFramework::Shell()->Execute("whoami");
  std::string currentPath = EloniFramework::Shell()->Execute("pwd");
  
  // show the output
  printf("Output of whoami: %s\n", whoami.c_str());
  printf("Output of pwd: %s\n", currentPath.c_str());
  
  // Restricted command:
  std::string sudosomething = EloniFramework::Shell()->Execute("service nginx stop");
  printf("Output of service nginx stop: %s\n", sudosomething.c_str());
  
  // Clean the database
  EloniFramework::Database()->Query("DELETE FROM `users`;");
  EloniFramework::Database()->Query("DELETE FROM `sqlite_sequence` WHERE `name`='users';");
  EloniFramework::Database()->Query("DELETE FROM `configuration`;");
  EloniFramework::Database()->Query("DELETE FROM `sqlite_sequence` WHERE `name`='configuration';");
  
  return 0;
}


