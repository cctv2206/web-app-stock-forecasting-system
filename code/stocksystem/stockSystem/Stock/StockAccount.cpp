//
//  StockAccount.cpp
//  FinalProject
//
//  Created by Wuyang on 4/1/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#include "StockAccount.h"
/*
 class StockAccount:public Account{
 public:
 void showStockPrice(string s);
 void showPortfolio();
 void buyShares(double m);
 void sellShares(double m);
 void graphPortfolio();
 void showTransHistory();
 };
 */
StockAccount::StockAccount(){
    IOFile *file = new IOFile;
    this->stockRe = new StockStruct;
//    initiate account balance and portfolio information ( return head of linkedlist)
    this->balance = file->rBalance();

//    save to stockList stock portfolio information from stockShare.txt
    this->stockList = new dLinkedList();

    this->stockList->copyList(file->rShare());

//    save to stockRe price per share of stock from Results.txt
    this->stockRe = file->readRes1();
    this->stockList->printList();
}

StockAccount::~StockAccount(){
//when called distructor, write current balance to Balance.txt and stock portfolio to StockShare.txt
    IOFile file;
    file.wBalance(this->getBalance());
    file.wShare(this->stockList);
}
void StockAccount::showallprice(){
    for(int i = 0; i< 48;i++){
//        cout<<this->stockRe->stock[i].price<<endl;
        cout<<this->stockRe->stock[i].ticker<<this->stockRe->stock[i].price<<endl;
    }
}

double StockAccount::showStockPrice(string stock){

    for (int i = 0 ; i< 48; i++){
        if (stock == this->stockRe->stock[i].ticker) {
            return this->stockRe->stock[i].price;
        }
    }
    cout<<"Not found the stock "<<stock<<endl;
    return 0;

}

void StockAccount::setBalance(double m){
    this->balance = m;
}

double StockAccount::getBalance(){
    return this->balance;
}

void StockAccount::display(){

}

string StockAccount::showPortfolio(){
    stringstream s,s1,s2;
    s<<this->getBalance();

    string out = "Available balance\t\t$"+ s.str() + "\n\n\n";

    if (stockList->getHead()==NULL) {
        out += "No record in Portfolio !";
        return out;
    }
    stockList->setTemp(stockList->getHead());
    double sum = 0;
    out += "StockTicker\tShares\tPrice/Share\tTotalPrice\n";
    while (stockList->getTemp() != NULL) {
/*find corresponding price per share of given ticker, then output information of
  Ticker, shares, price per share, total value
 */
        stringstream s,s1,s2;

        double perPrice = this->stockRe->getPrice(stockList->getTemp()->getTicker());
        s<<perPrice;
        s1<<stockList->getTemp()->getShares();
        s2<<stockList->getTemp()->getShares()*perPrice;
        out += stockList->getTemp()->getTicker()+"\t\t"+ s1.str() +"\t$"+s.str() + "\t\t$"+s2.str() +"\n";

        sum +=stockList->getTemp()->getShares()*perPrice;
        stockList->setTemp(stockList->getTemp()->getNext());
    }
    stringstream s3;
    s3<<sum;
    out += "\nTotal portfolio value: $"+ s3.str();
    return out;
}

int StockAccount::buyShares(int sh,string stock, double price){
//    check if the requested stock in stock list

    if(!stockRe->isStock(stock)){
        cout<<"Purchase FAIL !"<<endl;
        cout<<"Stock\t"<<stock<<"\tnot found !"<<endl;
        return 0;
    }else if (stockRe->getPrice(stock) < price) {
//    check if the expected price higher than present price

        cout<<"Purchase FAIL !"<<endl;
        cout<<"Price per share of stock\t"<<stock<<"\thigher than expected price !"<<endl;
        return 1;
    }else if (price * sh > getBalance()) {
//    check whether balance in account is enough

        cout<<"Purchase FAIL !"<<endl;
        cout<<"Insufficient balance in your account !"<<endl;
        return 2;
    }
//    Purchase successful
//    subtract money from accout
    setBalance(getBalance() - price * sh);

//    find whether stock is already in portfolio list: add new node / update share information
//    stockList.setNodeShare(stock, 1001);
    cout<<"Successfully buy stock\t"<<stock<<"\tshares "<<sh<<" on $"<<price *sh<<endl;
    if (stockList->findNode(stock)) {
        stockList->setNodeShare(stock,sh + stockList->getNodeShare(stock));
    }else{
        stockNode* newStock = new stockNode(stock,sh);
        stockList->addToEnd(newStock);
    }
//    Write Stock Transaction to txt

    IOFile file;
    file.wTransHis("Buy", stock, sh,price);
    return 3;

}

int StockAccount::sellShares(int sh, string stock, double price){
//    check if requested stock in stock list
    if (!stockList->findNode(stock)  ){
        cout<<"Sell FAIL !"<<endl;
        cout<<"Stock\t"<<stock<<"\tnot found !"<<endl;
        return 0;
    }else if(stockRe->getPrice(stock) > price){
//     check if expected price lower than present price
        cout<<"Sell FAIL !"<<endl;
        cout<<"Price per share of stock\t"<<stock<<"\tlower than expected price !"<<endl;
        return 1;
    }
//    subtract share and add money
    cout<<"Successfully sell stock\t"<<stock<<"\tshares "<<sh<<" on $"<<price *sh<<endl;

    stockList->setNodeShare(stock, stockList->getNodeShare(stock)-sh);
    if (stockList->getNodeShare(stock) == 0)
        stockList->removeNode(stock);
    setBalance(getBalance() + price * sh);
//    Write Stock Transaction to txt
    IOFile file;
    file.wTransHis("Sell", stock, sh, price);
    return 2;
}

string StockAccount::showTransHistory(){
    IOFile file;

    return file.rTransHis();
}
