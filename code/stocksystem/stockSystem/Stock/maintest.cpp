#include <iostream>
#include <fstream>
#include <string>
#include "StockAccount.h"
#include "BankAccount.h"
#include "dLinkedList.h"
#include "stockStruct.h"
#include "IOFile.h"
#include <time.h>
using namespace std;

int main (){
    IOFile file;
    file.rBankHis();
    file.rTransHis();
    cout<<" "<<endl;
    cout<<"***************************************************";
    cout<<"\n *****       Account Management System";
    cout<<"\n *****";
    cout<<"\n ***** 1  Stock Account";
    cout<<"\n ***** 2  Bank  Account";
    cout<<"\n ***** 3  Quit  Program";
    cout<<"\n****************************************************"<<endl;
    bool exe = true;
    
    while(exe){
        cout<<"Please enter operation number"<<endl;
        int choice;
        cin>>choice;
        switch (choice) {
            case 1:{
                cout<<"***************************************************";
                cout<<"\n *****       Stock Account";
                cout<<"\n *****";
                cout<<"\n ***** 1  View Current Portfolio";
                cout<<"\n ***** 2  View Stock Price";
                cout<<"\n ***** 3  Buy Shares";
                cout<<"\n ***** 4  Sell Shares";
                cout<<"\n ***** 5  View Graph for Portfolio Value";
                cout<<"\n ***** 6  View Stock Transaction History";
                cout<<"\n ***** 0  Return to previous menu";
                cout<<"\n****************************************************"<<endl;
                cout<<endl;
                bool exe1 = true;
                while(exe1){
                    StockAccount sta;
                    cout<<"Please enter operation number"<<endl;
                    cin>>choice;
                    switch (choice) {
                        case 1:{
                            sta.showPortfolio();
                            break;
                        }
                        case 2:{
                            cout<<"enter stock ticker you want to check price"<<endl;
                            string stocktic;
                            cin>>stocktic;
                            cout<<"Price per Share for\t"<<stocktic<<"\tis: "<<sta.showStockPrice(stocktic)<<endl;
                            break;
                        }
                        case 3:{
                            cout<<"enter stock ticker, share number, expected price"<<endl;
                            string stocktic;
                            int sh;
                            double price;
                            cin>>stocktic>>sh>>price;
                            sta.buyShares(sh, stocktic, price);
                            break;
                        }
                        case 4:{
                            cout<<"enter stock ticker, share number, expected price"<<endl;
                            string stocktic;
                            int sh;
                            double price;
                            cin>>stocktic>>sh>>price;
                            sta.sellShares(sh, stocktic, price);
                            break;
                        }
                        case 5:{
                            break;
                        }
                        case 6:{
                            sta.showTransHistory();
                            break;
                        }
                        case 0:{
                            exe1 = false;
                            break;
                        }
                        default:
                            break;
                    }
                }//while exe1 shop

            }//case 1 stop
                
            case 2:{
                cout<<"***************************************************";
                cout<<"\n *****       Bank Account";
                cout<<"\n *****";
                cout<<"\n ***** 1  View Avaiable Balance";
                cout<<"\n ***** 2  Deposit Money";
                cout<<"\n ***** 3  Withdrwal Money";
                cout<<"\n ***** 4 View Money Transaction History";
                cout<<"\n ***** 0  Return to previous menu";
                cout<<"\n****************************************************"<<endl;
                bool exe2 = true;
                while(exe2){
                    cout<<"Please enter operation number"<<endl;
                    cin>>choice;
                    BankAccount bac;
                    switch(choice){
                        case 1:{
                            cout<<"Avaible Balance is\t"<<bac.getBalance()<<endl;
                            break;
                        }
                        case 2:{
                            cout<<"Input Amount to Deposit"<<endl;
                            double m;
                            cin>>m;
                            bac.depositMoney(m);
                            break;
                        }
                        case 3:{
                            cout<<"Input Amount to Withdrawl"<<endl;
                            double m;
                            cin>>m;
                            bac.withdrawlMoney(m);
                            break;

                        }
                        case 4:{
                            bac.printHistory();
                            break;
                        }
                        case 0:{
                            exe2 = false;
                            break;
                        }
                        default:
                            break;
                    }//swicth stop
                }//while exe2 stop
            }//case 2 stop
            case 3:{
                exe = false;
                break;
            }
                
            default:{
                cout<<"Your selection must between 1 to 3"<<endl;
                break;
            }
        }//switch stop
    }//while stop
    
return 0;

}
