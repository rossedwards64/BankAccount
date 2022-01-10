#include <crtdbg.h>
#include <iostream>
#include "AccountFactory.h"

// old-school way of declaring constants � you should be using const int MENU_EXIT=0; but these are here to show you #defines as you will likely come across them in many places
#define MENU_EXIT           0
#define MENU_VIEW_SUMMARY   1
#define MENU_DEPOSIT        2
#define MENU_WITHDRAW       3
#define MENU_SELECT_ACCOUNT 4

// index of each account type type within our array
#define CURRENT_ACCOUNT     0
#define SAVINGS_ACCOUNT     1
#define LOAN_ACCOUNT        2

#define FIRST_MENU_ITEM     MENU_EXIT
#define LAST_MENU_ITEM      MENU_SELECT_ACCOUNT

void displayMenu();
int getMenuChoice();
int selectAccount();
void deposit(BankAccount& account);
void withdraw(BankAccount& account);

int main()
{
	#ifdef _DEBUG
	_onexit(_CrtDumpMemoryLeaks);
	#endif

    int choice = 0;

    // the current account is selected by default
    std::shared_ptr<BankAccount> selaccount = AccountFactory::getAccount(0);

    do
    {
        displayMenu();
        choice = getMenuChoice();

        switch (choice)
        {
        case MENU_VIEW_SUMMARY: selaccount->printSummary(); break;
        case MENU_DEPOSIT: deposit(*selaccount); break;
        case MENU_WITHDRAW: withdraw(*selaccount); break;
        case MENU_SELECT_ACCOUNT: selaccount = AccountFactory::getAccount(selectAccount()); break;
        }

    } while (choice != MENU_EXIT);

    // no need to delete the accounts array of pointers because that is on the stack

    return 0;
}

void displayMenu()
{
    std::cout << "\nBank Account Manager\n";
    std::cout << "====================\n";
    std::cout << MENU_VIEW_SUMMARY << ") View Account Summary\n";
    std::cout << MENU_DEPOSIT << ") Make deposit\n";
    std::cout << MENU_WITHDRAW << ") Make withdraw\n";
    std::cout << MENU_SELECT_ACCOUNT << ") Select Account\n";
    std::cout << MENU_EXIT << ") Exit\n";
}

int getMenuChoice()
{
    int choice;
    std::cout << "Choose option: ";
    std::cin >> choice;
    while (choice<FIRST_MENU_ITEM || choice>LAST_MENU_ITEM)
    {
        std::cout << "Invalid option.  Choose option: ";
        std::cin >> choice;
    }
    return choice;
}

int selectAccount()
{
    std::cout << "\nAccount Options\n";
    std::cout << "====================\n";
    std::cout << CURRENT_ACCOUNT << ") Current Account\n";
    std::cout << SAVINGS_ACCOUNT << ") Savings Account\n";
    std::cout << LOAN_ACCOUNT << ") Loan Account\n";

    int choice;
    std::cout << "Select account: ";
    std::cin >> choice;
    while (choice<CURRENT_ACCOUNT || choice>LOAN_ACCOUNT)
    {
        std::cout << "Invalid account.  Select account: ";
        std::cin >> choice;
    }
    return choice;
}

void deposit(BankAccount& account)
{
    double amount;
    std::cout << "\nMake a deposit\n";
    std::cout << "--------------\n";
    std::cout << "Enter amount to deposit \x9C";
    std::cin >> amount;

    if (!account.deposit(static_cast<int>(amount * 100)))
        std::cout << "\n** Cannot deposit further funds into account **\n";
}

void withdraw(BankAccount& account)
{
    double amount;
    std::cout << "\nWithdraw funds\n";
    std::cout << "--------------\n";
    std::cout << "Enter amount to withdraw \x9C";
    std::cin >> amount;

    if (!account.withdraw(static_cast<int>(amount * 100)))
        std::cout << "\n** Not enough funds to withdraw requested amount **\n";
}