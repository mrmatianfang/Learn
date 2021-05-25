#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class AOV{
private:
    const int INT_MAX = 0x7fffffff;
    int minTime = 0;
    
    // 出入度
    vector<int>indegree;
    vector<int>outdegree;
    
    // 起点
    vector<int>early_s;
    vector<int>late_s;
    
    // 结点数据
    vector<int>earliest;
    vector<int>latest;
    
public:
    int N;
    vector<vector<int>>graph;
    
    AOV(int n,int m):N(n)
    {
        indegree.resize(N+1);
        outdegree.resize(N+1);
        earliest.resize(N+1);
        latest.resize(N+1);
        
        for(int i = 0;i<=N;++i)
        {
            graph.push_back(vector<int>(N+1,INT_MAX));
            latest[i]=INT_MAX;
        }
        
        for(int i = 0;i<m;++i)
        {
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            graph[x][y]=w;
            indegree[y]+=1;
            outdegree[x]+=1;
        }
    }
    
    void Solve();
    int solve_early();
    void solve_late();
};

int AOV::solve_early()
{
    vector<int>visited(N+1,0);
    queue<int>q;
    int count = 0;
    
    for(auto it:early_s)
    {
        q.push(it);
        
        while(!q.empty())
        {
            int V = q.front();
            q.pop();
            visited[V]=1;
            count+=1;
            
            for(int i = 1;i<=N;++i)
            {
                if(!visited[i]&&graph[V][i]!=INT_MAX)
                {
                    if(--indegree[i]==0)
                    {
                        q.push(i);
                    }
                    earliest[i] = max(earliest[i],earliest[V]+graph[V][i]);
                }
            }
        }
    }
    
    if(count!=N)
    {
        return 0;
    }
    else 
    {
        for(auto it:late_s)
        {
            if(earliest[it]>minTime)
            {
                minTime = earliest[it];
            }
        }
        return 1;
    }
}

void AOV::solve_late()
{
    // 直接处理
    vector<int>visited(N+1,0);
    queue<int>q;
    
    for(auto it:late_s)
    {
        q.push(it);
        latest[it]=minTime;
        
        while(!q.empty())
        {
            int V = q.front();
            q.pop();
            visited[V]=1;
            
            for(int i = 1;i<=N;++i)
            {
                if(!visited[i]&&graph[i][V]!=INT_MAX)
                {
                    if(--outdegree[i]==0)
                    {
                        q.push(i);
                    }
                    latest[i] = min(latest[i],latest[V]-graph[i][V]);
                }
            }
        }
    }
}

void AOV::Solve()
{
    for(int i = 1;i<=N;++i)
    {
        if(indegree[i]==0)
        {
            early_s.push_back(i);
        }
        else if(outdegree[i]==0)
        {
            late_s.push_back(i);
        }
    }
    
    if(!solve_early())
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n",minTime);
        
        solve_late();
        
        for(int i = 1;i<=N;++i)
        {
            for(int j = N;j>=1;--j)
            {
                if(graph[i][j]!=INT_MAX&&earliest[i]==(latest[j]-graph[i][j]))
                {
                    printf("%d->%d\n",i,j);
                }
            }
        }
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    
    AOV aov = AOV(n,m);
    
    aov.Solve();
    
    return 0;
}
