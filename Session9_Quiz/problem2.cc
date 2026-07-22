/**
 * @file main.cc
 * @author Sara Saad Mahmoud
 * @version 1.0
 * @date 2026-07-21
 *
 * @brief Prints "Hello World" continuously.
 *
 * This program demonstrates an infinite loop in C++ by repeatedly
 * printing "Hello World" to the console every second.
 *
 * @details
 * The program uses the sleep() function from <unistd.h> to pause
 * execution for one second between each iteration of the loop.
 *
 * @note The program runs indefinitely and must be terminated
 * manually (e.g., by pressing Ctrl + C).
 */

#include <iostream>
#include <unistd.h>

int main()
{
    for(int i=0 ; 1 ; i++)
    {
        std::cout<<"Hello World"<<std::endl;
        sleep(1);
    }
    return(0);
}
