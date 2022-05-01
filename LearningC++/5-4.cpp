/*��̬���ݳ�Ա�;�̬������Ա*/

#include<iostream>
using namespace std;

class Point{
    private:
        int x, y;
        static int count;          // ���ж�����countֵ
    public:
        Point(int x=0, int y=0):x(x),y(y){
            count++;  // �ڹ��캯���ж�count�����ۼӣ����ж���ͬά��ͬһ��count
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
        b.showCount();               // ��������������ֿ飬�����ھͽ����ˣ�count�ͻ��1
    } 

    Point c(a);
    cout<<"Point C: "<<c.getX()<<", "<<c.getY()<<endl;
    c.showCount();  

    Point::showCount();              // ��̬���캯����û�ж���������Ҳ����ֱ�ӵ��ã�ʹ����������

    return 0;

}