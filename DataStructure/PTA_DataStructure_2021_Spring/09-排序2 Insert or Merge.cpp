#include <iostream>
#include <vector>

using namespace std;

void Print(const vector<int>&nums)
{
    int n = nums.size();
    for(int i = 0;i<n;++i)
    {
        printf("%d",nums[i]);
        if(i!=n-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void Read(vector<int>&nums,const int &n)
{
    for(int i = 0;i<n;++i)
    {
        int num;
        scanf("%d",&num);
        nums.push_back(num);
    }
}

bool Compare(const vector<int>&nums,const vector<int>&standard)
{
    int n = nums.size();
    for(int i = 0;i<n;++i)
    {
        if(nums[i]!=standard[i])
        {
            return false;
        }
    }
    return true;
}

bool insert_sort(vector<int>nums,const vector<int>&standard)
{
    int flag = false;
    int n = nums.size();
    
    for(int j = 1;j<n;++j)
    {
        int temp = nums[j];
        int i = j;
        for(;i>0&&nums[i-1]>temp;--i)
        {
            nums[i]=nums[i-1];
        }
        nums[i]=temp;
        if(Compare(nums,standard))
        {
            flag = true;
        }
        else if(flag)
        {
            printf("Insertion Sort\n");
            Print(nums);
            break;
        }
    }
    return flag;
}

void merge(int L,int R,int REnd,vector<int>&nums,vector<int>&tempNums)
{
    int LEnd = R-1;
    int temp = L;
    while(L<=LEnd&&R<=REnd)
    {
        if(nums[L]<=nums[R])
        {
            tempNums[temp++]=nums[L++];
        }
        else
        {
            tempNums[temp++]=nums[R++];
        }
    }
    while(L<=LEnd)
    {
        tempNums[temp++]=nums[L++];
    }
    while(R<=REnd)
    {
        tempNums[temp++]=nums[R++];
    }
}

void merge_pass(vector<int>&nums,vector<int>&tempNums,int n,int length)
{
    int i = 0;
    for(;i<n-2*length;i+=2*length)
    {
        merge(i,i+length,i+2*length-1,nums,tempNums);
    }
    if(i<n-length)
    {
        merge(i,i+length,n-1,nums,tempNums);
    }
    else
    {
        for(int j = i;j<n;++j)
        {
            tempNums[j] = nums[j];
        }
    }
}

void merge_sort(vector<int>&nums,const vector<int>&standard)
{
    int n = nums.size();
    vector<int>tempNums(n);
    int length = 1;
    bool flag = false;
    
    while(length<n)
    {
        merge_pass(nums,tempNums,n,length);
        if(Compare(tempNums,standard))
        {
            flag = true;
        } 
        else if(flag)
        {
            Print(tempNums);
            break;
        }
        length*=2;
        merge_pass(tempNums,nums,n,length);
        if(Compare(nums,standard))
        {
            flag = true;
        } 
        else if(flag)
        {
            Print(nums);
            break;
        }
        length*=2;
    }
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    
    vector<int>nums;
    vector<int>standard;
    
    Read(nums,n);
    Read(standard,n);
    
    if(!insert_sort(nums,standard))
    {
        printf("Merge Sort\n");
        merge_sort(nums,standard);
    }
    
    return 0;
}
