#ifndef _TRANSACTION_HPP_
#define _TRANSACTION_HPP_

#include <string>

/**
 * @file Transaction.hpp
 * @brief Defines the Transaction class.
 *
 * This file contains the declaration of the Transaction class,
 * which represents a banking transaction. Each transaction stores
 * information such as its unique ID, type, amount, participating
 * accounts, date, and time.
 *
 * The class also maintains a count of all active Transaction objects
 * and automatically assigns a unique transaction ID to every new
 * transaction.
 *
 * @author Sara Saad Mahmoud
 * @version 1.0
 * @date Jul 2026
 */


/**
 * @class Transaction
 * @brief Represents a banking transaction.
 *
 * A Transaction object records the details of a banking operation,
 * including its type, monetary amount, sender account, receiver
 * account (if applicable), and the date and time at which it was
 * created.
 *
 * Each transaction is assigned a unique identifier automatically.
 */
class Transaction
{
public:

    /**
     * @enum TransactionType
     * @brief Represents the supported transaction types.
     */
    enum class TransactionType
    {
        /** Money deposited into an account. */
        Deposit = 1,

        /** Money withdrawn from an account. */
        Withdraw,

        /** Money transferred between two accounts. */
        Transfer
    };


    /**
     * @brief Constructs a new Transaction object.
     *
     * Initializes the transaction with its type, amount,
     * sender account, and receiver account. A unique
     * transaction ID is assigned automatically.
     *
     * @param transaction_type Type of transaction.
     * @param amount Transaction amount.
     * @param sender_account_id Sender account ID.
     * @param receiver_account_id Receiver account ID.
     */
    Transaction(TransactionType transaction_type,
                double amount,
                unsigned int sender_account_id,
                unsigned int receiver_account_id,
                unsigned int transaction_id = 0,
                const std::string& date = "",
                const std::string& time = "");

    /**
     * @brief Destroys the Transaction object.
     */
    ~Transaction() = default;


    /**
     * @brief Gets the transaction date.
     *
     * @return Constant reference to the transaction date.
     */
    const std::string &getTransactionDate() const;


    /**
     * @brief Gets the transaction time.
     *
     * @return Constant reference to the transaction time.
     */
    const std::string &getTransactionTime() const;


    /**
     * @brief Gets the unique transaction ID.
     *
     * @return Transaction identification number.
     */
    unsigned int getTransactionID() const;


    /**
     * @brief Gets the transaction type.
     *
     * @return Transaction type.
     */
    TransactionType getTransactionType() const;


    /**
     * @brief Gets the sender account ID.
     *
     * @return Sender account identifier.
     */
    unsigned int getTransactionSenderAccountID() const;


    /**
     * @brief Gets the receiver account ID.
     *
     * @return Receiver account identifier.
     */
    unsigned int getTransactionReceiverAccountID() const;


    /**
     * @brief Gets the transaction amount.
     *
     * @return Amount involved in the transaction.
     */
    double getTransactionAmount() const;


    /**
     * @brief Displays the transaction information.
     *
     * Prints all available transaction details in a
     * human-readable format.
     */
    void displayTransaction() const;


    /**
     * @brief Gets the number of active transactions.
     *
     * @return Number of existing Transaction objects.
     */
    static unsigned int getTransactionCount();

    /**
        * @brief Sets the next available transaction ID.
        *
        * Updates the internal transaction ID counter so that newly
        * created transactions receive unique identifiers. This is
        * typically used after loading existing transactions from
        * persistent storage.
        *
        * @param maxID The highest transaction ID currently in use.
    */
    static void setNextTransactionID(unsigned int maxID);

private:

    /**
     * @brief Unique transaction identifier.
     */
    unsigned int transaction_id_;


    /**
     * @brief Type of the transaction.
     */
    TransactionType transaction_type_;


    /**
     * @brief Amount involved in the transaction.
     */
    double amount_;


    /**
     * @brief Sender account identifier.
     */
    unsigned int sender_account_id_;


    /**
     * @brief Receiver account identifier.
     *
     * This field may be unused for transaction types that
     * do not involve a receiving account.
     */
    unsigned int receiver_account_id_;


    /**
     * @brief Date on which the transaction occurred.
     */
    std::string transaction_date_;


    /**
     * @brief Time at which the transaction occurred.
     */
    std::string transaction_time_;


    /**
     * @brief Tracks the number of active Transaction objects.
     */
    static unsigned int transaction_count_;


    /**
     * @brief Stores the next available transaction ID.
     */
    static unsigned int next_transaction_id_;
};

#endif /* _TRANSACTION_HPP_ */