#include<iostream>
using namespace std;

class Complex{
private:
    double real;
    double imag;
public:
    Complex(double r=0.0, double i=0.0):real(r), imag(i){}
    void display() const;
};