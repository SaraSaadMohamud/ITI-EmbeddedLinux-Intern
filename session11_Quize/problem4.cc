/**
 * @file main.cpp
 * @author Sara Saad Mahmoud
 * @brief Checks whether a string is a palindrome.
 * @version 1.0
 * @date 2026-07-22
 *
 * @details
 * This program demonstrates how to determine whether a string
 * is a palindrome using C++.
 *
 * A palindrome is a string that reads the same forward and
 * backward.
 *
 * The program:
 * - Creates sample strings.
 * - Checks whether each string is a palindrome.
 * - Prints the corresponding result.
 *
 * @note
 * The comparison performed by this implementation is
 * case-sensitive. For example, "Madam" is considered different
 * from "madaM". To perform a case-insensitive comparison,
 * convert all characters to either lowercase or uppercase
 * before checking.
 */
#include <iostream>
#include <string>

/**
 * @brief Checks whether a string is a palindrome.
 *
 * @details
 * The function compares characters from the beginning and
 * the end of the string simultaneously.
 *
 * If any pair of characters differs, the string is not
 * a palindrome.
 * @param str Reference to the input string.
 * @return int
 * @retval 1  The string is a palindrome.
 * @retval -1 The string is not a palindrome.
 */
int checkPalindromeString(std::string &str);

int main()
{
    std::string str1 = "MadaM";
    std::string str2 = "sara";

    int check = checkPalindromeString(str1);
    if(check == -1)
    {
        std::cout<<"String: "<<str1<<" is not a pandlorm String!!\n";
    }
    else
    {
        std::cout<<"String: "<<str1<<" is a pandlorm String!!\n";
    }
    check = checkPalindromeString(str2);
    if(check == -1)
    {
        std::cout<<"String: "<<str2<<" is not a pandlorm String!!\n";
    }
    else
    {
        std::cout<<"String: "<<str2<<" is a pandlorm String!!\n";
    }

    return(0);
}

int checkPalindromeString(std::string &str)
{
    int len = str.length();
    int end = len -1;

    for(int i=0 ; i<len/2 ; i++)
    {
        if(str[i] != str[end])
        {
            return(-1);
        }
        end--;
    }

    return(1);
}