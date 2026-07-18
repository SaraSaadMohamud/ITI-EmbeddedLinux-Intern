/**
 * @file main.cpp
 * @brief Reverses the characters of a string.
 *
 * This program reverses a string in place by swapping
 * characters from the beginning and the end until the
 * middle of the string is reached.
 *
 * @author Sara Saad
 * @version 1.0
 * @date 2026
 */

#include <iostream>
#include <string>

/**
 * @brief Reverses a string in place.
 *
 * Swaps characters from both ends of the string until
 * the middle of the string is reached.
 *
 * @param str Reference to the string to be reversed.
 */
void reverseString(std::string &str);

int main()
{
    std::string str = "sara saad";
    std::cout<<"String: "<<str<<std::endl;
    reverseString(str);
    std::cout<<"Reverse String: "<<str<<std::endl;
}

void reverseString(std::string &str)
{
    int length = str.length();
    int rs = length-1;
    int temp =0;

    for(int i=0 ; i<length/2 ; i++)
    {
        temp = str[i];
        str[i] = str[rs];
        str[rs] = temp;
        rs--;
    }
}