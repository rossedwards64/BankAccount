#pragma once
#include "InterestAccount.h"

class SavingsAccount : public InterestAccount
{
public:
	SavingsAccount(unsigned long accountNumber, std::string accountName, int balance);
	~SavingsAccount();
	virtual bool deposit(int amount);
	virtual bool withdraw(int amount);

private:
	int subBalance = 50000;
	int month = 0;
};

