#include <iostream>
#include <array>

int main()
{
    std::array<int,10> arr = {10,20,30,40,50,60,70,80,90,100};

    std::cout<<"\n==================== begain & back ======================\n";
    std::cout<<arr.back()<<std::endl;
    std::cout<<*(arr.begin())<<std::endl;

    std::cout<<"\n==================== begain & end ======================\n";
    for(auto i = arr.begin() ; i< arr.end(); ++i)
    {
        std::cout<<*i<<"\t";
    }

    std::cout<<"\n\n==================== rbegain & rend ======================\n";
    for(auto i = arr.rbegin() ; i< arr.rend(); ++i)
    {
        std::cout<<*i<<"\t";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
}