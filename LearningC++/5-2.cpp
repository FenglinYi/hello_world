#include<iostream>
using namespace std;

int i = 1;              // ȫ�ֱ��������о�̬������

void other(){
    static int a = 2;   // ��̬�ֲ�����������ȫ���������ֲ��ɼ���ֻ�ڵ�һ�ν��뺯��ʱ����ʼ��
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
    static int a;       // ��̬�ֲ�����������ȫ���������ֲ��ɼ���Ĭ�ϳ�ʼֵΪ0
    int b=-10;          // b,cΪ�ֲ����������ж�̬������
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