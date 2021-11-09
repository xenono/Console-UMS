
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/connection.h>

using std::string;
#ifndef CONSOLEUSERMANAGMENTSYSTEM_DATABASE_H
#define CONSOLEUSERMANAGMENTSYSTEM_DATABASE_H


class Database {
private:
    sql::Driver* Driver;
    std::unique_ptr<sql::Connection> Connection;
    string Uri, User, Password,DatabaseName;
    std::unique_ptr<sql::Connection>  connect();

public:
    Database(string uri, string user, string password, string databaseName);
//    std::unique_ptr<sql::ResultSet> GetUsers();
    void GetUsers();
};


#endif //CONSOLEUSERMANAGMENTSYSTEM_DATABASE_H
