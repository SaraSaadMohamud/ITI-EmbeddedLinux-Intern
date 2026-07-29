/**
 * @file main.cpp
 * @brief Counts the number of vowels in a string.
 *
 * This program checks each character in a string and counts
 * the total number of English vowels (A, E, I, O, U),
 * regardless of whether they are uppercase or lowercase.
 *
 * @author Sara Saad
 * @version 1.0
 * @date 2026
 */

#include <iostream>
#include <string>

/**
 * @brief Counts the number of vowels in a string.
 *
 * Iterates through the given string and increments the value
 * pointed to by @p sum whenever a vowel is found.
 *
 * Supported vowels:
 * - A, E, I, O, U
 * - a, e, i, o, u
 *
 * @param str Reference to the input string.
 * @param sum Pointer to the variable that stores the vowel count.
 */
void checkVowels(std::string &str, unsigned int *sum);

int main()
{
    std::string str = "AWoeiaaauuQlmn" ;
    unsigned int sum = 0;
    checkVowels(str,&sum);
    std::cout<<"String: "<<str<<std::endl;
    std::cout<<"Number of Vowels in String: "<<sum<<std::endl;

    return(0);
}

void checkVowels(std::string &str , unsigned int *sum)
{
    int strlen = str.length();
    for(int i=0 ; i<strlen ; i++)
    {
        if((str[i]=='A') || (str[i]=='a') ||
           (str[i]=='E') || (str[i]=='e') ||
           (str[i]=='U') || (str[i]=='u') || 
           (str[i]=='O') || (str[i]=='o') ||
           (str[i]=='I') || (str[i]=='i'))
           {
                (*sum) ++;
           }
    }
}

