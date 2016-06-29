//
//  BankAccount.cpp
//  FinalProject
//
//  Created by Wuyang on 4/1/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#include "BankAccount.h"
/*
 class BankAccount:public Account{
 public:
 void display();
 void depositMoney(double m);
 void withdrawMoney(double m);
 void printHistory();
 private:
 double balance;
 };
*/
BankAccount::BankAccount(){
    IOFile file;
    setBalance(file.rBalance());
}
BankAccount::~BankAccount(){
    IOFile file;
    file.wBalance(this->getBalance());
}
void BankAccount::display(){
    QString p = QString("Available balance\t%1").arg(getBalance());
    QLabel *label = new QLabel(p);
    label->setFixedSize(100,100);
    label->setAlignment(Qt::AlignCenter);
    label->show();
}

void BankAccount::setBalance(double m){
    if (m>0) {
        this->balance = m;
    }
}

double BankAccount::getBalance(){
    return this->balance;
}
void BankAccount::depositMoney(double m){
    if (m>0)
        this->setBalance(this->getBalance()+m);
    IOFile file;
    file.wBankHis("Deposit  ",m);

}
bool BankAccount::withdrawlMoney(double m){
    if (m>0){
        if(m<=this->getBalance()){
            this->setBalance(this->getBalance()-m);
            IOFile file;
            file.wBankHis("Withdra",m);
            return true;
        }
    }
    return false;

}

string BankAccount::printHistory(){
    IOFile file;
    string a = file.rBankHis();
    return a;
}
