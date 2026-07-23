#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec1 = {1,2,3,4,5};

    std::cout<<"\n======================= .front ========================\n";
    std::cout<<vec1.front()<<std::endl;

    std::cout<<"\n======================= .back ========================\n";
    std::cout<<vec1.back()<<std::endl;

    std::cout<<"\n======================= .data ========================\n";
    std::cout<<*(vec1.data())<<std::endl;

    std::cout<<"\n======================= .at ========================\n";
    std::cout<<vec1.at(4)<<std::endl;

    std::cout<<"\n======================= .size ========================\n";
    std::cout<<vec1.size()<<std::endl;

    std::cout<<"\n======================= .max_size ========================\n";
    std::cout<<(vec1.max_size())<<std::endl;

    std::cout<<"\n======================= .empty ========================\n";
    std::cout<<std::boolalpha<<vec1.empty()<<std::endl;
    return(0);
}