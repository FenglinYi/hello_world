// 运算符重载为成员函数

/*  oprd1 B oprd2等价于  oprd1.operator B(oprd2)
    c1+c2 ==>  c1.operator+(c2)
*/
#include<iostream>
using namespace std;

class Clock{
public:
    Clock(int h=0, int m=0, int s=0);
    void showTime() const;
    Clock &operator++();           // 返回Clock类型的引用
    Clock operator++(int);
private:
    int hour, minute, second;
};

Clock::Clock(int h, int m, int s){
    if(h>=0 && h<24 && h>=0 && h<60 && s>=0 && s<60){
        this->hour = h;
        this->minute = m;
        this->second = s;
    }
    else{
        cout<<"Time error!"<<endl;
    }

}

void Clock::showTime() const{
    cout<<hour<<":"<<minute<<":"<<second<<endl;
}

Clock& Clock::operator++(){
    second++;
    if(second>=60){
        second-=60;
        minute++;
        if(minute>=60){
            minute-=60;
            hour = (hour+1)%24;
        }
    }

    return *this;
}

Clock Clock::operator++(int){
    Clock old = *this;
    ++(*this);
    return old;
}

int main(){
    Clock myclock(23, 59, 59);
    myclock.showTime();

    myclock++;
    myclock.showTime();

    ++myclock;
    myclock.showTime();


}


