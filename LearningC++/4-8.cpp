/*联合体*/

#include<iostream>
#include<string>
using namespace std;

class ExamInfo{                  
    private:
        string name;               // 课程名
        enum MODE{                 // 计分模式
            GRADE, PASS, PERCENTAGE
        } mode;    // mode为枚举变量                
        union{                     // 具体成绩
            char grade;
            bool pass;
            int percent;
        };

    public:                                        // 书写三个构造函数
        ExamInfo(string name, char grade):name(name), mode(GRADE), grade(grade){}

        ExamInfo(string name, bool pass):name(name), mode(PASS), pass(pass){}

        ExamInfo(string name, int percent):name(name), mode(PERCENTAGE), percent(percent){}

        void show();   // 只做声明，不做具体实现，具体实现在类外实现

};

void ExamInfo::show(){
    cout<<name<<": ";
    switch (mode)
    {
    case GRADE:
        cout<<grade;
        break;

    case PASS:
        cout<<pass;
        break;

    case PERCENTAGE:
        cout<<percent;
        break;
    default:
        break;
    }
    cout<<endl;
}

int main(){
    ExamInfo course1("English",'B');
    ExamInfo course2("Calculus", true);
    ExamInfo course3("C++ Programming", 85);

    course1.show();
    course2.show();
    course3.show();

    return 0;
}