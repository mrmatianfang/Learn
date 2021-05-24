#include <iostream>
#include <vector>

using namespace std;

const int INT_MAX = 99999999;

class Graph{
private:
    
public:
    int nv,ne;
    vector<vector<int>>graph;
    
    Graph(int n,int e):nv(n),ne(e)
    {
        for(int i = 0;i<=nv;++i)
        {
            graph.push_back(vector<int>(nv+1,INT_MAX));
        }
    }
    void Init();
    pair<int,int> Floyd();
};

void Graph::Init()
{
    for(int i = 0;i<ne;++i)
    {
        int s,e,w;
        scanf("%d %d %d",&s,&e,&w);
        graph[s][e]=w;
        graph[e][s]=w;
    }
}

pair<int,int> Graph::Floyd()
{
    for(int k = 1;k<=nv;++k)
    {
        for(int i = 1;i<=nv;++i)
        {
            for(int j = 1;j<=nv;++j)
            {
                if(graph[i][j]>graph[i][k]+graph[k][j])
                {
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }
    
    int number = -1;
    int minData = INT_MAX;
    for(int i = 1;i<=nv;++i)
    {
        int temp = 0;
        for(int j = 1;j<=nv;++j)
        {
            if(i!=j&&graph[i][j]>temp)
            {
                temp = graph[i][j];
            }
            if(temp==INT_MAX)
            {
                return {-1,0};
            }
        }
        if(temp<minData)
        {
            number = i;
            minData = temp;
        }
    }
    return {number,minData};
}

int main()
{
    int n,e;
    scanf("%d %d",&n,&e);
    
    Graph g = Graph(n,e);
    
    g.Init();
    
    pair<int,int>result = g.Floyd();
    
    if(result.first==-1)
    {
        printf("0\n");
    }
    else
    {
        printf("%d %d\n",result.first,result.second);
    }
    
    return 0;
}
