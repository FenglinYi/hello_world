// 运算符重载为非成员函数

/*  oprd1 B oprd2等价于  operator B(oprd1, oprd2)
    c1+c2 ==>  operator+(c1, c2)
*/

#include<iostream>
using namespace std;


class Complex{
public:
    Complex(double r=0.0, double i =0.0):real(r), imag(i){}
    friend Complex operator+(const Complex &c1, const Complex &c2);
    friend Complex operator-(const Complex &c1, const Complex &c2);
    friend ostream & operator<<(ostream & out, const Complex &c);          // 是ostream类型的一个引用
private:
    double real;
    double imag;
};

Complex operator+(const Complex &c1, const Complex &c2){
    return Complex(c1.real+c2.real, c1.imag+c2.imag);
}

Complex operator-(const Complex &c1, const Complex &c2){
    return Complex(c1.real-c2.real, c1.imag-c2.imag);
}

ostream & operator<<(ostream & out, const Complex &c){
    out<<"("<<c.real<<","<<c.imag<<")";
    return out;            // out以引用的方式返回，可以实现连续输出
}

int main(){
    Complex c1(3, 5.2), c2(4.0, 9), c3;
    cout<<c1<<" "<<c2<<endl;

    c3 = c1+c2;
    cout<<c3<<endl;

    c3=c1-c2;
    cout<<c3<<endl;
}