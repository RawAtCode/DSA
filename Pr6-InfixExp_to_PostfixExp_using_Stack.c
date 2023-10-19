// PROGRAM 6 - Implement the conversion of infix notation to postfix notation

#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

typedef struct Stack{
    int tos;
    char items[SIZE];
}Stack;


void initStack(Stack *stack){           // initializing stack
    stack->tos = -1;
}


// Pushing Function
void push(Stack *stack, char ch){
    if(stack->tos == SIZE - 1){
        printf("\nOVERFLOW!!\n");
    }

    else{
        stack->tos++;
        stack->items[stack->tos] = ch;
    }
}


// Popping Function
char pop(Stack *stack){
    if(stack->tos == -1){
        printf("\nUNDERFLOW!!\n");
        return '\0';                    // '\0' means NULL in character datatype
    }

    else{
        char ch = stack->items[stack->tos];
        stack->tos--;

        return ch;
    }
}


// Peeking Function
char peek(Stack *stack){
    if(stack->tos == -1){
        return '\0';
    }

    else{
        char ch = stack->items[stack->tos];
        return ch;
    }
}


// Operator Checking Function
int isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}


// Operand Checking Function
int isOperand(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}


// Precedence Function
int getPrecedence(char operator){
    if(operator == '+' || operator == '-'){
        return 1;
    }
    
    if(operator == '*' || operator == '/'){
        return 2;
    }
    
    if(operator == '^'){
        return 3;
    }

    return 0;
}


// Infix to Postfix Function
void infixToPostfix(const char *infixExp){
    Stack stack;
    initStack(&stack);

    int infixLength = 0;
    while(infixExp[infixLength] != '\0'){
        infixLength++;
    }

    char postfixExp[SIZE];
    int postfixIndex = 0;
    int i = 0;
    char prevChar = '\0';
    
    while(i < infixLength){
        char ch = infixExp[i];

        // check for special characters
        if(!isOperator(ch) && !isOperator(ch)){
            printf("Invalid Expression!!\n");
            return;
        }

        // check for two operators together
        else if(isOperand(ch)){
            if(isOperator(prevChar)){
                printf("\nInvalid Expression!!\n");
                return;
            }

            postfixExp[postfixIndex] = ch;
            postfixIndex++;
        }

        // check for two operands together
        else if(isOperator(ch)){
            if(isOperand(prevChar)){
                printf("\nInvalid Expression!!\n");
                return;
            }

            while(getPrecedence(ch) <= getPrecedence(peek(&stack))){
                postfixExp[postfixIndex] = pop(&stack);
                postfixIndex++;
            }
            push(&stack, ch);
        }
        
        else if(ch == '('){
            push(&stack, ch);
        }

        else if(ch == ')'){
            while(peek(&stack) != '('){
                postfixExp[postfixIndex] = pop(&stack);
                postfixIndex++;
            }
            pop(&stack);
        }

        prevChar = ch;
        i++;
    }

    while(peek(&stack) != '\0'){
        postfixExp[postfixIndex] = pop(&stack);
        postfixIndex++;
    }

    postfixExp[postfixIndex] = '\0';
    printf("\nPostfix Expression: %s", postfixExp);
    printf("\n");
}



// =========== MAIN ========== //
int main(){
    char infixExp[SIZE];

    printf("\nEnter an Infix Expression: ");
    scanf("%s", infixExp);

    infixToPostfix(infixExp);

    return 0;
}