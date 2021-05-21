#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    vector<int>nums;
    
    scanf("%d",&N);
    int result = -1;
    int temp = 0;
    int L = 0,R = 0,tL = 0;
    
    for(int i = 0;i<N;++i)
    {
        int num;
        scanf("%d",&num);
        nums.push_back(num);
        temp+=num;
        if(temp>result)
        {
            result = temp;
            R = i;
            L = tL;
        }
        if(temp<0)
        {
            temp = 0;
            tL = i+1;
        }
    }
    
    if(result<0)
    {
        printf("0 %d %d\n",nums[0],nums[N-1]);
    }
    else
    {
        printf("%d %d %d\n",result,nums[L],nums[R]);
    }
    
    return 0;
}
