/**
 * @file problem1.cc
 * @author Sara Saad Mahmoud
 * @date 2026-07-21
 * @brief Finds the first non-repeated character in a string.
 *
 * This program reads a string from the user, sorts its characters,
 * and determines the first character that appears only once.
 * If no unique character exists, an appropriate message is displayed.
 *
 * @details
 * The program accepts a string from the user, sorts its characters
 * using the C++ Standard Library's std::sort() function, and then
 * searches for the first non-repeated character.
 *
 * @version 1.0
 */

#include <iostream>
#include <string>
#include <algorithm>

/**
 * @brief Finds the first non-repeated character in a string.
 *
 * The function sorts the input string in ascending order and then
 * searches for the first character that occurs exactly once.
 *
 * @param str Reference to the input string.
 * @return char The first non-repeated character.
 * @retval -1 If no unique character exists.
 *
 * @note The original string is modified because it is sorted.
 */
char findFirstUnrepeadCharacter(std::string &str);


/**
 * @brief Program entry point.
 *
 * Prompts the user to enter a string, calls
 * findFirstUnrepeadCharacter(), and displays the result.
 *
 * @return int Returns 0 upon successful execution.
 */
int main()
{
    std::string str;
    std::cout<<"Enter String of Reapeated Characters: ";
    std::getline(std::cin,str);

    std::cout<<"\n===============================================================\n";
    std::cout<<"String: "<<str<<std::endl;
    char res = findFirstUnrepeadCharacter(str);
    if(res == -1)
    {
        std::cout<<"There are no unrepeated character!!\n"<<std::endl;
    }
    else
    {
        std::cout<<"First unrepeated Number: "<<res<<std::endl;
    }

    return(0);
}

char findFirstUnrepeadCharacter(std::string &str)
{
    unsigned int len = str.length();
    std::sort(str.begin(), str.end());
    std::cout<<"Sorted String Character: "<<str<<std::endl;

    for(int i=0 ; i<len ; i++)
    {
        if(str[i] != str[i+1] && (str[i] != str[i-1]))
        {
            return(str[i]);
        }
    }
    return(-1);
}