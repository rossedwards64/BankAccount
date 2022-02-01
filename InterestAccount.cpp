#include "InterestAccount.h"

#include <utility>

InterestAccount::InterestAccount(const unsigned long accountNumber, std::string accountName, const int balance) 
{
	setAccountNumber(accountNumber);
	setAccountName(std::move(accountName));
	changeBalance(balance, '+');
}

InterestAccount::InterestAccount() { changeBalance(0, '+'); }

InterestAccount::~InterestAccount() = default;

void InterestAccount::setInterestRate(const float newInterestRate) { interestRate = newInterestRate;}

void InterestAccount::updateInterest() 
{
	
}

