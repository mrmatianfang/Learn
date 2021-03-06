Position BinarySearch( List L, ElementType X )
{
    int left = 1,right = L->Last;
    while(left<=right)
    {
        int mid = (left+right)>>1;
        if(L->Data[mid]==X)
        {
            return mid;
        }
        else if(L->Data[mid]>X)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    return NotFound;
}
