#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

class Graph{
private:
    const int INT_MAX = 0x7fffffff;
    vector<int>firstJump;
    vector<int>minCount;
public:
    int N,D;
    vector<pair<int,int>>cor;

    Graph(int n,int d):N(n),D(d)
    {
        for(int i = 0;i<N;++i)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            cor.push_back({x,y});
        }
    }
    double GetDistance(const int &x1,const int &y1,const int &x2,const int & y2);
    bool CanJump(int x1,int y1,int x2,int y2,double L);
    bool CanSave(int x,int y);
    void GetFisrtJump();
    int BFS(int node,vector<int>&layer,vector<int>&path);
    void Solve();
};

double Graph::GetDistance(const int &x1,const int &y1,const int &x2,const int & y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

bool Graph::CanJump(int x1,int y1,int x2,int y2,double L)
{
    return GetDistance(x1,y1,x2,y2)<=L;
}

bool Graph::CanSave(int x,int y)
{
    return abs(x)+D>=50||abs(y)+D>=50;
}

void Graph::GetFisrtJump()
{
    for(int i = 0;i<N;++i)
    {
        if(CanJump(0,0,cor[i].first,cor[i].second,D+7.5))
        {
            firstJump.push_back(i);
        }
    }
}

int Graph::BFS(int node,vector<int>&layer,vector<int>&path)
{
    // 初始化
    for(int i = 0;i<N;++i)
    {
        layer[i] = INT_MAX;
        path[i] = -1;
    }

    layer[node] = 1;
    queue<int>q;
    vector<int>visited(N,0);
    q.push(node);

    while(!q.empty())
    {
        node = q.front();
        q.pop();
        visited[node]=1;
        int x = cor[node].first,y = cor[node].second;
        if(CanSave(x,y))
        {
            return node;
        }
        for(int i = 0;i<N;++i)
        {
            if(!visited[i]&&CanJump(x,y,cor[i].first,cor[i].second,D))
            {
                visited[i] = 1;
                path[i] = node;
                layer[i] = layer[node]+1;
                q.push(i);
            }
        }
    }

    return -1;
}

void Graph::Solve()
{
    // 获取第一跳
    GetFisrtJump();

    // 对每个第一跳进行BFS
    vector<int>path(N,-1);
    vector<int>layer(N,INT_MAX);
    int flag = -1;
    int minLength = INT_MAX;

    for(int i = 0;i<firstJump.size();++i)
    {
        flag = BFS(firstJump[i],layer,path);
        if(flag!=-1)
        {
            if(layer[flag]<minLength)
            {
                minCount.clear();
                minLength = layer[flag];
                minCount.push_back(firstJump[i]);
            }
            else if(layer[flag]==minLength)
            {
                minCount.push_back(firstJump[i]);
            }
        }
    }

    // 输出
    if(minCount.size()==0)
    {
        // 无结果
        printf("0\n");
    }
    else
    {
        // 找到第一跳最短的结果
        double minL = INT_MAX;
        flag = -1;
        for(int i = 0;i<minCount.size();++i)
        {
            int _l = GetDistance(0,0,cor[minCount[i]].first,cor[minCount[i]].second);
            if(_l<minL)
            {
                minL = _l;
                flag = minCount[i];
            }
        }

        flag = BFS(flag,layer,path);

        printf("%d\n",layer[flag]+1);

        stack<int>stk;

        while(flag!=-1)
        {
            stk.push(flag);
            flag = path[flag];
        }

        while(!stk.empty())
        {
            flag = stk.top();
            stk.pop();
            printf("%d %d\n",cor[flag].first,cor[flag].second);
        }
    }
}

int main()
{
    int n,d;
    scanf("%d %d",&n,&d);

    if(d+7.5>=50)
    {
        printf("1\n");
    }
    else
    {
        Graph g = Graph(n,d);

        g.Solve();
    }
    return 0;
}
