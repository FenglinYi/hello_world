/*  相比之前，改进了：
    用字符串来表示账户；每笔账目增加说明；增加报告错误的函数
    用数组来管理多个账户
    使用日期类来表示日期
*/


// date.h， 定义一个类
// 核心是闰年的判断和totalDays的计算
#ifndef _DATE_H_
#define _DATE_H_

class Date{
private:
    int year;
    int month;
    int day;
    int totalDays;          // 当前日期是从公元元年1月1日开始的第几天
public:
    Date(int year, int month, int day);
    int getYear() const {return year;}
    int getMonth() const {return month;}
    int getDay() const {return day;}
    int getMaxDay() const;         // 获得当月有多少天
    bool isLeapYear() const{       // 判断是否是闰年
        return year%4==0 && year%100!=0 || year%400==0;
    } 
    void show() const;             // 输出当前日期
    int distance(const Date & date) const{       // 计算两个日期之间差多少天
        return totalDays-date.totalDays;
    }
};

#endif                 // _DATE_H_