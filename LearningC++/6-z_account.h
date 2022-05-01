// account.h�� ����һ����

#ifndef _ACCOUNT_H_            // �����Ͳ��ᱻ�ظ�����
#define _ACCOUNT_H_

#include"6-z_date.h"
#include<string>
using namespace std;

class SavingsAccount{
private:
    string id;              // �˺�
    double balance;         // ���
    double rate;            // ����������
    Date lastDate;          // �ϴα������ʱ��
    double accumulation;    // �����ۼ�֮��
    static double total;    // �����˻����ܽ��
    void record(const Date& date, double amount, const string& desc);  // ��¼һ���ˣ�dateΪ���ڣ�amountΪ���,descΪ˵����ÿ�ε��ø��µ�ǰ�˻���״̬��lastdate, accumulation, balance, total��
    void error(const string & msg) const;   // ���������Ϣ
    double accumulate(const Date& date) const{      // ��õ�ָ������Ϊֹ�Ĵ������ۻ�ֵ
        return accumulation+balance*date.distance(lastDate);   // ����ĳһ��Ǯ���˶�����
    }
public:
    SavingsAccount(const Date& date, const string& id, double rate);     // ���캯��

    const string& getId() const {return id;}
    double getBalance() const {return balance;}
    double getRate() const {return rate;}
    static double getTotal() {return total;}

    void deposit(const Date& date, double amount, const string & desc);     // �����ֽ�
    void withdraw(const Date& date, double amount, const string & desc);    // ȡ���ֽ�
    void settle(const Date& date);                     // ������Ϣ��ÿ��1��1�յ���һ�θú���
    void show() const;                               // ��ʾ�˻���Ϣ
};

#endif          // _ACCOUNT_H_