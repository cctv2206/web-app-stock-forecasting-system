//
//  BankAccount.h
//  FinalProject
//
//  Created by Wuyang on 4/1/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#ifndef __FinalProject__BankAccount__
#define __FinalProject__BankAccount__
#include <fstream>
#include "Account.h"
#include "iostream"

class BankAccount:public Account{
public:
    BankAccount();
    ~BankAccount();
    void display();
    void depositMoney(double m);
    bool withdrawlMoney(double m);
    string printHistory();
    void setBalance(double m);
    double getBalance();
private:
    double balance;
};

#endif /* defined(__FinalProject__BankAccount__) */
