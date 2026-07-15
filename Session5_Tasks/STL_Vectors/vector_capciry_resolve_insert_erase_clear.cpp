#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec1;
    vec1.reserve(20);
    vec1.assign(20,10);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout<<"\n======================= .reserve & .capacity ========================\n";
    std::cout<<"Capicity of current memory allocated: "<<vec1.capacity()<<std::endl;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout<<"\n==============================.erase ================================\n";
    std::cout<<"Vector Element Bafore Erase: ";
    for(auto i : vec1)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<"\n";
    vec1.erase(vec1.begin() + 2);
    std::cout<<"Vector Element After Erase: ";
    for(auto i : vec1)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<"\n";
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::cout<<"\n==============================.insert ================================\n";
    std::cout<<"Vector Element Bafore insert: ";
    for(auto i : vec1)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<"\n";
    vec1.insert(vec1.begin() + 2 , 5);
    std::cout<<"Vector Element After insert: ";
    for(auto i : vec1)
    {
        std::cout<<i<<"\t";
    }
    std::cout<<"\n";
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout<<"\n==============================.clear ================================\n";

    std::cout<<"size of vector before clearing: "<<vec1.size()<<::std::endl;
    vec1.clear();
    std::cout<<"size of vector after clearing: "<<vec1.size()<<::std::endl;

    return(0);
}