/*³£ÒıÓÃ*/

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
        friend float dist(const Point &p1, const Point &p2);
};

float dist(const Point &p1, const Point &p2){      
    double distance, x, y;

    x = p1.x - p2.x;
    y = p1.y - p2.y;
    distance =  static_cast<float>(sqrt(x*x+y*y));
    return distance;
}


int main(){
    double d1;
    Point myp1(1,1), myp2(2,3);
    d1 = dist(myp1, myp2);         

    cout<<"The diatance of two points is: "<<d1<<endl;
}