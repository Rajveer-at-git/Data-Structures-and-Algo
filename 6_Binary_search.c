// Binary Search
/*
        Binary Search Algorithm
1. Start
2. Set LB = 0 and UB = n - 1
3. Repeat while LB <= UB:
    Calculate MID = (LB + UB) / 2
    If A[MID] == item,
        Print "Item found!"
        Return MID
    Else if A[MID] > item,
        Set UB = MID - 1
    Else
        Set LB = MID + 1
4. If item not found, return -1
5. End
   
*/
# include<stdio.h>
int BinarySearch(int A[], int n, int item)
{
    int LB=0, UB=n-1, MID;
        
    while(LB <= UB)
    {
        MID  = (LB+UB)/2;
        if(A[MID] == item)
        {
            printf("Item found!\n");
            return(MID);
        }
        else if(A[MID]>item)
            UB = MID-1;
        else 
            LB = MID+1;
    }
    printf("Not found.\n");
    return -1;
        
}
int main()
{
    int A[] = {0,1,2,3,4,5,6,7};
    int n = sizeof(A)/sizeof(A[0]);
    int item = 5;
    int index = BinarySearch(A,n,item);
    printf("index: %d\n",index);
}