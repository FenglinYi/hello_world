#include "6-z_date.h"
#include<iostream>
#include<cstdlib>
using namespace std;

// �洢ƽ���е�ĳ����1��֮ǰ�ж����죬Ϊ����getMaxDay()ʵ�֣���������һ��
namespace{      // namespaceʹ����Ķ���ֻ�ڵ�ǰ�ļ�����Ч
    const int DAYS_BEFORE_MONTH[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
};

Date::Date(int year, int month, int day):year(year), month(month), day(day){
    if(day<=0 || day>getMaxDay()){             // ��õ����ж�����
        cout<<"Invalid date:";
        show();
        cout<<endl;
        exit(1);
    }
    int years = year-1;
    totalDays = years*365+years/4-years/100+years/400+DAYS_BEFORE_MONTH[month-1]+day;   // ��ǰ�����Ǵӹ�ԪԪ��1��1�տ�ʼ�ĵڼ���
    if(isLeapYear() && month>2) totalDays++;  // ����������ҵ�ǰ�·ݴ���2��������+1
}

int Date::getMaxDay() const{                  // ��õ����ж�����
    if(isLeapYear() && month==2){
        return 29;
    }
    else
        return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month-1];
}

void Date::show()const{
     cout<<getYear()<<"-"<<getMonth()<<"-"<<getDay();
}





