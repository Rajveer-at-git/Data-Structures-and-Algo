/*             Algorithm
1) Start
2) Repeat steps 3 to 6 for i = 0 to n-2:
3) Set min = i
4) Repeat for j = i+1 to n-1:
     If A[j] < A[min], then set min = j
5) Swap A[i] and A[min]
6) End
*/

/*              Method
0) Divide the array into two parts:

1) Sorted (initially empty)

2) Unsorted (the entire array at first)

3) Find the smallest element in the unsorted part.

4) Swap it with the first unsorted element.

5) Repeat until the array is sorted.*/

#include <stdio.h>
void inputArray(int A[], int n)
{
    printf("Enter the elements in the list: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d:", i);
        scanf("%d", &A[i]);
    }
}

void SelectionSort(int A[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int Min = i;
        for(int j=i+1;j<=n-1;j++)
        {
            if(A[j] < A[Min])
                Min = j;
        }
        int temp = A[i];
        A[i] = A[Min];
        A[Min] = temp;
    }
    printf("List: \n");
    for (int i; i < n; i++)
        printf("%5d", A[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of the list: ");
    scanf("%d", &n);
    int A[n];
    inputArray(A, n); // Function called
    SelectionSort(A, n);
}
