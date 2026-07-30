#include "Utilities.hpp"

void bufferClear()
{
    std::cin.clear();  
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cout<<"\n------------------------------------------------------------------------------\n\n";
}
