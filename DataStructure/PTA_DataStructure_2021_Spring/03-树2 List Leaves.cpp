#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BuildTree(vector<pair<int,int>>&tree)
{
    int N = 0;
    scanf("%d",&N);
    
    tree.resize(N);
    vector<int>visit(N,0);
    
    for(int i = 0;i<N;++i)
    {
        char l,r;
        scanf("\n%c %c",&l,&r);
        if(l!='-')
        {
            tree[i].first = l-'0';
            visit[l-'0']=1;
        }
        else
        {
            tree[i].first = -1;
        }
        if(r!='-')
        {
            tree[i].second = r-'0';
            visit[r-'0']=1;
        }
        else
        {
            tree[i].second = -1;
        }
    }
    
    int root = -1;
    for(int i = 0;i<N;++i)
    {
        if(!visit[i])
        {
            root = i;
            break;
        }
    }
    return root;
}

void Print(const vector<int>&vec)
{
    int n = vec.size();
    for(int i = 0;i<n;++i)
    {
        printf("%d",vec[i]);
        if(i!=n-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void LevelTraversal(const vector<pair<int,int>>&tree,int root)
{
    vector<int>result;
    queue<int>q;
    q.push(root);
    
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0;i<n;++i)
        {
            root = q.front();
            q.pop();
            if(tree[root].first!=-1)q.push(tree[root].first);
            if(tree[root].second!=-1)q.push(tree[root].second);
            if(tree[root].first==-1&&tree[root].second==-1)
            {
                result.push_back(root);
            }
        }
    }
    
    Print(result);
}

int main()
{
    vector<pair<int,int>>tree;
    
    int root = BuildTree(tree);
    
    LevelTraversal(tree,root);
    
    return 0;
}
