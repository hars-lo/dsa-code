#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;

    // Static variable to keep track of total accounts
    static int totalAccounts;
    // Static vector to store all bank accounts
    static vector<BankAccount> accounts;

public:
    // Constructor to initialize account with number and balance
    BankAccount(int accountNumber, double initialBalance) : accountNumber(accountNumber), balance(initialBalance) {
        totalAccounts++;
        accounts.push_back(*this);  // Add the new account to the vector
    }

    // Static function to deposit an amount into a specific account
    static void deposit(int accountNumber, double amount) {
        for (auto& account : accounts) {
            if (account.accountNumber == accountNumber) {
                account.balance += amount;
                cout << "Deposited " << amount << " to account " << accountNumber << ". New balance: " << account.balance << endl;
                return;
            }
        }
        cout << "Account number " << accountNumber << " not found." << endl;
    }

    // Static function to withdraw an amount from a specific account
    static void withdraw(int accountNumber, double amount) {
        for (auto& account : accounts) {
            if (account.accountNumber == accountNumber) {
                if (account.balance >= amount) {
                    account.balance -= amount;
                    cout << "Withdrew " << amount << " from account " << accountNumber << ". New balance: " << account.balance << endl;
                } else {
                    cout << "Insufficient funds in account " << accountNumber << ". Current balance: " << account.balance << endl;
                }
                return;
            }
        }
        cout << "Account number " << accountNumber << " not found." << endl;
    }

    // Static function to display all accounts
    static void displayAccounts() {
        cout << "\nAccount Details:" << endl;
        for (const auto& account : accounts) {
            cout << "Account Number: " << account.accountNumber << ", Balance: " << account.balance << endl;
        }
        cout << "Total number of accounts created: " << totalAccounts << endl;
    }
};

// Initialize static variables
int BankAccount::totalAccounts = 0;
vector<BankAccount> BankAccount::accounts;

// Main function to demonstrate the usage of BankAccount class
int main() {
    // Creating bank accounts
    BankAccount acc1(101, 500.0);
    BankAccount acc2(102, 1000.0);
    BankAccount acc3(103, 1500.0);

    // Performing transactions
    BankAccount::deposit(101, 200.0);
    BankAccount::withdraw(102, 500.0);
    BankAccount::withdraw(103, 2000.0);  // Insufficient funds scenario

    // Display all accounts
    BankAccount::displayAccounts();

    return 0;
}
