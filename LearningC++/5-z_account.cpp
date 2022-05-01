// 实现一个类，SavingsAccount类的相关函数成员实现
#include "5-z_account.h"
#include <cmath>
#include <iostream>
using namespace std;

double SavingsAccount::total = 0;
SavingsAccount::SavingsAccount(int date, int id, double rate):id(id), balance(0), rate(rate), lastDate(date), accumulation(0){
    cout<<date<<"\t#"<<id<<" is created"<<endl;
}

void SavingsAccount::record(int date, double amount){
    accumulation = accumulate(date);
    lastDate = date;
    amount = floor(amount*100+0.5)/100;     // 四舍五入保留两位小数
    balance+=amount;
    total+=amount;
    cout<<date<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
}

void SavingsAccount::deposit(int date, double amount){
    record(date, amount);
}

void SavingsAccount::withdraw(int date, double amount){
    if(amount>balance){
        cout<<"Error:not enough money!";
    }
    else
        record(date, -amount);
}

void SavingsAccount::settle(int date){                    // 结算利息
    double interst = accumulate(date)*rate/365;
    if(interst!=0) 
        record(date, interst);
    accumulation = 0;        // 把之前累加的天数全部进行结算利息，结算以后accumulation清零
}

void SavingsAccount::show(){
    cout<<"#"<<id<<"\tBalance:"<<balance<<endl;
}
