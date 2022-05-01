#include<iostream>
using namespace std;

int i = 1;              // 全局变量，具有静态生存期

void other(){
    static int a = 2;   // 静态局部变量，具有全局寿命，局部可见，只在第一次进入函数时被初始化
    static int b;

    int c = 10;
    a += 2;
    i += 32;
    c += 5;
    cout<<"---OTHER---"<<endl;
    cout<<"i: "<<i<<"\ta: "<<a<<"\tb: "<<b<<"\tc: "<<c<<endl;
    b = a;
}

int main(){
    static int a;       // 静态局部变量，具有全局寿命，局部可见，默认初始值为0
    int b=-10;          // b,c为局部变量，具有动态生存期
    int c=0;

    cout<<"---MAIN---"<<endl;
    cout<<"i: "<<i<<"\ta: "<<a<<"\tb: "<<b<<"\tc: "<<c<<endl;

    c+=8;
    other();
    cout<<"---MAIN---"<<endl;
    cout<<"i: "<<i<<"\ta: "<<a<<"\tb: "<<b<<"\tc: "<<c<<endl;

    i += 10;
    other();
    return 0;
}