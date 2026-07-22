/**
 * @file main.cc
 * @author Sara Saad Mahmoud
 * @version 1.0
 * @date 2026-07-21
 *
 * @brief Finds the missing number in a sequence of integers.
 *
 * This program reads ten integer values from the user, sorts them in
 * ascending order, and attempts to determine the missing number in the
 * sequence. If no missing number is found, an appropriate message is
 * displayed.
 *
 * @note The input array is passed by value to the search function,
 * so the original array remains unchanged after sorting.
 */

#include <iostream>
#include <algorithm>
#include <array>

/** Number of elements in the array. */
constexpr unsigned int len = 10;

/**
 * @brief Finds the missing number in a sorted sequence.
 *
 * The function sorts the input array and searches for a gap between
 * consecutive numbers to determine the missing value.
 *
 * @param numbers Array containing the input numbers.
 * @return unsigned int The missing number.
 * @retval -1 If no missing number exists.
 */
unsigned int findMissingNumber(std::array<unsigned int, len> numbers);

int main()
{
   
    std::array<unsigned int, len> numbers;

    for(unsigned int i=0 ; i<len ; i++)
    {
        std::cout<<"Enter Number"<<i+1<<": ";
        std::cin>>numbers[i];
    }

    unsigned int missing_number = findMissingNumber(numbers);
    std::cout<<"\n===============================================================\n";

    if(missing_number == -1)
    {
        std::cout<<"There are no missing Numbers!!\n";
    }
    else
    {
        std::cout<<"Missing Number: "<<missing_number<<std::endl;
    }
  

}

unsigned int findMissingNumber(std::array<unsigned int, len> numbers)
{
    std::sort(numbers.begin() , numbers.end());  
    std::cout<<"Sorted Numbers: ";
    for(auto i =0 ; i<len ; i++)
    {
        std::cout<<numbers[i]<<" ";
    }
    std::cout<<std::endl;
    
    for(unsigned int i=0 ; i<len ; i++)
    {
        if(numbers[i] != (numbers[i] + 1))
        {
            return(numbers[i] + 1);
        }
    }
    return(-1);
}
