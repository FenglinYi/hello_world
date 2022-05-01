class Point{
    private:
        int x, y;
        static int count;
    public:
        Point(int x=0, int y=0):x(x),y(y){count++;}
        Point(const Point &p);
        ~Point(){--count;}
        int getX(){return x;}
        int getY(){return y;}
        static void showCount();
};