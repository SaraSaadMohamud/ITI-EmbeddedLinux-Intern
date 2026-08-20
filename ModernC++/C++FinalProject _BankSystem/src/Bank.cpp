/**
 * @file Bank.cpp
 * @brief Implements the Bank class.
 *
 * This file contains the implementation of the Bank class, which manages
 * a collection of bank accounts. It provides functionality for adding,
 * removing, searching, depositing, withdrawing, transferring funds,
 * and displaying account information.
 *
 * The Bank class owns all Account objects stored in its internal
 * collection and is responsible for releasing their allocated memory.
 *
 * @author Sara Saad Mahmoud
 * @version 1.0
 * @date Jul 2026
 */

#include "Bank.hpp"
#include <iostream>
#include <stdexcept>

Bank::Bank(const std::string &bank_name) : bank_name_(bank_name)
{
    loadAccounts();
    loadTransactions();
}

Bank::~Bank()
{
    for(Account* account : accounts_)
    {
        delete account;
    }
}

const std::string &Bank::getBankName() const
{
    return bank_name_;
}

void Bank::addAccount(Account* new_acc)
{
    if(new_acc == nullptr)
    {
        throw std::invalid_argument("Invalid input: null account pointer.");
    }
    if (findAccount(new_acc->getAccountID()) != nullptr)
    {
        throw std::invalid_argument("Account has already been added.");
    }
    accounts_.push_back(new_acc);
    saveAccount();
}

void Bank::removeAccount(unsigned int account_id)
{
    Account* copy = findAccount(account_id);

   if(copy == nullptr)
   {
    throw std::invalid_argument("Bank doesn't have this account.");
   }

   
   for(auto iterator = accounts_.begin() ; iterator != accounts_.end() ; ++iterator)
   {
    if ((*iterator )== copy)
    {
        delete (*iterator);
        accounts_.erase(iterator);
        saveAccount();
        return;
    }
   } 
}

Account* Bank::findAccount(unsigned int account_id) const
{
    for(auto account_ptr : accounts_)
    {
        if((account_ptr->getAccountID()) == account_id)
        {
            return(account_ptr);
        }
    }

    return(nullptr);
}

void Bank::deposit(double amount, unsigned int account_id)
{
    Account* target_account = findAccount(account_id);
    if(target_account == nullptr)
    {
        throw std::invalid_argument("Account not found.");
    }
    target_account->deposit(amount);

    Transaction copy_transaction(Transaction::TransactionType::Deposit,amount,0,account_id);
    addTransaction(copy_transaction);
    saveAccount();
    saveTransactions();
}

void Bank::withdraw(double amount, unsigned int account_id)
{
    Account* target_account = findAccount(account_id);
    if(target_account == nullptr)
    {
        throw std::invalid_argument("Account not found.");
    }
    target_account->withdraw(amount);

    Transaction copy_transaction(Transaction::TransactionType::Withdraw,amount,account_id, 0);
    addTransaction(copy_transaction);
    saveAccount();
    saveTransactions();
}

void Bank::transfer(double amount,
                  unsigned int account1_id,
                  unsigned int account2_id)
{
    Account* sender_account = findAccount(account1_id);
    Account* receiver_account = findAccount(account2_id);

    if(!sender_account)
    {
        throw std::invalid_argument("Sender Account not found.");
    }
    if (!receiver_account)
    {
        throw std::invalid_argument("Receiver Account not found.");
    }

    if(sender_account == receiver_account)
    {
        throw std::invalid_argument("You can't Transfer to the same account.");
    }

    sender_account->withdraw(amount);
    receiver_account->deposit(amount);

    Transaction copy_transaction(Transaction::TransactionType::Transfer,amount,account1_id,account2_id);
    addTransaction(copy_transaction);
    saveAccount(); 
    saveTransactions();
}

unsigned int Bank::getAccountsCount() const
{
    return accounts_.size();
}

void Bank::addTransaction(const Transaction & obj)
{
    transactions_.push_back(obj);
}

void Bank::displayAccounts() const
{
    if(accounts_.empty())
    {
        std::cout<<"No Accounts Yes!\n";
        return;
    }

    for(auto iterator : accounts_)
    {
        iterator->displayAccountInfo();
    }
}

void Bank::displayBankAccountTransaction(unsigned int account_id) const
{
    Account * target_account = findAccount(account_id);
    bool flag = false;
    if(target_account == nullptr)
    {
        throw std::invalid_argument("Account not found.");
    }

    for(const auto &transaction : transactions_)
    {
        if( (transaction.getTransactionReceiverAccountID() == account_id)|| 
            (transaction.getTransactionSenderAccountID()   == account_id) )
        {
            transaction.displayTransaction();
            flag = true;
        }
    }

    if(!flag)
    {
        std::cout<<"No Transaction for this Account Yet!\n"<<std::endl;
    }
}
    

void Bank::displayTransactions() const
{
    if(transactions_.empty())
    {
        std::cout<<"No Transactions Yet!.\n";
        return;
    }
    for(const auto &count : transactions_)
    {
        count.displayTransaction();
    }
}

void Bank::displayTransactionStatistics() const
{
    unsigned int deposit = 0, withdraw = 0, transfer = 0;
     if(transactions_.empty())
    {
        std::cout<<"No Transactions Yet!.\n";
        return;
    }

    for(const auto &transaction : transactions_)
    {
        if(transaction.getTransactionType() == Transaction::TransactionType::Deposit)
        {
            ++deposit;
        }
        else if(transaction.getTransactionType() == Transaction::TransactionType::Withdraw)
        {
            ++withdraw;
        }
        else if(transaction.getTransactionType() == Transaction::TransactionType::Transfer)
        {
            ++transfer;
        }
    }

    std::cout << "------------ Transaction Statistics ------------\n";
    std::cout<<"Total Deposit       : "<<deposit                <<std::endl;
    std::cout<<"Total Withdraw      : "<<withdraw               <<std::endl;
    std::cout<<"Total Transfer      : "<<transfer               <<std::endl;
    std::cout<<"Total Transaction   : "<<transactions_.size()   <<std::endl;
}

void Bank::displayBankInfo()const 
{
    std::cout<<"----------- Bank Information -------------\n";
    std::cout<<"Name            : "<<bank_name_             <<std::endl;
    std::cout<<"Accounts        : "<<accounts_.size()       <<std::endl;
    std::cout<<"Transactions    : "<<transactions_.size()   <<std::endl;
}

void Bank::saveAccount() const
{
    std::ofstream file("data/accounts.txt");
    if(!file)
    {
        throw std::runtime_error("Can't open account file.\n");
    }

    for(const auto &account : accounts_)
    {
        
        if(auto saving = dynamic_cast<SavingsAccount*>(account))
        {
            file
            <<saving->getAccountID()<<","
            <<saving->getAccountOwnerName()<<"," 
            <<saving->getPassword()<<","
            <<"Savings,"
            <<saving->getAccountBalance()<<","
            <<saving->getInterestRate()<<"\n";
        }
        else if (auto checking = dynamic_cast<CheckingAccount*>(account))
        {
            file
            <<checking->getAccountID()<<","
            <<checking->getAccountOwnerName()<<","
            <<checking->getPassword()<<","
            <<"Checking,"
            <<checking->getAccountBalance()<<","
            <<checking->getOverdraftLimit()<<"\n";
        }
    }
}

void Bank::loadAccounts()
{
    std::ifstream file("data/accounts.txt");
    unsigned int maxid = 0;
    if(!file)
    {
        return;
    }

    std::string line;
    while(std::getline(file,line))
    {
        if(line.empty())
        {
            continue;
        }
        std::stringstream ss(line);
        std::string idStr;
        std::string name;
        std::string password;
        std::string type;
        std::string balanceStr;
        std::string extraStr;

        std::getline(ss, idStr, ',');
        std::getline(ss, name, ',');
        std::getline(ss, password, ',');
        std::getline(ss, type, ',');
        std::getline(ss, balanceStr, ',');
        std::getline(ss, extraStr, ',');

        unsigned int id = std::stoul(idStr);
        double balance = std::stod(balanceStr);
        double extra = std::stod(extraStr);

        if(id > maxid)
        {
            maxid = id;
        }

        if(type == "Savings")
        {
            accounts_.push_back(
                new SavingsAccount(
                    name,
                    balance,
                    password,
                    extra,
                    id
                )   
            );
        }

        else if(type == "Checking")
        {
            accounts_.push_back(
                new CheckingAccount(
                    name,
                    balance,
                    password,
                    extra,
                    id
                )
            );
        }

    }

    Account::setNextAccountID(maxid);
}

void Bank::saveTransactions() const 
{
    std::ofstream file("data/transactions.txt");
    if(!file)
    {
        throw std::runtime_error("Can't open transaction file.\n");
    }

    for(const auto &transaction : transactions_)
    {
        if(transaction.getTransactionType() == Transaction::TransactionType::Deposit){
            file
            <<transaction.getTransactionID()<<","
            <<"Deposit,"
            <<transaction.getTransactionAmount()<<","
            <<transaction.getTransactionDate()<<","
            <<transaction.getTransactionTime()<<","
            <<transaction.getTransactionSenderAccountID()<<","
            <<transaction.getTransactionReceiverAccountID()<<"\n" ;   
        }
        else if(transaction.getTransactionType() == Transaction::TransactionType::Withdraw)
        {
            file
            <<transaction.getTransactionID()<<","
            <<"Withdraw,"
            <<transaction.getTransactionAmount()<<","
            <<transaction.getTransactionDate()<<","
            <<transaction.getTransactionTime()<<","
            <<transaction.getTransactionSenderAccountID()<<","
            <<transaction.getTransactionReceiverAccountID()<<"\n" ;  
        }
        else if(transaction.getTransactionType() == Transaction::TransactionType::Transfer)
        {
            file
            <<transaction.getTransactionID()<<","
            <<"Transfer,"
            <<transaction.getTransactionAmount()<<","
            <<transaction.getTransactionDate()<<","
            <<transaction.getTransactionTime()<<","
            <<transaction.getTransactionSenderAccountID()<<","
            <<transaction.getTransactionReceiverAccountID()<<"\n" ;  
        }
    }
}

void Bank::loadTransactions()
{
    std::ifstream file("data/transactions.txt");

    if (!file)
    {
        return;
    }

    unsigned int maxID = 0;
    std::string line;

    while (std::getline(file, line))
    {
        if(line.empty())
            continue;
        std::stringstream ss(line);

        std::string idStr;
        std::string typeStr;
        std::string amountStr;
        std::string date;
        std::string time;
        std::string senderStr;
        std::string receiverStr;

        std::getline(ss, idStr, ',');
        std::getline(ss, typeStr, ',');
        std::getline(ss, amountStr, ',');
        std::getline(ss, date, ',');
        std::getline(ss, time, ',');
        std::getline(ss, senderStr, ',');
        std::getline(ss, receiverStr, ',');

        unsigned int id = std::stoul(idStr);
        double amount = std::stod(amountStr);
        unsigned int senderID = std::stoul(senderStr);
        unsigned int receiverID = std::stoul(receiverStr);

        Transaction::TransactionType type;

        if (typeStr == "Deposit")
        {
            type = Transaction::TransactionType::Deposit;
        }
        else if (typeStr == "Withdraw")
        {
            type = Transaction::TransactionType::Withdraw;
        }
        else if (typeStr == "Transfer")
        {
            type = Transaction::TransactionType::Transfer;
        }
        else
        {
            continue;
        }

        transactions_.emplace_back(
            type,
            amount,
            senderID,
            receiverID,
            id,
            date,
            time
        );

        if (id > maxID)
        {
            maxID = id;
        }
    }

    Transaction::setNextTransactionID(maxID);
}