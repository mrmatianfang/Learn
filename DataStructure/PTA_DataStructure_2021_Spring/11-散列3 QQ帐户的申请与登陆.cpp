// my map
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct QQNumber{
    string user,password;
    QQNumber(string u,string p):user(u),password(p){}
};

class HashMap{
private:
    const int num_of_qqNumber = 200000;
    int toInt(string s);
    int GetHash(string s);
public:
    int TSize;
    vector<vector<QQNumber>>table;

    HashMap():TSize(num_of_qqNumber)
    {
        table.resize(num_of_qqNumber);
    }
    int Find(QQNumber q);
    int Set(QQNumber q);
};

int HashMap::toInt(string s)
{
    int num = 0;
    for(int i = 3;i<s.size();++i)
    {
        num = num*10+s[i]-'0';
    }
    return num;
}

// 获取哈希值
int HashMap::GetHash(string s)
{

    return (toInt(s) % num_of_qqNumber);
}

int HashMap::Find(QQNumber q)
{
    int index = GetHash(q.user);

    for(int i = 0;i<table[index].size();++i)
    {
        if(table[index][i].user==q.user)
        {
            //密码正确
            if(table[index][i].password==q.password)
            {
                return 0;
            }
            else
            {
                return -2;
            }
        }
    }
    // 用户不存在
    return -1;
}

int HashMap::Set(QQNumber q)
{
    // 已经存在
    if(Find(q)!=-1)
    {
        return -1;
    }
    int index = GetHash(q.user);
    table[index].push_back(q);
    return 0;
}

int main()
{
    int N = 0;
    scanf("%d",&N);
    HashMap h = HashMap();

    for(int i = 0;i<N;++i)
    {
        char op;
        scanf("\n%c",&op);

        string user,pw;
        cin>>user>>pw;
        QQNumber temp = QQNumber(user,pw);

        if(op=='L')
        {
            // login
            int flag = h.Find(temp);
            if(flag==-1)
            {
                printf("ERROR: Not Exist");
            }
            else if(flag==-2)
            {
                printf("ERROR: Wrong PW");
            }
            else
            {
                printf("Login: OK");
            }
        }
        else if(op=='N')
        {
            // new
            int flag = h.Set(temp);
            if(flag == 0)
            {
                printf("New: OK");
            }
            else
            {
                printf("ERROR: Exist");
            }
        }
        printf("\n");
    }

    return 0;
}

// unordered_map
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string,string>hashMap;

int main()
{
    int N = 0;
    scanf("%d",&N);
    
    for(int i = 0;i<N;++i)
    {
        char op;
        scanf("\n%c",&op);
        
        string user,pw;
        cin>>user>>pw;
        
        if(op=='L')
        {
            // login
            if(hashMap.find(user)==hashMap.end())
            {
                printf("ERROR: Not Exist");
            }
            else if(hashMap[user]!=pw)
            {
                printf("ERROR: Wrong PW");
            }
            else
            {
                printf("Login: OK");
            }
        }
        else if(op=='N')
        {
            // new
            if(hashMap.find(user)==hashMap.end())
            {
                hashMap[user]=pw;
                printf("New: OK");
            }
            else
            {
                printf("ERROR: Exist");
            }
        }
        printf("\n");
    }
    
    return 0;
}
