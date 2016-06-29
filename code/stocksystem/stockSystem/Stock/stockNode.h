//
//  stockNode.h
//  FinalProject
//
//  Created by Wuyang on 4/1/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#ifndef __FinalProject__stockNode__
#define __FinalProject__stockNode__

#include "iostream"
using namespace std;
class stockNode{
    friend class dLinkedList;
public:
    stockNode(){
        this->next = NULL;
        this->prev = NULL;
    }
    stockNode(string name, int n){
        this->stockTicker = name;
        this->shares = n;
        this->next = NULL;
        this->prev = NULL;
    };
    string getTicker();
    int getShares();
    void setShare(int s);
    stockNode* getNext();
private:
    string stockTicker;
    int shares;
    stockNode* next;
    stockNode* prev;
};
#endif /* defined(__FinalProject__stockNode__) */
