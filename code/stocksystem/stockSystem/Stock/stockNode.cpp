//
//  stockNode.cpp
//  FinalProject
//
//  Created by Wuyang on 4/1/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#include "stockNode.h"

string stockNode::getTicker(){
    return this->stockTicker;
}

int stockNode::getShares(){
    return this->shares;
}

void stockNode::setShare(int s){
    this->shares = s;
}

stockNode* stockNode::getNext(){
    return this->next;
}
