#include <iostream>
#include <vector>

using namespace std;

const int M_INT_MIN = -0x7fffffff;

void Print(const vector<int>&vec,int num)
{
    while(num!=0)
    {
        printf("%d",vec[num]);
        if(num!=1)
        {
            printf(" ");
        }
        num/=2;
    }
    printf("\n");
}

void insertHeap(vector<int>&heap,int num)
{
    heap.push_back(num);
    int n = heap.size() - 1;
    while(heap[n/2]>num)
    {
        heap[n] = heap[n/2];
        n/=2;
    }
    heap[n] = num;
}

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    
    vector<int>heap;
    heap.push_back(M_INT_MIN);
    
    for(int i = 0;i<N;++i)
    {
        int num;
        scanf("%d",&num);
        insertHeap(heap,num);
    }
    
    for(int i = 0;i<M;++i)
    {
        int num = 0;
        scanf("%d",&num);
        Print(heap,num);
    }
    
    return 0;
}
