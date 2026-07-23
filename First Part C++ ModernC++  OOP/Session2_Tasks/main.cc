/**
 * @file main.cpp
 * @brief Simple Console ATM Banking System
 * @author Sara Saad
 * @version 1.0
 * @date 2026-07-12
 */
/*********************************************** include Part ************************************** */
#include"Atm.hpp"

/******************************************** Main-Function **************************************** */
int main()
{
    unsigned int balance = 0;

    // ====================== LOGIN PHASE ======================
    if(!logIn())
    {
        return(0);
    }
    // ====================== MAIN MENU ======================
    else
    {
        system("clear");
        mainMenue(balance);
    }
    
    return(0);
}
/**************************************************************************************************** */
