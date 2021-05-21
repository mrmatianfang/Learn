#include <iostream>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    
    int result = 0, temp = 0;
    
    for(int i = 0;i<N;++i)
    {
        int num;
        scanf("%d",&num);
        temp+=num;
        if(temp>result)
        {
            result = temp;
        }
        if(temp<0)
        {
            temp = 0;
        }
    }
    
    printf("%d\n",result);
    
    return 0;
}
