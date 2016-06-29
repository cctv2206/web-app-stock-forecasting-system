//
//  IOFile.h
//  FinalProject
//
//  Created by Wuyang on 4/1/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#ifndef __FinalProject__IOFile__
#define __FinalProject__IOFile__

#include <iostream>
#include <fstream>
#include <time.h>
#include "stockStruct.h"
#include<iomanip>
#include <QString>
#include <QLabel>
#include <string.h>
using namespace std;
class IOFile{
public:
    void showTime();
//read Result_1.txt, Result_2.txt
    StockStruct* readRes1();
    StockStruct* readRes2();
//Write Money Transaction History
    void wMoneyHis(string, double);
//Write and Read Balance
    double rBalance();
    void wBalance(double);
//Write and Read Stock share
    stockNode* rShare();
    void wShare(dLinkedList *sh);
//    Write and Read Stock Transaction and Money Transaction
    void wTransHis(string event,string comp,int share, double perPrice);
    string rTransHis();
    void wBankHis(string event, double amount);
    string rBankHis();

};

#endif /* defined(__FinalProject__IOFile__) */
