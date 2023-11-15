#include <iostream>
//#include <mysql_driver.h>
//#include <mysql_connection.h>

using namespace std;

int main() {
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* conn;
    sql::Statement* stmt;
    sql::ResultSet* rs;

    // Establishing connection to the database
    driver = sql::mysql::get_mysql_driver_instance();
    conn = driver->connect("tcp://127.0.0.1:3306", "232ngg15", "62215237");
    conn->setSchema("database_name");

    // Creating and executing the SQL query
    stmt = conn->createStatement();
    rs = stmt->executeQuery("SELECT * FROM employees");

    // Fetching and printing data from the result set
    if (rs->rowsCount() == 0) {
        cout << "ResultSet is empty." << endl;
    }
    else {
        while (rs->next()) {
            int employeeNumber = rs->getInt("employeeNumber");
            string firstName = rs->getString("firstName");
            string lastName = rs->getString("lastName");
            string email = rs->getString("email");

            cout << "Employee Number: " << employeeNumber << endl;
            cout << "Name: " << firstName << " " << lastName << endl;
            cout << "Email: " << email << endl;
            cout << "-----------------------------" << endl;
        }
    }

    // Terminating the objects and closing the connection
    delete rs;
    delete stmt;
    delete conn;

    return 0;
}
