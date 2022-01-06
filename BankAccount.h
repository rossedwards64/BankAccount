#pragma once
#include <iostream>
#include <string>

class BankAccount
{
public:
	BankAccount(unsigned long accountNumber, std::string accountName, int balance);
	BankAccount();
	virtual ~BankAccount();
	void printSummary() const;
	int getBalance() const;
	virtual bool deposit(int amount) = 0;
	virtual bool withdraw(int amount) = 0;

protected:
	void setAccountNumber(unsigned long newAccountNumber);
	void setAccountName(std::string newAccountName);
	void changeBalance(int amount, char operand);

private:
	unsigned long accountNumber = 0;
	std::string accountName = " ";
	int balance = 0;
};

