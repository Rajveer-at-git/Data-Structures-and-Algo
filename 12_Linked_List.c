#include <stdio.h>
#include <stdlib.h> // Required for malloc and exit

// Node structure definition
struct node {
    int data;
    struct node *next;
};

// Function prototypes
struct node* insert_beg(struct node *head); // Now takes head and returns the new head
void traverse(struct node *head);           // Now takes head as a parameter

int main() {
    // 1. Declare head locally in main and initialize to NULL
    struct node *head = NULL; 
    int ch;
    
    while(1) {
        printf("\n\n--- Linked List Menu ---");
        printf("\n1. Insert at beginning");
        printf("\n2. Traverse and print");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                // 2. Pass head to the function and update it with the return value
                head = insert_beg(head);
                break;
            case 2:
                traverse(head);
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    }
    return 0; // Good practice to have a return statement
}

// Takes the current head and returns the new head of the list
struct node* insert_beg(struct node *head) {
    struct node *ptr;
    int item;

    // 3. CRITICAL FIX: Allocate memory for the node structure itself
    ptr = (struct node *) malloc(sizeof(struct node));

    // 4. IMPROVEMENT: Check if malloc failed
    if (ptr == NULL) {
        printf("\nMemory allocation failed. Cannot add node.");
        return head; // Return the original head without changes
    }
    
    printf("\nEnter item to insert: ");
    scanf("%d", &item);
    
    ptr->data = item;
    ptr->next = head; // Point new node's next to the old head
    
    printf("Node successfully inserted.");
    
    return ptr; // The new node is now the head of the list
}

// Takes the head of the list to be traversed
void traverse(struct node *head) {
    // Use a temporary pointer to traverse, leaving head unchanged
    struct node *ptr = head;

    if (ptr == NULL) {
        printf("\nThe list is empty.");
        return;
    }

    printf("\nNodes in the Linked List are: \n");
    while (ptr != NULL) {
        printf("%d --> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n"); // Indicate the end of the list
}