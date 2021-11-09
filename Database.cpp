//
// Created by xenono on 09/11/2021.
//
#include "Database.h"

using std::cout;

Database::Database(string uri, string user, string password, string databaseName) {
    Uri = uri;
    User = user;
    Password = password;
    DatabaseName = databaseName;
    Driver = get_driver_instance();
    Connection = connect();

}

std::unique_ptr<sql::Connection> Database::connect() {
    try {
        std::unique_ptr<sql::Connection> con(Driver->connect(Uri, User, Password));
        con->setSchema(DatabaseName);
        return con;
    } catch (sql::SQLException &e) {
        cout << "#ERR" << e.what() << " Code:" << e.getErrorCode();
        return nullptr;
    }
}

//std::unique_ptr<sql::ResultSet>  Database::GetUsers() {
//    if(Connection == nullptr)
//        cout << "NULL";
//    std::unique_ptr<sql::Statement> statement(Connection->createStatement());
//    std::unique_ptr<sql::ResultSet> result(statement->executeQuery("SELECT * from users"));
//    return result;
//}

void Database::GetUsers() {
    try {

        std::unique_ptr<sql::Statement> statement(Connection->createStatement());
        std::unique_ptr<sql::ResultSet> res(statement->executeQuery("SELECT * from users"));
        cout << "--- List of users ---" << std::endl;
        while (res->next()) {
            cout << res->getString("firstName")
                 << " " << res->getString("secondName")
                 << " " << res->getInt64("phoneNumber") << std::endl;
        }
        cout << "---------------------";

    } catch (sql::SQLException &e) {

        cout << "# ERR: " << e.what();
        cout << " Code: " << e.getErrorCode();

    }
}


