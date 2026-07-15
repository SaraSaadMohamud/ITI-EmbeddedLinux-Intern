#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    /* assign all located memory to the same value*/
    vec.assign(10,50);

    for(auto i : vec)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<"\n\n=======================================================================================\n\n";

    vec.push_back(10);
    for(auto i : vec)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<"\n\n======================================================================================\n\n";

    std::vector<int> vec1(10,500);
    for(auto i : vec1)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<"\n\n======================================================================================\n\n";

    std::vector<int> vec2{10,20,30,40,50,60,70,80,90,100};
    for(auto i : vec2)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<"\n\n======================================================================================\n\n";

    std::vector<int> vec3 = {1,2,3,4,5,6,7,8,9,10};
    for(auto i : vec3)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<"\n\n======================================================================================\n\n";
}