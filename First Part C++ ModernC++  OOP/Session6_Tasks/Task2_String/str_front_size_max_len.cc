#include <iostream>
#include <string>

int main()
{
    std::string str = "Sara Saad";
    auto ch = str.front();

    std::cout<<"String: "<<std::endl;
    std::cout<<"First Character: "<<ch<<std::endl;

    std::string str1 = "Hello, World";
    std::cout<<"Sting : "<<str1<<std::endl;
    str1.insert(7,"beautiful ");
    std::cout<<"Sting after insertion: "<<str1<<std::endl;

    std::cout<<"string Length: "<<str.length()<<std::endl;
    std::cout<<"string Size: "<<str.size()<<std::endl;
    std::cout<<"string Size: "<<str.max_size()<<std::endl;

    std::cout<<"\n====================================================\n\n";

    std::cout<<"string Length: "<<str1.length()<<std::endl;
    std::cout<<"string Size: "<<str1.size()<<std::endl;
    std::cout<<"string Size: "<<str1.max_size()<<std::endl;

    /* Push new character in the string*/
    std::cout<<"\n====================================================\n\n";
    std::cout<<"String: "<<str1<<std::endl;
    str1.push_back('!');
    std::cout<<"String after poshing character: "<<str1<<std::endl;
    std::cout<<"\n====================================================\n\n";
    std::cout<<"String: "<<str<<std::endl;
    str.push_back('M');
    std::cout<<"String after poshing character: "<<str<<std::endl;
    std::cout<<"\n====================================================\n\n";

    /*Pop last character at the string*/
    std::cout<<"String: "<<str<<std::endl;
    str.pop_back();
    std::cout<<"String after poping last character: "<<str<<std::endl;

    std::cout<<"\n====================================================\n\n";
    std::cout<<"String1: "<<str1<<std::endl;
    str1.pop_back();
    std::cout<<"String1 after poping last character: "<<str1<<std::endl;

    return(0);
}