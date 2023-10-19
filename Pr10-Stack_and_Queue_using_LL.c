// PROGRAM 10 - IMPLEMENT STACKS AND QUEUES USING A LINKED LIST

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* tos;
}Stack;

typedef struct Queue{
    Node* front;
    Node* rear;
}Queue;




//=============== STACK ===============//


void initStack(Stack* stack){       // initializing the stack
    stack->tos = NULL;
}


// Push Function
void push(Stack* stack, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL){
        printf("\nMemory Allocation Failed!!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = stack->tos;
    stack->tos = newNode;
}


// Pop Function
void pop(Stack* stack){
    if(stack->tos == NULL){
        printf("\nUNDERFLOW!!\n");
        return;
    }

    Node* topNode = stack->tos;
    int data = topNode->data;
    stack->tos = topNode->next;
    free(topNode);
    printf("\nPopped %d from the stack.\n", data);    
}


//=============== QUEUE ===============//


void initQueue(Queue* queue){
    queue->front = NULL; 
    queue->rear = NULL;
}


// Enqueue Function
void enqueue(Queue* queue, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    if(queue->front == NULL){
        queue->front = newNode;
        queue->rear = newNode;
    }

    else{
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}


// Dequeue Function
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("\nUNDERFLOW!!\n");
        return -1;
    }

    Node* frontNode = queue->front;
    int data = frontNode->data;
    queue->front = frontNode->next;
    free(frontNode);
    return data;
}


void displayStack(Stack* stack) {
    Node* currentNode = stack->tos;

    if(currentNode == NULL){
        printf("\nStack is empty.\n");
        return;
    }

    printf("Stack: ");
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void displayQueue(Queue* queue) {
    Node* currentNode = queue->front;

    if(currentNode == NULL){
        printf("\nQueue is empty.\n");
        return;
    }

    else{
        printf("Queue: ");
        while (currentNode != NULL) {
            printf("%d ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
    
}



// ============ MAIN ============//

int main() {
    Stack stack;
    initStack(&stack);

    Queue queue;
    initQueue(&queue);

    int choice, data;

    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Stack\n");
        printf("2. Queue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                while (1) {
                    printf("\nStack Menu:\n");
                    printf("1. Push\n");
                    printf("2. Pop\n");
                    printf("3. Display\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter data to push: ");
                            scanf("%d", &data);
                            push(&stack, data);
                            break;
                        case 2:
                            pop(&stack);
                            break;
                        case 3:
                            displayStack(&stack);
                            break;
                        case 4:
                            break;
                        default:
                            printf("\nInvalid choice!!\n");
                    }

                    if (choice == 4) {
                        break; // Return to the main menu
                    }
                }
                break;

            case 2:
                while (1) {
                    printf("\nQueue Menu:\n");
                    printf("1. Enqueue\n");
                    printf("2. Dequeue\n");
                    printf("3. Display\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter data to enqueue: ");
                            scanf("%d", &data);
                            enqueue(&queue, data);
                            break;
                        case 2:
                            data = dequeue(&queue);
                            if (data != -1) {
                                printf("Dequeued %d from the queue.\n", data);
                            }
                            break;
                        case 3:
                            displayQueue(&queue);
                            break;
                        case 4:
                            break;
                        default:
                            printf("\nInvalid choice!!\n");
                    }

                    if (choice == 4) {
                        break; // Return to the main menu
                    }
                }
                break;

            case 3:
                printf("\nGoodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice!!\n");
        }
    }

    return 0;
}