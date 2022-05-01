// account.h�� ����һ����

#ifndef _ACCOUNT_H_            // �����Ͳ��ᱻ�ظ�����
#define _ACCOUNT_H_

class SavingsAccount{
private:
    int id;                 // �˺�
    double balance;         // ���
    double rate;            // ����������
    int lastDate;           // �ϴα������ʱ��
    double accumulation;    // �����ۼ�֮��
    static double total;    // �����˻����ܽ��
    void record(int date, double amount);  // ��¼һ���ˣ�dateΪ���ڣ�amountΪ��ÿ�ε��ø��µ�ǰ�˻���״̬��lastdate, accumulation, balance, total��

    double accumulate(int date) const{     // ��õ�ָ������Ϊֹ�Ĵ������ۻ�ֵ
        return accumulation+balance*(date-lastDate);   // ����ĳһ��Ǯ���˶�����
    }
public:
    SavingsAccount(int id, int date, double rate);     // ���캯��

    int getId() const {return id;}
    double getBalance() const {return balance;}
    double getRate() const {return rate;}
    static double getTotal() {return total;}

    void deposit(int date, double amount);     // �����ֽ�
    void withdraw(int date, double amount);    // ȡ���ֽ�
    void settle(int date);                     // ������Ϣ��ÿ��1��1�յ���һ�θú���
    void show();                               // ��ʾ�˻���Ϣ
};

#endif          // _ACCOUNT_H_