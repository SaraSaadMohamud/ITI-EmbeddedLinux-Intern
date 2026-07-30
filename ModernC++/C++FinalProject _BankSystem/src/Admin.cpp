#include "Admin.hpp"
#include "SavingsAccount.hpp"
#include "CheckingAccount.hpp"
#include <iostream>
#include <limits>
#include <string>


void displayAdminMenu(Bank &bank)
{
    unsigned int choice;
    unsigned int flag = 0;

    while(true)
    {
        flag=0;
        do{
            std::cout<<"Enter your Choice: ";
            if(!(std::cin>>choice))
            {
                std::cout<<"invalid Input!!\n";
                bufferClear();
                flag++;
                continue;
            }
            if(choice < 1 || choice > 11)
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
                addNewAccount(bank);
            break;
            case 2:
                removeAccount(bank);
            break;
            case 3:
                deposit(bank);
            break;

            case 4:
                withdraw(bank);
            break;

            case 5:
                transfer(bank);
            break;

            case 6:
                displayAccountTransaction(bank);
            break;

            case 7:
            bank.displayAccounts();
            break;

            case 8:
            bank.displayBankInfo();
            break;

            case 9:
                bank.displayTransactions();
                break;
                
            case 10:
            bank.displayTransactionStatistics();
            break;

            case 11:
                return;
            break;

            case 0:
                exit(1);
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

void addNewAccount(Bank& bank)
{
    Account* account = nullptr;
    unsigned int account_type;
    std::string name;
    double balance;
    int flag = 0;
    
    std::cout<<"Name:";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::getline(std::cin,name);

    do{
        std::cout<<"Balance: ";
        if(!(std::cin>>balance))
        {
            std::cout<<"invalid Input!!\n";
            bufferClear();
            flag++;
            continue;
        }
        if(balance<=0)
        {
            std::cout<<"invalid Input!!\n";
            flag++;
        }
        else{
            break;
        }
        
    }while(flag<3);
    if(flag == 3)
    {
        std::cout << "Too many invalid attempts. Returning to menu...\n"  ;
        return;
    } 

    ///////////////////////////////////////////////////////////////////////////
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
        else
        {
            break;
        }
        
    }while(flag<3);

    if(flag == 3)
    {
        std::cout << "Too many invalid attempts. Returning to menu...\n"  ;
        return;
    }  
    ///////////////////////////////////////////////////////////////////////////

    if(account_type == 1)
    {
        double interest_rate;
        flag=0;
        do{
            std::cout << "Interest Rate: ";
            if(!(std::cin>>interest_rate))
            {
                std::cout<<"invalid Input!!\n";
                bufferClear();
                flag++;
            }
            else{
                break;
            }
        }while(flag<3);

        if(flag == 3)
        {
            std::cout << "Too many invalid attempts. Returning to menu...\n"  ;
            return;
        } 
        try
        {                
            account = new SavingsAccount(name,balance,interest_rate);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
            return;
        }
    }
    ///////////////////////////////////////////////////////////////////////////
    else if(account_type == 2)
    {
        double overdraft_limit;
        flag=0;
        do{
            std::cout << "Overdraft Limit: ";
            if(!(std::cin>>overdraft_limit))
            {
                std::cout<<"invalid Input!!\n";
                bufferClear();
                flag++;
            }
            else
            {
                break;
            }
        }while(flag<3);

        if(flag == 3)
        {
            std::cout << "Too many invalid attempts. Returning to menu...\n"  ;
            return;
        } 

        try
        {
            account = new CheckingAccount(name,balance,overdraft_limit);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
            return;
        }
    }
    ///////////////////////////////////////////////////////////////////////////

    try
    {  
        bank.addAccount(account);
        std::cout << "Account created successfully.\n";
        std::cout<<"Account ID: "<<account->getAccountID()<<std::endl;
    }
    catch(const std::exception& e)
    {
        delete account;
        std::cout << e.what() << '\n';
    }
    ///////////////////////////////////////////////////////////////////////////
}

void removeAccount(Bank &bank)
{
    unsigned int account_id, flag = 0;
    do{
        std::cout<<"Enter Account ID: ";
        if(!(std::cin>>account_id))
        {
            std::cout<<"invalid Input!!\n";
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
        break;
        
    }while(flag<3);

    if(flag == 3)
    {
        std::cout << "Too many invalid attempts. Returning to menu...\n"  ;
        return;
    } 
    ///////////////////////////////////////////////////////////////////////////
    try
    {  
        bank.removeAccount(account_id);
        std::cout<<"Account removed successfully.\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}

void deposit(Bank &bank)
{
    double amount;
    unsigned int account_id;
    int flag = 0;

    do{
        std::cout<<"Enter Account ID: ";
        if(!(std::cin>>account_id))
        {
            std::cout<<"invalid Input!!\n";
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
        break;
        
    }while(flag<3);

    if(flag == 3)
    {
        std::cout << "Too many invalid attempts. Returning to menu...\n"  ;
        return;
    } 

    flag=0;
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
        bank.deposit(amount,account_id);
        std::cout << "Deposit completed successfully.\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

}

void withdraw(Bank &bank)
{

    double amount;
    unsigned int account_id;
    int flag = 0;

    do{
        std::cout<<"Enter Account ID: ";
        if(!(std::cin>>account_id))
        {
            std::cout<<"invalid Input!!\n";
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
        break;
        
    }while(flag<3);

    if(flag == 3)
    {
        std::cout << "Too many invalid attempts. Returning to menu...\n"  ;
        return;
    } 

    flag=0;
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
        bank.withdraw(amount,account_id);
        std::cout << "Withdraw completed successfully.\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}

void transfer(Bank &bank)
{
    double amount;
    unsigned int sender_account_id, receiver_account_id, flag = 0;

    do{
        std::cout<<"Enter Sender Account ID: ";
        if(!(std::cin>>sender_account_id))
        {
            std::cout<<"invalid Input!!\n";
            bufferClear();
            flag++;
            continue;
        }
        if(sender_account_id==0)
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

    flag=0;
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
        bank.transfer(amount,sender_account_id,receiver_account_id);
        std::cout << "Transfer completed successfully.\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}

void displayBankAccountTransaction(Bank &bank)
{
    unsigned int account_id;
    int flag = 0;

    do{
        std::cout<<"Enter Account ID: ";
        if(!(std::cin>>account_id))
        {
            std::cout<<"invalid Input!!\n";
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
        break;
        
    }while(flag<3);

    if(flag == 3)
    {
        std::cout << "Too many invalid attempts. Returning to menu...\n"  ;
        return;
    } 

    try
    {  
        bank.displayBankAccountTransaction(account_id);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}