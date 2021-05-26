#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string,int>hashMap;

void solve(int &maxTime,string &minPhone,string &number,vector<string>&phones)
{
    if(++hashMap[number]>maxTime)
    {
        maxTime = hashMap[number];
        phones.clear();
        phones.push_back(number);
        minPhone = number;
    }
    else if(hashMap[number]==maxTime)
    {
        phones.push_back(number);
        if(minPhone>number)
        {
            minPhone = number;
        }
    }
}

int main()
{
    
    
    int n = 0;
    scanf("%d",&n);
    
    vector<string>phones;
    string minPhone="123456789123";
    int maxTime = 0;
    
    for(int i = 0;i<n;++i)
    {
        string from,to;
        cin>>from>>to;
        solve(maxTime,minPhone,from,phones);
        solve(maxTime,minPhone,to,phones);
    }
    
    if(phones.size()!=1)
    {
        cout<<minPhone<<" "<<hashMap[minPhone]<<" "<<phones.size();
    }
    else
    {
        cout<<phones[0]<<" "<<hashMap[phones[0]];
    }
    
    return 0;
}
