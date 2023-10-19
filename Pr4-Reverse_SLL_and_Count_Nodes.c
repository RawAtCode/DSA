//Function for counting the nodes and reversing a Single Link List


#include <stdio.h>
#include <stdlib.h>

//Structure of the node
struct Node{
    int data;
    struct Node* next;
};

typedef struct Node Node;


//Function to create a new list
void createList(Node** head, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

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



//Function for counting the nodes in the list
int countNodes(Node* head){
    int count = 0;
    Node* current = head;
    while(current != NULL){
        count++;
        current = current->next;
    }
    return count;
}



//Function to reverse the list
void reverseList(Node** head){
    Node* prev = NULL;
    Node* current = *head;
    Node* save;

    while(current != NULL){
        save = current->next;
        current->next = prev;
        prev = current;
        current = save;
    }
    *head = prev;
}


//Function to display the list
void displayList(Node* head){
    Node* current = head;
    while(current != NULL){
        printf("%d -> ",current->data);
        current = current->next;
    }
    printf("NULL\n");
}


//================ MAIN STARTS HERE ===================//

int main(){
    struct Node* head = NULL;
    int size, data, i, nodes;

    printf("LET'S CREATE THE LIST FIRST.\n");
    printf("Enter the number of nodes in the list: ");
    scanf("%d",&size);

    for(i=0; i<size; i++){
        printf("Enter the %d element: ",i+1);
        scanf("%d",&data);
        createList(&head, data);
    }
    printf("List created successfully.\n\n");

    while (1){
        printf("\nMenu:\n");
        printf("1. Count the number of nodes\n2. Reverse the list\n3. Display the list\n4. Exit\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            nodes = countNodes(head);
            printf("There are %d nodes in the single link list.\n",nodes);
            break;
        
        case 2:
            reverseList(&head);                                     
            printf("Reversed List: ");
            displayList(head);
            break;

        case 3:
            printf("Single List: ");
            displayList(head);
            break;

        case 4:
            printf("Exiting the program. See Ya!!\n\n");
            exit(0);
        
        default:
            printf("BRAAAAA......What are you doin'??\n\n");
        }
    }
    return 0;
}