// 输入是"123x46758"代替二维数组，目标状态是提前给定的。程序输出就是需要移动几次
/* 
    有溯源，但是会出现0xfeeefeee：此指针指向的位置已经被释放了， 但释放后，又错误的重新调用了这个无效指针。
    以及报错：terminate called after throwing an instance of 'std::bad_alloc' what(): std::bad_alloc
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
        Node * parent;    // 指向父节点，用于溯源得出最佳路径
    public:
        Node(string s, Node *par=nullptr){          // 构造函数
            state = s;
            parent = par;
        }
        
        void showInfo(){    // 打印路径
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
            queue<Node> open;    // 用来存储九宫格的状态。open表示接下来要遍历的状态，这些状态去衍生出子状态

            unordered_map<string, int> close;  // 用字符串来标记变换次数，字符串做下标。close表示已经出现过的状态

            open.push(*this);       // 初始化状态，第一个状态就是初始输入的状态

            Node *temp = &open.front();
            cout<<temp<<endl;

            close[this->state] = 0;       // 给初始化状态初始化移动次数

            int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};    // 移动的四个方向

            string end = "123804765";	   // 目标状态120345678
            stack<Node> path;              // 解答路径，采用stack来做，逆序压栈，顺序输出，得到正确结果
            int i=0;
            while(open.size())             // 只要q中还有状态，就可以继续搜寻下去            
            {
                Node *t_Node;
                t_Node = &open.front();     // 取出队头状态
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
                int distance = close[t];     // distance代表变换的次数
                int k = t.find('0');         // 返回查找元素的下标(基于0)
                int x = k / 3, y = k % 3;    // 模拟二维数组

                for(int i = 0; i < 4; i++) 	 // 枚举四个方向
                {
                    int a = x + dx[i], b = y + dy[i];     // 原理与走迷宫类似，每次都只会枚举最近的四个点
                    if(a >= 0 && a < 3 && b >= 0 && b < 3)
                    {
                        swap(t[a*3 + b], t[k]);           // 将x的位置K移动到新的位置a*3+b，实现手段是将这两个位置的元素进行交换swap	
                        //所以第一次枚举到最终状态一定是最优解
                        if(!close.count(t))                   // 对移动以后的新状态进行count，只有未枚举过的状态才可以进入队列。map中不存在相同的元素，count只能返回 0 或 1
                        {
                            close[t] = distance + 1;          // 每一次变换，distance都从其上一个状态的基础上加1
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
    for(int i = 0; i < 9; i++)    // 以单个字符的形式输入，再连接成字符串，避免直接以字符串形式输入时将空格输入
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
        cout << "需要执行"<<result.first<<"步" << endl;  // 输出的是需要几次才能完成状态转换，无法完成输出-1  
        if(PRINT){         // 是否需要打印状态变化的路径
            while(!result.second.empty()){       // result.second是path
                result.second.top().showInfo();
                result.second.pop();
            }
        }      
    }
    else
        cout<<"无解！"<<endl;
    end = clock();

    cout<<"total time:"<<double(end-begin)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}