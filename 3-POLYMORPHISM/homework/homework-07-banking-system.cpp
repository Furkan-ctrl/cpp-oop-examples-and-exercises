#include <iostream>
#include <string>

using namespace std;

/*
    Exercise: Implement a Banking System

    In this exercise, you will create a basic banking system with the following classes:

    1. Account (Base Class):
        Create a base class called Account with the following attributes and methods:
        - accountNumber (integer)
        - balance (double)
        - Account(const int accountNumber, const double balance) constructor.
        - A virtual destructor for proper resource cleanup.
        - virtual void deposit(double amount) method to deposit funds into the account.
        - virtual void withdraw(double amount) method to withdraw funds from the account.
        - virtual void displayBalance() method to display the current balance.

    2. SavingsAccount (Derived Class):
        Create a derived class called SavingsAccount that inherits from Account. This class should include:
         - A constructor that takes an account number, initial balance, and an interest rate (e.g., 3%).
         - An overridden displayBalance() method that displays the current balance along with the interest rate.
         - An overridden withdraw() method that checks if the withdrawal amount is less than the balance and, if so, 
           processes the withdrawal. If the withdrawal amount exceeds the balance, display an error message.
    3.  CheckingAccount (Derived Class):
         - Create another derived class called CheckingAccount that inherits from Account. This class should include:
         - A constructor that takes an account number and initial balance.
         - An overridden displayBalance() method that displays the current balance along with a message indicating it's a checking account.
         - An overridden withdraw() method that checks if the withdrawal amount is less than the balance and, if so, 
           processes the withdrawal. If the withdrawal amount exceeds the balance, display an error message.
    4. Main Function:
        - In the main() function, create instances of both SavingsAccount and CheckingAccount. 
        - Deposit and withdraw funds from these accounts, and display their balances to demonstrate polymorphism.
    
    5. Proper Cleanup:
     - Make sure to delete the account objects at the end of the main() function to ensure that their destructors are called.
*/


class Account {
protected:
    int accountNumber;
    double balance;

public:
    Account(const int accNum, const double bal) : accountNumber(accNum), balance(bal) {}
    
    virtual ~Account() {
        cout << "Account #" << accountNumber << " destroyed." << endl;
    }
    
    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " into Account #" << accountNumber << endl;
        }
    }
    
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }
    
    virtual void displayBalance() {
        cout << "Account #" << accountNumber << " Balance: $" << balance << endl;
    }
};


class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const int accNum, const double bal, const double rate) 
        : Account(accNum, bal), interestRate(rate) {}

    void displayBalance() override {
        cout << "Savings Account #" << accountNumber 
             << " | Balance: $" << balance 
             << " | Interest Rate: " << interestRate << "%" << endl;
    }

    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Error: Insufficient funds in Savings Account #" << accountNumber 
                 << ", Cannot withdraw $" << amount << endl;
        } else if (amount > 0) {
            balance -= amount;
            cout << "Withdrew $" << amount << " from Savings Account #" << accountNumber << endl;
        }
    }
};


class CheckingAccount : public Account {
public:
    CheckingAccount(const int accNum, const double bal) : Account(accNum, bal) {}

    void displayBalance() override {
        cout << "Checking Account #" << accountNumber 
             << " | Balance: $" << balance << endl;
    }

    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Error: Insufficient funds in Checking Account #" << accountNumber 
                 << ", Cannot withdraw $" << amount << endl;
        } else if (amount > 0) {
            balance -= amount;
            cout << "Withdrew $" << amount << " from Checking Account #" << accountNumber << endl;
        }
    }
};

int main() {
    // Create instances of SavingsAccount and CheckingAccount
    // Deposit and withdraw funds, display balances
    // Properly clean up objects

    /*
        Erase: 

        // Create SavingsAccount and CheckingAccount instances
        Account* savings = new SavingsAccount(1001, 1000.0, 3.0); // Account Number, Initial Balance, Interest Rate
        Account* checking = new CheckingAccount(2001, 2000.0);     // Account Number, Initial Balance

        // Deposit and withdraw funds from accounts
        

        // Display balances using polymorphism
        

        // Properly clean up objects
        
    */

    Account* savings = new SavingsAccount(1001, 1000.0, 3.0); // Account Number, Initial Balance, Interest Rate
    Account* checking = new CheckingAccount(2001, 2000.0);    // Account Number, Initial Balance

    cout << "--- Initial Balances ---" << endl;
    savings->displayBalance();
    checking->displayBalance();
    cout << endl;

    cout << "--- Transactions ---" << endl;
    savings->deposit(500.0);
    checking->withdraw(500.0);
    
    savings->withdraw(2000.0); 
    cout << endl;

    cout << "--- Final Status ---" << endl;
    savings->displayBalance();
    checking->displayBalance();
    cout << endl;

    cout << "--- Cleaning up resources ---" << endl;
    delete savings;
    delete checking;


    return 0;
}
