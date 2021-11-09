cmake_minimum_required(VERSION 3.20)
project(ConsoleUserManagmentSystem)

set(CMAKE_CXX_STANDARD 17)
include_directories(/home/xenono/mysql/include)
link_directories(/home/xenono/mysql/lib)
link_libraries(libmysqlcppconn.so libmysqlcppconn.so.7 libmysqlcppconn.so.7.1.1.12 libmysqlcppconn-static.a)
add_executable(ConsoleUserManagmentSystem main.cpp Database.cpp Database.h)
