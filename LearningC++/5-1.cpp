#include<iostream>
using namespace std;

int i;

int main(){
    i = 5;
    {                          // �ֿ������ھֲ�����
        int i=10;
        cout<<i<<endl;         // 10
    }

    cout<<i<<endl;             // 5
}