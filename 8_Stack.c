#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int top = -1, Stack[MAX];

void push();
void pop();
void print();

int main()
{
    int ch;
    while(1)
    {
        printf("\n   Stack");
        printf("\n1. Insert into Stack");
        printf("\n2. Delete from the Stack");
        printf("\n3. Print the Contents of the Stack");
        printf("\n4. Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                print();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void push()
{
    int item;
    if(top == MAX - 1)
    {
        printf("\nOverflow\n");
    }
    else
    {
        printf("\nEnter the element: ");
        scanf("%d", &item);
        top++;
        Stack[top] = item;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("\nUnderflow\n");
    }
    else
    {
        printf("\n%d is Removed from Stack\n", Stack[top]);
        top--;
    }
}

void print()
{
    if(top == -1)
    {
        printf("\nStack is empty\n");
        return;
    }
    printf("\nThe contents of the stack are:\n");
    for(int i = top; i >= 0; i--)
        printf("%d\n", Stack[i]);
}