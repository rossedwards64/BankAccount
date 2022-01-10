#include "BankAccount.h"

BankAccount::BankAccount(const unsigned long accountNumber, std::string accountName, const int balance)
	: accountNumber(accountNumber), accountName(std::move(accountName)), balance(balance) { }

BankAccount::BankAccount() : balance(0) { }

BankAccount::~BankAccount() = default;

void BankAccount::printSummary() const
{
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

int BankAccount::getBalance() const { return balance; }

void BankAccount::setAccountNumber(const unsigned long newAccountNumber) { accountNumber = newAccountNumber; }

void BankAccount::setAccountName(std::string newAccountName) { accountName = std::move(newAccountName); }

void BankAccount::changeBalance(const int amount, const char operand)
{
	if (operand == '+') { balance += amount; }
	else if (operand == '-') { balance -= amount; }
}

