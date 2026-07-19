#include <iostream>
#include <string>

int main()
{   
    std::string str = "Ahmed Saad";
    /*Get the reverse of after last element = before first element*/
    auto fch = str.crend();
    /* Get the reverse of the first elements = last element */
    auto lch = str.crbegin();

    std::cout<<"String: "<<str<<std::endl;
    std::cout<<"First Character in String: "<<*fch<<std::endl;
    std::cout<<"Last Character in String: "<<*lch<<std::endl;

    /*Return The Data of String*/
    auto data = str.data();
    std::cout<<"Data: "<<data<<std::endl;

    /* Erase start of index 5 , 1 character*/
    str.erase(5,1);
    std::cout<<"String After erase index 5: "<<str<<std::endl;

    /* Erase start of index 5 , 2 character*/
    str.erase(5,2);
    std::cout<<"String After erase index 5,6: "<<str<<std::endl;

    /* Erase start of index 0 , 5 character*/
    str.erase(0,5);
    std::cout<<"String After erase index [0:4]: "<<str<<std::endl;

    str = "Ahmed Saad";
    std::cout<<"String: "<<str<<std::endl;

    auto check = str.find("Sara");
    if(check == std::string::npos)
    {
        std::cout<<"Substring not found!!\n"<<std::endl;
    }
    else
    {
        std::cout<<"Substring found at index : "<<check<<std::endl;
    }
    
    check = str.find("Saad");
    if(check ==  std::string::npos)
    {
        std::cout<<"Substring not found!!\n"<<std::endl;
    }
    else
    {
        std::cout<<"Substring found at index : "<<check<<std::endl;
    }

    str = "Sara";
    std::cout<<"String: "<<str<<std::endl;
    size_t pos = str.find_first_not_of("Sa");

    if(check !=  std::string::npos)
    {
        std::cout<<"first character not found in 'sa' is in pos : "<<pos<<std::endl;
    }
    else
    {
        std::cout<<"All character are in sa"<<std::endl;
    }

    str = "Hello World";
    std::cout<<"String: "<<str<<std::endl;
    auto po = str.find_first_of("aiuoe");

    if(check !=  std::string::npos)
    {
        std::cout<<"first character  found in 'aiuoe' is in pos : "<<po<<std::endl;
    }
    else
    {
        std::cout<<"No character of 'aiuoe' found!!"<<std::endl;
    }

    /* find position of last character not in this string*/
    str = "Eng.Sherif";
    size_t p = str.find_last_not_of("if");
    if(check !=  std::string::npos)
    {
        std::cout<<"last character not found in 'if' is in pos : "<<p<<std::endl;
    }
    else
    {
        std::cout<<"All character in 'if' found!!"<<std::endl;
    }

    /* find position of last character in this string*/
    str = "Hello, World";
    size_t P = str.find_last_of("aeuio");
    if(check !=  std::string::npos)
    {
        std::cout<<"Last character  found in 'aiuoe' is in pos : "<<P<<std::endl;
    }
    else
    {
        std::cout<<"No character of 'aiuoe' found!!"<<std::endl;
    }
    
    return(0);
}