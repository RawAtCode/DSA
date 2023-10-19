// PROGRAM 3 - INSERTION AND DELETION IN DOUBLE LINK LIST AND CIRCULAR DOUBLE LINK LIST

#include<stdio.h>
#include<stdlib.h>

// Structure of the node
typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;


// Function to create a new node
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL){
        printf("\nMEMORY ALLOCATION FAILED!!\n");
        exit(1);            //here 1 represents PROGRAM TERMINATED UNSUCCESSFULLY
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


// ===================== DOUBLE LINK LIST FUNCTIONS =====================//


// Function to insert node at beginning
Node* insertAtBeginning(Node* head, int data){
    Node* newNode = createNode(data);

    if(head == NULL){
        return newNode;
    }

    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return newNode;
    }
}



// Function to insert node after a specific value
Node* insertAfterValue(Node* head, int data, int targetValue){
    Node* current = head;

    while(current != NULL && current->data != targetValue){
        current = current->next;
    }

    if(current == NULL){
        printf("\nEntered value: %d is not in the list,\n", targetValue);
        return head;
    }

    Node* newNode = createNode(data);

    newNode->next = current->next;
    newNode->prev = current;
    
    if(current->next != NULL){
        Node* temp = current->next;
        temp->prev = newNode;
    }
    current->next = newNode;

    return head;
}


// Function to insert node at end
Node* insertAtEnd(Node* head, int data){
    Node* newNode = createNode(data);
    if(head == NULL){
        return newNode;
    }

    else{
        Node* current = head;
        while(current->next != NULL){
            current = current->next;
        }

        current->next = newNode;
        newNode->prev = current;
        newNode->next = NULL;
    }
}



// Function to delete node at beginning
Node* deleteAtBeginning(Node* head){
    if(head == NULL){
        printf("\nOops!! Looks like the list is empty.\n");
        return NULL;
    }

    Node* temp = head;
    head = head->next;
    free(temp);
    
    return head;
}



// Function to delete node after specific value
Node* deleteAfterValue(Node* head, int targetValue){
    if(head == NULL){
        printf("\nOops!! Looks like the list is empty.\n");
        return NULL;
    }

    Node* current = head;

    while(current->next != NULL && current->data != targetValue){
        current = current->next;
    }

    if(current == NULL){
        printf("\nTarget Value %d is not in the list.\n", targetValue);
        return head;
    }

    if(current->next == NULL){
        printf("\nTarget Value %d is the last node. Can't perform deletion.\n", targetValue);
        return head;
    }

    Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    nodeToDelete->next->prev = current;

    free(nodeToDelete);
    
    return head;
}



// Function to delete node at end
Node* deleteAtEnd(Node* head){
    if(head == NULL){
        printf("\nOops!! Looks like the list is empty.\n");
        return NULL;
    }

    if(head->next == NULL){             //only one node in the list
        free(head);
        return NULL;
    }

    Node* current = head;

    while(current->next != NULL){
        current = current->next;
    }

    current->prev->next = NULL;
    free(current);

    return head;
}



// Function to display double link list
void displayList(Node* head){
    if(head == NULL){
        printf("\nOops!! Looks like the list is empty.\n");
        return;
    }

    Node* current = head;
    while(current != NULL){
        printf("%d <-> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}



// ===================== CIRCULAR DOUBLE LINK LIST FUNCTIONS =====================//



// Function to insert node at beginning
Node* insertAtBeginningCircular(Node* head, int data){
    Node* newNode = createNode(data);

    if(head == NULL){
        newNode->next = newNode;
        newNode->prev = newNode;

        return newNode;
    }

    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
    head = newNode;

    return head;
}



// Function to insert node after a specific value
Node* insertAfterValueCircular(Node* head, int data, int targetValue){
    Node* newNode = createNode(data);

    if(head == NULL){
        newNode->next = newNode;
        newNode->prev = newNode;

        return newNode;
    }

    Node* current = head;

    while(current != head){
        if(current->data == targetValue){
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;

            return head;
        }

        current = current->next;
    }  

    printf("\nTarget Value %d is not in the list.\n", targetValue);

    return head;
}



// Function to insert node at end
Node* insertAtEndCircular(Node* head, int data){
    Node* newNode = createNode(data);

    if(head == NULL){
        newNode->next = newNode;
        newNode->prev = newNode;

        return newNode;
    }

    Node* current = head;

    while(current->next != head){
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    newNode->next = head;

    return head;
}



// Function to delete node at beginning
Node* deleteAtBeginningCircular(Node* head){
    if(head == NULL){
        printf("\nOops!! Looks like the list is empty.\n");
        return NULL;
    }

    if(head->next == head){
        free(head);
        return NULL;
    }

    Node* temp = head;
    
    head->next->prev = head->prev;
    head->prev->next = head->next;
    head = temp->next;

    free(temp);

    return head;
}



// Function to delete node after specific value
Node* deleteAfterValueCircular(Node* head, int targetValue){
    if(head == NULL){
        printf("\nOops!! Looks like the list is empty.\n");
        return NULL;
    }

    if(head->next == head){
        free(head);
        return NULL;
    }

    Node* current = head;

    while(current->data != targetValue){
        current = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    
    free (current);

    return head;
}



// Function to delete node at end
Node* deleteAtEndCircular(Node* head){
    if(head == NULL){
        printf("\nOops!! Looks like the list is empty.\n");
        return NULL;
    }

    if(head->next == head){
        free(head);
        return NULL;
    }

    Node* current = head;

    while(current->next != head){
        current = current->next;
    }

    current->prev->next = head;
    head->prev = current->prev;

    free(current);

    return head;
}



// Function to display double link list
void displayListCircular(Node* head){
    if(head == NULL){
        printf("\nOops!! Looks like the list is empty.\n");
        return;
    }

    Node* current = head;

    do{
        printf("%d <-> ", current->data);
        current = current->next;
    }while(current != head);

    printf("HEAD\n");
}



// ===================== MAIN =====================//
int main() {
    Node* doubleList = NULL;        //Initialize double-linked list
    Node* circularDoubleList = NULL;      //Initialize circular double-linked list

    int choice;
    int data, targetValue;

    while (1) {
        printf("\nChoose the list:\n");
        printf("1. Double Linked List\n");
        printf("2. Circular Double Linked List\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nOperations for Double Linked List:\n");
                printf("1. Insert at Beginning\n");
                printf("2. Insert After a Specific Value\n");
                printf("3. Insert at End\n");
                printf("4. Delete at Beginning\n");
                printf("5. Delete After a Specific Value\n");
                printf("6. Delete at End\n");
                printf("7. Display List\n");
                printf("8. Back to Main Menu\n");

                while (1) {
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter data to insert: ");
                            scanf("%d", &data);
                            doubleList = insertAtBeginning(doubleList, data);
                            break;

                        case 2:
                            printf("Enter target value: ");
                            scanf("%d", &targetValue);
                            printf("Enter data to insert: ");
                            scanf("%d", &data);
                            doubleList = insertAfterValue(doubleList, data, targetValue);
                            break;

                        case 3:
                            printf("Enter data to insert: ");
                            scanf("%d", &data);
                            doubleList = insertAtEnd(doubleList, data);
                            break;

                        case 4:
                            doubleList = deleteAtBeginning(doubleList);
                            break;

                        case 5:
                            printf("Enter target value: ");
                            scanf("%d", &targetValue);
                            doubleList = deleteAfterValue(doubleList, targetValue);
                            break;

                        case 6:
                            doubleList = deleteAtEnd(doubleList);
                            break;

                        case 7:
                            printf("Double Linked List: ");
                            displayList(doubleList);
                            break;

                        case 8:
                            break;

                        default:
                            printf("Invalid choice!\n");
                            break;
                    }

                    if (choice == 8) {
                        break;
                    }
                }
                break;

            case 2:
                printf("\nOperations for Circular Double Linked List:\n");
                printf("1. Insert at Beginning\n");
                printf("2. Insert After a Specific Value\n");
                printf("3. Insert at End\n");
                printf("4. Delete at Beginning\n");
                printf("5. Delete After a Specific Value\n");
                printf("6. Delete at End\n");
                printf("7. Display List\n");
                printf("8. Back to Main Menu\n");

                while (1) {
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter data to insert: ");
                            scanf("%d", &data);
                            circularDoubleList = insertAtBeginningCircular(circularDoubleList, data);
                            break;

                        case 2:
                            printf("Enter target value: ");
                            scanf("%d", &targetValue);
                            printf("Enter data to insert: ");
                            scanf("%d", &data);
                            circularDoubleList = insertAfterValueCircular(circularDoubleList, data, targetValue);
                            break;

                        case 3:
                            printf("Enter data to insert: ");
                            scanf("%d", &data);
                            circularDoubleList = insertAtEndCircular(circularDoubleList, data);
                            break;

                        case 4:
                            circularDoubleList = deleteAtBeginningCircular(circularDoubleList);
                            break;

                        case 5:
                            printf("Enter target value: ");
                            scanf("%d", &targetValue);
                            circularDoubleList = deleteAfterValueCircular(circularDoubleList, targetValue);
                            break;

                        case 6:
                            circularDoubleList = deleteAtEndCircular(circularDoubleList);
                            break;

                        case 7:
                            printf("\nCircular Double Linked List: ");
                            displayListCircular(circularDoubleList);
                            break;

                        case 8:
                            break;

                        default:
                            printf("\nInvalid choice!\n");
                            break;
                    }

                    if (choice == 8) {
                        break;
                    }
                }
                break;

            case 3:
                printf("\nGOODBYE! Exiting the program.\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}