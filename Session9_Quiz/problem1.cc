/**
 * @file main.cc
 * @author Sara Saad Mahmoud
 * @version 1.0
 * @date 2026-07-21
 *
 * @brief Reverses the order of words in a string.
 *
 * This program demonstrates a simple string manipulation technique.
 * It prints a string with the order of its two words reversed while
 * preserving the characters within each word.
 *
 * @details
 * The program assumes that the input string contains exactly two words
 * separated by a single space. The function locates the space character
 * and prints the second word followed by the first word.
 *
 * @note This function does not modify the original string; it only
 * prints the reversed word order.
 */

#include <iostream>
#include <string>

/**
 * @brief Prints the input string with its word order reversed.
 *
 * The function searches for the first space character in the string,
 * then prints the second word followed by the first word.
 *
 * @param str Reference to the input string.
 */
void getReverseString(std::string &str);

int main()
{
    std::string str = "Hello World";
    std::cout<<"String: "<<str<<std::endl;
    std::cout<<"================== After Reversing =================\nString:";
    getReverseString(str);

    return(0);
}

void getReverseString(std::string &str)
{
    int arr[2];
    int i = 0;

    for( i=0 ; str[i]!=' ' ; i++);
    int length = str.length();

    for(int temp = i ; temp< length ; temp++)
    {
        std::cout<<str[temp];
    }
    std::cout<<" ";
    for(int temp = 0 ; temp< i ; temp++)
    {
        std::cout<<str[temp];
    }
    std::cout<<std::endl;
}