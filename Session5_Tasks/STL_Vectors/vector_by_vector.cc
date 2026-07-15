#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec1 = {10,20,30,40,50,60,70,80,90,100};
    std::vector<int> vec2(vec1.begin(),vec1.end());

    std::cout<<"Vector1 Element: ";
    for(auto i : vec1)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;

    std::cout<<"Vector2 Element: ";
    for(auto i : vec2)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;

    std::cout<<"\n==========================================================================================\n\n";

    std::vector<int> vec3(10);
    std::cout<<"Vector3 Element: ";
    for(auto i : vec3)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;
    
    fill(vec3.begin(),vec3.end(), 20);
    std::cout<<"Vector3 Element: ";
    for(auto i : vec3)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;

    std::cout<<"\n==========================================================================================\n\n";
    return(0);
}