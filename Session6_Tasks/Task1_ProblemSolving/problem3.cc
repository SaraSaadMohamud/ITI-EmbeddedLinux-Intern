/**
 * @file main.cpp
 * @brief Finds the second largest element in a vector.
 *
 * This program sorts a vector of integers in ascending order
 * and retrieves the second largest element. The original vector
 * is modified because it is sorted in place.
 *
 * @author Sara Saad
 * @version 1.0
 * @date 2026
 */

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Finds the second largest element in a vector.
 *
 * The vector is sorted in ascending order, and the second
 * largest element is stored in the variable pointed to by
 * @p max.
 *
 * @param vec Reference to the input vector.
 * @param max Pointer to the variable that stores the second largest element.
 */
void getSeondLargestElement(std::vector<int> &vec, int *max);


/**
 * @brief Prints all elements of a vector.
 *
 * Displays each element separated by tabs.
 *
 * @param vec Constant reference to the vector to be printed.
 */
void printVector(const std::vector<int> &vec);

int main()
{
    std::vector<int> vec = {10,20,100,1,6,9,500,-5};
    int max = 0;
    printVector(vec);
    getSeondLargestElement(vec, &max);
    std::cout<<"Second Max Element in Vector: "<<max<<std::endl<<std::endl;

    return(0);
}
void getSeondLargestElement(std::vector<int> &vec, int *max)
{
    std::sort(vec.begin(), vec.end());
    int length = vec.size();

    if(max == nullptr)
    {
        std::cout<<"Null Pointer, Invalid Function Prameter!\n";
        exit(0);
    }
    *max = vec[length-2];
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