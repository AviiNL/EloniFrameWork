/**
 * @author Yme-Jan Iedema <yj.iedema@gmail.com>
 * @file ShellManager.h
 * 
 * ShellManager
 * 
 * This class will allow the usage of 'some' bash commands ran as a 
 * specific user.
 */

#ifndef DG2_BASHMANAGER_H
#define DG2_BASHMANAGER_H

// Include all general headers
#include "Includes.h"

// Class specific headers
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <sys/types.h>
#include <pwd.h>

namespace fs = boost::filesystem;

class ShellManager {
  private:
    struct passwd             pwd;
    struct passwd             *result;
    char                      *buf;
    size_t                    bufsize;
    int                       s;
    std::string               _dir;
    uid_t                     ruid, euid, saveduid;
    std::vector<std::string>  blacklist;
    
  public:
    ShellManager();
    int           setUser(std::string Username);
    int           setUser(int UserID);
    std::string   setWorkingDirectory(std::string dir);
    std::string   Execute(std::string cmd);
};

#endif
