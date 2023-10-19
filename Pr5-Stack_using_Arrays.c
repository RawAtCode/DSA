// PROGRAM 5 - 5.	Implement operations (push, pop, peep) on a stack using arrays. Check the status of the stack whether there is underflow or overflow.

#include<stdio.h>
#include<stdlib.h>
#define SIZE 3


typedef struct Stack {
    int tos;
    int st[SIZE];
}Stack;


// Push Function

void push(Stack *stack, int data){
    if(stack->tos == SIZE){                               //check for overflow
        printf("\nOVERFLOW!!\n");
        return;
    }

    stack->st[stack->tos] = data;
    stack->tos++;
    
    printf("Pushed %d into the stack.\n", data);
}

// Pop Function

void pop(Stack *stack){
    if(stack->tos == 0){
        printf("\nUNDERFLOW!!\n");                          //check for underflow
        return;
    }

    stack->tos--;
    int data = stack->st[stack->tos];

    printf("Popped %d out of the stack.\n", data);
}


// Peep Function

void peep(Stack *stack){
    if(stack->tos == 0){
        printf("\nStack is empty.\n");
        return;
    }

    printf("TOS: %d", stack->st[stack->tos]);
}


int main(){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if(stack == NULL){
        printf("\nMEMORY ALLOCATION FAILED!!\n");
        return -1;
    }

    stack->tos = 0;                            //initially stack is empty

    int choice, value;

    while(1){
        printf("\nMENU:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the value to push: ");
            scanf("%d", &value);
            push(stack, value);
            break;
        
        case 2:
            pop(stack);
            break;

        case 3:
            peep(stack);
            break;        

        case 4:
            printf("\nGOODBYE!!\n");
            free(stack);
            exit(0);

        default:
            printf("\nOOPS!! ENTER A VALID CHOICE!\n");
            break;
        }
    }
}