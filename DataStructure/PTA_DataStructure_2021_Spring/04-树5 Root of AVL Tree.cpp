#include <iostream>

using namespace std;

using Tree = struct TreeNode*;
struct TreeNode{
    int val;
    int height;
    Tree left,right;
    TreeNode(int v):val(v),left(nullptr),right(nullptr),height(1){}
};

int getHeight(Tree root)
{
    if(root==nullptr)
    {
        return 0;
    }
    return root->height;
}

int getBalanceFactor(Tree root)
{
    if(root==nullptr)
    {
        return 0;
    }
    return getHeight(root->left)-getHeight(root->right);
}

int getTreeHeight(Tree root)
{
    if(root==nullptr)
    {
        return 0;
    }
    return max(getHeight(root->left),getHeight(root->right))+1;
}

Tree LLRotate(Tree root)
{
    Tree Left = root->left;
    
    Tree temp = Left->right;
    
    Left->right = root;
    
    root->left = temp;
    
    root->height = getTreeHeight(root);
    Left->height = getTreeHeight(Left);
    
    return Left;
}

Tree RRRotate(Tree root)
{
    Tree Right = root->right;
    
    Tree temp = Right->left;
    
    Right->left = root;
    
    root->right = temp;
    
    root->height = getTreeHeight(root);
    Right->height = getTreeHeight(Right);
    
    return Right;
}

// LRRotate = RR + LL
// RLRotate = LL + RR

Tree Insert(Tree root,int num)
{
    if(root==nullptr)
    {
        root = new TreeNode(num);
    }
    else
    {
        if(root->val>num)
        {
            root->left = Insert(root->left,num);
        }
        else if(root->val<num)
        {
            root->right = Insert(root->right,num);
        }
        
        root->height = getTreeHeight(root);
        
        int balanceFactor = getBalanceFactor(root);
        
        // LLRotate
        if(balanceFactor>1&&getBalanceFactor(root->left)>0)
        {
            return LLRotate(root);
        }
        
        // RRRotate
        if(balanceFactor<-1&&getBalanceFactor(root->right)<0)
        {
            return RRRotate(root);
        }
        
        // LRRotate
        if(balanceFactor>1&&getBalanceFactor(root->left)<0)
        {
            root->left = RRRotate(root->left);
            return LLRotate(root);
        }
        
        // RLRotate
        if(balanceFactor<-1&&getBalanceFactor(root->right)>0)
        {
            root->right = LLRotate(root->right);
            return RRRotate(root);
        }
        
    }
    return root;
}

int main()
{
    int n;
    scanf("%d",&n);
    Tree root = nullptr;
    
    for(int i = 0;i<n;++i)
    {
        int num = 0;
        scanf("%d",&num);
        root = Insert(root,num);
    }
    
    printf("%d\n",root->val);
    
    return 0;
}
