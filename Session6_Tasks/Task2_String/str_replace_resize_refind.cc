#include <iostream>
#include <string>

int main()
{
    std::string str = "Sara Saad";
    std::cout<<"String: "<<str<<std::endl;

    str.replace(5,5,"Mahmoud");
    std::cout<<"String After Replacing 5 character: "<<str<<std::endl;
    std::cout<<"\n====================================================\n\n";

    std::string str1;
    std::cout<<"String1 Capcity: "<<str1.capacity()<<std::endl;
    str1.reserve(500);
    std::cout<<"String1 Capcity After Reserve: "<<str1.capacity()<<std::endl;
    std::cout<<"\n====================================================\n\n";

    std::string str2;
    std::cout<<"String: "<<str2<<std::endl;
    str2.resize(10,'S');
    std::cout<<"String After Resize: "<<str2<<std::endl;
    std::cout<<"\n====================================================\n\n";

    std::string str3 = "Hello, World, World";
    size_t pos = str3.rfind("World");
     if(pos !=  std::string::npos)
    {
        std::cout<<"last 'World' apper is in pos : "<<pos<<std::endl;
    }
    else
    {
        std::cout<<"the string 'World' not found!!"<<std::endl;
    }
    std::cout<<"\n====================================================\n\n";

    std::string str4 = "Sara Saad";
    std::cout<<"String: "<<str4<<std::endl;
    std::string sub = str4.substr(5,4);
    std::cout<<"Substring: "<<sub<<std::endl;
    std::cout<<"\n====================================================\n\n";

    std::string str5 = "Sherif Osama";
    std::string str6 = "Sara Saad";
    std::cout<<"\n=============================== Strings Before Swaping =====================================\n\n";
    std::cout<<"String1: "<<str5<<std::endl;
    std::cout<<"String2: "<<str6<<std::endl;
    str5.swap(str6);
    std::cout<<"\n=============================== Strings After Swaping =====================================\n\n";
    std::cout<<"String1: "<<str5<<std::endl;
    std::cout<<"String2: "<<str6<<std::endl;
    
    return(0);
}
