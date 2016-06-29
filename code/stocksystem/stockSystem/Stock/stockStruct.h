//
//  stockStruct.h
//  FinalProject
//
//  Created by Wuyang on 4/1/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#ifndef __FinalProject__stockStruct__
#define __FinalProject__stockStruct__

#include "iostream"
#include "dLinkedList.h"
using namespace std;
class StockStruct{
public:
    struct Stock{
        string ticker;
        double price;
        string time;
    };
    double getPrice(string t);
    bool isStock(string s);
    struct Stock stock[49],stock2[49];
    string ticker;
    double price;
    string time;
};
#endif /* defined(__FinalProject__stockStruct__) */
