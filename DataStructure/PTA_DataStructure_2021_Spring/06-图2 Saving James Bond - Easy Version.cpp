#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int Read(vector<pair<int,int>>&cor)
{
    int n,d;
    scanf("%d %d",&n,&d);
    
    for(int i = 0;i<n;++i)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        cor.push_back({x,y});
    }
    
    return d;
}

double GetDistance(const int x1,const int y1,const int x2,const int y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

bool CanJump(const int x1,const int y1,const int x2,const int y2,const int d)
{
    return GetDistance(x1,y1,x2,y2)<=d;
}

bool IsSafe(int x,int y,int d)
{
    return abs(x)+d>=50||abs(y)+d>=50;
}

bool DFS(int node,vector<int>&visit,const int &d,const vector<pair<int,int>>&cor)
{
    visit[node]=1;
    int n = cor.size();
    int x = cor[node].first,y = cor[node].second;
    bool answer = false;
    
    if(IsSafe(x,y,d))
    {
        answer = true;
    }
    else
    {
        for(int i = 0;i<n;++i)
        {
            if(!visit[i]&&CanJump(x,y,cor[i].first,cor[i].second,d))
            {
                answer = DFS(i,visit,d,cor);
            }
            if(answer)
            {
                break;
            }
        }
    }
    return answer;
}

int main()
{
    vector<pair<int,int>>cor;
    
    int d = Read(cor);
    int n = cor.size();
    
    vector<int>visit(n,0);
    bool answer = false;
    
    for(int i = 0;i<n;++i)
    {
        int x = cor[i].first,y = cor[i].second;
        if(!visit[i]&&CanJump(0,0,x,y,d+15))
        {
            answer = DFS(i,visit,d,cor);
        }
        if(answer)
        {
            break;
        }
    }
    
    printf("%s\n",answer?"Yes":"No");
    
    return 0;
}
