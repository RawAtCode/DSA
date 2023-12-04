// Program 13 : Implement traversals on BST using stacks

#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Structure for a stack node
struct StackNode {
    struct TreeNode* treeNode;
    struct StackNode* next;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a new stack node
struct StackNode* createStackNode(struct TreeNode* treeNode) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->treeNode = treeNode;
    stackNode->next = NULL;
    return stackNode;
}

// Function to push a node onto the stack
void push(struct StackNode** root, struct TreeNode* treeNode) {
    struct StackNode* stackNode = createStackNode(treeNode);
    stackNode->next = *root;
    *root = stackNode;
}

// Function to pop a node from the stack
struct TreeNode* pop(struct StackNode** root) {
    if (*root == NULL)
        return NULL;
    struct TreeNode* popped = (*root)->treeNode;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    free(temp);
    return popped;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* root) {
    return root == NULL;
}

// Inorder traversal using a stack
void inorderTraversal(struct TreeNode* root) {
    struct StackNode* stack = NULL;
    struct TreeNode* current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);

        current = current->right;
    }
}

// Preorder traversal using a stack
void preorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct StackNode* stack = NULL;
    push(&stack, root);

    while (!isEmpty(stack)) {
        struct TreeNode* current = pop(&stack);
        printf("%d ", current->data);

        if (current->right != NULL)
            push(&stack, current->right);

        if (current->left != NULL)
            push(&stack, current->left);
    }
}

// Postorder traversal using two stacks
void postorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct StackNode* stack1 = NULL;
    struct StackNode* stack2 = NULL;

    push(&stack1, root);

    while (!isEmpty(stack1)) {
        struct TreeNode* current = pop(&stack1);
        push(&stack2, current);

        if (current->left != NULL)
            push(&stack1, current->left);

        if (current->right != NULL)
            push(&stack1, current->right);
    }

    while (!isEmpty(stack2)) {
        printf("%d ", pop(&stack2)->data);
    }
}

// Function to insert a node into the BST
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to display the menu
void displayMenu() {
    printf("\n1. Insert node\n");
    printf("2. Inorder Traversal\n");
    printf("3. Preorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Driver program
int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("\nExiting program.\nHappy Coding!\n");
                break;
            default:
                printf("\nPlease enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
