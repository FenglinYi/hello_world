// ʵ��һ���࣬SavingsAccount�����غ�����Աʵ��
#include "6-z_date.cpp"
#include "6-z_account.h"
#include <cmath>
#include <iostream>
using namespace std;

double SavingsAccount::total = 0;
SavingsAccount::SavingsAccount(const Date& date, const string& id, double rate):id(id), balance(0), rate(rate), lastDate(date), accumulation(0){
    date.show();
    cout<<"\t#"<<id<<" is created"<<endl;
}

void SavingsAccount::record(const Date& date, double amount, const string& desc){
    accumulation = accumulate(date);
    lastDate = date;
    amount = floor(amount*100+0.5)/100;     // �������뱣����λС��
    balance+=amount;
    total+=amount;
    date.show();
    cout<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<"\t"<<desc<<endl;
}

void SavingsAccount::error(const string & msg) const{   // ���������Ϣ
    cout<<"Error(#"<<id<<"):"<<msg<<endl;
}
void SavingsAccount::deposit(const Date& date, double amount, const string& desc){
    record(date, amount, desc);
}

void SavingsAccount::withdraw(const Date& date, double amount, const string& desc){
    if(amount>balance){
        error("not enough money!");
    }
    else
        record(date, -amount, desc);
}

void SavingsAccount::settle(const Date& date){                    // ������Ϣ
    double interst = accumulate(date)*rate/date.distance(Date(date.getYear()-1,1,1));
    if(interst!=0) 
        record(date, interst, "interest");
    accumulation = 0;        // ��֮ǰ�ۼӵ�����ȫ�����н�����Ϣ�������Ժ�accumulation����
}

void SavingsAccount::show() const{
    cout<<"#"<<id<<"\tBalance:"<<balance<<endl;
}
