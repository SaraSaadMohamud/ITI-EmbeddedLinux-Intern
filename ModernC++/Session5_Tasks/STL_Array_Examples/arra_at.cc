#include <iostream>
#include <array>

int main()
{
    std::array<int,5> arr = {10,30,20,40,60};

    std::cout<<arr.at(0)<<std::endl;
    std::cout<<arr.at(1)<<std::endl;
    std::cout<<arr.at(2)<<std::endl;
    std::cout<<arr.at(3)<<std::endl;
    std::cout<<arr.at(4)<<std::endl;
    
    return(0);
}