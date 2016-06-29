//
//  stockStruct.cpp
//  FinalProject
//
//  Created by Wuyang on 4/1/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#include "stockStruct.h"

double StockStruct::getPrice(string t){
    for (int i = 0 ; i< 48; i++) {
        if (stock[i].ticker ==t)
            return stock[i].price;
    }
    return 0;
}

bool StockStruct::isStock(string s){
    for (int i = 0 ; i< 48; i++) {
        if (stock[i].ticker == s)
            return true;
    }
    return false;
}
