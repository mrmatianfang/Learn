#include <iostream>
#include <vector>

using namespace std;

using Tree = struct TreeNode*;
struct TreeNode{
    int val;
    Tree left,right;
    // 访问过为1，未访问过为0
    int flag;
    TreeNode():val(0),left(nullptr),right(nullptr),flag(0){}
    TreeNode(int v):val(v),left(nullptr),right(nullptr),flag(0){}
};

Tree Insert(Tree root,int val)
{
    if(root==nullptr)
    {
        root = new TreeNode(val);
    }
    else
    {
        if(root->val>val)
        {
            root->left = Insert(root->left,val);
        }
        else if(root->val<val)
        {
            root->right = Insert(root->right,val);
        }
    }
    return root;
}

bool Search(Tree root,int num)
{
    bool result = true;
    while(root->val!=num)
    {
        if(root->flag==0)
        {
            result = false;
            break;
        }
        if(root->val>num)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    root->flag = 1;
    return result;
}

void ResetTree(Tree root)
{
    if(!root)
    {
        return;
    }
    root->flag = 0;
    ResetTree(root->left);
    ResetTree(root->right);
}

void judge(Tree root,const int &N)
{
    bool result = true;
    for(int i = 0;i<N;++i)
    {
        int num = 0;
        scanf("%d",&num);
        if(result)
        {
            if(!Search(root,num))
            {
                result = false;
            }
        }
    }
    if(result)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}

int main()
{
    int N,L;
    
    while(1)
    {
        scanf("%d",&N);
        if(N==0)
        {
            break;
        }
        scanf("%d",&L);
        
        Tree root = nullptr;
        
        for(int i = 0;i<N;++i)
        {
            int num;
            scanf("%d",&num);
            root = Insert(root,num);
        }
        
        for(int i = 0;i<L;++i)
        {
            ResetTree(root);
            judge(root,N);
        }
    }
    return 0;
}
