/*                  Algorithm
1)Start
2)Repeat steps 3 to 5 for pass = 0 to n-1:
3)Repeat steps 4 for j = 0 to n-pass-1:
4)If A[j] > A[j+1], then swap A[j] and A[j+1]
5)End*/

/*                   Method

0) Compare adjacent elements.

1) If they are in the wrong order, swap them.

2) After one full pass, the largest element is at the end.

3) Repeat the process for the remaining unsorted part.*/

# include <stdio.h>
void InputArray(int A[],int n)
{
    printf("Enter the elements in the list: ");
    for(int i=0;i<n;i++)
    {
        printf("Element %d: ",i);
        scanf("%d",&A[i]);
    }
}

void BubbleSort(int A[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)      
    {                            
        // We have to run the inner loop with n-1-i cause in bubble sort with every successful iteration the largest element finds its place/home(last position of the array) 
        for(int j=0;j<n-1-i;j++)  
        // Can also write this like n-1-pass, just creaete int pass = 0 and give pass++ in the end of the outer loop, it will work as count for the iteration however the i already keeps the count 
        {
            if(A[j] > A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the size of the list: ");
    scanf("%d",&n);
    int A[n];
    InputArray(A,n);
    BubbleSort(A,n);
    printf("List: \n");
    for(int i=0;i<n;i++)
    printf("%5d",A[i]);
    printf("\n");
}