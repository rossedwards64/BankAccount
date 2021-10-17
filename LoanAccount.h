#pragma once
#include "InterestAccount.h"
class LoanAccount : public InterestAccount
{
public:
	LoanAccount(unsigned long accoutNumber, std::string accountName, int balance);
	~LoanAccount();
	virtual bool deposit(int amount);
	virtual bool withdraw(int amount);
};

