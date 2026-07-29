#include <iostream>
#include <array>

int main()
{
    std::array<int,10> arr = {20,30,40,50,60,80,90,100,10,70};
    std::cout<<"\n========================================================================================\n\n";

    std::cout<<arr.front()<<std::endl;
    std::cout<<arr.max_size()<<std::endl;
    std::cout<<arr.size()<<std::endl;
    std::cout<<"\n========================================================================================\n\n";

    for(int i=0 ; i< 10 ; i++)
    {
        std::cout<<arr[i]<<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"\n========================================================================================\n\n";

    return(0);
}