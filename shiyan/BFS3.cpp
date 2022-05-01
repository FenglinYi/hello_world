// ������"123x46758"�����ά���飬Ŀ��״̬����ǰ�����ġ��������������Ҫ�ƶ�����
/* 
    ����Դ�����ǻ����0xfeeefeee����ָ��ָ���λ���Ѿ����ͷ��ˣ� ���ͷź��ִ�������µ����������Чָ�롣
    �Լ�����terminate called after throwing an instance of 'std::bad_alloc' what(): std::bad_alloc
*/

#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
#include<time.h>

#define PRINT true

using namespace std;

class Node{
    private:
        string state;
        Node * parent;    // ָ�򸸽ڵ㣬������Դ�ó����·��
    public:
        Node(string s, Node *par=nullptr){          // ���캯��
            state = s;
            parent = par;
        }
        
        void showInfo(){    // ��ӡ·��
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cout<<state[i*3+j]<<" ";
                }
                cout<<endl;
            }
            cout<<"-->"<<endl;
        }


        pair<int, stack<Node>> bfs()
        {
            queue<Node> open;    // �����洢�Ź����״̬��open��ʾ������Ҫ������״̬����Щ״̬ȥ��������״̬

            unordered_map<string, int> close;  // ���ַ�������Ǳ任�������ַ������±ꡣclose��ʾ�Ѿ����ֹ���״̬

            open.push(*this);       // ��ʼ��״̬����һ��״̬���ǳ�ʼ�����״̬

            Node *temp = &open.front();
            cout<<temp<<endl;

            close[this->state] = 0;       // ����ʼ��״̬��ʼ���ƶ�����

            int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};    // �ƶ����ĸ�����

            string end = "123804765";	   // Ŀ��״̬120345678
            stack<Node> path;              // ���·��������stack����������ѹջ��˳��������õ���ȷ���
            int i=0;
            while(open.size())             // ֻҪq�л���״̬���Ϳ��Լ�����Ѱ��ȥ            
            {
                Node *t_Node;
                t_Node = &open.front();     // ȡ����ͷ״̬
                string t = t_Node->state;
                open.pop();
                temp->showInfo();
                cout<<i++<<endl;
                if(t == end){
                    cout<<"haha"<<endl;
                    while (t_Node)
                    {
                        path.push(*t_Node);
                        t_Node = t_Node->parent;
                    }
                    return make_pair(close[t], path);
                }
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
                            open.push(Node(t, parent=t_Node));
                        }
                        swap(t[a*3 + b], t[k]);
                    }
                }
            }
            return make_pair(-1, path);
        }
};




int main()
{
    time_t begin, end;
    pair<int, stack<Node>> result;
    char s[2];
    string state;    
    for(int i = 0; i < 9; i++)    // �Ե����ַ�����ʽ���룬�����ӳ��ַ���������ֱ�����ַ�����ʽ����ʱ���ո�����
    {
        cin >> s;
        state += *s;
    }
    Node originalState(state);

    cout<<sizeof(originalState)<<endl;

    begin = clock();
    result= originalState.bfs();
    cout<<result.second.size()<<endl;
    if(result.first!=-1){
        cout << "��Ҫִ��"<<result.first<<"��" << endl;  // ���������Ҫ���β������״̬ת�����޷�������-1  
        if(PRINT){         // �Ƿ���Ҫ��ӡ״̬�仯��·��
            while(!result.second.empty()){       // result.second��path
                result.second.top().showInfo();
                result.second.pop();
            }
        }      
    }
    else
        cout<<"�޽⣡"<<endl;
    end = clock();

    cout<<"total time:"<<double(end-begin)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}