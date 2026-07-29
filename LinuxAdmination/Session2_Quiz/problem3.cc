/**
 * @file main.cpp
 * @brief Finds the missing numbers in an integer sequence.
 *
 * This program determines the missing positive integers in an
 * unsorted vector. It searches for every number from 1 up to
 * the maximum value in the vector and reports those that do
 * not exist in the input sequence.
 *
 * @author Sara Saad Mahmoud
 * @version 1.0
 * @date Jul 2026
 */

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Finds all missing numbers in an integer sequence.
 *
 * The function determines the largest value in the input vector,
 * then searches for every integer from 1 up to that maximum value.
 * Any value that does not exist in the vector is added to the
 * returned vector.
 *
 * @param vec1 Reference to the input vector.
 *
 * @return A vector containing all missing integers in ascending order.
 *
 * @note This implementation assumes the input vector contains
 * positive integers.
 */
std::vector <unsigned int> getMissingNumbers(std::vector <unsigned int> &vec1);

/**
 * @brief Prints the contents of a vector.
 *
 * Displays all missing numbers in a readable format.
 *
 * @param vec Constant reference to the vector containing
 * the missing numbers.
 */
void printMissingVectorElements(const std::vector <unsigned int> &vec);

int main()
{
    std::vector <unsigned int> vec1{3,7,4,9,12,6,1,11,2};
    std::vector <unsigned int> vec2 =  getMissingNumbers(vec1);
    printMissingVectorElements(vec2);

    return(0);
}

void printMissingVectorElements(const std::vector <unsigned int> &vec)
{
    std::cout<<"Missing Elements: ";
    for(auto i : vec)
    {
        std::cout<<i<<" ";
    }

    std::cout<<std::endl;
}

std::vector <unsigned int> getMissingNumbers(std::vector <unsigned int> &vec1)
{
    std::vector <unsigned int> missing_vec;
    unsigned int max = *std::max_element(vec1.begin(), vec1.end());

    for(auto i=1 ; i<=max ; ++i)
    {
       if( (std::find(vec1.begin(), vec1.end(), i)) == vec1.end())
       {
            missing_vec.push_back(i);
       }
    }

    return(missing_vec);
}