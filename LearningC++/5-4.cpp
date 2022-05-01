/*静态数据成员和静态函数成员*/

#include<iostream>
using namespace std;

class Point{
    private:
        int x, y;
        static int count;          // 所有对象共享count值
    public:
        Point(int x=0, int y=0):x(x),y(y){
            count++;  // 在构造函数中对count进行累加，所有对象共同维护同一个count
        }

        Point(Point &p){
            x = p.x;
            y = p.y;
            count++;
        }
        ~Point(){count--;}

        int getX(){return x;}
        int getY(){return y;}

        static void showCount(){
            cout<<"Object count="<<count<<endl<<endl;
        }
};

int Point::count = 0;

int main(){
    // Point k;
    Point a(4,5);
    cout<<"Point A: "<<a.getX()<<", "<<a.getY()<<endl;
    a.showCount();


    {
        Point b(9,10);
        cout<<"Point B: "<<b.getX()<<", "<<b.getY()<<endl;
        b.showCount();               // 这个对象出了这个字块，生存期就结束了，count就会减1
    } 

    Point c(a);
    cout<<"Point C: "<<c.getX()<<", "<<c.getY()<<endl;
    c.showCount();  

    Point::showCount();              // 静态构造函数在没有对象的情况下也可以直接调用，使用类名即可

    return 0;

}