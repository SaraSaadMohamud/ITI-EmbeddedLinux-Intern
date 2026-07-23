#include <iostream>
#include <array>

int main()
{
    std::array<int,10> arr = {10,20,30,40,50,60,70,80,90,100};

    std::cout<<"\nYou can't change the Data store in the array because cbegin cend prevent that!\n";
    for(auto i = arr.cbegin() ; i < arr.cend() ; ++i)
    {
        std::cout<<*i<<"\t";
    }
    std::cout<<std::endl;

    std::cout<<"\n========================================================================\n";
    std::cout<<"You can't change the Data store in the array because cbegin cend prevent that!, just get the revers of the array elements\n";
    for(auto i = arr.crbegin() ; i < arr.crend() ; ++i)
    {
        std::cout<<*i<<"\t";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    
    return(0);
}