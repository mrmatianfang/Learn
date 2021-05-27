// 拓扑排序
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graph{
private:
    const int INT_MAX = 0x7fffffff;
    int GetMin(vector<int>&temp,const vector<int>&nums);
    
public:
    int N;
    vector<vector<int>>graph;
    vector<int>indegree;

    Graph(int n):N(n)
    {
        indegree.resize(N);
        for(int i = 0;i<n;++i)
        {
            graph.push_back(vector<int>(n,INT_MAX));
        }
    }
    void TopSort(const vector<int>&nums);
    void Print(const vector<int>&nums);
};

void Graph::Print(const vector<int>&nums)
{
    int n = nums.size();
    for(int i = 0;i<n;++i)
    {
        printf("%d",nums[i]);
        if(i!=n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int Graph::GetMin(vector<int>&temp,const vector<int>&nums)
{
    int ret = 0;
    auto d = temp.begin();
    for(auto it = temp.begin();it!=temp.end();++it)
    {
        if(nums[(*it)]<nums[*d])
        {
            d = it;
        }
    }
    ret = *d;
    temp.erase(d);
    return ret;
}

void Graph::TopSort(const vector<int>&nums)
{
    vector<int>temp;
    vector<int>result;
    for(int i = 0;i<N;++i)
    {
        if(indegree[i]==0&&nums[i]>=0)
        {
            temp.push_back(i);
        }
    }

    while(temp.size()!=0)
    {
        int V = GetMin(temp,nums);
        result.push_back(nums[V]);
        for(int i = 0;i<N;++i)
        {
            if(graph[V][i]!=INT_MAX)
            {
                if(--indegree[i]==0)
                {
                    temp.push_back(i);
                }
            }
        }
    }
    Print(result);
}

int main()
{
    int N = 0;
    scanf("%d",&N);
    vector<int>nums(N,0);
    Graph g = Graph(N);

    for(int i = 0;i<N;++i)
    {
        int num = 0;
        scanf("%d",&num);
        nums[i]=num;
        if(num<0)
        {
            // 空
            continue;
        }
        // 获取hash值
        int index = num%N;
        // 存入拓扑图
        while(index!=i)
        {
            g.indegree[i]+=1;
            g.graph[index][i]=1;
            // 循环
            index = (index+1)%N;
        }
    }

    g.TopSort(nums);

    return 0;
}
