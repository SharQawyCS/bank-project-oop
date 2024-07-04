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
        // Perform Windows-specific action
#elif defined(__APPLE__) || defined(__MACH__)
        // macOS
        system("clear");
        // Perform macOS-specific action
#elif defined(__linux__)
        // Linux
        system("clear");
        // Perform Linux-specific action
#else
        std::cout << "Unknown OS" << std::endl;
        // Perform action for unknown OS
#endif
    }

    static void Pause()
    {
#if defined(_WIN32) || defined(_WIN64)
        // Windows
        system("pause>0"); // Perform Windows-specific action
#elif defined(__APPLE__) || defined(__MACH__)
        // macOS
        system("read -n 1 -s -p \" Press any key to continue... \"; echo");
        // Perform macOS-specific action
#elif defined(__linux__)
        // Linux
        system("read -n 1 -s -p \" Press any key to continue... \"; echo");
        // Perform Linux-specific action
#else
        std::cout << "Unknown OS" << std::endl;
        // Perform action for unknown OS
#endif
    }
};