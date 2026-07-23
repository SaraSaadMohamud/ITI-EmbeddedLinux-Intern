#include <iostream>
#include <string>

int main()
{
    std::string str1 = "sara";
    std::string str2 = "saad";
    std::string str3 = "saad";

    int res1 = str1.compare(str2);
    int res2 = str2.compare(str3);

    if((res1 == 0) || (res2 == 0))
    {
        std::cout<<"Two string are the same!.\n"<<std::endl;
    }
    if ((res2 > 0) || (res1 > 0))
    {
        std::cout<<"String1 is bigger than String2.!"<<std::endl;
    }
    if((res2 < 0) || (res1 < 0))
    {
        std::cout<<"String2 is bigger than String1.!"<<std::endl;
    }

    /* Get the number of Character that string can hold*/
    std::cout<<"String1 Capcity: "<<str1.capacity()<<std::endl;
    std::cout<<"String2 Capcity: "<<str2.capacity()<<std::endl;
    std::cout<<"String3 Capcity: "<<str3.capacity()<<std::endl;

    std::string str4 = "Sara Saad Mahmoud";
    char str5[10];
    str4.copy(str5,10,0);

    std::cout<<str4<<std::endl;
    std::cout<<str5<<std::endl;

    return(0);
}