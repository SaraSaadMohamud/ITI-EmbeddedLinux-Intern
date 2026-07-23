#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {1,2,3,4,5};
    std::cout<<"Vector Elements: ";
    for(auto a : vec)
    {
        std::cout<<a<<"\t";
    }
    std::cout<<std::endl;
//////////////////////////////////////////////////////////////////////
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(10);
    std::cout<<"Vector Elements: ";
    for(auto a : vec)
    {
        std::cout<<a<<"\t";
    }
    std::cout<<std::endl;
//////////////////////////////////////////////////////////////////////
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    std::cout<<"Vector Elements: ";
    for(auto a : vec)
    {
        std::cout<<a<<"\t";
    }
    std::cout<<std::endl;

    return(0);
}