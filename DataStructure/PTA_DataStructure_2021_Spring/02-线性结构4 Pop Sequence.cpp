#include <iostream>
#include <stack>

using namespace std;

bool check(int M,int N)
{
    stack<int>stk;
    int count = 1;
    bool flag = true;
    for(int i = 0;i<N;++i)
    {
        int num = 0;
        scanf("%d",&num);
        
        if(flag)
        {
            while(count<=num||stk.empty())
            {
                stk.push(count);
                count+=1;
                if(stk.size()>M)
                {
                    flag = false;
                    break;
                }
            }
            if(stk.top()!=num)
            {
                flag = false;
            }
            stk.pop();
        }
    }
    
    return flag;
}

int main()
{
    int M,N,K;
    scanf("%d %d %d",&M,&N,&K);
    
    for(int i = 0;i<K;++i)
    {
        if(check(M,N))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    
    return 0;
}
