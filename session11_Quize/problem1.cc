/**
 * @file main.cpp
 * @author Sara Saad Mahmoud
 * @brief Finds two numbers in a vector whose sum equals a target value.
 * @version 1.0
 * @date 2026-07-22
 *
 * @details
 * This program demonstrates a simple algorithm for solving the
 * "Two Sum" problem in C++.
 *
 * The program:
 * - Stores integer values in a std::vector.
 * - Sorts the vector in ascending order.
 * - Searches for two elements whose sum equals a given target value.
 * - Returns the two numbers if found.
 * - Prints a message if no such pair exists.
 *
 * The implementation uses nested loops after sorting the vector.
 *
 * @note
 * The original vector is modified because std::sort() rearranges
 * its elements.
 */

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Searches for two numbers whose sum equals the target value.
 *
 * @param vec1 Reference to the vector of integers.
 * @param k Target sum.
 * @param num1 Pointer used to store the first matching number.
 * @param num2 Pointer used to store the second matching number.
 *
 * @return int
 * @retval 0  Two numbers were found.
 * @retval -1 No valid pair exists.
 */
int getSumofTwoNumber(std::vector<int> &vec1, int k, int*num1 ,int *num2);


/**
 * @brief Prints all elements of a vector.
 *
 * @param vec1 Reference to the vector.
 */
void printVector(std::vector<int> &vec1);

int main()
{
   std::vector<int> vec1 = {1,3,14,4,9,2,20};
   constexpr int k = 11;
   int num1=0,num2=0;

   printVector(vec1);
   int res = getSumofTwoNumber(vec1,k,&num1,&num2);
   if(res == -1)
   {
        std::cout<<"The are no two numbers in the vector which sum = "<<k<<"!!.\n";
   }
   else
   {
        std::cout<<"The Two Numbers that there sum = "<<k<<"is : \n";
        std::cout<<"Number1: "<<num1<<std::endl;
        std::cout<<"Number2: "<<num2<<std::endl;
   }

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

int getSumofTwoNumber(std::vector<int> &vec1, int k, int*num1 ,int *num2)
{
    std::sort(vec1.begin(), vec1.end());
    printVector(vec1);

    for(int i=0 ; ((i<vec1.size()) && (vec1[i] != k)) ; ++i )
    {
        for(int j=i+1 ; (j<vec1.size()-1) ; j++)
        {
            if( (vec1[i] + vec1[j]) == k )
            {
                * num1=vec1[i];
                * num2=vec1[j];
                 return(0);
            }
        }
    }
    return(-1);
}