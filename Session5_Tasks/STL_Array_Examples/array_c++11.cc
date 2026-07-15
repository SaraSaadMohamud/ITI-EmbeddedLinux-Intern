#include <iostream>
#include <array>

int main()
{
    std::array<int,5> arr = {10,20,30,40,50};
    for(const int&i : arr)
    {
        std::cout<<i<<std::endl;
    }
    
    return(0);
}