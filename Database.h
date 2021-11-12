
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/connection.h>

using std::string;
#ifndef CONSOLEUSERMANAGMENTSYSTEM_DATABASE_H
#define CONSOLEUSERMANAGMENTSYSTEM_DATABASE_H


class Database {
public:
    bool IsConnected = false;
private:
    sql::Driver* Driver;
    std::unique_ptr<sql::Connection> Connection;
    string Uri, User, Password,DatabaseName;
    std::unique_ptr<sql::Connection>  Connect();

public:
    Database(string uri, string user, string password, string databaseName);
    void GetUsers();
    void InsertUser(string firstName, string secondName, string phoneNumber);
    void DeleteUser(int id);
    bool CheckIfUserExists(int id);
};


#endif //CONSOLEUSERMANAGMENTSYSTEM_DATABASE_H
