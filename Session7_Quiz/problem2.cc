/**
 * @file main.cpp
 * @brief Compares the sums of elements in multiple vectors.
 *
 * This program calculates the sum of elements for three integer vectors
 * and compares their totals to determine whether they have equal sums.
 *
 * @author Sara Saad
 * @version 1.0
 * @date 2026
 */

#include <iostream>
#include <vector>

/**
 * @brief Calculates the sum of all elements in a vector.
 *
 * Iterates through the vector and adds each element to the value
 * pointed to by the sum pointer.
 *
 * @param vec Input vector containing unsigned integer elements.
 * @param sum Pointer to the variable where the calculated sum is stored.
 */
void vectorElementsSumming(std::vector <unsigned int> vec , unsigned int *sum);

int main()
{
    std::vector <unsigned int> vec1 = {10,50,80,90,100};
    std::vector <unsigned int> vec2 = {10,100,70,50,100};
    std::vector <unsigned int> vec3 = {1,2,3,4,5};
    unsigned int vec1_sum = 0,vec2_sum =0,vec3_sum=0;

    vectorElementsSumming(vec1,&vec1_sum);
    vectorElementsSumming(vec2,&vec2_sum);
    vectorElementsSumming(vec3,&vec3_sum);

    if(vec1_sum == vec2_sum)
    {
        std::cout<<"Vector1 & vector2  have the Same Sum Element!\n";
    }
    else 
    {
        std::cout<<"Vector1 & vector2  Don't have the Same Sum Element!\n";
    }

    if(vec1_sum == vec3_sum)
    {
        std::cout<<"Vector1 & vector3  have the Same Sum Element!\n";
    }
    else 
    {
        std::cout<<"Vector1 & vector3  Don't have the Same Sum Element!\n";
    }

    if(vec2_sum == vec3_sum)
    {
        std::cout<<"Vector2 & vector3  have the Same Sum Element!\n";
    }
    else 
    {
        std::cout<<"Vector2 & vector3  Don't have the Same Sum Element!\n";
    }

    return(0);
}
void vectorElementsSumming(std::vector <unsigned int> vec, unsigned int *sum)
{
    if(vec.empty() == true);
    else
    {
        for(auto i : vec)
        {
            *(sum) += i;
        }
        std::cout<<*sum<<std::endl;
    }
}