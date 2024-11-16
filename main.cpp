#include "config/api.h"

#include <iostream>
#include <pqxx/pqxx>

int main()
{
    try
    {
        pqxx::connection connection(API::connectionString);
        if (connection.is_open())
        {
            std::cout << "Opened database successfully: " << connection.dbname() << std::endl;
        }
        else
        {
            std::cerr << "Can't open database" << std::endl;
            return 1;
        }

        pqxx::work transaction(connection);
        pqxx::result result = transaction.exec("select first_name from actor");

        for (auto row : result)
        {
            std::cout << "ID = " << row[0].as<std::string>() << std::endl;
        }

        transaction.commit();
        connection.close();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}