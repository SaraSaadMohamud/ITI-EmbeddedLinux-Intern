/**
 * @file main.cpp
 * @author Sara Saad Mahmoud
 * @brief Moves all zero elements in a vector to the end while preserving the order of non-zero elements.
 * @version 1.0
 * @date 2026-07-22
 * @details
 * This program demonstrates a simple algorithm for moving all zero
 * values in a vector to the end without changing the relative order
 * of the remaining (non-zero) elements.
 *
 * The program:
 * - Creates a vector of integers.
 * - Displays the original vector.
 * - Moves all zeros to the end.
 * - Displays the modified vector.
 * @note
 * The vector is modified in-place. No additional vector is created.
 * @copyright
 * Copyright (c) 2026 Sara Saad Mahmoud.
 * All rights reserved.
 */

#include <iostream>
#include<vector>


/**
 * @brief Moves all zero elements to the end of the vector.
 * @details
 * The function scans the vector from left to right.
 * Whenever a zero is found, all subsequent elements are
 * shifted one position to the left, and the zero is placed
 * at the end of the vector.
 * The relative order of all non-zero elements is preserved.
 * @param vec1 Reference to the vector.
 */
void MoveAllZerosToTheEnd(std::vector<int> &vec1);


/**
 * @brief Prints all elements of the vector.
 * @param vec1 Reference to the vector.
 */
void printVector(std::vector<int> &vec1);

int main()
{
    std::vector<int> vec1 = {1,0,3,0,5,6};
    printVector(vec1);
    std::cout<<"========================= After Moving all Zeros to the End =============================\n";
    MoveAllZerosToTheEnd(vec1);
    printVector(vec1);

    return(0);
}

void printVector(std::vector<int> &vec1)
{
    std::cout<<"Vector Elements: ";
    for(auto i= vec1.begin() ; i<vec1.end() ; ++i)
    {
        std::cout<<*i<<" ";
    }
    std::cout<<std::endl;
}

void MoveAllZerosToTheEnd(std::vector<int> &vec1)
{
    int len = vec1.size();
    int zero_num = 0;
    for(int i=0 ; i<len - zero_num ; i++) 
    {
        if(vec1[i] == 0)
        {
            zero_num++;
            for(int j= i ; j<(len-zero_num); j++) 
            {
                vec1[j] = vec1[j+1];
            }
            vec1[len - zero_num] = 0;
        }
    }
}