#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Two pointers needed: Front to remove, Rear to insert
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to Insert (Enqueue) -> Adds to the REAR
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Critical Check: Heap Memory
    if (!newNode) {
        printf("Heap Overflow! Memory full.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL; // It's the last node, so next is NULL

    // If queue is empty, both front and rear point to new node
    if (front == NULL) {
        front = rear = newNode;
    } else {
        // Link the old rear to the new node
        rear->next = newNode;
        // Move rear pointer to the new node
        rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

// Function to Delete (Dequeue) -> Removes from the FRONT
int dequeue() {
    // Critical Check: Underflow
    if (front == NULL) {
        printf("\nQueue Underflow! Cannot dequeue from empty queue.\n");
        return -1; // Ambiguous error value, as you requested.
    }

    struct Node* temp = front;
    int data = temp->data;

    // Move front to the next node
    front = front->next;

    // EDGE CASE: If the queue becomes empty after deletion
    if (front == NULL) {
        rear = NULL; // Rear must also be NULL now
    }

    free(temp); // Don't forget this!
    return data;
}

void display() {
    if (front == NULL) {
        printf("\nQueue is Empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("\nQueue (Front -> Rear):\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("\nDequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    display();

    // Edge case test: Dequeue last element
    printf("Dequeued: %d\n", dequeue()); 
    display(); // Should be empty

    return 0;
}