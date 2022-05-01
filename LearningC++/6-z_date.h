/*  ���֮ǰ���Ľ��ˣ�
    ���ַ�������ʾ�˻���ÿ����Ŀ����˵�������ӱ������ĺ���
    ����������������˻�
    ʹ������������ʾ����
*/


// date.h�� ����һ����
// ������������жϺ�totalDays�ļ���
#ifndef _DATE_H_
#define _DATE_H_

class Date{
private:
    int year;
    int month;
    int day;
    int totalDays;          // ��ǰ�����Ǵӹ�ԪԪ��1��1�տ�ʼ�ĵڼ���
public:
    Date(int year, int month, int day);
    int getYear() const {return year;}
    int getMonth() const {return month;}
    int getDay() const {return day;}
    int getMaxDay() const;         // ��õ����ж�����
    bool isLeapYear() const{       // �ж��Ƿ�������
        return year%4==0 && year%100!=0 || year%400==0;
    } 
    void show() const;             // �����ǰ����
    int distance(const Date & date) const{       // ������������֮��������
        return totalDays-date.totalDays;
    }
};

#endif                 // _DATE_H_