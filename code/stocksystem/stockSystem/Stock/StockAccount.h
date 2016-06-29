//
//  StockAccount.h
//  FinalProject
//
//  Created by Wuyang on 4/2/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#ifndef __FinalProject__StockAccount__
#define __FinalProject__StockAccount__

#include "Account.h"
class StockAccount:public Account{
public:
    //setBalance() set current changing balance
    //showBalance() get current changing balance
    StockAccount();
    ~StockAccount();
    void setBalance(double);
    double getBalance();
    double showStockPrice(string s);
    string showPortfolio();
    int buyShares(int sh,string stock, double price);
    int sellShares(int sh, string stock, double price);
    void graphPortfolio();
    string showTransHistory();
    void display();
    void showallprice(); //test
private:
    double balance;
    stockNode* portf;       //para@portf head of stockList
    dLinkedList *stockList;  //list putting stock information including ticker and shares
    StockStruct* stockRe;    // save price per share read from StockResult_1.txt

};
#endif /* defined(__FinalProject__StockAccount__) */
