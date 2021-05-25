#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using pEdge = struct Edge*;
struct Edge{
    int s,e,w;
    Edge(int start,int end,int weight):s(start),e(end),w(weight){}
};

class AOE{
private:
    vector<int>indegree;
public:
    int N,M;
    vector<pEdge>edges;
    
    AOE(int n,int m):N(n),M(m)
    {
        indegree.resize(N);
        for(int i =0;i<M;++i)
        {
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            edges.push_back(new Edge(x,y,w));
            indegree[y]+=1;
        }
    }
    void TopSort();
};

void AOE::TopSort()
{
    queue<int>q;
    vector<int>dist(N,0);
    
    for(int i =0;i<N;++i)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    
    int last = 0;
    int count = 0;
    
    while(!q.empty())
    {
        int V = q.front();
        q.pop();
        last = V;
        count+=1;
        
        for(auto edge = edges.begin();edge!=edges.end();)
        {
            // V指向的点
            if((*edge)->s==V)
            {
                if(--indegree[(*edge)->e]==0)
                {
                    q.push((*edge)->e);
                }
                dist[(*edge)->e] = max(dist[(*edge)->e],dist[(*edge)->s]+(*edge)->w);
                edges.erase(edge);
            }
            else
            {
                ++edge;
            }
        }
    }
    
    if(count==N)
    {
        printf("%d\n",dist[last]);
    }
    else
    {
        printf("Impossible\n");
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    
    AOE aoe = AOE(n,m);
    
    aoe.TopSort();
    
    return 0;
}
