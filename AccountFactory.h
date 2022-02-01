#pragma once
#include <memory>
#include "CurrentAccount.h"
#include "LoanAccount.h"
#include "SavingsAccount.h"

class AccountFactory
{
public:
	static std::shared_ptr<BankAccount> getAccount(const int choice)
	{
		if (choice == 0)
			return std::make_shared<CurrentAccount>(101, "Current Account", 400);
		else if (choice == 1)
			return std::make_shared<SavingsAccount>(201, "Savings Account", 400);
		else
			return std::make_shared<LoanAccount>(301, "Loan Account", 5000);
	}
};