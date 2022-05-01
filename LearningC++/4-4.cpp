/*����࣬���ƹ��캯��*/

#include<iostream>
#include<cmath>
using namespace std;


/******************************* Point *************************/
class Point{
    private:
        int x,y;   //�����
    public:
        Point(int xx=0, int yy=0){          // ���캯��
            x = xx;
            y = yy;
        }
        Point(Point &p);                   // ���ƹ��캯������һ������Ĺ��캯��
        int getX(){return x;};
        int getY(){return y;};
};

Point::Point(Point &p){
    x = p.x;                // p.getX();?????����Ϊʲô��ֱ��p.x��x��˽������?????
    y = p.y;
    cout<<"Calling the copy constructor of Point"<<endl;
}



/******************************* Line *************************/
class Line{
    private:
        Point p1, p2;
        double len;
    public:
        Line(Point xp1, Point xp2);                 // ���캯��
        Line(Line &l);                              // ���ƹ��캯��
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




