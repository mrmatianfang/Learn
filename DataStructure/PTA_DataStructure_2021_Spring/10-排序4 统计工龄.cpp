#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int,int>hashMap;

int main()
{
    int n = 0;
    scanf("%d",&n);
    vector<int>nums;
    
    for(int i = 0;i<n;++i)
    {
        int num = 0;
        scanf("%d",&num);
        if(++hashMap[num]==1)
        {
            nums.push_back(num);
        }
    }
    
    sort(nums.begin(),nums.end());
    
    for(auto num:nums)
    {
        printf("%d:%d\n",num,hashMap[num]);
    }
    
    return 0;
}
