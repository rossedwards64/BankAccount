#include "LoanAccount.h"
#include <iostream>

LoanAccount::LoanAccount(unsigned long accoutNumber, std::string accountName, int balance) {
	setAccountNumber(accoutNumber);
	setAccountName(accountName);
	changeBalance(balance, '+');
}

LoanAccount::~LoanAccount() {
	
}

bool LoanAccount::deposit(int amount) {
	int balance = getBalance();
	balance += amount;
	changeBalance(amount, '+');
	return true;
}

bool LoanAccount::withdraw(int amount) {
	std::cout << "**Withdraw is not possible for this account**" << std::endl;
	return false;
}

