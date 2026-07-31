#ifndef _CHECKING_ACCOUNT_HPP_
#define _CHECKING_ACCOUNT_HPP_
/**
    * @file CheckingAccount.hpp
    * @brief Defines the CheckingAccount class.
    *
    * This file contains the declaration of the CheckingAccount class,
    * which inherits from the Account class and provides checking
    * account-specific functionality such as overdraft protection.
    *
    * Checking accounts support:
    * - Overdraft limit management
    * - Checking account-specific withdrawal rules
    * - Customized account information display
    * - Tracking the number of active checking accounts
    *
    * @author Sara Saad Mahmoud
    * @version 1.0
    * @date Jul 2026
 */

#include "Account.hpp"

class CheckingAccount : public Account
{
    public:
    /**
        * @class CheckingAccount
        * @brief Represents a checking bank account.
        *
        * The CheckingAccount class extends the Account class by allowing
        * withdrawals that may exceed the available balance, provided the
        * overdraft limit is not exceeded.
        *
        * It overrides the withdrawal and account information display
        * functions to implement checking account behavior.
    */
    CheckingAccount(const std::string &name,
            double balance,
            const std::string &password,
            double overdraft_limit,
            unsigned int account_id = 0);

    /**
     * @brief Destroys the CheckingAccount object.
    */
    ~CheckingAccount() override;

    /**
     * @brief Displays complete checking account information.
     *
     * Overrides the base Account implementation to include
     * the account's overdraft limit.
    */
    void displayAccountInfo() const override;


    /**
     * @brief Withdraws money from the checking account.
     *
     * Allows withdrawals according to the checking account's
     * overdraft policy.
     *
     * @param amount Amount to withdraw.
    */
    void withdraw(double amount) override;


    /**
     * @brief Gets the account's overdraft limit.
     *
     * @return The maximum overdraft amount allowed.
    */
    double getOverdraftLimit() const;

    /**
     * @brief Gets the number of active checking accounts.
     *
     * @return Number of existing CheckingAccount objects.
    */
    static unsigned int getCheckingAccountCount() ;

    private:
    /**
     * @brief Maximum overdraft amount permitted for the account.
    */
    double overdraft_limit_;

    /**
     * @brief Tracks the number of active checking accounts.
     */
    static unsigned int checking_account_count_;
};

#endif /* _CHECKING_ACCOUNT_HPP_ */