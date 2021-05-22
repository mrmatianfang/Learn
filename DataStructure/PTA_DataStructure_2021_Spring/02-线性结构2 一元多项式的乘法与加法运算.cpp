#include <iostream>

using namespace std;

using pNode = struct Node*;
struct Node{
    int coef,expon;
    pNode next;
    Node():coef(0),expon(0),next(nullptr){}
    Node(int c,int e):coef(c),expon(e),next(nullptr){}
};

void Attach(int c,int e,pNode &head)
{
    if(c==0)
    {
        return;
    }
    head->next = new Node(c,e);
    head = head->next;
}

pNode Read()
{
    int n = 0;
    scanf("%d",&n);
    pNode head = new Node(0,0);
    pNode pHead = head;
    
    for(int i = 0;i<n;++i)
    {
        int c,e;
        scanf("%d %d",&c,&e);
        Attach(c,e,pHead);
    }
    
    return head;
}

void Print(pNode head)
{
    head = head->next;
    if(!head)
    {
        printf("0 0");
    }
    else
    {
        while(head!=nullptr)
        {
            printf("%d %d",head->coef,head->expon);
            if(head->next!=nullptr)
            {
                printf(" ");
            }
            head = head->next;
        }
    }
    printf("\n");
}

pNode PolyAdd(pNode p1,pNode p2)
{
    pNode head = new Node(),pHead = head;
    
    p1=p1->next,p2=p2->next;
    while(p1&&p2)
    {
        if(p1->expon==p2->expon)
        {
            Attach(p1->coef+p2->coef,p1->expon,pHead);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->expon>p2->expon)
        {
            Attach(p1->coef,p1->expon,pHead);
            p1=p1->next;
        }
        else
        {
            Attach(p2->coef,p2->expon,pHead);
            p2=p2->next;
        }
    }
    
    pHead->next = p1?p1:p2;
    
    return head;
}

pNode PolyMul(pNode p1,pNode p2)
{
    pNode head = new Node(),pHead = head;
    pNode ret = new Node();
    
    p1=p1->next,p2=p2->next;
    while(p1)
    {
        pNode p = p2;
        while(p)
        {
            Attach(p1->coef*p->coef,p1->expon+p->expon,pHead);
            p = p->next;
        }
        ret = PolyAdd(ret,head);
        pHead = head;
        p1=p1->next;
    }
    
    return ret;
}

int main()
{
    pNode p1 = Read();
    pNode p2 = Read();
    
    pNode pMul = PolyMul(p1,p2);
    
    Print(pMul);
    
    pNode pAdd = PolyAdd(p1,p2);
    
    Print(pAdd);
    
    return 0;
}
