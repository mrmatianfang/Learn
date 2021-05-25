#include <iostream>
#include <vector>

using namespace std;

const int INT_MAX = 0x7fffffff;

struct weight{
    int length;
    int cost;
    weight():length(INT_MAX),cost(INT_MAX){}
    weight(int l,int c):length(l),cost(c){}
};

class Graph{
private:
    bool Compare(const weight w1,const weight w2);
public:
    int N,M,S,D;
    vector<vector<weight>>graph;
    
    Graph(int _n,int _m,int _s,int _d):N(_n),M(_m),S(_s),D(_d)
    {
        for(int i =0;i<N;++i)
        {
            graph.push_back(vector<weight>(N,weight()));
        }
        for(int i = 0;i<M;++i)
        {
            int s,d,l,c;
            scanf("%d %d %d %d",&s,&d,&l,&c);
            graph[s][d].length = l;
            graph[s][d].cost = c;
            graph[d][s].length = l;
            graph[d][s].cost = c;
        }
    }
    void Dijkstra();
};

bool Graph::Compare(const weight w1,const weight w2)
{
    return w1.length==w2.length?w1.cost<w2.cost:w1.length<w2.length;
}

void Graph::Dijkstra()
{
    vector<weight>dist(N,weight());
    vector<int>visited(N,0);
    
    dist[S]=weight(0,0);
    
    while(1)
    {
        weight temp = weight();
        int node = -1;
        
        for(int i = 0;i<N;++i)
        {
            if(!visited[i]&&Compare(dist[i],temp))
            {
                temp = dist[i];
                node = i;
            }
        }
        
        if(node == -1)
        {
            break;
        }
        
        visited[node]=1;
        
        for(int i = 0;i<N;++i)
        {
            if(!visited[i]&&graph[node][i].length!=INT_MAX)
            {
                temp = weight(dist[node].length+graph[node][i].length,dist[node].cost+graph[node][i].cost);
                if(Compare(temp,dist[i]))
                {
                    dist[i] = temp;
                }
            }
        }
    }
    
    printf("%d %d\n",dist[D].length,dist[D].cost);
}

int main()
{
    int n,m,s,d;
    scanf("%d %d %d %d",&n,&m,&s,&d);
    
    Graph g = Graph(n,m,s,d);
    
    g.Dijkstra();
    
    return 0;
}
