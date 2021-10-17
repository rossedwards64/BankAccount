#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(unsigned long accoutNumber, std::string accountName, int balance) {
	this->accountNumber = accountNumber;
	this->accountName = accountName;
	this->balance = balance;
}

BankAccount::BankAccount() {
	balance = 0;
}

BankAccount::~BankAccount() {

}

void BankAccount::printSummary() {
	const int pounds = balance / 100;
	const int pence = balance - (pounds * 100);

	std::cout << std::endl << accountName << std::endl;

	for (unsigned int i = 0; i < accountName.length(); i++) {
		std::cout << "-";
	}

	std::cout << std::endl;
	std::cout << "Account Number: " << accountNumber << std::endl;
	std::cout << "Balance: \x9C" << pounds << ".";

	if (pence < 10) {
		std::cout << "0";
	}

	std::cout << pence << std::endl << std::endl;
}

int BankAccount::getBalance() {
	return balance;
}

void BankAccount::setAccountNumber(unsigned long newAccountNumber) {
	accountNumber = newAccountNumber;
}

void BankAccount::setAccountName(std::string newAccountName) {
	accountName = newAccountName;
}

void BankAccount::changeBalance(int amount, char operand) {
	if (operand == '+') {
		balance += amount;
	}
	else if (operand == '-') {
		balance -= amount;
	}
}

