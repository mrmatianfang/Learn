#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph{
private:
    const int M_INT_MAX = 0x7fffffff;
public:
    int nv,ne;
    vector<vector<int>>graph;
    
    Graph(int n,int e):nv(n),ne(e)
    {
        for(int i = 0;i<n;++i)
        {
            graph.push_back(vector<int>(n,M_INT_MAX));
        }
        for(int i = 0;i<ne;++i)
        {
            int s,t;
            scanf("%d %d",&s,&t);
            graph[s][t]=1;
            graph[t][s]=1;
        }
    }
    
    void Print(const vector<int>&vec);
    void BFS(int node,vector<int>&visit,vector<int>&result);
    void DFS(int node,vector<int>&visit,vector<int>&result);
    void Solve(int flag);
};

void Graph::Print(const vector<int>&vec)
{
    int n = vec.size();
    
    printf("{ ");
    for(int i = 0;i<n;++i)
    {
        printf("%d ",vec[i]);
    }
    printf("}\n");
}

void Graph::DFS(int node,vector<int>&visit,vector<int>&result)
{
    visit[node]=1;
    result.push_back(node);
    
    for(int i = 0;i<nv;++i)
    {
        if(!visit[i]&&graph[node][i]!=M_INT_MAX)
        {
            DFS(i,visit,result);
        }
    }
}

void Graph::BFS(int node,vector<int>&visit,vector<int>&result)
{
    queue<int>q;
    q.push(node);
    visit[node]=1;
    
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0;i<n;++i)
        {
            node = q.front();
            q.pop();
            result.push_back(node);
            
            for(int i = 0;i<nv;++i)
            {
                if(!visit[i]&&graph[node][i]!=M_INT_MAX)
                {
                    visit[i]=1;
                    q.push(i);
                }
            }
        }
    }
}

void Graph::Solve(int flag)
{
    vector<int>visit(nv,0);
    vector<int>result;
    
    for(int i = 0;i<nv;++i)
    {
        if(!visit[i])
        {
            result.clear();
            if(flag==0)
            {
                DFS(i,visit,result);
            }
            else if(flag==1)
            {
                BFS(i,visit,result);
            }
            Print(result);
        }
    }
}

int main()
{
    int n,e;
    scanf("%d %d",&n,&e);
    
    Graph g = Graph(n,e);
    
    g.Solve(0);
    
    g.Solve(1);
    
    return 0;
}
