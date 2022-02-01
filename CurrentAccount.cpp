#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(const unsigned long accountNumber, std::string accountName, const int balance) 
{
	setAccountNumber(accountNumber);
	setAccountName(std::move(accountName));
	changeBalance(balance, '+');
	std::cout << "Opening Current Account\n";
}

CurrentAccount::~CurrentAccount() { std::cout << "Closing Current Account\n"; }

bool CurrentAccount::deposit(const int amount) 
{
	int balance = getBalance();
	balance += amount;
	changeBalance(amount, '+');
	return true;
}

bool CurrentAccount::withdraw(const int amount)
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