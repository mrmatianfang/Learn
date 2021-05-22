#include <iostream>
#include <unordered_map>

using namespace std;

using pNode = struct Node*;
struct Node{
    int address;
    int val;
    int next;
    pNode nex;
    Node():address(0),val(0),next(0),nex(nullptr){}
    Node(int a,int v,int ne):address(a),val(v),next(ne),nex(nullptr){}
    Node(int a,int v,int ne,pNode n):address(a),val(v),next(ne),nex(n){}
};

pNode Read(int &k)
{
    int start,n;
    unordered_map<int,pNode>hashMap;
    
    scanf("%d %d %d",&start,&n,&k);
    
    for(int i = 0;i<n;++i)
    {
        int a,v,nex;
        scanf("%d %d %d",&a,&v,&nex);
        hashMap[a] = new Node(a,v,nex);
    }
    
    pNode head = new Node(),pHead = head;
    
    while(start!=-1)
    {
        pHead->nex = hashMap[start];
        pHead = pHead->nex;
        start=pHead->next;
    }
    
    return head;
}

void Print(pNode head)
{
    head = head->nex;
    while(head)
    {
        printf("%05d %d ",head->address,head->val);
        if(head->nex)
        {
            printf("%05d",head->next);
        }
        else
        {
            printf("-1");
        }
        printf("\n");
        head = head->nex;
    }
}

pair<pNode,pNode> reverseK(pNode head,pNode tail)
{
    pNode pHead = head,prev = tail->nex;
    while(prev!=tail)
    {
        pNode temp = pHead->nex;
        pHead->nex = prev;
        if(prev)
        {
            pHead->next = prev->address;
        }
        prev = pHead;
        pHead = temp;
    }
    return {tail,head};
}

pNode Reverse(pNode head,int k)
{
    pNode pHead = head->nex,prev = head;
    
    while(pHead)
    {
        pNode tail = pHead;
        int count = 1;
        while(count<k&&tail)
        {
            tail = tail->nex;
            count+=1;
        }
        if(count<k||tail==nullptr)
        {
            break;
        }
        pair<pNode,pNode>result = reverseK(pHead,tail);
        prev->nex = result.first;
        prev->next = result.first->address;
        prev = result.second;
        pHead = prev->nex;
    }
    
    return head;
}

int main()
{
    int k = 0;
    pNode head = Read(k);
    
    head = Reverse(head,k);
    
    Print(head);
    
    return 0;
}
