// 代表main函数

#include "5-z_account.h"
#include "5-z_account.cpp"
#include <iostream>
using namespace std;

int main(){
    SavingsAccount sa0(1,21325302, 0.015);
    SavingsAccount sa1(1,58320212, 0.015);
    sa0.deposit(5, 5000);
    sa1.deposit(25, 10000);
    sa0.deposit(35, 5500);
    sa1.withdraw(50, 4000);

    sa0.settle(61);                      // 开户第90天开始结算利息
    sa1.settle(61);

    sa0.show();
    sa1.show();

    cout<<"Total:"<<SavingsAccount::getTotal()<<endl;
    return 0;
}