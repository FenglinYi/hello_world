#include<iostream>
#include<vector>
using namespace std;
#define RUNNING

void swap(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void test1(){
    char a;
    int b;
    unsigned c;
    string d;
    int *e;

    int _256 = 3;         // _256������Ϊ����ʹ��
    cout<<_256<<endl;

    cout<<sizeof(a)<<" "<<sizeof(b)<<" "<<sizeof(c)<<" "<<sizeof(d)<<" "<<sizeof(e)<<endl;    // 1 4 4 32 8
}


int &test2(int &a){
    a+=3;
    return a;             // ���ñ��뷵��һ����ֵ-->"�ǳ������õĳ�ʼֵ��������ֵ"
}


int main(){
    int x=1, y=100;
    swap(x, y);
    cout<<x<<"\t"<<y<<endl;

    test1();

    cout<<test2(x);

}



