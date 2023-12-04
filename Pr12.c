// PROGRAM 12  Implement operations on Binary Search Tree (Insertion, Deletion, Search,Traversals (using recursion)- Inorder, Preorder, Postorder). 

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

// Fucntion to create a new node

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


// INSERT Fucntion

Node* insertNode(Node* root, int value){
    if(root == NULL){
        return createNode(value);
    }

    if(value < root->data){
        root->left = insertNode(root->left, value);
    }

    else if(value > root->data){
        root->right = insertNode(root->right, value);
    }

    return root;
}


// SEARCH Function

Node* searchNode(Node* root, int value){
    if(root == NULL || root->data == value){
        return root;
    }

    if(value < root->data){
        return searchNode(root->left, value);
    }

    return searchNode(root->right, value);
}


// NOTE :  The leftmost leaf node of the tree is the minimum value in the tree

Node* findMinimumNode(Node* root){
        while(root->left != NULL){
        root = root->left;
    }

    return root;
}


// DELETE Function


Node* deleteNode(Node* root, int value){
    if(root == NULL){
        return root;
    }

    if(value < root->data){
        root->left = deleteNode(root->left, value);
    }

    else if(value > root->data){
        root->right = deleteNode(root->right, value);
    }

    else{
        if(root->left == NULL){                 // node having right child only
            Node* minNode = root->right;
            free(root);

            return minNode;
        }

        else if(root->right == NULL){           // node having left child only
            Node* minNode = root->left;
            free(root);

            return minNode;
        }

        // node having both left and right child
        Node* minNode = findMinimumNode(root->right);
        root->data = minNode->data;
        root->right = deleteNode(root->right, minNode->data);
    }
}


// ========== TRAVERSAL Functions ========== //

// 1. Preorder [NLR]
void preorderTraversal(Node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}


// 2. Inorder [LNR]
void inorderTraversal(Node* root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}


// 3. Postorder [LRN]
void postorderTraversal(Node* root){
    if(root != NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}


// Freeing the allocated memory
void freeBST(Node* root){
    if(root != NULL){
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}



// =============== MAIN ============== //

int main(){
    Node* root = NULL;
    int choice, value;

    do{
        printf("\nMENU: ");
        printf("\n1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Search\n");
        printf("4. Traversal\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;

            case 2:
                printf("\nEnter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("\nEnter the value to search: ");
                scanf("%d", &value);

                if(searchNode(root, value) != NULL){
                    printf("%d is in the BST.\n", value);
                }

                else{
                    printf("%d is not in the BST.\n", value);
                }

                break;

            case 4:
                    do{
                        printf("\n\nTraversal Menu: \n");
                        printf("\n1. Preorder Traversal\n");
                        printf("2. Inorder Traversal\n");
                        printf("3. Postorder Traversal\n");
                        printf("4. Go Back\n");

                        printf("\nEnter your choice: ");
                        scanf("%d", &choice);

                        switch(choice){
                            case 1:
                                preorderTraversal(root);
                                break;

                            case 2:
                                inorderTraversal(root);
                                break;

                            case 3:
                                postorderTraversal(root);
                                break;

                            case 4:
                                break;
                            
                            default:
                                printf("\nPlease enter a valid choice.\n");
                        }
                    }while(choice != 4);

            case 5:
                freeBST(root);
                printf("\nExiting the program.\nHappy Coding!!\n");
                break;

            default:
                printf("\nPlease enter a valid choice.\n");   
        }
    }while(choice != 5);

    return 0;
}