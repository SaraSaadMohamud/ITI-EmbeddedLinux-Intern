/**
 * @file main.cpp
 * @brief Reverses the elements of a vector in place.
 *
 * This program demonstrates how to reverse the order of
 * elements in an integer vector without using an additional
 * container. The vector is reversed by swapping elements
 * from both ends toward the center.
 *
 * @author Sara Saad
 * @version 1.0
 * @date Jul - 2026
 */

#include <iostream>
#include <vector>

/**
 * @brief Reverses the elements of a vector in place.
 *
 * Uses the two-pointer technique to swap elements from the
 * beginning and the end of the vector until the middle is reached.
 *
 * @param vec Reference to the vector to be reversed.
 */
void reverseInPlace(std::vector<int>  &vec );

/**
 * @brief Prints all elements of a vector.
 *
 * Displays each element separated by tabs.
 *
 * @param vec Vector containing integer elements to print.
 */
void printVector(std::vector<int> vec );

int main()
{

    std::vector<int>  vec = {10,20,30,40,50};
    std::cout<<"\n================= Before Reversing ===========================\n";
    printVector(vec);
    reverseInPlace(vec);
    std::cout<<"\n================= After Reversing ===========================\n";
    printVector(vec);
    std::cout<<std::endl;

    return(0);
}

void reverseInPlace(std::vector<int> &vec)
{
    int length = vec.size();
    int rev = length-1;
    int temp =0;

    for(auto i = 0 ; i<length/2 ; i++)
    {
        temp = vec[i];
        vec[i] = vec[rev];
        vec[rev] = temp;
        rev--;
    }
}

void printVector(std::vector<int> vec)
{
    std::cout<<"Vector Elements: ";
    for(auto i : vec)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;
}