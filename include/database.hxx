// file      : hello/database.hxx
// copyright : not copyrighted - public domain

//
// Create concrete database instance based on the DATABASE_* macros.
//

#ifndef DATABASE_HXX
#define DATABASE_HXX

#include <cstdlib>  // std::exit
#include <iostream>
#include <memory>  // std::shared_ptr
#include <string>

#include <odb/database.hxx>

#if defined(DATABASE_MYSQL)
#include <odb/mysql/database.hxx>
#elif defined(DATABASE_SQLITE)
#include <odb/connection.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>
#include <odb/transaction.hxx>
#elif defined(DATABASE_PGSQL)
#include <odb/pgsql/database.hxx>
#elif defined(DATABASE_ORACLE)
#include <odb/oracle/database.hxx>
#elif defined(DATABASE_MSSQL)
#include <odb/mssql/database.hxx>
#else
#error unknown database; did you forget to define the DATABASE_* macros?
#endif

inline std::shared_ptr<odb::database> create_database(std::string user,
                                                      std::string password,
                                                      std::string database,
                                                      std::string host) {
  using namespace std;
  using namespace odb::core;
#if defined(DATABASE_MYSQL)
  shared_ptr<database> db(
      new odb::mysql::database(user, password, database, host));
#elif defined(DATABASE_SQLITE)
  shared_ptr<database> db(
      new odb::sqlite::database(user, password, database, host, false,
                                SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE));

  // Create the database schema. Due to bugs in SQLite foreign key
  // support for DDL statements, we need to temporarily disable
  // foreign keys.
  //
  {
    connection_ptr c(db->connection());

    c->execute("PRAGMA foreign_keys=OFF");

    transaction t(c->begin());
    schema_catalog::create_schema(*db);
    t.commit();

    c->execute("PRAGMA foreign_keys=ON");
  }
#elif defined(DATABASE_PGSQL)
  shared_ptr<database> db(
      new odb::pgsql::database(user, password, database, host));
#elif defined(DATABASE_ORACLE)
  shared_ptr<database> db(
      new odb::oracle::database(user, password, database, host));
#elif defined(DATABASE_MSSQL)
  shared_ptr<database> db(
      new odb::mssql::database(user, password, database, host));
#endif

  return db;
}

#endif  // DATABASE_HXX
