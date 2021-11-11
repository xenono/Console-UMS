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
    try {
        Connection = Connect();
        if(Connection == nullptr)
            IsConnected = false;
        else
            IsConnected=true;
    } catch (sql::SQLException &e) {
        cout << "#ERR" << e.what() << " Code:" << e.getErrorCode();
        Connection = nullptr;
    }
}

std::unique_ptr<sql::Connection> Database::Connect() {
    try {
        std::unique_ptr<sql::Connection> con(Driver->connect(Uri, User, Password));
        con->setSchema(DatabaseName);
        return con;
    } catch (sql::SQLException &e) {
        cout << "#ERR" << e.what() << " Code:" << e.getErrorCode();
        return nullptr;
    }
}

void Database::GetUsers() {
    if(Connection == nullptr) {
        cout << "Database or Connection Error";
        return;
    }
    try {
        std::unique_ptr<sql::Statement> statement(Connection->createStatement());
        std::unique_ptr<sql::ResultSet> res(statement->executeQuery("SELECT * from users"));
        cout << std::endl << "--- List of users ---" << std::endl;
        while (res->next()) {
            cout << res->getInt("id") << " - " << res->getString("firstName")
                 << " " << res->getString("secondName")
                 << " " << res->getString("phoneNumber") << std::endl;
        }
        cout << "---------------------" << std::endl;

    } catch (sql::SQLException &e) {
        cout << "GetUsers ERROR ";
        cout << "#ERR: " << e.what();
        cout << " Code: " << e.getErrorCode();

    }
}

void Database::InsertUser(string firstName, string secondName, string phoneNumber){
    try {
        std::unique_ptr<sql::Statement> statement(Connection->createStatement());
        statement->execute("INSERT INTO users(firstName,secondName,phoneNumber) VALUES ('" + firstName + "','" + secondName + "','" + phoneNumber + "');");
        cout << "User has been added.";
    }catch(sql::SQLException &e){
        cout << "InsertUser Error ";
        cout << "#ERR: " << e.what();
        cout << " Code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " " << std::endl;
    }

}

void Database::DeleteUser(int id){
    try {
        std::unique_ptr<sql::Statement> statement(Connection->createStatement());
        statement->execute("DELETE FROM users WHERE id=" + std::to_string(id) + ";");
        cout << "Users has been successfully deleted";
    }catch(sql::SQLException &e){
        cout << "DeleteUser Error "
        << "#ERR: " << e.what()
        << " Code: " << e.getErrorCode()
        << ", SQLState: " << e.getSQLState() << " " << std::endl;
    }
}



