#include "DatabaseManager.h"

DatabaseManager::DatabaseManager() { }

/**
 * Open the database
 * 
 * @return int
 */
int DatabaseManager::Open(std::string filename) {
  dbFile = EloniFrameWork::Path() + "/" + filename;
  
  rc = sqlite3_open(dbFile.c_str(), &db);
  
  if( rc ) {
    fprintf(stderr, "SQL Error: Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
  }
  
  return rc;
}

/**
 * Close the database
 */
void DatabaseManager::Close() {
  sqlite3_close(db);
}

/**
 * Queries the database and returns the data in a dictionary style
 * result for easy access (all values are fetched as string)
 * 
 * eg: result[0]["username"]
 * 
 * return vector<map<string, string>>
 */
std::vector< std::map<std::string,std::string> > DatabaseManager::Query(std::string query, std::string filename) {
  
  // CRITICAL FIXME: Make query more secure using regex and whatnot.
  
  this->Open(filename);
  std::vector< std::map<std::string,std::string> > rows;
  
  sqlite3_stmt *stmt;
  if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL) == SQLITE_OK) {
    std::string test_string(query);
    boost::algorithm::to_lower(test_string);
    int cols = sqlite3_column_count(stmt);
    for (;;) {
      std::map<std::string,std::string> _cols;
      int rc = sqlite3_step(stmt);
      
      if (rc == SQLITE_DONE && rc != SQLITE_ROW)
        break;
      if(test_string.find("select ") == std::string::npos) // TODO: Refactor
        break;
      
      for(int col = 0; col < cols; col++) {
        
        int bytes = sqlite3_column_bytes( stmt, col );
        unsigned char const* v = sqlite3_column_text( stmt, col );
        
        std::string val;
        std::string var = sqlite3_column_name( stmt, col );
        val.assign( reinterpret_cast<char const*>(v), bytes );
        
        _cols.insert(std::pair<std::string,std::string>(var,val));
      }
      rows.push_back(_cols);
    }
    sqlite3_finalize(stmt);
  }
  this->Close();
  return rows;
}

