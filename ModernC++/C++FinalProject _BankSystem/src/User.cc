#include "User.hpp"
#include <iostream>
#include <limits>

void displayUserMenu(Bank& bank, Account* current_user)
{
    int choice = 0,flag = 0;

    while(true)
    {
        flag = 0;
        std::cout<<"\n------------------- User Menu ---------------------\n";
        std::cout<<"1. Deposit.\n";
        std::cout<<"2. Withdraw.\n";
        std::cout<<"3. Transfer.\n";
        std::cout<<"4. Display My Account.\n";
        std::cout<<"5. Display My Acoount Transaction\n";
        std::cout<<"6. LogOut.\n";
        std::cout<<"7. Exit.\n";
        std::cout<< "--------------------------------------------------------------\n";

        
        do{
            std::cout<<"Enter Your Choice: ";
            if(!(std::cin>>choice))
            {
                std::cout<<"invalid Input!!\n";
                bufferClear();
                flag++;
                continue;
            }
            if(choice < 1 || choice > 7)
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
                deposit(bank,current_user);
            break;

            case 2:
                withdraw(bank,current_user);
            break;

            case 3:
                transfer(bank,current_user);
            break;

            case 4:
                displayAccountInfo(current_user);
            break;

            case 5:
                displayAccountTransactions(bank, current_user);
            break;

            case 6:
                return;
            break;

            case 7:
                exit(0);
            break;
        }

    }

}

void bufferClear()
{
    std::cin.clear();  
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cout<<"\n------------------------------------------------------------------------------\n\n";
}

void deposit(Bank& bank, Account* current_user)
{
    double amount;
    int flag=0;
    
    do{
        std::cout<<"Enter Amount: ";
        if(!(std::cin>>amount))
        {
            std::cout<<"invalid Input!!\n";
            bufferClear();
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

    try
    {  
        bank.deposit(amount,current_user->getAccountID());
        std::cout << "Deposit completed successfully.\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}

void withdraw(Bank& bank, Account* current_user)
{
    double amount;
    int flag=0;
    
    do{
        std::cout<<"Enter Amount: ";
        if(!(std::cin>>amount))
        {
            std::cout<<"invalid Input!!\n";
            bufferClear();
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

    try
    {  
        bank.withdraw(amount,current_user->getAccountID());
        std::cout << "Withdraw completed successfully.\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}

void transfer(Bank& bank, Account* current_user)
{
    double amount;
    unsigned int receiver_account_id;
    int flag=0;
    
    do{
        std::cout<<"Enter Amount: ";
        if(!(std::cin>>amount))
        {
            std::cout<<"invalid Input!!\n";
            bufferClear();
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

    flag=0;
    do{
        std::cout<<"Enter Receiver Account ID: ";
        if(!(std::cin>>receiver_account_id))
        {
            std::cout<<"invalid Input!!\n";
            bufferClear();
            flag++;
            continue;
        }
        if(receiver_account_id==0)
        {
            std::cout<<"Invalid account ID.\n";
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

    try
    {  
        bank.transfer(amount,current_user->getAccountID(), receiver_account_id);
        std::cout << "Transfering completed successfully.\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}

void displayAccountInfo(Account* current_user)
{
    if(current_user)
        current_user->displayAccountInfo();
}

void displayAccountTransactions(Bank& bank, Account* current_user)
{
    try
    {
        bank.displayBankAccountTransaction(current_user->getAccountID());
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}