/**
 * @file main.cpp
 * @brief Removes negative numbers from a vector.
 *
 * This program displays the original vector, removes all
 * negative values, and then prints the updated vector.
 *
 * @author Sara Saad
 * @version 1.0
 * @date 2026
 */

#include <iostream>
#include <vector>

/**
 * @brief Removes all negative elements from a vector.
 *
 * Traverses the vector and removes every element whose value
 * is less than zero.
 *
 * @param vec Reference to the vector to be modified.
 */
void removeNegativeNumber(std::vector<int> &vec);

/**
 * @brief Prints all elements of a vector.
 *
 * Displays each element separated by tabs.
 *
 * @param vec Vector containing integer elements to print.
 */
void print_vector(std::vector<int> vec);

int main()
{
    std::vector<int> vec = {1,2,-5,10,20,-30,40};
    std::cout<<"Allvector Elements: ";
    print_vector(vec);
    removeNegativeNumber(vec);
    std::cout<<"After Removeing Negative Elements: ";
    print_vector(vec);

    return(0);
}

void print_vector(std::vector<int> vec)
{
    for(auto i : vec)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;
}

void removeNegativeNumber(std::vector<int> &vec)
{
    int vecsize = (vec.size()) -1;
    for(auto i : vec)
    {
        if(vec[i]<0 && (vecsize != i))
        {
            vec[i] = vec[vecsize];
            vec[vecsize] =0;
            vecsize--;
            vec.pop_back();
        }
        if(vecsize == i)
        {
            vec[i]=0;
            vec.pop_back();
        }
    }
}

