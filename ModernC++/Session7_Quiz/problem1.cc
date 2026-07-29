/**
 * @file main.cpp
 * @brief Demonstrates merging two vectors into a third vector.
 *
 * This program:
 * - Creates two integer vectors.
 * - Merges their elements into a third vector.
 * - Displays all vectors.
 *
 * @author Sara Saad
 * @version 1.0
 * @date 2026
 */

#include <iostream>
# include <vector>

/**
 * @brief Merges two vectors into a third vector.
 *
 * The function copies all elements from the two input vectors
 * into the destination vector. The order depends on the first
 * element of each vector:
 * - If the first element of vec1 is smaller, vec1 is copied first.
 * - Otherwise, vec2 is copied first.
 *
 * @param vec1 Reference to the first input vector.
 * @param vec2 Reference to the second input vector.
 * @param vec3 Reference to the destination vector where merged elements are stored.
 */
void mergeTwoVectores(std::vector<int> &vec1, std::vector<int> &vec2, std::vector<int> &vec3);

/**
 * @brief Prints all elements of a vector.
 *
 * Displays each element separated by tabs, followed by a newline.
 *
 * @param vec Vector containing integer elements to print.
 */
void print_vector(std::vector<int> vec);

int main()
{
    /**************************************** Merge two vector*********************************** */
    std::vector<int> vec1 = {1,2,3,4,5};
    std::vector<int> vec2 = {6,7,8,9,10};
    std::vector<int> vec3;

    std::cout<<"\n================= Merge two vectors========================\n\n";
    mergeTwoVectores(vec1,vec2,vec3);
    std::cout<<"Vector1 Elements: ";
    print_vector(vec1);
    std::cout<<"Vector2 Elements: ";
    print_vector(vec2);
    std::cout<<"Vector3 Elements: ";
    print_vector(vec3);

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

void mergeTwoVectores(std::vector<int> &vec1, std::vector<int> &vec2, std::vector<int> &vec3)
{
    int vec1size = vec1.size();
    int vec2size = vec2.size();
    int totsize = vec1size + vec2size;
    vec3.resize(totsize);

    int start = (vec1[0] > vec2[0]) ? 2 : 1;

    if(start == 1)
    {
        for(auto i =0 ; i<vec1size ; i++)
        {
            vec3[i] = vec1[i];
        }
        for(int i = vec1size ; i<totsize ; ++i)
        {
            vec3[i] = vec2[i-vec1size];
        }
    }
    else if (start == 2)
    {
        for(auto i =0 ; i<vec2size ; i++)
        {
            vec3[i] = vec2[i];
        }
        for(int i = vec2size ; i<totsize ; ++i)
        {
            vec3[i] = vec2[i-vec2size];
        }
    }

}

