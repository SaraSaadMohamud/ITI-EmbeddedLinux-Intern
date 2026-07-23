/**
 * @file main.cpp
 * @author Sara Saad Mahmoud
 * @brief Counts the frequency of each character in a lowercase string.
 * @version 1.0
 * @date 2026-07-22
 *
 * @details
 * This program demonstrates how to count the number of occurrences
 * of each lowercase English alphabet character in a string using
 * a std::vector as a frequency table.
 *
 * The program:
 * - Creates a string.
 * - Initializes a frequency vector of size 26.
 * - Counts the occurrence of each letter.
 * - Prints only the characters that appear in the string along
 *   with their frequencies.
 *
 * @note
 * This implementation assumes that the input string contains only
 * lowercase English letters ('a' to 'z').
 */

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Counts the frequency of each lowercase letter in a string.
 * @details
 * The function initializes a vector of size 26 with zeros.
 * Each index represents one lowercase English letter:
 *
 * - Index 0  -> 'a'
 * - Index 1  -> 'b'
 * - ...
 * - Index 25 -> 'z'
 * The function increments the corresponding counter for every
 * character in the string and then prints all characters that
 * appear at least once.
 * @param str Reference to the input string.
 * @param vec Reference to the frequency vector.
 */
void getNumberofRepetation(std::string &str, std::vector<int> &vec);

int main()
{
    std::string str = "banana";
    std::vector<int> vec;

    getNumberofRepetation(str,vec);
    
    return(0);
}

void getNumberofRepetation(std::string &str, std::vector<int> &vec)
{
    vec.resize(26,0);

    for(int i=0 ; i< str.length() ; i++)
    {
        vec[str[i] - 'a']++;
    }

    for(int i=0 ; i<26 ; i++)
    {
        if(vec[i]!=0)
            std::cout << char(i+'a') << " : " << vec[i] << '\n';
    }

}