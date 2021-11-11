#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/connection.h>
#include "Database.h"
#include <chrono>
#include <thread>

#define DEFAULT_URI "tcp://127.0.0.1"
#define EXAMPLE_USER "root"
#define EXAMPLE_PASS "root"
#define EXAMPLE_DB "consoleums"

using std::cout, std::endl, std::cin, std::string;

void displayMenu();

int main() {
    const string url = DEFAULT_URI;
    const string user(EXAMPLE_USER);
    const string pass(EXAMPLE_PASS);
    const string database(EXAMPLE_DB);
    int userMenuChoice = 5;
    // User Interface
    cout << "Welcome to Console User Management System." << std::endl;
    cout << "Press enter to connect to the database";
    cin.get();
    cout << "Connecting to SQL database";
    for (int i = 8; i > 0; i--) {
        cout << ".";
        cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(i * 100 / 4));

    }
    cout << std::endl;
    auto db = new Database(url, user, pass, database);
    if (db->IsConnected) {
        cout << "Database connected";
    } else {
        cout << std::endl << "Connection failed!" << std::endl << "Please check database connection and credentials.";
        return 1;
    }
    while (userMenuChoice != 0) {
        displayMenu();
        cout << "Option: ";
        cin >> userMenuChoice;
    }
    return 1;
}

void displayMenu() {
    cout << "\n --- Menu ---\n"
         << " 0 - Exit\n"
         << " 1 - Get Users\n"
         << " 2 - Insert User\n"
         << " 3 - Delete User\n"
         << " --- ---- --- \n";
}
