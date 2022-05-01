/*组合类，复制构造函数*/

#include<iostream>
#include<cmath>
using namespace std;


/******************************* Point *************************/
class Point{
    private:
        int x,y;   //坐标点
    public:
        Point(int xx=0, int yy=0){          // 构造函数
            x = xx;
            y = yy;
        }
        Point(Point &p);                   // 复制构造函数，是一个特殊的构造函数
        int getX(){return x;};
        int getY(){return y;};
};

Point::Point(Point &p){
    x = p.x;                // p.getX();?????这里为什么能直接p.x，x是私有数据?????
    y = p.y;
    cout<<"Calling the copy constructor of Point"<<endl;
}



/******************************* Line *************************/
class Line{
    private:
        Point p1, p2;
        double len;
    public:
        Line(Point xp1, Point xp2);                 // 构造函数
        Line(Line &l);                              // 复制构造函数
        double getLen(){return len;};

};

Line::Line(Point xp1, Point xp2):p1(xp1),p2(xp2){
    cout<<"Calling constructor of line"<<endl;;
    double x = static_cast<double> (p1.getX()-p2.getX());
    double y = static_cast<double> (p1.getY()-p2.getY());
    len = sqrt(x*x+y*y);
}

Line::Line(Line &l):p1(l.p1),p2(l.p2){
    cout<<"Calling the copy constructor of Line"<<endl;
    len = l.len;
}

int main(){
    Point myp1(10,10), myp2(4,5);
    Line line(myp1,myp2);
    Line line2(line);
    cout<<"The length of the line is: "<<endl;
    line.getLen();

    cout<<"The length of the line2 is: "<<endl;
    line2.getLen();

    cout<<myp1.getX();
}




