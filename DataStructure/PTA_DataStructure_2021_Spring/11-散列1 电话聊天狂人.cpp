// my hash map
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct phoneNumber{
    string number;
    int times;
    phoneNumber(string num):number(num),times(1){}
};

class HashMap{
private:
    const int base = 100000;
public:
    vector<vector<phoneNumber>>numbers;

    HashMap()
    {
        numbers.resize(base);
    }

    int getHash(string number);
    int insert(string number);
};

int HashMap::getHash(string number)
{
    return stoi(number.substr(6))%base;
}

int HashMap::insert(string number)
{
    int hash = getHash(number);
    for(auto &num:numbers[hash])
    {
        if(num.number==number)
        {
            num.times+=1;
            return num.times;
        }
    }
    numbers[hash].push_back(phoneNumber(number));
    return 1;
}

int main()
{
    int n = 0;
    scanf("%d",&n);

    HashMap h = HashMap();
    int nums = 0;
    int maxTime = 0;
    string result="123456789101";

    for(int i = 0;i<n;++i)
    {
        string from,to;
        cin>>from>>to;

        int t1 = h.insert(from);
        if(t1>maxTime)
        {
            nums = 1;
            maxTime = t1;
            result = from;
        }
        else if(t1==maxTime)
        {
            nums+=1;
            if(result>from)
            {
                result = from;
            }
        }
        int t2 = h.insert(to);
        if(t2>maxTime)
        {
            nums = 1;
            maxTime = t2;
            result = to;
        }
        else if(t2==maxTime)
        {
            nums+=1;
            if(result>to)
            {
                result = to;
            }
        }
    }

    cout<<result<<" "<<maxTime;
    if(nums!=1)
    {
        cout<<" "<<nums;
    }

    return 0;
}


// unordered_map
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
