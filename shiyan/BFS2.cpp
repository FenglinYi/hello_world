// ������"123x46758"�����ά���飬Ŀ��״̬����ǰ�����ġ��������������Ҫ�ƶ�����
// ����Դ��ֱ�ӵó��𰸵�����ʱ��
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<time.h>

using namespace std;

int bfs(string state)
{
    queue<string> open;    // �����洢�Ź����״̬��open��ʾ������Ҫ������״̬����Щ״̬ȥ��������״̬

    unordered_map<string, int> close;  // ���ַ�������Ǳ任�������ַ������±ꡣclose��ʾ�Ѿ����ֹ���״̬

    open.push(state);       // ��ʼ��״̬����һ��״̬���ǳ�ʼ�����״̬
    close[state] = 0;       // ����ʼ��״̬��ʼ���ƶ�����

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};    // �ƶ����ĸ�����

    string end = "123804765";	   //Ŀ��״̬123804765

    while(open.size())             // ֻҪq�л���״̬���Ϳ��Լ�����Ѱ��ȥ            
    {
        auto t = open.front();     // ȡ����ͷ״̬
        open.pop();
        if(t == end) 
            return close[t];

        int distance = close[t];     // distance����任�Ĵ���
        int k = t.find('0');         // ���ز���Ԫ�ص��±�(����0)
        int x = k / 3, y = k % 3;    // ģ���ά����

        for(int i = 0; i < 4; i++) 	 // ö���ĸ�����
        {
            int a = x + dx[i], b = y + dy[i];     // ԭ�������Թ����ƣ�ÿ�ζ�ֻ��ö��������ĸ���
            if(a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[a*3 + b], t[k]);           // ��x��λ��K�ƶ����µ�λ��a*3+b��ʵ���ֶ��ǽ�������λ�õ�Ԫ�ؽ��н���swap	
	            //���Ե�һ��ö�ٵ�����״̬һ�������Ž�
                if(!close.count(t))                   // ���ƶ��Ժ����״̬����count��ֻ��δö�ٹ���״̬�ſ��Խ�����С�map�в�������ͬ��Ԫ�أ�countֻ�ܷ��� 0 �� 1
                {
                    close[t] = distance + 1;          // ÿһ�α任��distance��������һ��״̬�Ļ����ϼ�1
                    open.push(t);
                }
                swap(t[a*3 + b], t[k]);
            }
        }
    }
    return -1;
}

int main()
{
    time_t begin, end;
    char s[2];
    string state;    
    for(int i = 0; i < 9; i++)    // �Ե����ַ�����ʽ���룬�����ӳ��ַ���������ֱ�����ַ�����ʽ����ʱ���ո�����
    {
        cin >> s;
        state += *s;
    }
    begin = clock();
    cout << bfs(state) << endl;  // ���������Ҫ���β������״̬ת�����޷�������-1
    end = clock();
    cout<<"total time:"<<double(end-begin)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}