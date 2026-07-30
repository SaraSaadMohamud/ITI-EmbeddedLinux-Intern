#include "LogIn.hh"
#include <iostream>
#include <limits>
#include <string_view>

constexpr std::string_view  ADMIN_USERNAME = "Sara";
constexpr std::string_view  ADMIN_PASSWORD = "1234";

void displayMainMenu(Bank & bank)
{
    int choice, flag =0;
    while(true)
    {
        flag=0;
        std::cout<<"\n----------------------------- Bank System --------------------------------\n";
        std::cout<<"1. Admin LogIn\n";
        std::cout<<"2. User LogIn\n";
        std::cout<<"3. Exit\n";
        std::cout<<"----------------------------------------------------------------------------\n";

        do{
            std::cout<<"Enter your Choice: ";
            if(!(std::cin>>choice))
            {
                std::cout<<"invalid Input!!\n";
                bufferClear();
                flag++;
                continue;
            }
            if(choice < 1 || choice > 3)
            {
                std::cout<<"invalid Input!!\n";
                flag++;
                continue;
            }
            
            break;
        }while(flag<3);

        if(flag == 3)
        {
            std::cout << "Too many invalid attempts. Returning to menu...\n"  ;
            return;
        } 

        switch(choice)
        {
            case 1:
                adminLogIn(bank); 
            break;
            case 2:
                userLogIn(bank);
            break;
            case 3:
                return;
            break;

        }
    }

}


void adminLogIn(Bank &bank)
{
    std::string name;
    std::string password;
    int flag = 0;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(flag<3)
    {
        std::cout<<"Enter Admin Name: ";
        std::getline(std::cin,name);

        std::cout<<"Enter Admin Password: ";
        std::getline(std::cin, password);

        if(name != ADMIN_USERNAME)
        {
            std::cout<<"Invalid Admin Name!\n";
            flag++;
            continue;
        }

        if(password != ADMIN_PASSWORD)
        {
            std::cout<<"invalid Admin Password!!\n";
            flag++;
            continue;
        }
        break;
    }

    if(flag == 3)
    {
        std::cout << "Too many invalid attempts. Returning to main menu...\n"  ;
        return;
    }

    displayAdminMenu(bank);
      
}

void userLogIn(Bank &bank)
{
    unsigned int account_id, flag =0;
    std::string password;
    Account* current = nullptr;

    while(flag < 3)
    {
        std::cout<<"Enter Account ID: ";
        if(!(std::cin>>account_id))
        {
            std::cout<<"invalid Account ID!!\n";
            bufferClear();
            flag++;
            continue;
        }
        if(account_id==0)
        {
            std::cout<<"Invalid account ID.\n";
            flag++;
            continue;
        }

        current = bank.findAccount(account_id);
        if(!current)
        {
            std::cout<<"Invalid Account ID.\n";
            flag++;
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Enter Password: ";
        std::getline(std::cin,password);

        if(password != current->getPassword())
        {
            std::cout<<"Invalid Password!\n";
            flag++;
            continue;
        }
        break;
    }

    if(flag == 3)
    {
        std::cout << "Too many invalid attempts. Returning to main menu...\n"  ;
        return;
    }

    displayUserMenu(bank,current);

}

