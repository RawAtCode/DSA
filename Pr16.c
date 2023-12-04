// Program 16 : Implement AVL Tree

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
}Node;

int height(Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int balanceFactor(Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node *newNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node *rightRotate(Node *node) {
    Node* leftOfNode = node->left;
    Node* rightOfLeft = leftOfNode->right;

    leftOfNode->right = node;
    node->left = rightOfLeft;

    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
    leftOfNode->height = 1 + (height(leftOfNode->left) > height(leftOfNode->right) ? height(leftOfNode->left) : height(leftOfNode->right));

    return leftOfNode;
}

struct Node *leftRotate(struct Node *node) {
    Node* rightOfNode = node->right;
    Node* leftOfRight = rightOfNode->left;

    rightOfNode->left = node;
    node->right = leftOfRight;

    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
    rightOfNode->height = 1 + (height(rightOfNode->left) > height(rightOfNode->right) ? height(rightOfNode->left) : height(rightOfNode->right));

    return rightOfNode;
}

struct Node *insert(struct Node *root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    int balance = balanceFactor(root);

    if (balance > 1) {
        if (data < root->left->data) {
            return rightRotate(root);
        } else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    if (balance < -1) {
        if (data > root->right->data) {
            return leftRotate(root);
        } else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

struct Node *minValueNode(struct Node *node) {
    struct Node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node *deleteNode(struct Node *root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL || root->right == NULL) {
            struct Node *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            struct Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    int balance = balanceFactor(root);

    if (balance > 1) {
        if (balanceFactor(root->left) >= 0)
            return rightRotate(root);
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    if (balance < -1) {
        if (balanceFactor(root->right) <= 0)
            return leftRotate(root);
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

struct Node *search(struct Node *root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return search(root->left, data);

    return search(root->right, data);
}

void inOrder(struct Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void displayMenu() {
    printf("\n\nAVL Tree Menu:\n");
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Search Key\n");
    printf("4. In-order traversal)\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node *root = NULL;
    int choice, data, searchData;

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
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;

            case 3:
                printf("Enter data to search: ");
                scanf("%d", &searchData);
                if (search(root, searchData) != NULL)
                    printf("Data found in the tree.\n");
                else
                    printf("Data not found in the tree.\n");
                break;

            case 4:
                printf("In-order traversal of the AVL tree: ");
                inOrder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}
