#include "CurrentAccount.h"
#include <string>

CurrentAccount::CurrentAccount(unsigned long accoutNumber, std::string accountName, int balance) {
	setAccountNumber(accoutNumber);
	setAccountName(accountName);
	changeBalance(balance, '+');
}

CurrentAccount::~CurrentAccount() {

}

bool CurrentAccount::deposit(int amount) {
	int balance = getBalance();
	balance += amount;
	changeBalance(amount, '+');
	return true;
}

bool CurrentAccount::withdraw(int amount) {
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