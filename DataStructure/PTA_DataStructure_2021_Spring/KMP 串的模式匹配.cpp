#include <iostream>
#include <string>
#include <vector>

using namespace std;

void GetMatch(vector<int>&match,const string &pattern)
{
    int n = pattern.size();
    for(int i = 1;i<n;++i)
    {
        int j = match[i-1];
        while(j>=0&&pattern[j+1]!=pattern[i])
        {
            j = match[j];
        }
        if(pattern[j+1]==pattern[i])
        {
            match[i]=j+1;
        }
        else
        {
            match[i]=-1;
        }
    }
}

int KMP(const string &standard,const string &pattern)
{
    int n = standard.size(),m = pattern.size();
    int s = 0,p = 0;
    
    vector<int>match(m,-1);
    GetMatch(match,pattern);
    
    while(s<n&&p<m)
    {
        if(standard[s]==pattern[p])
        {
            ++s;
            ++p;
        }
        else if(p>0)
        {
            p = match[p-1]+1;
        }
        else
        {
            ++s;
        }
    }
    
    return p==m?s-m:-1;
}

int main()
{
    string standard;
    int n = 0;
    
    cin>>standard;
    scanf("%d",&n);
    
    for(int i = 0;i<n;++i)
    {
        string pattern;
        cin>>pattern;
        
        int p = KMP(standard,pattern);
        if(p==-1)
        {
            printf("Not Found\n");
        }
        else
        {
            cout<<standard.substr(p)<<endl;
        }
    }
    
    return 0;
}
