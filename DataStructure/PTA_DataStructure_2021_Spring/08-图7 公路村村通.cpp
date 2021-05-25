// prim & kruskal
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int s,e;
    int weight;
    Edge(int _s,int _e,int _w):s(_s),e(_e),weight(_w){}
};

class MST{
private:
    const int INT_MAX = 0x7fffffff;
    
    // Kruskal
    vector<int>parent;
    vector<Edge>edges;
    int Find(int node);
    bool Union(int x,int y);
    
public:
    int N,M;
    vector<vector<int>>graph;

    MST(int n,int m):N(n),M(m)
    {
        for(int i = 0;i<=N;++i)
        {
            graph.push_back(vector<int>(N+1,INT_MAX));
        }
        for(int i = 0;i<M;++i)
        {
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            
            graph[x][y]=w;
            graph[y][x]=w;
            
            edges.push_back(Edge(x,y,w));
        }
    }
    void Kruskal();
    void Prim();
};

// ------------------------------------Prim------------------------------------
void MST::Prim()
{
    vector<int>collected(N+1,0);
    vector<int>dist(N+1,INT_MAX);
    int result = 0;
    
    int node = 1;
    dist[node]=0;
    
    // 执行n-1次
    int count = 0;
    for(int a = 0;a<N;++a)
    {
        int minDist = INT_MAX;
        node = -1;
        for(int i = 1;i<=N;++i)
        {
            if(!collected[i]&&dist[i]<minDist)
            {
                minDist = dist[i];
                node = i;
            }
        }
        if(node==-1)
        {
            break;
        }
        
        result+=minDist;
        collected[node]=1;
        count+=1;
        
        for(int i = 1;i<=N;++i)
        {
            if(!collected[i]&&dist[i]>graph[node][i])
            {
                dist[i]=graph[node][i];
            }
        }
    }
    if(count==N)
    {
        printf("%d\n",result);
    }
    else
    {
        printf("-1\n");
    }
}

// -----------------------------------Kruskal-----------------------------------
int MST::Find(int node)
{
    while(parent[node]>0)
    {
        node = parent[node];
    }
    return node;
}

bool MST::Union(int x,int y)
{
    int root1 = Find(x);
    int root2 = Find(y);
    if(root1!=root2)
    {
        if(parent[root1]<parent[root2])
        {
            parent[root2]+=parent[root1];
            parent[root1] = y;
        }
        else
        {
            parent[root1]+=parent[root2];
            parent[root2] = x;
        }
        return true;
    }
    return false;
}

void MST::Kruskal()
{
    // 初始化
    for(int i = 0;i<=N;++i)
    {
        parent.push_back(-1);
    }
    
    // 排序
    sort(edges.begin(),edges.end(),[&](const Edge &e1,const Edge &e2){
        return e1.weight<e2.weight;
    });
    
    int count = 0;
    int result = 0;
    for(int i = 0;i<M;++i)
    {
        int x = edges[i].s,y = edges[i].e;
        if(Union(x,y))
        {
            count+=1;
            result+=edges[i].weight;
        }
        if(count==N-1)
        {
            break;
        }
    }
    if(count!=N-1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",result);
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    MST mst = MST(n,m);

    mst.Prim();

    //mst.Kruskal();

    return 0;
}
