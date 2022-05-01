/*�������й����˻��������*/

#include<iostream>
#include<cmath>
using namespace std;

class SavingsAccount{     // �����˻���
    private:
        int id;           // �˺�
        double balance;   // ���
        double rate;      // ����������
        int lastDate;      // �ϴα������ʱ��
        double accumulation;   // �����ۼ�֮��

        void record(int date, double amount);  // ��¼һ���ˣ�dateΪ���ڣ�amountΪ��descΪ˵��

        double accumulate(int date) const{     // ��õ�ָ������Ϊֹ�Ĵ������ۻ�ֵ
            return accumulation+balance*(date-lastDate);
        }
    public:
        SavingsAccount(int id, int date, double rate);     // ���캯��

        int getId(){return id;}
        double getBalance(){return lastDate;}
        double getRate(){return rate;}

        void deposit(int date, double amount);     // �����ֽ�
        void withdraw(int date, double amount);    // ȡ���ֽ�
        void settle(int date);                     // ������Ϣ��ÿ��1��1�յ���һ�θú���
        void show();                               // ��ʾ�˻���Ϣ
};

// ���Ա������ʵ��
SavingsAccount::SavingsAccount(int id, int date, double rate):id(id), balance(0), rate(rate), lastDate(date), accumulation(0){
    cout<<date<<"\t"<<id<<" is created"<<endl;
}

void SavingsAccount::record(int date, double amount){  // �޸��������ı䶯���
    accumulation = accumulate(date);
    lastDate = date;
    amount = floor(amount*100+0.5)/100;                // �������뱣����λС����*100�����ã�
    balance += amount;                                 // �������
    cout<<date<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
}

void SavingsAccount::deposit(int date, double amount){    // �����ֽ�
    record(date, amount);
}

void SavingsAccount::withdraw(int date, double amount){   // ȡ���ֽ�
    if(amount<getBalance()){
        cout<<"Error: not enough money"<<endl;
    }
    else
        record(date, -amount);
}

void SavingsAccount::settle(int date){                    // ������Ϣ
    double interst = accumulate(date)*rate/365;
    if(interst!=0) 
        record(date, interst);
    accumulation = 0;
}

void SavingsAccount::show(){                             // ��ʾ
    cout<<"#"<<id<<"\tBalance:"<<balance<<endl;
}

int main(){
    SavingsAccount sa0(21325302, 1, 0.015);
    SavingsAccount sa1(58320212, 1, 0.015);
    sa0.deposit(5, 5000);
    sa1.deposit(25, 10000);
    sa0.deposit(45, 5500);
    sa1.withdraw(60, 4500);

    sa0.settle(90);                      // ������90�쿪ʼ������Ϣ
    sa1.settle(90);

    sa0.show();
    sa1.show();
}



