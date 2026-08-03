/**
 * @file main.cpp
 * @brief Sorts the characters of a string in ascending order.
 *
 * This program reads a string from the user and sorts its characters
 * in ascending order using a simple comparison-based sorting algorithm.
 *
 * The sorting operation is performed directly on the original string
 * using references, without creating another string.
 *
 * @author Sara Saad
 * @date 2026-08-03
 */

#include <iostream>
#include <string>

/**
 * @brief Sorts the characters of a string in ascending order.
 *
 * Compares each character with the characters that follow it.
 * If a character is greater than the following character, their
 * positions are swapped.
 *
 * @param str Reference to the string that will be sorted.
 *
 * @note The input string is modified directly because it is passed
 *       by reference.
 */
void sortString(std::string &str);

int main()
{
    std::string str;
    
    std::cout << "Enter String: ";
    std::getline(std::cin, str);

    std::cout << "\nString Before Sorting: " << str << std::endl;

    sortString(str);

    std::cout << "String After Sorting: " << str << std::endl;

    return 0;
}

void sortString(std::string &str)
{
    int length = str.length();
    char temp;

    for (auto i = 0; i < length; ++i)
    {
        for (auto j = i + 1; j < length; ++j)
        {
            if (str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

