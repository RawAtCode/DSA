// PROGRAM 8 - 


#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int q[SIZE];
int front = -1;
int rear = -1;

// Enqueue Function

void enqueue(int data){
    if(rear == SIZE - 1){
        printf("\nOVERFLOW!!\n");
    }

    else{
        if(front == -1){
            front = 0;
        }

        rear++;
        q[rear] = data;

        printf("\nEnqueued %d in the queue.\n", data);
    }
}


// Dequeue Function

void dequeue(){
    if(front == -1){
        printf("\nUNDERFLOW!!\n");
    }

    else{
        int data = q[front];
        front++;

        if(front > rear){
        front = -1;
        rear = -1;
        }

        printf("\nDequeued %d from the queue.\n", data);
    }
}


// Display Function

void displayQueue(){
    if(front == -1){
        printf("\nOops! Looks like the queue is empty.\n");
    }

    else{
        printf("Queue: ");
        
        for(int i = 0; i <= rear; i++){
            printf("%d ", q[i]);
        }
    }
}


// Main Function

int main(){
    int choice, data;

    while(1){
        printf("\nMENU: \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the data you want to enqueue: ");
            scanf("%d", &data);

            enqueue(data);
            break;
        
        case 2:
            dequeue();
            break;

        case 3:
            displayQueue();
            break;
        
        case 4:
            printf("\nGoodbye!\n");
            exit(0);

        default:
            printf("\nEnter a valid choice.\n");
            break;
        }
    }

    return 0;
}