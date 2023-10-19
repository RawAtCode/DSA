// Program-2 : TRAVERSE, INSERT, DELETE, LINEAR SEARCH on ARRAY

#include<stdio.h>
#include<stdlib.h>

// FUNCTION TO TRAVERSE AND PRINT THE ARRAY

void traverseArray(int myArray[], int size){
    for(int i=0; i<size; i++){
        printf("%d\t", myArray[i]);
    }
}


// FUNCTION TO INSERT AT A SPECIFIC INDEX

void insertAtIndex(int myArray[], int *size, int data, int index) {
  if (index < 0 || index > *size) {
    printf("Pls enter a valid index.\n");
    return;
  }

  // shifting each element forward
  for (int i = *size; i > index; i--) {
    myArray[i] = myArray[i - 1];
  }

  myArray[index] = data;
  (*size)++;
}



// FUNCTION TO INSERT AT END

void insertAtEnd(int myArray[], int* size, int data){
    if(*size >= 100){
        printf("Array is already full.\n");
        return;
    }

    myArray[*size] = data;
    (*size)++;
}


// FUNCTION TO DELETE AT A SPECIFIC INDEX

void deleteAtIndex(int myArray[], int *size, int index) {
  if (index < 0 || index >= *size) {
    printf("Invalid index for deletion.\n");
    return;
  }

  // Shifting each element backwards
  for (int i = index + 1; i < *size; i++) {
    myArray[i - 1] = myArray[i];
  }

  (*size)--;
}



// FUNCTION TO DELETE AT END

void deleteAtEnd(int myArray[], int *size){
    if(*size <= 0){
        printf("Array is empty.\n");
        return;
    }

    (*size)--;
}


// LINEAR SEARCH FUNCTION

int linearSearch(int myArray[], int size, int targetValue){
    for(int i=0; i<size; i++){
        if(myArray[i] == targetValue){
            return i;
        }
    }

    return -1;
}





// =================== MAIN STARTS HERE =================== //

int main(){
    int size;
    printf("\nEnter the size of array: ");
    scanf("%d", &size);

    if(size <= 0){
        printf("\nPls enter a valid array size.\n");
        return 1;                       //here 1 represents : exiting with an error
    }

    int* myArray = (int*)malloc(size * sizeof(int));            //allocating memory to the given size array
    
    if(myArray == NULL){
        printf("\nMEMORY ALLOCATION FAILED!!\n");
        return 1;
    }

    printf("\nENTER THE ELEMENTS OF THE ARRAY: \n");

    for(int i=0; i<size; i++){
        printf("Enter %d element: ", i+1);
        scanf("%d", &myArray[i]);
    }

    int choice, data, targetValue, index;

    while(1){
        printf("\nMENU: \n");
        printf("1. Traverse the array\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Linear Search\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                traverseArray(myArray, size);
                break;

            case 2:
                while(1){
                    printf("\n1. Insert at a specific index");
                    printf("\n2. Insert at end");
                    printf("\n3. Return to main menu\n");
                    printf("\nEnter your choice: ");
                    scanf("%d", &choice);

                    switch(choice){
                        case 1:
                            printf("\nEnter the element to insert: ");
                            scanf("%d", &data);
                            printf("\nEnter the index to insert at: ");
                            scanf("%d", &index);
                            insertAtIndex(myArray, &size, data, index);
                            printf("\nUpdated array: ");
                            traverseArray(myArray, size);
                            break;

                        case 2:
                            printf("\nEnter the element to insert at end: ");
                            scanf("%d", &data);
                            insertAtEnd(myArray, &size, data);
                            printf("\nUpdated array: ");
                            traverseArray(myArray, size);
                            break;

                        case 3:
                            break;

                        default:
                            printf("INVALID CHOICE!!\n");
                    }

                    if(choice == 3){
                        break;
                    }
                }
                break;

            case 3:
                while(1){
                    printf("\n1. Delete at a specific index");
                    printf("\n2. Delete at end");
                    printf("\n3. Return to main menu\n");
                    printf("\nEnter your choice: ");
                    scanf("%d", &choice);

                    switch(choice){
                        case 1:
                            printf("\nEnter the index to delete at: ");
                            scanf("%d", &index);
                            deleteAtIndex(myArray, &size, index);
                            printf("\nUpdated array: ");
                            traverseArray(myArray, size);
                            break;

                        case 2:
                            deleteAtEnd(myArray, &size);
                            printf("\nUpdated array: ");
                            traverseArray(myArray, size);
                            break;

                        case 3:
                            break;
                        
                        default:
                            printf("INVALID CHOICE!!\n");
                    }

                    if(choice == 3){
                        break;
                    }
                }
                break;

            case 4:
                printf("\nEnter the element to search: ");
                scanf("%d", &targetValue);

                int result = linearSearch(myArray, size, targetValue);

                if(result != -1){
                    printf("\n%d is at index: %d", targetValue, result);
                }

                else{
                    printf("Entered value %d is not in the array.", targetValue);
                }

                break;

            case 5:
                free(myArray);
                printf("\nGOODBYE! HAPPY CODING.\n");
                return 0;

            default:
                printf("\nINVALID CHOICE!! TRY AGAIN.\n");
        }

    }

    return 0;

}