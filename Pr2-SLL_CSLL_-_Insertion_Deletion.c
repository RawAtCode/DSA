#include<stdio.h>                                                           //Header file to import the "printf" and "scanf" functions
#include<stdlib.h>                                                          //Header file to import the "malloc" function

struct Node{                                                                //Structure for the Node
    int data;
    struct Node* next;
};

typedef struct Node Node;


//Function to create a new node

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));                            //allocating the size to the newly created node
    if(newNode == NULL){
        printf("Memory allocation failed!!\n");                             //Might happen due to system failures or power failures
        exit(1);                                                            //1 refers to failure and 0 refers to successful execution of the program
    }

    newNode->data = data;                                                   //Storing value in the data field
    newNode->next = NULL;                                                   //Storing null value in the address field

    return newNode;
}



//==================================== SINGLE LINK LIST FUNCTIONS ====================================//



//Function to insert data at the beginning

void insertAtBeginning(Node** head, int data){
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

//Function to insert data after a specific value

void insertAfter(Node** head, int data, int targetValue){
    Node* current = *head;
    while(current != NULL){
        if(current->data == targetValue){
            Node* newNode = createNode(data);
            newNode->next = current->next;                                  //making the link
            current->next = newNode;                                        //breaking the link
            return;
        }

        current = current->next;
    }

    printf("Entered value %d is not found in the list.\n",targetValue);    
}

//Function to insert data at the end

void insertAtEnd(Node** head, int data){
    Node* newNode = createNode(data);
    if(*head == NULL){              
        *head = newNode;
    }

    else{
        Node* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

//Function to delete data at the beginning

void deleteAtBeginning(Node** head){
    if(*head == NULL){
        printf("List is empty. Cannot perform deletion.\n");
        return;
    }
    else{
        Node* temp = *head;
        *head = (*head)->next;                                              //making the link
        free(temp);                                                         //breaking the link and freeing the memory
        return;
    }
}

//Function to delete data after a specific value
void deleteAfter(Node** head, int targetValue){
    if(*head == NULL){
        printf("List is empty. Cannot perform deletion.\n");
        return;
    }

    Node* current = *head;
    while(current != NULL && current->data != targetValue){
        current = current->next;
    }

    if(current == NULL){
        printf("Entered value is not found in the list.\n");
        return;
    }

    if( current->next == NULL){
        printf("Cannot delete after %d as it is the last node itself.\n",targetValue);
        return;
    }

    Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;                                     //making the link
    free(nodeToDelete);                                                     //breaking the link and freeing the memory

}


//Function to delete data at the end

void deleteAtEnd(Node** head){
    if(*head == NULL){                                                      //checking if the list is empty
        printf("List is empty. Cannot perform deletion.\n");
        return;
    }

    if((*head)->next == NULL){                                              //checking if the list has only one node
        free(*head);
        *head = NULL;
        return;
    }

    Node* current = *head;
    Node* head1 = NULL;                                                     //this will keep track of the predecessor node of the last node

    while(current->next != NULL){
        head1 = current;
        current = current->next;
    }
    head1->next = NULL;                                                     //making the link
    free(current);                                                          //breaking the link and freeing the memory
}

//Function to display a single link list
void displaySingleLinkList(Node* head){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }

    Node* current = head;
    while(current != NULL){
        printf("%d -> ",current->data);
        current = current->next;
    }
    printf("NULL\n");
}



//==================================== SINGLE CIRCULAR LINK LIST FUNCTIONS ====================================//



//Function to insert data at the beginning
void insertAtBeginningCircular(Node**head, int data){
    Node* newNode = createNode(data);

    if(*head == NULL){
        *head = newNode;
        newNode->next = *head;
    }
    else{
        Node* current = *head;
        while(current->next != *head){
            current = current->next;
        }
        newNode->next = *head;                                              //making the link
        current->next = newNode;                                            //breaking the link
        *head = newNode;
    }
}


//Function to insert data after a specific value
void insertAfterCircular(Node** head, int data, int targetValue){
    Node* newNode = createNode(data);

    if(*head == NULL){
        printf("List is empty. Cannot insert the data\n");
        return;
    }

    Node* current = *head;

    do{
        if(current->data == targetValue){
            newNode->next = current->next;                                  //making the link
            current->next = newNode;                                        //breaking the link
            return;
        }
        current = current->next;
    }while(current != *head);

    printf("Entered value %d is not found in the list.\n",targetValue);  
}


//Function to insert data at the end
void insertAtEndCircular(Node** head, int data){
    Node* newNode = createNode(data);

    if(*head == NULL){
        *head = newNode;
        newNode->next = *head;
    }
    else{
        Node* current = *head;
        while(current->next != *head){
            current = current->next;
        }
        newNode->next = *head;                                              //making the link
        current->next = newNode;                                            //breaking the link
    }
}


//Function to delete data at the beginning
void deleteAtBeginningCircular(Node**head){
    if(*head == NULL){                                                      //checking if the list is empty
        printf("List is empty. Cannot perform deletion.\n");
        return;
    }

    Node* temp = *head;
    Node* current = *head;
    while(current->next != *head){
        current = current->next;
    }

    if(current == *head){
        *head = NULL;
    }
    else{
        *head = temp->next;
        current->next = *head;
    }
    free(temp);                                                             //freeing the memory after deleting first node
}


//Function to delete data at the end
void deleteAtEndCircular(Node** head){
    if(*head == NULL){                                                      //checking if the list is empty
        printf("List is empty. Cannot perform deletion.\n");
        return;
    }

    if((*head)->next == *head){                                             //checking if the list has only one node
        free(*head);
        *head = NULL;
        return;
    }

    Node* current = *head;
    Node* head1 = NULL;                                                     //this will keep track of the predecessor node of the last node

    while(current->next != *head){
        head1 = current;
        current = current->next;
    }
    
    head1->next = *head;
    free(current);                                                          //freeing the memory after deleting last node
}


//Function to display a circular single link list
void displayCircularSingleLinkList(Node* head){
    if(head == NULL){                                                       //checking if the list is empty
        printf("List is empty.\n");
        return;
    }
    Node* current = head;
    do{
        printf("%d -> ",current->data);
        current = current->next;
    }while(current != head);

    printf("HEAD\n");                                                       //linking the last node to the first    
}



//==================================== MAIN STARTS HERE ====================================//



int main() {
    Node* singleList = NULL;                                                //Initialize a single link list
    Node* circularList = NULL;                                              //Initialize a circular single link list

    int choice, data, afterData;

    while (1) {
        printf("\nChoose the list:\n");
        printf("1. Single Link List\n2. Circular Single Link List\n3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Single Link List Operations:\n");
                printf("1. Insert at Beginning\n2. Insert after a Specific Value\n3. Insert at End\n");
                printf("4. Delete at Beginning\n5. Delete after a Specific Value\n6. Delete at End\n");
                printf("7. Display\n8. Return to Main Menu\n");

                while (1) {
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter data to insert at the beginning: ");
                            scanf("%d", &data);
                            insertAtBeginning(&singleList, data);
                            printf("Single Link List after Operation: ");
                            displaySingleLinkList(singleList);
                            break;

                        case 2:
                            printf("Enter the value after which you want to insert: ");
                            scanf("%d", &afterData);
                            printf("Enter data to insert: ");
                            scanf("%d",&data);
                            insertAfter(&singleList, data, afterData);
                            printf("Single Link List after Operation: ");
                            displaySingleLinkList(singleList);
                            break;

                        case 3:
                            printf("Enter data to insert at the end: ");
                            scanf("%d", &data);
                            insertAtEnd(&singleList, data);
                            printf("Single Link List after Operation: ");
                            displaySingleLinkList(singleList);
                            break;
                        
                        case 4:
                            deleteAtBeginning(&singleList);
                            printf("Single Link List after Operation: ");
                            displaySingleLinkList(singleList);
                            break;

                        case 5:
                            printf("Enter the value after which you want to delete: ");
                            scanf("%d", &afterData);
                            deleteAfter(&singleList, afterData);
                            printf("Single Link List after Operation: ");
                            displaySingleLinkList(singleList);
                            break;

                        case 6:
                            deleteAtEnd(&singleList);
                            printf("Single Link List after Operation: ");
                            displaySingleLinkList(singleList);
                            break;

                        case 7:
                            printf("Singly Linked List: ");
                            displaySingleLinkList(singleList);
                            break;

                        case 8:
                            break;

                        default:
                            printf("Invalid choice.\n");
                    }

                    if (choice == 8) {
                        break;
                    }
                }
                break;

            case 2:
                printf("Circular Singly Linked List Operations:\n");
                printf("1. Insert at Beginning\n2. Insert after a Specific Value\n3. Insert at End\n");
                printf("4. Delete at Beginning\n5. Delete at End\n");
                printf("6. Display\n7. Return to Main Menu\n");

                while (1) {
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter data to insert at the beginning: ");
                            scanf("%d", &data);
                            insertAtBeginningCircular(&circularList, data);
                            printf("Circular Single Link List after Operation: ");
                            displayCircularSingleLinkList(circularList);
                            break;

                        case 2:
                            printf("Enter the value after which you want to insert: ");
                            scanf("%d", &afterData);
                            printf("Enter data to insert: ");
                            scanf("%d",&data);
                            insertAfterCircular(&circularList, data, afterData);
                            printf("Circular Single Link List after Operation: ");
                            displayCircularSingleLinkList(circularList);
                            break;
                            
                        case 3:
                            printf("Enter data to insert at the end: ");
                            scanf("%d", &data);
                            insertAtEndCircular(&circularList, data);
                            printf("Circular Single Link List after Operation: ");
                            displayCircularSingleLinkList(circularList);
                            break;

                        case 4:
                            deleteAtBeginningCircular(&circularList);
                            printf("Circular Single Link List after Operation: ");
                            displayCircularSingleLinkList(circularList);
                            break;

                        case 5:
                            deleteAtEndCircular(&circularList);
                            printf("Circular Single Link List after Operation: ");
                            displayCircularSingleLinkList(circularList);
                            break;

                        case 6:
                            printf("Circular Single Link List: ");
                            displayCircularSingleLinkList(circularList);
                            break;

                        case 7:
                            break;

                        default:
                            printf("Invalid choice.\n");
                    }

                    if (choice == 7) {
                        break;
                    }
                }
                break;

            case 3:
                printf("\nExiting the program.\nThank You!!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}