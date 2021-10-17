#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(unsigned long accoutNumber, std::string accountName, int balance) {
	setAccountNumber(accoutNumber);
	setAccountName(accountName);
	changeBalance(balance, '+');
}

SavingsAccount::~SavingsAccount() {

}
 
bool SavingsAccount::deposit(int amount) {
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

bool SavingsAccount::withdraw(int amount) {
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