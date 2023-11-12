// Program 9 - Implement a circular queue using arrays and linked list. 

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct CircularQueueLL{
    Node* front;
    Node* rear;
}CircularQueueLL;

typedef struct CircularQueueArray{
    int arr[SIZE];
    int front;
    int rear;
}CircularQueueArray;


// ============ LINK LIST QUEUE FUNCTIONS ============ //


// Create a Circular Queue using LL

CircularQueueLL* createQueueLL(){
    CircularQueueLL* queue = (CircularQueueLL*)malloc(sizeof(CircularQueueLL));
    
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}


// Enqueue Function

void enqueueLL(CircularQueueLL* queue, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = value;
    newNode->next = NULL;

    if(queue->front == NULL){
        queue->front = newNode;
    }

    else{
        queue->rear->next = newNode;
    }

    queue->rear = newNode;
    queue->rear->next = queue->front;

    printf("\nEnqueued %d in the queue.\n", value);
}


// Dequeue Function

void dequeueLL(CircularQueueLL* queue){
    if(queue->front == NULL){
        printf("\nQueue is empty.\n");
        return;
    }

    else{
        int value;

        if(queue->front == queue->rear){            // only one node in list
            value = queue->front->data;
            free(queue->front);

            queue->front = queue->rear = NULL;
        }

        else{
            struct Node* nodeToDequeue = queue->front;
            value = nodeToDequeue->data;

            queue->front = queue->front->next;
            queue->rear->next = queue->front;

            free(nodeToDequeue); 
        }

        printf("\nDequeued %d from the queue.\n", value);
    }
}



// Display Function

void displayQueueLL(CircularQueueLL* queue){
    Node* current = queue->front;

    if(current == NULL){
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nQueue (using LL) : ");
    
    do{
        printf("%d ", current->data);
        current = current->next;
    }while(current != queue->front);
}



// ============ ARRAY QUEUE FUNCTIONS ============== //


// Create a Circular Queue using Array

CircularQueueArray* createQueueArray(){
    CircularQueueArray* queue = (CircularQueueArray*)malloc(sizeof(CircularQueueArray));

    queue->front = queue->rear = -1;
    return queue;
}


// Enqueue Function

void enqueueArray(CircularQueueArray* queue, int value){
    if((queue->rear+1) % SIZE == queue->front){
        printf("\nOVERFLOW!!\n");
        return;
    }

    else{
        if(queue->front == -1){
            queue->front = 0;
        }
        
        queue->rear = (queue->rear+1) % SIZE;
        queue->arr[queue->rear] = value;

        printf("\nEnqueued %d in the queue.\n", value);
    }
}


// Dequeue Function

void dequeueArray(CircularQueueArray* queue){
    int item;

    if(queue->front == -1){
        printf("\nUNDERFLOW!!\n");
        return;
    }

    else{
        item = queue->arr[queue->front];
        
        if(queue->front == queue->rear){
            queue->front = queue->rear = -1;
        }

        else{
            queue->front = (queue->front+1) % SIZE;
        }

        printf("\nDequeued %d from the queue.\n", item);
    }
}


// Display Function

void displayQueueArray(CircularQueueArray* queue){
    if(queue->front == -1){
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nQueue (using Array) :");
    int current = queue->front;

    do{
        printf("%d ", queue->arr[current]);
        current = (current + 1) % SIZE;
    }while(current != (queue->rear + 1) % SIZE);
}



// =============== MAIN FUNCTION =============== //

int main() {
    int choice;
    int value;
    int queueType; // 0 for linked list, 1 for array

    // Initialize queues
    CircularQueueLL* queueLL = createQueueLL();
    CircularQueueArray* queueArray = createQueueArray();

    do {
        printf("\nMain Menu:\n");
        printf("1. Circular Queue using Array\n");
        printf("2. Circular Queue using Link List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                queueType = 1; // Queue using Array
                break;

            case 2:
                queueType = 0; // Queue using Link List
                break;

            case 3:
                printf("\nExiting the program.\nHappy Coding!!\n");
                exit(0);

            default:
                printf("\nPlease enter a valid choice.\n");
                continue;
        }

        do {
            printf("\n1. Enqueue\n");
            printf("2. Dequeue\n");
            printf("3. Display\n");
            printf("4. Go Back\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter the value to enqueue: ");
                    scanf("%d", &value);
                    if (queueType == 0) {
                        enqueueLL(queueLL, value);
                        printf("\nAfter Operation,");
                        displayQueueLL(queueLL);
                    } else {
                        enqueueArray(queueArray, value);
                        printf("\nAfter Operation,");
                        displayQueueArray(queueArray);
                    }
                    break;

                case 2:
                    if (queueType == 0) {
                        dequeueLL(queueLL);
                        printf("\nAfter Operation,");
                        displayQueueLL(queueLL);
                    } else {
                        dequeueArray(queueArray);
                        printf("\nAfter Operation,");
                        displayQueueArray(queueArray);
                    }
                    break;

                case 3:
                    if (queueType == 0) {
                        displayQueueLL(queueLL);
                    } else {
                        displayQueueArray(queueArray);
                    }
                    break;

                case 4:
                    break;

                default:
                    printf("\nPlease enter a valid choice.\n");
            }
        } while (choice != 4);

    } while (choice != 3);

    // Free allocated memory
    free(queueLL);

    return 0;
}
