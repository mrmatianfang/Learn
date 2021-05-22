#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 层序遍历
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

// 2^H-1+X=N
// H = log(N+1)
// L = 2^n-1+X
int getLeftLength(int n)
{
    int H = static_cast<int>(log(n+1)/log(2));
    int X = n+1-static_cast<int>(pow(2,H));
    X = min(X,static_cast<int>(pow(2,H-1)));
    return X+static_cast<int>(pow(2,H-1))-1;
}

void solve(int numLeft,int numRight,int TRoot,vector<int>&result,const vector<int>&nums)
{
    int n = numRight - numLeft + 1;
    if(n==0)
    {
        return;
    }
    
    int L = getLeftLength(n);
    
    result[TRoot] = nums[numLeft+L];
    
    solve(numLeft,numLeft+L-1,2*TRoot+1,result,nums);
    
    solve(numLeft+L+1,numRight,2*TRoot+2,result,nums);
    
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    
    vector<int>nums;
    vector<int>result(n);
    
    for(int i = 0;i<n;++i)
    {
        int num;
        scanf("%d",&num);
        nums.push_back(num);
    }
    
    sort(nums.begin(),nums.end());
    
    solve(0,n-1,0,result,nums);
    
    Print(result);
    
    return 0;
}
