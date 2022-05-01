// 输入是"123x46758"代替二维数组，目标状态是提前给定的。程序输出就是需要移动几次
// 无溯源，直接得出答案的运行时间
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<time.h>

using namespace std;

int bfs(string state)
{
    queue<string> open;    // 用来存储九宫格的状态。open表示接下来要遍历的状态，这些状态去衍生出子状态

    unordered_map<string, int> close;  // 用字符串来标记变换次数，字符串做下标。close表示已经出现过的状态

    open.push(state);       // 初始化状态，第一个状态就是初始输入的状态
    close[state] = 0;       // 给初始化状态初始化移动次数

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};    // 移动的四个方向

    string end = "123804765";	   //目标状态123804765

    while(open.size())             // 只要q中还有状态，就可以继续搜寻下去            
    {
        auto t = open.front();     // 取出队头状态
        open.pop();
        if(t == end) 
            return close[t];

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
    for(int i = 0; i < 9; i++)    // 以单个字符的形式输入，再连接成字符串，避免直接以字符串形式输入时将空格输入
    {
        cin >> s;
        state += *s;
    }
    begin = clock();
    cout << bfs(state) << endl;  // 输出的是需要几次才能完成状态转换，无法完成输出-1
    end = clock();
    cout<<"total time:"<<double(end-begin)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}