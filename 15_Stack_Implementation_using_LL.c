#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (!newNode) {
        printf("\nHeap Overflow! System out of memory.\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto the stack.\n", value);
}

int pop() {
    if (top == NULL) {
        printf("\nStack Underflow! Returning -1 as error.\n");
        // CRITICISM: This is bad practice. 
        // If you pushed -1 onto the stack, you won't distinguish it from this error.
        return -1; 
    }

    struct Node* temp = top;
    int poppedValue = temp->data;
    top = top->next;
    free(temp);

    return poppedValue;
}

int peek() {
    if (top == NULL) {
        printf("\nStack is empty. Nothing to peek.\n");
        return -1; // Same problem here. Ambiguity.
    }
    return top->data;
}

void display() {
    if (top == NULL) {
        printf("\nStack is Empty.\n");
        return;
    }
    
    struct Node* temp = top;
    printf("\nStack Elements (Top to Bottom):\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    printf("\nTop element is %d\n", peek());

    printf("\nPopped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    display();
    
    // Let's test your ignorance
    printf("Popped element: %d\n", pop()); // Pops 10
    printf("Popped element: %d\n", pop()); // Stack empty, returns -1

    return 0;
}