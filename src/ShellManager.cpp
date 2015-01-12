#include "ShellManager.h"

/**
 * Constructor
 * 
 * Fill the blacklist
 */
ShellManager::ShellManager() {
  blacklist.push_back("&&");
  blacklist.push_back("shutdown");
  blacklist.push_back("restart");
  blacklist.push_back("sudo");
  blacklist.push_back("su");
  blacklist.push_back("service");
}

/**
 * Attempt to set the user id based on username
 * 
 * @return int
 */
int ShellManager::setUser(std::string Username) {

  bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
  if ((int)bufsize == -1)          /* Value was indeterminate */
    bufsize = 16384;               /* Should be more than enough */

  buf = (char*)malloc(bufsize);
  if (buf == NULL) {
    perror("malloc");
    throw this;
  }
  
  s = getpwnam_r(Username.c_str(), &pwd, buf, bufsize, &result);
  if (result == NULL) {
    if (s == 0)
      fprintf(stderr, "User %s not found\n", Username.c_str());
    else {
      errno = s;
      perror("getpwnam_r");
    }
    throw this;
  }
  
  return setUser(pwd.pw_uid);
}

/**
 * Set active userid
 * 
 * @return int setresuid
 */
int ShellManager::setUser(int UserID) {
  setresuid(euid, euid, -1);
  return setresuid(UserID, UserID, euid);
}

/**
 * Set working directory
 * 
 * @return string working directory or application binary
 * directory if fail
 */
std::string ShellManager::setWorkingDirectory(std::string dir) {
  if (dir == "" || !fs::exists(dir)) {
    dir = EloniFramework::Path();
  }
  
  if( fs::exists(dir) )
    this->_dir = dir;
    
  return this->_dir;
}

/**
 * Execute a bash command in working directory
 * 
 * @return string bash output
 */
std::string ShellManager::Execute(std::string cmd) {
  for(std::string str : blacklist)
    if(cmd.find(str) != std::string::npos)
      return "Running " + str + " is not allowed!";
  
  std::string command = "";
  if( _dir != "" )
    command += "cd " + _dir + " && ";
  
  command += cmd;
  
  FILE* pipe = popen(command.c_str(), "r");
  if (!pipe) return "ERROR";
  char buffer[4096];
  std::string result = "";
  while(!feof(pipe)) {
    if(fgets(buffer, 4096, pipe) != NULL)
      result += buffer;
  }
  pclose(pipe);
  if(result[result.length()-1] == '\n')
    result.pop_back();
    
  return result;
}
