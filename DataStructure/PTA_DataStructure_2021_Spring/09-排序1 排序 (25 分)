#include <iostream>
#include <vector>
#include <cmath>

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

// -----------------------------冒泡排序-----------------------------
void bubble_sort(vector<int>&nums)
{
    int n = nums.size();
    for(int P = n - 1;P>0;--P)
    {
        int flag = 0;
        for(int j = 0;j<P;++j)
        {
            if(nums[j]>nums[j+1])
            {
                flag = 1;
                swap(nums[j],nums[j+1]);
            }
        }
        if(flag==0)
        {
            break;
        }
    }
}

// -----------------------------插入排序-----------------------------
void insertion_sort(vector<int>&nums)
{
    int n = nums.size();
    for(int i = 1;i<n;++i)
    {
        int temp = nums[i];
        int j = i;
        for(;j>0&&nums[j-1]>temp;--j)
        {
            nums[j] = nums[j-1];
        }
        nums[j] = temp;
    }
}

// -----------------------------希尔排序-----------------------------
void shell_sort(vector<int>&nums)
{
    int n = nums.size();
    for(int D = n/2;D>=1;D/=2)
    {
        for(int P = D;P<n;++P)
        {
            int temp = nums[P];
            int i = P;
            for(;i>=D&&nums[i-D]>temp;i-=D)
            {
                nums[i] = nums[i-D];
            }
            nums[i] = temp;
        }
    }
}

// ------------------------------堆排序------------------------------
void PercDown(vector<int>&nums,int top,int n)
{
    int parent = top,child = 2*parent+1;
    int temp = nums[top];
    for(;2*parent+1<n;parent = child)
    {
        child = 2*parent+1;
        if(child+1<n&&nums[child+1]>nums[child])
        {
            child+=1;
        }
        if(nums[child]<temp)
        {
            break;
        }
        nums[parent] = nums[child];
    }
    nums[parent] = temp;
}

void heap_sort(vector<int>&nums)
{
    int n = nums.size();
    // build heap,建立最大堆
    for(int i = n/2;i>=0;--i)
    {
        PercDown(nums,i,n);
    }
    for(int i = n-1;i>=0;--i)
    {
        swap(nums[0],nums[i]);
        PercDown(nums,0,i);
    }
}

// -----------------------------归并排序-----------------------------
    // 递归
void Merge(vector<int>&nums,vector<int>&tempNums,int L,int R,int RightEnd)
{
    int num_of_elements = RightEnd - L + 1;
    int temp = L;
    int LeftEnd = R-1;
    
    while(L<=LeftEnd&&R<=RightEnd)
    {
        if(nums[L]<nums[R])
        {
            tempNums[temp++] = nums[L++];
        }
        else
        {
            tempNums[temp++] = nums[R++];
        }
    }
    
    while(L<=LeftEnd)
    {
        tempNums[temp++] = nums[L++];
    }
    while(R<=RightEnd)
    {
        tempNums[temp++] = nums[R++];
    }
    
    for(int i = RightEnd;i>=RightEnd - num_of_elements;--i)
    {
        nums[i] = tempNums[i];
    }
}

void MSort(vector<int>&nums,vector<int>&tempNums,int L,int RightEnd)
{
    if(L<RightEnd)
    {
        int Center = (L+RightEnd)>>1;
        MSort(nums,tempNums,L,Center);
        MSort(nums,tempNums,Center+1,RightEnd);
        Merge(nums,tempNums,L,Center+1,RightEnd);
    }
}

    // 迭代
void Merge1(vector<int>&nums,vector<int>&tempNums,int L,int R,int RightEnd)
{
    int temp = L;
    int LeftEnd = R-1;
    
    while(L<=LeftEnd&&R<=RightEnd)
    {
        if(nums[L]<nums[R])
        {
            tempNums[temp++] = nums[L++];
        }
        else
        {
            tempNums[temp++] = nums[R++];
        }
    }
    
    while(L<=LeftEnd)
    {
        tempNums[temp++] = nums[L++];
    }
    while(R<=RightEnd)
    {
        tempNums[temp++] = nums[R++];
    }
}

void merge_pass(vector<int>&nums,vector<int>&tempNums,int n,int length)
{
    int i = 0;
    for(;i<n-2*length;i+=2*length)
    {
        Merge1(nums,tempNums,i,i+length,i+2*length-1);
    }
    if(i+length<n)
    {
        Merge1(nums,tempNums,i,i+length,n-1);
    }
    else
    {
        for(int j = i;j<n;++j)
        {
            tempNums[j] = nums[j];
        }
    }
}

void merge_sort(vector<int>&nums)
{
    int n = nums.size();
    vector<int>tempNums(n);
    // 递归
    // MSort(nums,tempNums,0,n-1);
    
    // 迭代
    int length = 1;
    while(length<n)
    {
        merge_pass(nums,tempNums,n,length);
        length*=2;
        merge_pass(tempNums,nums,n,length);
        length*=2;
    }
}


// -----------------------------快速排序-----------------------------
int getPivot(vector<int>&nums,int left,int right)
{
    int center = (left+right)>>1;
    if(nums[left]>nums[center])
    {
        swap(nums[left],nums[center]);
    }
    if(nums[left]>nums[right])
    {
        swap(nums[left],nums[right]);
    }
    if(nums[center]>nums[right])
    {
        swap(nums[center],nums[right]);
    }
    swap(nums[center],nums[right-1]);
    return nums[right - 1];
}

void Qsort(vector<int>&nums,int l,int r)
{
    if(r-l>0)
    {
        int pivot = getPivot(nums,l,r);
        int left = l,right = r - 1;
        while(left<right)
        {
            while(nums[--right]>pivot);
            while(nums[++left]<pivot);
            if(left<right)
            {
                swap(nums[left],nums[right]);
            }
        }
        swap(nums[left],nums[r-1]);
        Qsort(nums,l,left-1);
        Qsort(nums,left+1,r);
    }
}

void quick_sort(vector<int>&nums)
{
    int n = nums.size();
    Qsort(nums,0,n-1);
}

// ------------------------------桶排序------------------------------
void bucket_sort(vector<int>&nums)
{
    if(nums.size()==1)
    {
        return;
    }
    vector<vector<int>>buckets_positive(10);
    vector<vector<int>>buckets_negative(10);
    
    const int N = 5;
    
    for(int i = 0;i<N;++i)
    {
        for(auto num:nums)
        {
            if(num>0)
            {
                buckets_positive[(num/static_cast<int>(pow(10,i)))%10].push_back(num);
            }
            else
            {
                buckets_negative[(-1*num/static_cast<int>(pow(10,i)))%10].push_back(-1*num);
            }
        }
        nums.clear();
        for(int j = 9;j>=0;--j)
        {
            for(auto num:buckets_negative[j])
            {
                nums.push_back(num*-1);
            }
            buckets_negative[j].clear();
        }
        for(int j = 0;j<10;++j)
        {
            for(auto num:buckets_positive[j])
            {
                nums.push_back(num);
            }
            buckets_positive[j].clear();
        }
    }
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    vector<int>nums;
    
    for(int i = 0;i<n;++i)
    {
        int num = 0;
        scanf("%d",&num);
        nums.push_back(num);
    }
    
    // bubble_sort(nums);
    
    // insertion_sort(nums);
    
    // shell_sort(nums);
    
    // heap_sort(nums);
    
    // merge_sort(nums);
    
    // quick_sort(nums);
    
    // 复数处理遇到问题,需要分成两堆，正数一堆，复数一堆，分别处理
    // bucket_sort(nums);
    
    Print(nums);
    
    return 0;
}
