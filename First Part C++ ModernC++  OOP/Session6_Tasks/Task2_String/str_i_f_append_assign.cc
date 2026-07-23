#include <iostream>
#include <string>

int main()
{
    std::string name = "sara saad";
    std::string int_num = "212";
    std::string float_num = "14.5";
    
    int num = 11;
    int num1 = 14.5;
    std::string str;

    std::cout<<name<<std::endl;
    std::cout<<stoi(int_num)<<std::endl;
    std::cout<<stof(float_num)<<std::endl;

    std::cout<<std::to_string(num)<<std::endl;
    std::cout<<std::to_string(num1)<<std::endl;

    name.append(" Mahmoud");
    std::cout<<name<<std::endl;

    str.assign("Ahmed Saad Mahmoud");
    std::cout<<str<<std::endl;

    return(0);
}