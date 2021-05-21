List Merge( List L1, List L2 )
{
    List l1 = L1->Next,l2 = L2->Next;
    List L = malloc(sizeof(struct Node));
    List pL = L;
    
    while(l1&&l2)
    {
        if(l1->Data<=l2->Data)
        {
            L->Next = l1;
            l1 = l1->Next;
        }
        else
        {
            L->Next = l2;
            l2 = l2->Next;
        }
        L = L->Next;
    }
    
    L->Next = l1?l1:l2;
    
    L1->Next = NULL;
    L2->Next = NULL;
    
    return pL;
}
