#pragma once
#include <iostream>
#include "clsUser.h"
clsUser CurrentUser = clsUser::Find("", "");

class Global
{
public:
        static void Clear()
        {
                // Function to check the OS and perform an action based on the OS type
#if defined(_WIN32) || defined(_WIN64)
                // Windows
                system("cls");
#elif defined(__APPLE__) || defined(__MACH__)
                // macOS
                system("clear");
#elif defined(__linux__)
                // Linux
                system("clear");
#else
                std::cout << "Unknown OS" << std::endl;
#endif
        }

        static void Pause()
        {
#if defined(_WIN32) || defined(_WIN64)
                system("pause>0"); // Perform Windows-specific action
#elif defined(__APPLE__) || defined(__MACH__)
                system("read -n 1 -s -p \" Press any key to continue... \"; echo");
#elif defined(__linux__)
                system("read -n 1 -s -p \" Press any key to continue... \"; echo");
#else
                std::cout << "Unknown OS" << std::endl;
#endif
        }
};