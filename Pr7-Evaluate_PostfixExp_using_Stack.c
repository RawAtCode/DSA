// PROGRAM 7 - Implement evaluation of postfix notation using stacks.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 30

typedef struct Stack {
    int tos;
    double items[SIZE];
} Stack;

void initStack(Stack *stack) {
    stack->tos = -1;
}

void push(Stack *stack, double value) {
    if (stack->tos == SIZE - 1) {
        printf("\nOVERFLOW!!\n");
    } else {
        stack->tos++;
        stack->items[stack->tos] = value;
    }
}

double pop(Stack *stack) {
    if (stack->tos == -1) {
        printf("\nUNDERFLOW!!\n");
        return 0.0;
    } else {
        double value = stack->items[stack->tos];
        stack->tos--;
        return value;
    }
}

double peek(Stack *stack) {
    if (stack->tos == -1) {
        return 0.0;
    } else {
        return stack->items[stack->tos];
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int isOperand(char ch) {
    return (ch >= '0' && ch <= '9');
}

int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    }
    if (operator == '*' || operator == '/') {
        return 2;
    }
    if (operator == '^') {
        return 3;
    }
    return 0;
}

void infixToPostfix(const char *infixExp, char *postfixExp) {
    Stack stack;
    initStack(&stack);

    int infixLength = strlen(infixExp);
    int postfixIndex = 0;

    for (int i = 0; i < infixLength; i++) {
        char ch = infixExp[i];

        if (isOperand(ch)) {
            postfixExp[postfixIndex++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (peek(&stack) != '(') {
                postfixExp[postfixIndex++] = pop(&stack);
            }
            pop(&stack); // Pop and discard the opening parenthesis
        } else if (isOperator(ch)) {
            while (precedence(ch) <= precedence(peek(&stack))) {
                postfixExp[postfixIndex++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (peek(&stack) != '\0') {
        postfixExp[postfixIndex++] = pop(&stack);
    }

    postfixExp[postfixIndex] = '\0';
}

double evaluatePostfix(const char *postfixExp) {
    Stack evaluateStack;
    initStack(&evaluateStack);

    int postfixLength = strlen(postfixExp);

    for (int i = 0; i < postfixLength; i++) {
        char ch = postfixExp[i];

        if (isOperand(ch)) {
            push(&evaluateStack, ch - '0'); // Convert character digit to double
        } else if (isOperator(ch)) {
            double operand2 = pop(&evaluateStack);
            double operand1 = pop(&evaluateStack);

            switch (ch) {
                case '+':
                    push(&evaluateStack, operand1 + operand2);
                    break;
                case '-':
                    push(&evaluateStack, operand1 - operand2);
                    break;
                case '*':
                    push(&evaluateStack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0.0) {
                        printf("\nDivision by zero is not allowed!\n");
                        exit(1);
                    }
                    push(&evaluateStack, operand1 / operand2);
                    break;
                case '^':
                    push(&evaluateStack, pow(operand1, operand2));
                    break;
                default:
                    break;
            }
        }
    }

    double result = pop(&evaluateStack);
    return result;
}

int main() {
    char infixExp[SIZE];

    printf("\nEnter an Infix Expression: ");
    scanf("%s", infixExp);

    char postfixExp[SIZE];
    infixToPostfix(infixExp, postfixExp);
    printf("Postfix Expression: %s\n", postfixExp);

    double result = evaluatePostfix(postfixExp);
    printf("Result: %lf\n", result);

    return 0;
}
