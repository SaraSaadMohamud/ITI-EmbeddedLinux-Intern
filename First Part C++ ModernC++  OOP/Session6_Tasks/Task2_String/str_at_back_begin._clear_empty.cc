#include <iostream>
#include <string>

int main()
{
    std::string str = "Sara Saad";
    /* Return the First character*/
    char ch = str.at(3);
    std::cout<<str<<std::endl;
    std::cout<<ch<<std::endl;

    /*Return the last character*/
    char ch1 = str.back();
    std::cout<<ch1<<std::endl;

    /*return iterator for the first charecter */
    auto ch2 = str.begin();
    std::cout<<*ch2<<std::endl;

    /* clear the data inside the string*/
    str.clear();
    std::cout<<str<<std::endl;

    /* check if the string is empty or not*/
    bool check = str.empty();
    std::cout<<"Is string is Empty: "<< std::boolalpha <<check<<std::endl;

    return(0);
}