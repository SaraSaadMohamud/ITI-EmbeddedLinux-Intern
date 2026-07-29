#include "Admin.hpp"
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <memory>

void displayAdminMenu(Bank &bank)
{
    unsigned int choice;
    unsigned int flag = 0;
    std::cout<<"------------------------------- Bank System ------------------------------\n\n";
    std::cout<<"1. Add New Account.\n\n";
    std::cout<<"2. Remove Account.\n\n";
    std::cout<<"3. Deposit.\n\n";
    std::cout<<"4. Withdraw.\n\n";
    std::cout<<"5. Transfer.\n\n";
    std::cout<<"6. Display Account Transactions\n\n";

    std::cout<<"7. Display All Accounts.\n\n";
    std::cout<<"8. Display Bank Infromation\n\n";
    std::cout<<"9. Display Bank Transaction\n\n";
    std::cout<<"10. Display Transaction Statistics.\n\n";

    std::cout<<"11. logout.\n\n";
    std::cout<<"0. Exit.\n\n";

    do
    {
        if(!(std::cin>>choice))
        {
            std::cout<<"invalid Input!!\n";
            bufferClear();
            flag++;
        }
        if(choice < 0)
        {
            std::cout<<"invalid Input!!\n";
            flag++;
        }
    }while(flag<3);

    switch(choice)
    {
        case 1:
            addNewAccount(bank);
        break;

        case 2:
        bank.removeAccount();
        break;

        case 3:
            bank.deposit();
        break;

        case 4:
        bank.withdraw();
        break;

        case 5:
        bank.transfer();
        break;

        case 6:
        bank.displayBankAccountTransaction();
        break;

        case 7:
        bank.displayAccounts();
        break;

        case 9:
        bank.displayBankInfo();
        break;

        case 10:
        bank.displayTransactionStatistics();
        break;

        case 11:

        break;

        case 0:
            exit(1);
        break;

        default:
        break;
    }
    
}

void bufferClear()
{
    std::cin.clear();  
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cout<<"\n------------------------------------------------------------------------------\n\n";
}

void addNewAccount(Bank& bank)
{
    Account* account = nullptr;
    unsigned int account_type;
    std::string name;
    double balance_;
    int flag = 0;

    
    std::cout<<"Name:";
    bufferClear();
    std::getline(std::cin,name);

    do{
        std::cout<<"Balance: ";
        if(!(std::cin>>balance_))
        {
            std::cout<<"invalid Input!!\n";
            bufferClear();
            flag++;
            continue;
        }
        if(balance_<=0)
        {
            std::cout<<"invalid Input!!\n";
            flag++;
        }
        
    }while(flag<3);
    if(flag == 3)
    {
        std::cout << "Too many invalid attempts. Returning to menu...\n"  ;
        return;
    } 

    flag = 0;

    do{
        std::cout<<"Account Type [1: Saving Account, 2: Checking Account]";
        if(!(std::cin>>account_type))
        {
            std::cout<<"invalid Input!!\n";
            bufferClear();
            flag++;
            continue;
        }
        if((account_type!= 1) && (account_type!= 2))
        {
            std::cout<<"invalid Input!!\n";
            flag++;
        }
        
    }while(flag<3);

    if(flag == 3)
    {
        std::cout << "Too many invalid attempts. Returning to menu...\n"  ;
        return;
    }  

    if(account_type == 1)
    {
        double interest_rate;
        flag=0;
        do{
            if(!(std::cin>>interest_rate))
            {
                std::cout<<"invalid Input!!\n";
                bufferClear();
                flag++;
            }
        }while(flag<3);

        if(flag == 3)
        {
            std::cout << "Too many invalid attempts. Returning to menu...\n"  ;
            return;
        } 
        account = new SavingsAccount(name,balance_,interest_rate);
    }
    else if(account_type == 2)
    {
        double overdraft_limit;
        flag=0;
        do{
            if(!(std::cin>>overdraft_limit))
            {
                std::cout<<"invalid Input!!\n";
                bufferClear();
                flag++;
            }
        }while(flag<3);

        if(flag == 3)
        {
            std::cout << "Too many invalid attempts. Returning to menu...\n"  ;
            return;
        } 

        account = new CheckingAccount(name,balance_,overdraft_limit);
    }

    bank.addAccount(account);
}