/**
 * @file main.cpp
 * @brief Removes duplicate elements from a vector.
 *
 * This program sorts a vector of integers and removes duplicate
 * values manually without using the STL std::unique() algorithm.
 * Duplicate elements are removed by shifting subsequent elements
 * one position to the left and reducing the vector size.
 *
 * @author Sara Saad
 * @version 1.0
 * @date Jul - 2026
 */

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Removes duplicate elements from a vector.
 *
 * The vector is first sorted so that duplicate values become
 * adjacent. Whenever two consecutive elements are equal,
 * the remaining elements are shifted one position to the left,
 * the last element is removed using pop_back(), and the current
 * index is rechecked to handle multiple consecutive duplicates.
 *
 * @param vec Reference to the vector from which duplicates
 *            will be removed.
 */
void removeDuplicate(std::vector<int> &vec);

/**
 * @brief Prints all elements of a vector.
 *
 * Displays the vector elements separated by tabs.
 *
 * @param vec Constant reference to the vector to print.
 */
void printVector(const std::vector<int> &vec);

int main()
{
    std::vector<int> vec = {10,20,50,10,10,30,20,100,3,50,30};
    std::cout<<"\n==================== Before Remove Duplicate ====================== \n";
    printVector(vec);

    removeDuplicate(vec);
    

    return(0);
}

void removeDuplicate(std::vector<int> &vec)
{
    int len = vec.size();
    int temp =0;
    std::sort(vec.begin(),vec.end());
    std::cout<<"\n=========================== Sorted Vector =========================\n\n";
    printVector(vec);
    for(size_t i =0 ; i < vec.size()-1; i++)
    {
        if(vec[i] == vec[i+1])
        {
            for(int j=i +1; j< vec.size() ; j++)
            {
                vec[j] = vec[j+1];
            }

            vec.pop_back();
            i--;
        }
    }

    std::cout<<"\n==================== After Remove Duplicate ======================= \n";
    printVector(vec);

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