/*������*/

#include<iostream>
#include<string>
using namespace std;

class ExamInfo{                  
    private:
        string name;               // �γ���
        enum MODE{                 // �Ʒ�ģʽ
            GRADE, PASS, PERCENTAGE
        } mode;    // modeΪö�ٱ���                
        union{                     // ����ɼ�
            char grade;
            bool pass;
            int percent;
        };

    public:                                        // ��д�������캯��
        ExamInfo(string name, char grade):name(name), mode(GRADE), grade(grade){}

        ExamInfo(string name, bool pass):name(name), mode(PASS), pass(pass){}

        ExamInfo(string name, int percent):name(name), mode(PERCENTAGE), percent(percent){}

        void show();   // ֻ����������������ʵ�֣�����ʵ��������ʵ��

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