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

void PercDown(vector<int>&nums,int top,int n)
{
    int parent = top,child = 0;
    int num = nums[top];
    for(;2*parent+1<n;parent=child)
    {
        child = 2*parent+1;
        if(child+1<n&&nums[child+1]>nums[child])
        {
            child+=1;
        }
        if(nums[child]<=num)
        {
            break;
        }
        nums[parent] = nums[child];
    }
    nums[parent]=num;
}

void heap_sort(vector<int>&nums,const vector<int>&standard)
{
    int n = nums.size();
    for(int i = n/2;i>=0;--i)
    {
        PercDown(nums,i,n);
    }
    
    bool flag = false;
    
    for(int i = n-1;i>0;--i)
    {
        swap(nums[i],nums[0]);
        PercDown(nums,0,i);
        if(Compare(nums,standard))
        {
            flag = true;
        }
        else if(flag)
        {
            printf("Heap Sort\n");
            Print(nums);
            break;
        }
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
        heap_sort(nums,standard);
    }
    
    return 0;
}
