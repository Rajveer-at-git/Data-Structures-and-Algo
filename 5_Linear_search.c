//          Linear Search
# include<stdio.h>
int InputArray(int A[],int n)
{
    int number;
    printf("Enter the elements in the list: ");
    for(int i=0;i<n;i++)
    {
        printf("Element %d: ",i);
        scanf("%d",&A[i]);
    }
    printf("\n\nNow Enter the no. you want to check in the list: ");
    scanf("%d",&number);
    return number;
}

void LinearSearch(int A[], int n, int num)
{
    int found = 0;
    for(int i=0; i<n; i++)
    {
        if(A[i] == num)
        {
            printf("Yes, the number is present.\n");
            found = 1;
            break;
        }
    }
    if(!found)
        printf("No, the element is absent.\n");
}

int main()
{
    int n;
    printf("Enter the size of the list: ");
    scanf("%d",&n);
    int A[n];
    int num = InputArray(A ,n);
    LinearSearch(A, n, num);
}