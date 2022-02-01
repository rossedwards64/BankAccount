#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const unsigned long accountNumber, std::string accountName, const int balance) 
{
	setAccountNumber(accountNumber);
	setAccountName(std::move(accountName));
	changeBalance(balance, '+');
	std::cout << "Opening Savings Account\n";
}

SavingsAccount::~SavingsAccount()
{
	std::cout << "Closing Savings Account\n";
}

bool SavingsAccount::deposit(const int amount) 
{
	int balance = getBalance();
	if (amount <= subBalance) {
		balance += amount;
		changeBalance(amount, '+');
		return true;
	}
	else {
		return false;
	}
}

bool SavingsAccount::withdraw(const int amount) 
{
	int balance = getBalance();
	if (balance >= amount) {
		balance -= amount;
		changeBalance(amount, '-');
		return true;
	}
	else {
		return false;
	}
}