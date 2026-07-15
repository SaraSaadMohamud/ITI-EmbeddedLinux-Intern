#include <iostream>
#include <array>

int main()
{
    std::array<int,5> arr = {10,20,30,40,50};
    std::cout<<"\n";
    std::cout<<*(arr.data())<<std::endl;
    
    std::cout<<"Array is Empty: "<<std::boolalpha<<(arr.empty())<<std::endl;
    std::cout<<"\n================================================================================\n\n";

    std::array<int,10> arra ;
    arra.fill(100);

    for(auto i = arra.begin() ; i< arra.end() ; ++i)
    {
        std::cout<<*i<<"\t";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"\n=================================================================================\n\n";

    return(0);
}