/**
 * @file main.cpp
 * @brief Counts the frequency of each number in a vector.
 *
 * This program determines how many times each integer appears
 * in a vector using a frequency vector. The size of the frequency
 * vector is based on the maximum value found in the input vector.
 *
 * @author Sara Saad
 * @version 1.0
 * @date 2026
 */

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Counts the occurrences of each number in a vector.
 *
 * Traverses the input vector and increments the corresponding
 * index in the frequency vector. After counting, only the
 * numbers with non-zero occurrences are displayed.
 *
 * @param vec Reference to the input vector containing integers.
 * @param arr Reference to the frequency vector used to store
 *        the occurrence count of each integer.
 */
void countNumbersOccurs(const std::vector<int> &vec , std::vector<int> &arr);

/**
 * @brief Prints all elements of a vector.
 *
 * Displays each element separated by tabs.
 *
 * @param vec Constant reference to the vector to be printed.
 */
void printVector(const std::vector<int> &vec );

int main()
{
    std::vector<int> vec = {1,2,3,1,1,2,2,2,4,5,6,3};
    int maxValue = *std::max_element(vec.begin(), vec.end());
    std::vector<int> arr(maxValue + 1, 0);

    std::cout<<"\n====================== Counting Number Occurance ========================\n";
    printVector(vec);
    countNumbersOccurs(vec,arr);

    return(0);
}

void countNumbersOccurs(const std::vector<int> &vec, std::vector<int> &arr)
{
    
    for(size_t i =0 ;i < vec.size() ; ++i)
    {
        arr[vec[i]]++;
    }

    for(size_t i = 0 ; i < arr.size() ; i++)
    {
        if(arr[i] != 0)
            std::cout<<i<<" : "<<arr[i]<<std::endl;
    }
}

void printVector(const std::vector<int> &vec)
{
    std::cout<<"Vector Elements: ";
    for(auto i : vec)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;
}