#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {10,20,30};
    std::cout<<"Vector Capcity: "<<vec.capacity()<<std::endl;
    vec.reserve(10);
    std::cout<<"Vector Capcity: "<<vec.capacity()<<std::endl;
    vec.shrink_to_fit();
    std::cout<<"Vector Capcity: "<<vec.capacity()<<std::endl;

    std::cout<<"\n\n========================= Before Swapping ==========================\n";
    std::vector<int> vec1 = {10,20,30,40,50};
    std::vector<int> vec2 = {60,70,80,90,100};

    std::cout<<"Vector1 Elemetnt: ";
    for(int i: vec1)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;

    std::cout<<"Vector2 Elemetnt: ";
    for(int a: vec2)
    {
        std::cout<<a<<"\t";
    }
    std::cout<<std::endl;

    vec1.swap(vec2);
    std::cout<<"\n\n========================= After Swapping ==========================\n";
    std::cout<<"Vector1 Elemetnt: ";
    for(int i: vec1)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;

    std::cout<<"Vector2 Elemetnt: ";
    for(int a: vec2)
    {
        std::cout<<a<<"\t";
    }
    std::cout<<std::endl;

    return(0);
}