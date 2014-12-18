/*!
 * @author Yme-Jan Iedema <yj.iedema@gmail.com>
 * @file DatabaseManager.h
 * 
 * DatabaseManager
 * 
 * Wrapper for sqlite
 * The Query function throws a segementation error when accessing
 * tables or data that does not exit
 */

#ifndef DG2_DATABASEMANAGER_H
#define DG2_DATABASEMANAGER_H

#include "Includes.h"

#include <boost/algorithm/string.hpp>
#include <sqlite3.h>

class DatabaseManager {
  private:
    sqlite3     *db;
    int         rc;
    std::string dbFile;
    
  public:
    DatabaseManager();
    int           Open(std::string filename);
    void          Close();
    std::vector< std::map<std::string,std::string> > Query(std::string, std::string = "elonisas.db");
    
};

#endif
