#include <iostream>
#include <vector>

using namespace std;

int Find(const vector<int>&computers,int num)
{
    while(computers[num]>0)
    {
        num = computers[num];
    }
    return num;
}

void Union(vector<int>&computers,int x,int y)
{
    int root1 = Find(computers,x);
    int root2 = Find(computers,y);
    // 父母不相同
    if(root1!=root2)
    {
        if(computers[root1]>computers[root2])
        {
            computers[root2]+=computers[root1];
            computers[root1] = y;
        }
        else
        {
            computers[root1]+=computers[root2];
            computers[root2] = x;
        }
    }
}

bool check(vector<int>&computers,int x,int y)
{
    return Find(computers,x)==Find(computers,y);
}

int main()
{
    int N;
    scanf("%d",&N);
    
    vector<int>computers(N+1,-1);
    
    char op;
    while(1)
    {
        int x,y;
        scanf("\n%c %d %d",&op,&x,&y);
        if(op=='I')
        {
            Union(computers,x,y);
        }
        else if(op=='C')
        {
            if(check(computers,x,y))
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
        else if(op=='S')
        {
            break;
        }
    }
    
    int count = 0;
    for(int i = 1;i<=N;++i)
    {
        if(computers[i]<0)
        {
            count+=1;
        }
    }
    
    if(count==1)
    {
        printf("The network is connected.\n");
    }
    else 
    {
        printf("There are %d components.\n",count);
    }
    
    return 0;
}
