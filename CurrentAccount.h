#pragma once
#include <string>
#include <utility>
#include "BankAccount.h"

class CurrentAccount :
    public BankAccount
{
public:
    CurrentAccount(unsigned long accountNumber, const std::string accountName, int balance);
    ~CurrentAccount();
    virtual bool deposit(int amount);
    virtual bool withdraw(int amount);
};

