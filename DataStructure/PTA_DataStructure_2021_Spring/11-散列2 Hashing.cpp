#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool IsPrime(const int &num)
{
    if(num<=1)
    {
        return false;
    }
    for(int i = 2;i<=sqrt(num);++i)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    return true;
}

int Insert(const int &num,vector<int>&hashTable,const int &TSize)
{
    int cnum = 0;
    while(cnum<=TSize)
    {
        int index = (num+cnum*cnum)%TSize;
        if(hashTable[index]==0)
        {
            hashTable[index]=num;
            return index;
        }
        cnum+=1;
    }
    return -1;
}

int main()
{
    int TSize,N;
    scanf("%d %d",&TSize,&N);
    
    while(!IsPrime(TSize))
    {
        ++TSize;
    }
    
    vector<int>hashTable(TSize,0);
    
    for(int i = 0;i<N;++i)
    {
        int num = 0;
        scanf("%d",&num);
        num = Insert(num,hashTable,TSize);
        if(num!=-1)
        {
            printf("%d",num);
        }
        else
        {
            printf("-");
        }
        if(i!=N-1)
        {
            printf(" ");
        }
    }
    
    printf("\n");
    
    return 0;
}
