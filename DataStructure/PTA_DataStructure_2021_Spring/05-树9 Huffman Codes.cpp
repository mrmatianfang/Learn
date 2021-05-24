#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

const int M_INT_MIN = 0;
unordered_map<char,int>hashMap;

using HuffmanTree = struct TreeNode*;
struct TreeNode{
    int weight;
    HuffmanTree left,right;
    TreeNode():weight(M_INT_MIN),left(nullptr),right(nullptr){}
    TreeNode(int w):weight(w),left(nullptr),right(nullptr){}
    TreeNode(HuffmanTree h1,HuffmanTree h2):weight(h1->weight+h2->weight),left(h1),right(h2){}
};

// -------------------------- 最小堆 --------------------------
void Insert(HuffmanTree huff,vector<HuffmanTree>&heap)
{
    int n = heap.size();
    heap.push_back(huff);

    while(heap[n/2]->weight>huff->weight)
    {
        heap[n] = heap[n/2];
        n/=2;
    }
    heap[n]=huff;
}

void SwapNode(HuffmanTree &h1,HuffmanTree &h2)
{
    HuffmanTree h = h1;
    h1 = h2;
    h2 = h;
}

HuffmanTree Delete(vector<HuffmanTree>&heap)
{
    HuffmanTree H = heap[1];
    int n = heap.size();
    HuffmanTree huff = heap[n-1];

    heap.pop_back();
    n-=1;

    if(n>1)
    {
        int parent = 1,child = 0;
        for(;2*parent<n;parent = child)
        {
            child = 2*parent;
            if(child+1<n&&heap[child+1]->weight<heap[child]->weight)
            {
                child+=1;
            }
            if(huff->weight<=heap[child]->weight)
            {
                break;
            }
            SwapNode(heap[parent],heap[child]);
        }
        heap[parent] = huff;
    }

    return H;
}

int InitMinHeap(vector<HuffmanTree>&heap)
{
    // 哨兵结点
    heap.push_back(new TreeNode);
    int n = 0;
    scanf("%d",&n);

    for(int i = 0;i<n;++i)
    {
        getchar();

        char c;
        int w;
        scanf("%c %d",&c,&w);
        hashMap[c]=w;
        Insert(new TreeNode(w),heap);
    }

    return n;
}

// -------------------------- Huffman Tree --------------------------
int WPL(HuffmanTree huff,int depth)
{
    if(huff->left==nullptr)
    {
        return huff->weight*depth;
    }
    return WPL(huff->left,depth+1)+WPL(huff->right,depth+1);
}

HuffmanTree InitHuffmanTree(vector<HuffmanTree>&heap)
{
    int n = heap.size()-1;
    for(int i = 1;i<n;++i)
    {
        HuffmanTree huff = new TreeNode(Delete(heap),Delete(heap));
        Insert(huff,heap);
    }
    return Delete(heap);
}

bool check(const int &N,const int &codeLength)
{
    bool flag = true;
    int count = 1;
    HuffmanTree huff = new TreeNode(),pre = nullptr;

    for(int j = 0;j<N;++j)
    {
        getchar();

        char c;
        string code;
        scanf("%c",&c);
        cin>>code;

        if(flag)
        {
            pre = huff;
            int size = code.size();
            for(int i = 0;i<size;++i)
            {
                if(pre->weight!=0)
                {
                    flag = false;
                    continue;
                }
                if(code[i]=='0')
                {
                    if(pre->left==nullptr)
                    {
                        pre->left = new TreeNode();
                        count+=1;
                    }
                    pre = pre->left;
                }
                else if(code[i]=='1')
                {
                    if(pre->right==nullptr)
                    {
                        pre->right = new TreeNode();
                        count+=1;
                    }
                    pre = pre->right;
                }
            }
            if(pre->left||pre->right)
            {
                flag = false;
            }
            pre->weight = hashMap[c];
        }
    }

    if(count!=2*N-1||!flag||WPL(huff,0)!=codeLength)
    {
        return false;
    }
    return true;
}


int main()
{
    vector<HuffmanTree>heap;

    int N = InitMinHeap(heap);

    HuffmanTree root = InitHuffmanTree(heap);

    int codeLength = WPL(root,0);

    int M = 0;
    scanf("%d",&M);

    for(int i = 0;i<M;++i)
    {
        if(check(N,codeLength))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}
