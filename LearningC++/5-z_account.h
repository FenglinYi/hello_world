// account.h， 定义一个类

#ifndef _ACCOUNT_H_            // 这样就不会被重复包含
#define _ACCOUNT_H_

class SavingsAccount{
private:
    int id;                 // 账号
    double balance;         // 余额
    double rate;            // 存款的年利率
    int lastDate;           // 上次变更余额的时期
    double accumulation;    // 余额按日累加之和
    static double total;    // 所有账户的总金额
    void record(int date, double amount);  // 记录一笔账，date为日期，amount为金额。每次调用更新当前账户的状态（lastdate, accumulation, balance, total）

    double accumulate(int date) const{     // 获得到指定日期为止的存款金额按日累积值
        return accumulation+balance*(date-lastDate);   // 计算某一笔钱存了多少天
    }
public:
    SavingsAccount(int id, int date, double rate);     // 构造函数

    int getId() const {return id;}
    double getBalance() const {return balance;}
    double getRate() const {return rate;}
    static double getTotal() {return total;}

    void deposit(int date, double amount);     // 存入现金
    void withdraw(int date, double amount);    // 取出现金
    void settle(int date);                     // 结算利息，每年1月1日调用一次该函数
    void show();                               // 显示账户信息
};

#endif          // _ACCOUNT_H_