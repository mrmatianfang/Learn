BinTree Insert( BinTree BST, ElementType X )
{
    if(!BST)
    {
        BST = malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else
    {
        if(BST->Data>X)
        {
            BST->Left = Insert(BST->Left,X);
        }
        else if(BST->Data<X)
        {
            BST->Right = Insert(BST->Right,X);
        }
    }
    
    return BST;
}

BinTree Delete( BinTree BST, ElementType X )
{
    BinTree Tmp;
    if(!BST)
    {
        printf("Not Found\n");
    }
    else
    {
        if(BST->Data>X)
        {
            BST->Left = Delete(BST->Left,X);
        }
        else if(BST->Data<X)
        {
            BST->Right = Delete(BST->Right,X);
        }
        else
        {
            if(BST->Left&&BST->Right)
            {
                Tmp = FindMin(BST->Right);
                
                BST->Data = Tmp->Data;
                BST->Right = Delete(BST->Right,BST->Data);
            }
            else
            {
                Tmp = BST;
                if(BST->Left)
                {
                    BST = BST->Left;
                }
                else
                {
                    BST = BST->Right;
                }
                free(Tmp);
            }
        }
    }
    return BST;
}

Position Find( BinTree BST, ElementType X )
{
    while(BST)
    {
        if(BST->Data==X)
        {
            return BST;
        }
        else if(BST->Data>X)
        {
            BST = BST->Left;
        }
        else
        {
            BST = BST->Right;
        }
    }
    return NULL;
}

Position FindMin( BinTree BST )
{
    if(BST)
    {
        while(BST->Left)
        {
            BST = BST->Left;
        }
    }
    return BST;
}

Position FindMax( BinTree BST )
{
    if(BST)
    {
        while(BST->Right)
        {
            BST = BST->Right;
        }
    }
    return BST;
}
