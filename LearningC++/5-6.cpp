/*友元函数*/

#include<iostream>
#include<cmath>
using namespace std;

class Point{
    private:
        int x, y;
    public:
        Point(int xx=0, int yy=0):x(xx),y(yy){}
        int getX(){return x;}
        int getY(){return y;}
        friend float dist(Point &p1, Point &p2);
};

float dist(Point &p1, Point &p2){      // 友元实现  
    double distance, x, y;

    x = p1.x - p2.x;
    y = p1.y - p2.y;
    distance =  static_cast<float>(sqrt(x*x+y*y));
    return distance;
}

float dist2(Point p1, Point p2){     // 一般实现
    double distance, x, y;

    x = p1.getX() - p2.getX();
    y = p1.getY() - p2.getY();
    distance =  static_cast<float>(sqrt(x*x+y*y));
    return distance;
}


int main(){
    double d1, d2;
    Point myp1(1,1), myp2(2,3);
    d1 = dist(myp1, myp2);         // 友元实现
    d2 = dist2(myp1, myp2);        // 一般实现

    cout<<"The diatance of two points is: "<<d1<<"\t"<<d2<<endl;
}