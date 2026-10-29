#include "check_credentials.h"
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>


bool checkAdminCredentials() {
    std::string storedUsername, storedPassword;
    std::string inputUsername, inputPassword;
    std::ifstream file("admin_password.txt");

    if (file.is_open()) {
        std::cout << "Enter admin username: ";
        std::cin >> inputUsername;

        while (file >> storedUsername >> storedPassword) {
            if (storedUsername == inputUsername) {
                std::cout << "Enter password for " << inputUsername << ": ";
                std::cin >> inputPassword;

                if (inputPassword == storedPassword){
                    std::cout << "** Welcome to Hassan Bank Limited **"<< std::endl;
                    // Get the current time
                    std::time_t t = std::time(nullptr);

                    // Create a tm structure to hold the local time
                    std::tm localTime;

                    // Convert to local time using localtime_s
                    localtime_s(&localTime, &t);

                    // Display the date in YYYY-MM-DD format
                    std::cout << "Current date: "
                              << 1900 + localTime.tm_year << "-"
                              << 1 + localTime.tm_mon << "-"
                              << localTime.tm_mday << std::endl;

                    std::cout << storedUsername<<std::endl;
                }
                return inputPassword == storedPassword;
            }
        }
        std::cerr << "Username not found." << std::endl;
        return false;
    } else {
        std::cerr << "Error opening password file." << std::endl;
        return false;
    }
}