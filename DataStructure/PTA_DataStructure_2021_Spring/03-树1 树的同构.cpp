#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    char val;
    int left,right;
    TreeNode(char c):val(c),left(-1),right(-1){}
};

int BuildTree(vector<TreeNode>&tree)
{
    int n = 0;
    scanf("%d",&n);
    
    vector<int>visit(n,0);
    
    for(int i = 0;i<n;++i)
    {
        getchar();
        char v,l,r;
        scanf("%c %c %c",&v,&l,&r);
        TreeNode node = TreeNode(v);
        if(l!='-')
        {
            node.left = l-'0';
            visit[l-'0']=1;
        }
        if(r!='-')
        {
            node.right = r-'0';
            visit[r-'0']=1;
        }
        tree.push_back(node);
    }
    
    for(int i = 0;i<n;++i)
    {
        if(!visit[i])
        {
            return i;
        }
    }
    
    return -1;
}

bool Isomorphic(vector<TreeNode>&tree1,vector<TreeNode>&tree2,int root1,int root2)
{
    if(root1==-1&&root2==-1)
    {
        return true;
    }
    if((root1==-1&&root2!=-1)||(root1!=-1&&root2==-1))
    {
        return false;
    }
    if(tree1[root1].val!=tree2[root2].val)
    {
        return false;
    }
    if(tree1[root1].left==-1&&tree2[root2].left==-1)
    {
        return Isomorphic(tree1,tree2,tree1[root1].right,tree2[root2].right);
    }
    if((tree1[root1].left!=-1&&tree2[root2].left!=-1)&&tree1[tree1[root1].left].val==tree2[tree2[root2].left].val)
    {
        return (Isomorphic(tree1,tree2,tree1[root1].left,tree2[root2].left)
                &&Isomorphic(tree1,tree2,tree1[root1].right,tree2[root2].right));
    }
    else
    {
        return (Isomorphic(tree1,tree2,tree1[root1].left,tree2[root2].right)
                &&Isomorphic(tree1,tree2,tree1[root1].right,tree2[root2].left));
    }
}

int main()
{
    vector<TreeNode>tree1;
    vector<TreeNode>tree2;
    
    int root1 = BuildTree(tree1);
    int root2 = BuildTree(tree2);
    
    if(Isomorphic(tree1,tree2,root1,root2))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    
    return 0;
}
