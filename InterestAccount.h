#pragma once
#include "BankAccount.h"
class InterestAccount : public BankAccount
{
public:
	InterestAccount(unsigned long accountNumber, std::string accountName, int balance);
	InterestAccount();
	~InterestAccount();
	virtual bool deposit(int amount) = 0;
	virtual bool withdraw(int amount) = 0;
	void setInterestRate(float newInterestRate);
	void updateInterest();

private:
	float interestRate = 0;
};

