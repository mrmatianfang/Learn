#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph{
private:
    
public:
    int nv,ne;
    vector<vector<int>>edges;
    
    Graph(int n,int e):nv(n),ne(e)
    {
        edges.resize(n+1);
    }
    void init();
    void insertEdge(const int &x,const int &y);
    int BFS(int num);
    void solve();
};

void Graph::insertEdge(const int &x,const int &y)
{
    edges[x].push_back(y);
    edges[y].push_back(x);
}

void Graph::init()
{
    for(int i = 0;i<ne;++i)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        insertEdge(x,y);
    }
}

int Graph::BFS(int num)
{
    queue<int>q;
    int count = 0;
    int level = 0;
    q.push(num);
    
    vector<int>visited(nv+1,0);
    
    while(!q.empty())
    {
        int n = q.size();
        level+=1;
        for(int i = 0;i<n;++i)
        {
            num = q.front();
            q.pop();
            visited[num]=1;
            count+=1;
            for(int j = 0;j<edges[num].size();++j)
            {
                if(!visited[edges[num][j]])
                {
                    visited[edges[num][j]]=1;
                    q.push(edges[num][j]);
                }
            }
        }
        if(level>6)
        {
            break;
        }
    }
    return count;
}

void Graph::solve()
{
    for(int i = 1;i<=nv;++i)
    {
        int sum = BFS(i);
        printf("%d: %.2f%%\n",i,(100.0*sum/nv));
    }
}

int main()
{
    int n,e;
    scanf("%d %d",&n,&e);
    Graph g = Graph(n,e);
    
    g.init();
    
    g.solve();
    
    return 0;
}
