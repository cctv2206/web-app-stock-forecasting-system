//
//  dLinkedList.cpp
//  FinalProject
//
//  Created by Wuyang on 4/1/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#include "dLinkedList.h"

dLinkedList::dLinkedList(){
    head = NULL;
    tail = NULL;
    temp = NULL;
    curr = NULL;
    listSize = 0;
}
dLinkedList::~dLinkedList(){

}

int dLinkedList::size() const{
    return listSize;
}
bool dLinkedList::isEmpty(){
    if(head == NULL)
        return true;
    return false;
}
void dLinkedList::addToStart(stockNode* n){
    if(isEmpty()){
        head = n;
        tail = n;
    }else{
        head->prev = n;
        n->next = head;
        head = n;
    }
    listSize++;
}
void dLinkedList::addToEnd(stockNode* n){
    //    if head != null, go to the end of the list, use the next of last node pointing to new node
    //    if head == null, head = new node
    if (!isEmpty()) {
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
    }else{
        head = n;
    }
    listSize++;
}
void dLinkedList::printList(){
    if (head == NULL) {
        cout<<" No record in stock portfolio !"<<endl;
    }else{
        temp = head;
        cout<<"stock symbol\tshares"<<endl;
        while( temp != NULL){
            cout<<temp->stockTicker<<"\t\t\t"<<temp->shares<<endl;
            temp = temp->next;
        }
    }
}
void dLinkedList::printList(stockNode* n){
    if ( n == NULL){
        cout<<" No record in stock portfolio !"<<endl;
    }else{
        temp = n;
        cout<<"stock symbol\tshares"<<endl;
        while( temp != NULL){
            cout<<temp->stockTicker<<"\t\t\t"<<temp->shares<<endl;
            temp = temp->next;
        }
    }
}

void dLinkedList::removeStart(){
    if (isEmpty()) {
        return;
    }else if(head->next == NULL){
        head = head->next;
    }else{
        temp = head->next;
        temp->prev = NULL;
        delete head;
        head = temp;
    }
    listSize--;
}
void dLinkedList::removeEnd(){
    if (isEmpty()) {
        return;
    }else if(head->next == NULL){
        head = head->next;
    }else{
        temp = tail->prev;
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    listSize--;
}
void dLinkedList::removeNode(string t){
    if (isEmpty())
        return;
    if(head->stockTicker == t){
        temp = head->next;
        temp->prev = NULL;
        delete head;
        head = temp;
        listSize--;
        return;
    }
    temp = head;
    while (temp != NULL && temp->stockTicker != t){
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"stock cannot found !"<<endl;
    }else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        listSize--;
        return;
    }
}
bool dLinkedList::findNode(string t){
    if (isEmpty()) {
        return false;
    }else if (head->stockTicker == t) {
        return true;
    }
    temp = head;
    while (temp != NULL && temp->stockTicker != t) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return false;
    }else{
        return true;
    }

}
void dLinkedList::setNodeShare(string t,int share){
    if (head == NULL) {
        return;
    }else if(head->stockTicker == t){
        head->setShare(share);
        return;
    }
    temp = head;
    while (temp != NULL && temp->stockTicker != t) {
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }else{
        temp->setShare(share);
    }
}


int dLinkedList::getNodeShare(string t){
    if (isEmpty()) {
        return 0;
    }else if(head->stockTicker == t){
        return head->getShares();
    }
    temp = head;
    while (temp != NULL && temp->stockTicker != t) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return 0;
    }else{
        return temp->getShares();
    }
}

stockNode* dLinkedList::getHead(){
    return this->head;
}

stockNode* dLinkedList::getTemp(){
    return this->temp;
}

void dLinkedList::setTemp(stockNode* p){
    this->temp = p;
}

void dLinkedList::copyList(stockNode* p){
      if (p == NULL) {
        return;
    }else{
        stockNode* pTem;
        pTem = p;
        head = p;
        while (pTem != NULL ) {
            this->temp = pTem;
            pTem = pTem->next;
            this->temp = this->temp->next;
        }
    }
}
