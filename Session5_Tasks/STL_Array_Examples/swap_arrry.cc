#include <iostream>
#include <array>

int main()
{
    std::array<int,10> arr1 = {10,20,30,40,50,60,70,80,90,100};
    std::array<int,10> arr2 = {1,2,3,4,5,6,7,8,9,10};

    std::cout<<"\n\n======================== Before Swaping two Arraies Element ======================================\n\n";
    std::cout<<"Array1 Elements: ";
    for(int *i= arr1.begin() ; i< arr1.end() ; ++i)
    {
        std::cout<<*i<<"\t";
    }
    std::cout<<std::endl;

    std::cout<<"Array2 Elements: ";
    for(int *i= arr2.begin() ; i< arr2.end() ; ++i)
    {
        std::cout<<*i<<"\t";
    }
    std::cout<<std::endl;

    arr1.swap(arr2);
    std::cout<<"\n\n======================== After Swaping two Arraies Element ======================================\n\n";
    std::cout<<"Array1 Elements: ";
    for(int *i= arr1.begin() ; i< arr1.end() ; ++i)
    {
        std::cout<<*i<<"\t";
    }
    std::cout<<std::endl;

    std::cout<<"Array2 Elements: ";
    for(int *i= arr2.begin() ; i< arr2.end() ; ++i)
    {
        std::cout<<*i<<"\t";
    }
    std::cout<<std::endl;

    return(0);
}