#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int front = -1, rear = -1, Queue[MAX];

void insert();
void delete();
void print();

int main()
{
    int ch;
    while(1)
    {
        printf("\n   Circular Queue");
        printf("\n1. Insert into Queue");
        printf("\n2. Delete from the Queue");
        printf("\n3. Print the Contents of the Queue");
        printf("\n4. Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
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

void insert()
{
    int item;
    // Check for overflow
    if((front == 0 && rear == MAX-1) || (rear + 1) % MAX == front)
    {
        printf("\nOverflow\n");
        return;
    }
    printf("\nEnter the element: ");
    scanf("%d", &item);

    if(front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    Queue[rear] = item;
}

void delete()
{
    if(front == -1)
    {
        printf("\nUnderflow\n");
        return;
    }
    printf("\n%d is Removed from Queue\n", Queue[front]);
    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void print()
{
    if(front == -1)
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nThe contents of the circular queue are:\n");
    int i = front;
    while(1)
    {
        printf("%3d", Queue[i]);
        if(i == rear)
            break;
        i = (i + 1) % MAX;
    }
}