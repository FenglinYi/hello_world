#include<iostream>
using namespace std;

class hah{
    private:
        int age;
        double score;
        string name;
    public:
        hah(){}
        hah(int a, double b, string c):age(a), score(b), name(c){}

        int getInfo(){
            cout<<"age:"<<age<<endl;
            cout<<"score:"<<score<<endl;
            cout<<"name:"<<name<<endl;
        }
};

int main(){
    int a = 3;
    int b = a;
    cout<<&a<<endl;
    cout<<&b<<endl;

    hah stu1;
    hah stu2(23, 93.77, "lihua");
    hah stu3 = stu2;
    hah *stu4 = &stu2;
    cout<<&stu1<<endl;
    cout<<&stu2<<endl;
    cout<<&stu3<<endl;
    cout<<&stu4<<endl;
}
