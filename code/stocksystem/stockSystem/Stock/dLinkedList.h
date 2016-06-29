//
//  dLinkedList.h
//  FinalProject
//
//  Created by Wuyang on 4/1/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#ifndef __FinalProject__dLinkedList__
#define __FinalProject__dLinkedList__

#include "stockNode.h"
class dLinkedList:public stockNode{
public:
    dLinkedList();
    ~dLinkedList();
//    total point in linked list
    int size() const;
//    add new node to start or end
    void addToStart(stockNode* n);
    void addToEnd(stockNode* n);
//    print list
    void printList();
//    print list if providing a head of linked list
    void printList(stockNode* n);
//    remove node from start or end or appointed
    void removeStart();
    void removeEnd();
    void removeNode(string t);
//    if can find node in linked list
    bool findNode(string t);
//    change share of a node in linked list
    void setNodeShare(string t,int share);
//    find if linked list is empty
    int getNodeShare(string t);
    bool isEmpty();
    stockNode* getHead();
    stockNode* getTemp();
    void setTemp(stockNode* p);
//    copy linkedlist with head of p to another linkedlist dl
    void copyList(stockNode* p);
private:
    stockNode* head;
    stockNode* tail;
    stockNode* temp;
    stockNode* curr;
    int listSize;
};
#endif /* defined(__FinalProject__dLinkedList__) */
