// 建树方法
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

using pNode = struct TreeNode*;
struct TreeNode{
    int val;
    pNode left,right;
    TreeNode(int v):val(v),left(nullptr),right(nullptr){}
};

unordered_map<int,int>hashMap;

int Read(vector<int>&preorder,vector<int>&inorder)
{
    int N = 0;
    scanf("%d",&N);
    
    stack<int>stk;
    
    for(int i = 0;i<2*N;++i)
    {
        string op;
        cin>>op;
        if(op[1]=='u')
        {
            int num;
            scanf("%d",&num);
            preorder.push_back(num);
            stk.push(num);
        }
        else if(op[1]=='o')
        {
            inorder.push_back(stk.top());
            stk.pop();
        }
    }
    
    for(int i = 0;i<N;++i)
    {
        hashMap[inorder[i]]=i;
    }
    
    return N;
}

void Print(const vector<int>&vec)
{
    int n = vec.size();
    for(int i = 0;i<n;++i)
    {
        printf("%d",vec[i]);
        if(i!=n-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

pNode BuildTree(const vector<int>&preorder,int preLeft,int preRight,int inLeft,int inRight)
{
    if(inLeft>inRight)
    {
        return nullptr;
    }
    
    int val = preorder[preLeft];
    
    pNode root = new TreeNode(val);
    
    int inMid = hashMap[val];
    
    int length = inMid - inLeft;
    
    root->left = BuildTree(preorder,preLeft+1,preLeft+length,inLeft,inMid-1);
    
    root->right = BuildTree(preorder,preLeft+length+1,preRight,inMid+1,inRight);
    
    return root;
}

void PostorderTraversal(pNode root,vector<int>&postorder)
{
    pNode prev = nullptr;
    stack<pNode>stk;
    
    while(root||!stk.empty())
    {
        while(root)
        {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        if(root->right==nullptr||root->right==prev)
        {
            postorder.push_back(root->val);
            prev = root;
            root = nullptr;
        }
        else
        {
            stk.push(root);
            root = root->right;
        }
    }
}

int main()
{
    vector<int>preorder;
    vector<int>inorder;
    vector<int>postorder;
    
    int n = Read(preorder,inorder);
    
    pNode root = BuildTree(preorder,0,n-1,0,n-1);
    
    PostorderTraversal(root,postorder);
    
    Print(postorder);
    
    return 0;
}

// 不建树
