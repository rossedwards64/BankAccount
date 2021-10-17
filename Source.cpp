#include <iostream>
#include <string>
#include "CurrentAccount.h"
#include "LoanAccount.h"
#include "SavingsAccount.h"

using namespace std;

// old-school way of declaring constants – you should be using const int MENU_EXIT=0; but these are here to show you #defines as you will likely come across them in many places
#define MENU_EXIT           0
#define MENU_VIEW_SUMMARY   1
#define MENU_DEPOSIT        2
#define MENU_WITHDRAW       3
#define MENU_SELECT_ACCOUNT 4

// index of each account type type within our array
#define CURRENT_ACCOUNT     0
#define SAVINGS_ACCOUNT     1
#define LOAN_ACCOUNT        2
#define NOOFACCOUNTS        3

#define FIRST_MENU_ITEM     MENU_EXIT
#define LAST_MENU_ITEM      MENU_SELECT_ACCOUNT

void displayMenu();
int getMenuChoice();
int selectAccount();
void deposit(BankAccount& account);
void withdraw(BankAccount& account);

int main()
{
    // Create an array of pointers to store each account using polymorphism
    BankAccount* accounts[NOOFACCOUNTS] =
    {
      new CurrentAccount(101, "Current Account", 200),
      new SavingsAccount(201, "Savings", 400),
      new LoanAccount(301, "Loan", 5000)
    };

    int choice;

    // the current account is selected by default
    BankAccount* selaccount = accounts[CURRENT_ACCOUNT];

    do
    {
        displayMenu();
        choice = getMenuChoice();

        switch (choice)
        {
        case MENU_VIEW_SUMMARY: selaccount->printSummary(); break;
        case MENU_DEPOSIT: deposit(*selaccount); break;
        case MENU_WITHDRAW: withdraw(*selaccount); break;
        case MENU_SELECT_ACCOUNT: selaccount = accounts[selectAccount()]; break;
        }

    } while (choice != MENU_EXIT);

    for (int i = 0; i < NOOFACCOUNTS; i++)
        delete accounts[i];

    // no need to delete the accounts array of pointers because that is on the stack

    return 0;
}

void displayMenu()
{
    cout << "\nBank Account Manager\n";
    cout << "====================\n";
    cout << MENU_VIEW_SUMMARY << ") View Account Summary\n";
    cout << MENU_DEPOSIT << ") Make deposit\n";
    cout << MENU_WITHDRAW << ") Make withdraw\n";
    cout << MENU_SELECT_ACCOUNT << ") Select Account\n";
    cout << MENU_EXIT << ") Exit\n";
}

int getMenuChoice()
{
    int choice;
    cout << "Choose option: ";
    cin >> choice;
    while (choice<FIRST_MENU_ITEM || choice>LAST_MENU_ITEM)
    {
        cout << "Invalid option.  Choose option: ";
        cin >> choice;
    }
    return choice;
}

int selectAccount()
{
    cout << "\nAccount Options\n";
    cout << "====================\n";
    cout << CURRENT_ACCOUNT << ") Current Account\n";
    cout << SAVINGS_ACCOUNT << ") Savings Account\n";
    cout << LOAN_ACCOUNT << ") Loan Account\n";

    int choice;
    cout << "Select account: ";
    cin >> choice;
    while (choice<CURRENT_ACCOUNT || choice>LOAN_ACCOUNT)
    {
        cout << "Invalid account.  Select account: ";
        cin >> choice;
    }
    return choice;
}

void deposit(BankAccount& account)
{
    double amount;
    cout << "\nMake a deposit\n";
    cout << "--------------\n";
    cout << "Enter amount to deposit \x9C";
    cin >> amount;

    if (!account.deposit((int)(amount * 100)))
        cout << "\n** Cannot deposit further funds into account **\n";
}

void withdraw(BankAccount& account)
{
    double amount;
    cout << "\nWithdraw funds\n";
    cout << "--------------\n";
    cout << "Enter amount to withdraw \x9C";
    cin >> amount;

    if (!account.withdraw((int)(amount * 100)))
        cout << "\n** Not enough funds to withdraw requested amount **\n";
}