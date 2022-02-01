#include "LoanAccount.h"
#include <iostream>
#include <utility>

LoanAccount::LoanAccount(const unsigned long accountNumber, std::string accountName, const int balance) 
{
	setAccountNumber(accountNumber);
	setAccountName(std::move(accountName));
	changeBalance(balance, '+');
	std::cout << "Opening Loan Account\n";
}

LoanAccount::~LoanAccount()
{
	std::cout << "Closing Loan Account\n";
}

bool LoanAccount::deposit(const int amount) 
{
	int balance = getBalance();
	balance += amount;
	changeBalance(amount, '+');
	return true;
}

bool LoanAccount::withdraw(int amount) 
{
	std::cout << "**Withdraw is not possible for this account**" << std::endl;
	return false;
}

