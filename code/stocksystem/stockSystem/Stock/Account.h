//
//  Account.h
//  FinalProject
//
//  Created by Wuyang on 4/1/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#ifndef __FinalProject__Account__
#define __FinalProject__Account__

#include "iostream"
#include <time.h>
#include "IOFile.h"
#include <string>
#include <sstream>
using namespace std;
class Account{
public:
    virtual void display()=0;
    void setBalance(double m);
    double getBalance();
    void initiateBalance();
private:
    double balance;
};
#endif /* defined(__FinalProject__Account__) */
