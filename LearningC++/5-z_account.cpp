// ʵ��һ���࣬SavingsAccount�����غ�����Աʵ��
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
    amount = floor(amount*100+0.5)/100;     // �������뱣����λС��
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

void SavingsAccount::settle(int date){                    // ������Ϣ
    double interst = accumulate(date)*rate/365;
    if(interst!=0) 
        record(date, interst);
    accumulation = 0;        // ��֮ǰ�ۼӵ�����ȫ�����н�����Ϣ�������Ժ�accumulation����
}

void SavingsAccount::show(){
    cout<<"#"<<id<<"\tBalance:"<<balance<<endl;
}
