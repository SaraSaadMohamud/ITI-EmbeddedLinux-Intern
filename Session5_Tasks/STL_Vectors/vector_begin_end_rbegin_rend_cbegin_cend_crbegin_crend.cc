#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec1 = {10,20,30,40,50,60,70,80,90,100};

    std::cout<<"\n======================================= begin & end =============================================\n";
    for(auto i = vec1.begin() ; i< vec1.end() ; ++i)
    {
        std::cout<<*(i)<<"\t";
    }
    std::cout<<std::endl;

    std::cout<<"\n======================================= Cbegin & cend =============================================\n";
    for( auto i = vec1.cbegin() ; i< vec1.cend() ; ++i)
    {
        std::cout<<*(i)<<"\t";
    }
    std::cout<<std::endl;

    std::cout<<"\n======================================= rbegin & rend =============================================\n";
    for( auto i = vec1.rbegin() ; i< vec1.rend() ; ++i)
    {
        std::cout<<*(i)<<"\t";
    }
    std::cout<<std::endl;

    std::cout<<"\n======================================= crbegin & crend =============================================\n";
    for( auto i = vec1.crbegin() ; i< vec1.crend() ; ++i)
    {
        std::cout<<*(i)<<"\t";
    }
    std::cout<<std::endl;

    return(0);
}