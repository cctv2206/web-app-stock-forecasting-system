//  IOFile.cpp
//  FinalProject
//
//  Created by Wuyang on 4/1/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#include "IOFile.h"

void IOFile::showTime(){
    time_t seconds;
    seconds = time(NULL);
    tm * timeinfo;
    timeinfo = localtime(&seconds);
    cout<<"The current local time and date is:"<<asctime(timeinfo);
}


//Read Results_1.txt and Results_2.txt, save data in StockStruct

StockStruct* IOFile::readRes1(){
    StockStruct *stk = new StockStruct;
    ifstream theFile("Results_1.txt");
    int i =0;
    while(theFile >> stk->ticker >> stk->price >> stk->time){
        stk->stock[i].ticker = stk->ticker;
        stk->stock[i].price = stk->price;
        stk->stock[i].time = stk->time;

        i++;
    }
    return stk;
}

StockStruct* IOFile::readRes2(){
    StockStruct stk;
    ifstream theFile2("Results_2.txt");
    int i =0;
    while(theFile2 >> stk.ticker >> stk.price >> stk.time){
        stk.stock2[i].ticker = stk.ticker;
        stk.stock2[i].price = stk.price;
        stk.stock2[i].time = stk.time;
        i++;
    }
    StockStruct *p = &stk;
    return p;

}


// Read and Write Balance to File Balance.txt

double IOFile::rBalance(){
    ifstream inFile("Balance.txt");
    double balance;
    inFile >> balance;
    return balance;
}
void IOFile::wBalance(double m){
    ofstream outFile;
    outFile.open("Balance.txt");
    outFile<<m<<endl;
}

//Write and Read Stock share

stockNode* IOFile::rShare(){
    ifstream inFile("StockShare.txt");
    dLinkedList *shareList = new dLinkedList;
    stockNode* share[20];
    string ti;
    int sh;
    while (inFile >>ti>>sh) {
        share[shareList->size()]= new stockNode(ti,sh);
        shareList->addToEnd(share[shareList->size()]);
    }
    return shareList->getHead();
}

void IOFile::wShare(dLinkedList *sh){

    ofstream outFile;
    outFile.open("StockShare.txt");
    if (sh->getHead()==NULL)
        return;
    sh->setTemp(sh->getHead());
    while (sh->getTemp() != NULL) {
        outFile<<sh->getTemp()->getTicker()<<"\t\t"<<sh->getTemp()->getShares()<<endl;
        sh->setTemp(sh->getTemp()->getNext());
    }
}

// Write Stock Transacation History to file StockTranHis.txt

void IOFile::wTransHis(string event,string comp,int share, double perPrice){
    ofstream outFile;
    outFile.open("StockTransHis.txt",ios::app);
    time_t seconds;
    seconds = time(NULL);
    tm * timeinfo;
    timeinfo = localtime(&seconds);
    outFile<<event<<"\t"<<comp<<"\t"<<share<<"\t"<<"$"<<perPrice<<"\t\t"<<"$"<<share*perPrice<< "\t\t"<<asctime(timeinfo);

}
// Write Money Transacation History to file MoneyTranHis.txt

void IOFile::wBankHis(string event, double amount){
    ofstream outFile;
    outFile.open("MoneyTransHis.txt",ios::app);
    time_t seconds;
    seconds = time(NULL);
    tm * timeinfo;
    timeinfo = localtime(&seconds);
    outFile<<event<<"\t\t"<<amount<<"\t\t"<<asctime(timeinfo)<<endl;
}

string IOFile::rBankHis(){
    ifstream inFile("MoneyTransHis.txt");
    string event;
    string amount;
    string week;
    string month;
    string date;
    string time;
    string year;
    string out = "";
    while (inFile>>event>>amount>>week>>month>>date>>time>>year) {

        out += event + "\t\t$"+ amount + "\t" + time + "\t" + month + " "+ date + "." + year + "\n";

    }
    return out;
}

string IOFile::rTransHis(){
    ifstream inFile("StockTransHis.txt");
    string event;
    string company;
    string share;
    string perPrice;
    string totalPrice;
    string week;
    string month;
    string date;
    string time;
    string year;
    string out = "";
    while (inFile>>event>>company>>share>>perPrice>>totalPrice>>week>>month>>date>>time>>year) {
        out += event +"\t"+ company + "\t" + share + "\t" + perPrice + "\t" + totalPrice + "\t" + time + "\t" +month +" "+ date +"." +year + "\n";
    }
    return out;
}
