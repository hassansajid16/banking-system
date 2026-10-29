cmake_minimum_required(VERSION 3.28)
project(Savings_Account)

set(CMAKE_CXX_STANDARD 23)

add_executable(Savings_Account savings_account.cpp
        savings_account.h
        account.cpp
        account.h
        admin_password.txt
        check_credentials.cpp
        check_credentials.h
        checking_account.cpp
        checking_account.h
        main.cpp)


