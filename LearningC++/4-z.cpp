/*个人银行管理账户管理程序*/

#include<iostream>
#include<cmath>
using namespace std;

class SavingsAccount{     // 储蓄账户类
    private:
        int id;           // 账号
        double balance;   // 余额
        double rate;      // 存款的年利率
        int lastDate;      // 上次变更余额的时期
        double accumulation;   // 余额按日累加之和

        void record(int date, double amount);  // 记录一笔账，date为日期，amount为金额，desc为说明

        double accumulate(int date) const{     // 获得到指定日期为止的存款金额按日累积值
            return accumulation+balance*(date-lastDate);
        }
    public:
        SavingsAccount(int id, int date, double rate);     // 构造函数

        int getId(){return id;}
        double getBalance(){return lastDate;}
        double getRate(){return rate;}

        void deposit(int date, double amount);     // 存入现金
        void withdraw(int date, double amount);    // 取出现金
        void settle(int date);                     // 结算利息，每年1月1日调用一次该函数
        void show();                               // 显示账户信息
};

// 类成员函数的实现
SavingsAccount::SavingsAccount(int id, int date, double rate):id(id), balance(0), rate(rate), lastDate(date), accumulation(0){
    cout<<date<<"\t"<<id<<" is created"<<endl;
}

void SavingsAccount::record(int date, double amount){  // 修改余额并将余额的变动输出
    accumulation = accumulate(date);
    lastDate = date;
    amount = floor(amount*100+0.5)/100;                // 四舍五入保留两位小数（*100的作用）
    balance += amount;                                 // 更新余额
    cout<<date<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
}

void SavingsAccount::deposit(int date, double amount){    // 存入现金
    record(date, amount);
}

void SavingsAccount::withdraw(int date, double amount){   // 取出现金
    if(amount<getBalance()){
        cout<<"Error: not enough money"<<endl;
    }
    else
        record(date, -amount);
}

void SavingsAccount::settle(int date){                    // 结算利息
    double interst = accumulate(date)*rate/365;
    if(interst!=0) 
        record(date, interst);
    accumulation = 0;
}

void SavingsAccount::show(){                             // 显示
    cout<<"#"<<id<<"\tBalance:"<<balance<<endl;
}

int main(){
    SavingsAccount sa0(21325302, 1, 0.015);
    SavingsAccount sa1(58320212, 1, 0.015);
    sa0.deposit(5, 5000);
    sa1.deposit(25, 10000);
    sa0.deposit(45, 5500);
    sa1.withdraw(60, 4500);

    sa0.settle(90);                      // 开户第90天开始结算利息
    sa1.settle(90);

    sa0.show();
    sa1.show();
}



