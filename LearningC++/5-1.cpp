#include<iostream>
using namespace std;

int i;

int main(){
    i = 5;
    {                          // 字块内属于局部变量
        int i=10;
        cout<<i<<endl;         // 10
    }

    cout<<i<<endl;             // 5
}