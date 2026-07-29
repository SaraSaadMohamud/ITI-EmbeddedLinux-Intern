/**
 * @file main.cpp
 * @brief Counts the number of words in a sentence.
 *
 * This program demonstrates a simple algorithm for counting the number
 * of words in a sentence by counting the spaces between words.
 *
 * @author Sara Saad Mahmoud
 * @version 1.0
 * @date Jul 2026
 */

#include <iostream>
#include <string>

/**
 * @brief Counts the number of words in a string.
 *
 * The function assumes that words are separated by a single space.
 * It counts the number of spaces in the input string and returns
 * one more than the number of spaces.
 *
 * @param str The input sentence.
 *
 * @return The total number of words in the sentence.
 *
 * @note This implementation assumes:
 * - The sentence is not empty.
 * - Words are separated by exactly one space.
 * - There are no leading or trailing spaces.
 */
unsigned int getNumberOfWords(std::string str);

int main()
{
    std::string str = "Hello ITI I am Sara";
    std::cout<<"Number of Words in sentens : "<<getNumberOfWords(str);
    return(0);
}

unsigned int getNumberOfWords(std::string str)
{
    unsigned int count = 0;
    for(int i=0 ; i<str.length() ; ++i)
    {
        if(str[i] == ' ')
        {
            count++;
        }
    }
    return(++count);
}