#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/connection.h>
#include "Database.h"

#define DEFAULT_URI "tcp://127.0.0.1"
#define EXAMPLE_USER "root"
#define EXAMPLE_PASS "root"
#define EXAMPLE_DB "consoleums"

using std::cout, std::endl, std::cin, std::string;


int main() {
    const string url = DEFAULT_URI;
    const string user(EXAMPLE_USER);
    const string pass(EXAMPLE_PASS);
    const string database(EXAMPLE_DB);

    try {
//        sql::Driver * driver;

    /* Using the Driver to create a connection */
//        driver = get_driver_instance_by_name("");
//        cout << "Creating session on " << url << " ..."
//             << endl << endl;
//
//        std::unique_ptr< sql::Connection >
//                con(driver->connect(url, "root", "root"));
//        con->setSchema(database);
//
//        std::unique_ptr< sql::Statement > stmt(con->createStatement());
//        std::unique_ptr< sql::ResultSet >
//                res(stmt->executeQuery("SELECT * from users"));
//
    auto *db = new Database(url, user, pass, database);
//    std::unique_ptr<sql::ResultSet> res = db->GetUsers();
    db->GetUsers();

    }
    catch (sql::SQLException &e)
    {
        /*
          The JDBC API throws three different exceptions:

        - sql::MethodNotImplementedException (derived from sql::SQLException)
        - sql::InvalidArgumentException (derived from sql::SQLException)
        - sql::SQLException (derived from std::runtime_error)
        */

        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << "EXAMPLE_FUNCTION" << ") on line " << __LINE__ << endl;

        /* Use what() (derived from std::runtime_error) to fetch the error message */

        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;

        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
//    return 1;
}
