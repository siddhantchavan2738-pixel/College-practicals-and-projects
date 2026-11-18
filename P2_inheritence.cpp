// Practical 2
// Title: Design and implement a class hierarchy
// for Bank Account. Demonstrate access specifiers
// and member functions.


#include <iostream>
using namespace std;

// Base Class
class BankAccount
{
private:
    double balance;

protected:
    string accountHolder;

public:
    int accountNumber;

    BankAccount(string name, int accNo, double bal)
    {
        accountHolder = name;
        accountNumber = accNo;
        balance = bal;
    }

    void displayDetails()
    {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    double getBalance()
    {
        return balance;
    }
};

// Derived Class
class SavingsAccount : public BankAccount
{
public:
    SavingsAccount(string name, int accNo, double bal)
        : BankAccount(name, accNo, bal)
    {
    }

    void displayAccountType()
    {
        cout << "Account Type: Savings Account" << endl;
        cout << "Holder Name: " << accountHolder << endl;
    }
};

// Main Function
int main()
{
    SavingsAccount s1("Rahul", 101, 5000);

    cout << "--- Bank Account Details ---" << endl;

    s1.displayDetails();
    s1.displayAccountType();

    cout << "Accessing Public Member: "
         << s1.accountNumber << endl;

    cout << "Accessing Private Member through Getter: "
         << s1.getBalance() << endl;

    return 0;
}
