/**
 * @file Atm.cpp
 * @brief Implementation file for the Console ATM Banking System
 * @author Sara Saad
 * @version 1.0
 * @date 2026-07-12
 */

/*********************************************** include Part ************************************** */
#include "Atm.hpp"

/**************************************** Function Definiation ***************************************/

bool logIn(void)
{
    unsigned int attempts=0;
    unsigned int pass;

    do
    {
        std::cout<<"Enter the 4-digit password: ";
        if(!(std::cin>>pass))
        {
            std::cout<<"Invalid Password!!\n";
            clearError();
            attempts++;
            if (attempts>=3)
            {
                std::cout<<"You’ve reached the limit for attempts. Please try again later!!\n";
                return(0);
            }
        }
        else if(pass!= VALID_PASS)
        {
            std::cout<<"Invalid Password!!\n";
            attempts++;
            if (attempts>=3)
            {
                std::cout<<"You’ve reached the limit for attempts. Please try again later!!\n";
                return(0);
            }
        }
        else{
            break;
        }

    }while(true);
    return(1);
}
    
/***********************************************************************************************************/
void mainMenue(unsigned int &balance)
{
    unsigned int choice;

    do
    {
        std::cout<<"Welcome Again!!, Select a service: "<<std::endl;
        std::cout<<"1. Withdraw\n";
        std::cout<<"2. Deposit\n";
        std::cout<<"3. Check Balance\n";
        std::cout<<"4. Exit\n";
        std::cout<<"Enter Number of Service: ";

        if(!(std::cin>>choice))
        {
            std::cout<<"Invalid choice!!\n";
            clearError();
            continue;
        }

        unsigned int value = 0;
        switch(choice)
        {
            case 1:
                std::cout<<"Enter the withdrawal amount: ";
                if(!(std::cin>>value))
                {
                    std::cout<<"Invalid value!!\n";
                    clearError();
                    continue;
                }
                std::cout<<"\n";
                withdraw(balance,value);
                break;
            case 2:
                std::cout<<"Enter the deposit amount: ";
                if(!(std::cin>>value))
                {
                    std::cout<<"Invalid value!!\n";
                    clearError();
                    continue;
                }
                std::cout<<"\n";
                deposit(balance,value);
                break;
            case 3:
                std::cout<<"\n";
                std::cout<<"Available balance: [ "<<checkBalance(balance)<<" EGP]\n";
                std::cout<<"\n------------------------------------------------------------------------------\n\n";
                break;
            case 4:
                std::cout<<"\n";
                std::cout<<"Thank you for choosing our services.\n\n";
                exit(0);
            default:
                std::cout<<"\n";
                std::cout<<"Invalid Choice!!!\n";
                break;
        }
    
    }while(true);
}
/***********************************************************************************************************/
void withdraw(unsigned int &balance, unsigned int value)
{
    if(balance < value)
    {
        std::cout<<"The account balance is insufficient for this transaction!.\n";
    }
    else if(value > MAX_VALID_TRANSFER )
    {
        std::cout<<"It is not permitted to withdraw the stated amount in a single transaction\n";
    }
    else if (value < MIN_VALID_TRANSFER)
    {
        std::cout<<"The requested withdrawal amount is below the minimum limit!!\n";
    }
    else
    {
        balance -= value;
        std::cout<<"The withdrawal was successful!\n";
    }
    std::cout<<"------------------------------------------------------------------------------\n\n";

}
/*********************************************************************************************************** */

void deposit(unsigned int &balance, unsigned int value)
{
    if(value > MAX_VALID_TRANSFER )
    {
        std::cout<<"It is not permitted to deposit the stated amount in a single transaction\n";
    }
    else if (value < MIN_VALID_TRANSFER )
    {
        std::cout<<"The requested deposit amount is below the minimum limit!!\n";
    }
    else
    {
        balance += value;
        std::cout<<"The Deposit was successful!\n";
    }
    std::cout<<"------------------------------------------------------------------------------\n\n";
}
/*********************************************************************************************************** */

unsigned int checkBalance(const unsigned int &balance)
{
    return(balance);
}
/*********************************************************************************************************** */

void clearError(void)
{

    std::cin.clear();  
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cout<<"\n------------------------------------------------------------------------------\n\n";

}
/*********************************************************************************************************** */
