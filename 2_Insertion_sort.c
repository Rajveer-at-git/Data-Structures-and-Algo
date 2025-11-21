/*          Method
1) Start with the second element (first is already "sorted").

2) Compare it with elements before it.

3) Insert it into the correct position among the already sorted elements.

4) Repeat for each next element*/

/*   InserstionSort(A,n)
Algorithm:
1) for (k=1;k<n;k++)
2)   TEMP = A[k], PTR = k-1
3)   while(PTR >=0 && A[PTR]>TEMP)
        a) A[PTR+1] = A[PTR]
        b) PTR--
4) A[PTR+1] = TEMP
5) return 
*/

# include<stdio.h>
void InsertionSort(int A[], int n)
{
    for(int k=1;k<n;k++)
    {
        int TEMP = A[k];
        int PTR = k-1;
        while(PTR>=0 && A[PTR]>TEMP)
        {
            A[PTR+1] = A[PTR];
            PTR--;
        }
        A[PTR+1] = TEMP;
    }
}

int main()
{
    int A[] = {5,2,4,1,6,3};
    int n = sizeof(A)/sizeof(A[0]);
    InsertionSort(A,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    
}