#include <iostream>
#include <vector>

using namespace std;

// 表排序，计算各种环的数量，公式为N-S+K-2
int main()
{
    int N = 0,S = 0,K = 0;
    scanf("%d",&N);
    vector<int>nums;
    vector<int>table(N);
    
    for(int i = 0;i<N;++i)
    {
        int num;
        scanf("%d",&num);
        nums.push_back(num);
        // 直接表排序
        table[num] = i;
    }
    
    vector<int>visited(N,0);
    
    for(int i = 0;i<N;++i)
    {
        if(visited[i])
        {
            continue;
        }
        int j = i;
        int count = 1;
        while(table[j]!=j)
        {
            swap(j,table[j]);
            count+=1;
            visited[j]=1;
        }
        if(count==1)
        {
            S+=1;
        }
        else if(count>1)
        {
            K+=1;
        }
    }
    
    // 注意公式成立当且仅当三种环全部存在，因此分类讨论
    if(S==N)
    {
        //全部为单元环
        printf("0\n");
    }
    else if(nums[0]==0)
    {
        // 没有带零环
        printf("%d\n",N-S+K);
    }
    else
    {
        printf("%d\n",N-S+K-2);
    }
    
    return 0;
}
