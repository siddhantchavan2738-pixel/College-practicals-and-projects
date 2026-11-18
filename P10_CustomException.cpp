// Practical 10
// Title: Create a Custom Exception Hierarchy.
// Write a program that throws and catches specific
// exceptions for a banking transaction scenario.


#include <iostream>
#include <exception>
#include <string>
using namespace std;

// Base custom exception
class BankingException : public exception
{
protected:
    string message;

public:
    BankingException(string msg) : message(msg) {}

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

// Insufficient balance exception
class InsufficientBalance : public BankingException
{
public:
    InsufficientBalance()
        : BankingException("Insufficient balance!") {}
};

// Invalid amount exception
class InvalidAmount : public BankingException
{
public:
    InvalidAmount()
        : BankingException("Invalid transaction amount!") {}
};

// Bank account class
class BankAccount
{
private:
    double balance;

public:
    BankAccount(double amount)
    {
        balance = amount;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
            throw InvalidAmount();

        if (amount > balance)
            throw InsufficientBalance();

        balance -= amount;
        cout << "Withdrawal successful!" << endl;
        cout << "Remaining Balance: " << balance << endl;
    }

    void displayBalance()
    {
        cout << "Current Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount account(5000);

    account.displayBalance();

    try
    {
        account.withdraw(2000);
        account.withdraw(6000);
    }
    catch (const InsufficientBalance &e)
    {
        cout << "Banking Error: " << e.what() << endl;
    }
    catch (const InvalidAmount &e)
    {
        cout << "Banking Error: " << e.what() << endl;
    }
    catch (const BankingException &e)
    {
        cout << "Banking Error: " << e.what() << endl;
    }

    return 0;
}
