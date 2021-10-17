#include "InterestAccount.h"

InterestAccount::InterestAccount(unsigned long accountNumber, std::string accountName, int balance) {
	setAccountNumber(accountNumber);
	setAccountName(accountName);
	changeBalance(balance, '+');
}

InterestAccount::InterestAccount() {
	changeBalance(0, '+');
}

InterestAccount::~InterestAccount() {

}

void InterestAccount::setInterestRate(float newInterestRate) {
	interestRate = newInterestRate;
}

void InterestAccount::updateInterest() {
	
}

