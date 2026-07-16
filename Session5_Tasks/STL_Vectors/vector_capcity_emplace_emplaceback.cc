#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec ;
    vec.reserve(20);
    vec.assign(20,10);
    std::cout<<"Vector Capcity: "<<vec.capacity()<<std::endl;

    std::cout<<"vector Elements: ";
    for(auto a : vec)
    {
        std::cout<<a<<"\t";
    }
    std::cout<<std::endl;
    
    vec.emplace(vec.begin()+2 , 5);
    std::cout<<"vector Elements: ";
    for(auto a : vec)
    {
        std::cout<<a<<"\t";
    }
    std::cout<<std::endl;

    vec.emplace_back(5);
    std::cout<<"vector Elements: ";
    for(auto a : vec)
    {
        std::cout<<a<<"\t";
    }
    std::cout<<std::endl;

    vec[1] = 350;
    std::cout<<"vector Elements: ";
    for(auto a : vec)
    {
        std::cout<<a<<"\t";
    }
    std::cout<<std::endl;
    
    return(0);
}