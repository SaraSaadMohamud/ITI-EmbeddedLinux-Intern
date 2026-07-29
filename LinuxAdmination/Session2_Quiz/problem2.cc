/**
 * @file main.cpp
 * @brief Finds the missing numbers in an unsorted sequence.
 *
 * This program demonstrates how to identify missing integers in an
 * unsorted vector. The input vector is first sorted, then consecutive
 * elements are compared to determine which numbers are missing.
 *
 * @author Sara Saad Mahmoud
 * @version 1.0
 * @dat
*/

#include <iostream>
#include <vector>
#include <algorithm>


/**
 * @brief Finds the missing numbers in an integer sequence.
 *
 * The function creates a sorted copy of the input vector and compares
 * each pair of adjacent elements. Whenever two consecutive numbers are
 * not adjacent, the missing value between them is added to the result.
 *
 * @param vec1 Reference to the input vector.
 *
 * @return A vector containing the missing numbers.
 *
 * @note This implementation assumes that there is at most one missing
 * number between any two consecutive elements after sorting.
 */

std::vector <unsigned int> getMissingNumbers(std::vector <unsigned int> &vec1);


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
    std::vector <unsigned int> copy_vec = vec1;
    std::vector <unsigned int> missing_vec;
    std::sort(copy_vec.begin(), copy_vec.end()); // 1 2 3 4 6 7 9 11 12

    for(auto i=0 ; i<vec1.size() - 1 ; ++i)
    {
        if( (copy_vec[i] +1) != copy_vec[i+1])
        {
            missing_vec.push_back(copy_vec[i]+1);
        }
    }

    return(missing_vec);
}