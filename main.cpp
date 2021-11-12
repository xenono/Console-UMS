#include <iostream>
#include "Database.h"
#include <chrono>
#include <thread>
#include <regex>

#define DEFAULT_URI "tcp://127.0.0.1"
#define EXAMPLE_USER "root"
#define EXAMPLE_PASS ""
#define EXAMPLE_DB "consoleums"

using std::cout, std::endl, std::cin, std::string;

void displayMenu();

void insertUser(Database *db);

void deleteUser(Database *db);

bool isNonAlpha(string text);

bool isNumber(string text);

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
        switch (userMenuChoice) {
            case 0: {
                cout << "Exiting...";
                std::this_thread::sleep_for(std::chrono::milliseconds(2));
                break;
            }
            case 1: {
                db->GetUsers();
                break;
            }
            case 2: {
                cout << "Insert User Procedure" << std::endl;
                insertUser(db);
                break;
            }
            case 3: {
                cout << "Delete User Procedure" << std::endl;
                deleteUser(db);
                break;
            }
            default:
                cout << "Choose a number in range 0 to 3" << std::endl;
                break;
        }
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

void insertUser(Database *db) {
    string firstName, secondName, phoneNumber;
    do {

        cout << std::endl << "Enter user's first name" << std::endl;
        cout << "Name can only contain letters" << std::endl;
        cin >> firstName;

    } while (!firstName.empty() && !isNonAlpha(firstName));
    do {
        cout << std::endl << "Enter user's second name" << std::endl;
        cout << "Second name can only contain letters" << std::endl;
        cin >> secondName;
    } while (!secondName.empty() && !isNonAlpha(secondName));
    do {
        cout << std::endl << "Enter user's phone number" << std::endl;
        cout << "Phone has to be 11 digits long" << std::endl;
        cin >> phoneNumber;
    } while (!isNumber(phoneNumber));
    db->InsertUser(firstName, secondName, phoneNumber);
}

void deleteUser(Database *db){
    int userId;
    cout << "Enter id of user who will be deleted: ";
    cin >> userId;
    cout << std::endl;
    if(db->CheckIfUserExists(userId)){
        db->DeleteUser(userId);
    } else
        cout << "User with this ID  does not exist";
}

bool isNonAlpha(string text) {
    return std::regex_match(text, std::regex("[A-Za-z]+$"));
}

bool isNumber(string text) {
    return std::regex_match(text, std::regex("[0-9]{11}+$"));
}