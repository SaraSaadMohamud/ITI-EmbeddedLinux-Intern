/**
 * @file main.cpp
 * @brief Demonstrates common operations on C++ vectors.
 *
 * This program demonstrates several vector operations including:
 * - Finding the maximum and minimum elements.
 * - Comparing two vectors.
 * - Assigning values to vectors.
 * - Reversing a vector manually.
 * - Reversing a vector using the STL reverse() function.
 * - Printing vector elements.
 * - Detecting duplicate elements after sorting.
 *
 * The project is intended for learning basic STL vector manipulation
 * and pointer usage in Modern C++.
 *
 * @author Sara Saad
 * @version 1.0
 * @date 2026
 */

#include <problem_solving_quiz.hh>


int main()
{
    std::vector<int> vec1 = {1,2,3,4,5};
    std::vector<int> vec2 = {10,9,8,9,6};

    int max1 = vec1[0],min1 = vec1[0];
    int max2 = vec2[0],min2 = vec2[0];
    get_max_min(vec1,&max1,&min1);
    get_max_min(vec2,&max2,&min2);
    print_min_max(&max1,&min1);
    print_min_max(&max2,&min2);
    

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(vec1 == vec2)
    {
        std::cout<<"Two Vectors are Equal!!.\n";
    }
    else
    {
        std::cout<<"Two Vector are not equals!\n";
    }
    
    vec1.assign(5,10);
    vec2.assign(5,10);

    if(vec1 == vec2)
    {
        std::cout<<"Two Vectors are Equal!!.\n";
    }
    else
    {
        std::cout<<"Two Vector are not equals!\n";
    }

    //////////////////////////////////////////////////////////////
    if(equal(vec1.begin(),vec1.end(), vec2.begin()))
        std::cout<<"Two Vectors are Equal!!.\n";
    else
        std::cout<<"Two Vector are not equals!\n";

    std::cout<<"\n======================= Reverse Vector =====================\n\n";
    std::vector<int> vec3 = {10,9,8,9,6};
    print_vector(vec3);
    revers_vector(vec3);
    print_vector(vec3);

    std::cout<<"\n======================= Reverse Vector  Built in function =====================\n\n";
    print_vector(vec3);
    reverse(vec3.begin(),vec3.end());
    print_vector(vec3);

    std::cout<<"\n=======================  Vector Check =====================\n\n";
    std::vector<int> vec4 = {1,2,3,4,3};
    int index;
    print_vector(vec4);
    check_repetation(vec4,&index);
    if(index == -1)
    std::cout<<"null pointer, Check function Inputs!!\n";
    else
        std::cout<<"Vector has repeated element at index: "<<index<<" equal = "<<vec4[index];

    return(0);
}

void get_max_min(std::vector<int> &vec, int *max, int*min)
{
    if(vec.empty() == 1)
    {
        max = nullptr;
        min = nullptr;
    }
    else
    {
        for(auto i : vec)
        {
            if(i> *max)
            {
                *max = i;
            }
            else if (i< *min)
            {
                *min = i;
            }
        
        }
    }
}
    
void print_min_max(int *max, int*min)
{
    if((max == nullptr) || (min == nullptr))
    {
        std::cout<<"Nullptr, Vector is Empety!!?\n";
    }
    else
    {
        std::cout<<"Vector Max Element: "<<*max<<std::endl;
        std::cout<<"Vector Min Element: "<<*min<<std::endl<<std::endl;
    }
}

//////////////////////////////////////////////////////////////////////////////////////
void revers_vector(std::vector<int> &vec)
{
    int size = vec.size();
    int rev = size -1;
    for(int i=0 ; i<size/2 ; i++)
    {
        int temp;
        temp = vec[i];
        vec[i] = vec[rev];
        vec[rev] = temp;
        rev--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

void print_vector(std::vector<int> &vec)
{
    std::cout<<"Vector Elements: ";
    for(auto i : vec)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;
}

void check_repetation(std::vector<int> &vec, int *index)
{
    if(index == nullptr)
    {
        *index == -1;
    }
    else
    {
        sort(vec.begin(), vec.end());
        std::cout<<"1.Sorted Vector Data!\n";
        print_vector(vec);
        for(auto i=0 ; i<vec.size() ; ++i)
        {
            if(vec[i] == vec[i+1])
            {
                *index = i+1;
                break;
            }
        }
    }
    
}