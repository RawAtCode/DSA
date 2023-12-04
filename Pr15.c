#include <stdio.h>

// INSERTION SORT
void insertionSort(int myArray[], int size){
    for(int i = 1; i < size; i++){
        int value = myArray[i];
        int prev = i - 1;

        while(prev >= 0 && myArray[prev] > value){
            myArray[prev+1] = myArray[prev];
            prev = prev-1;
        }

        myArray[prev+1] = value;
    }
}


// QUICK SORT
int partitionFunction(int myArray[], int beg, int end){
    int pivot = myArray[beg];
    int i = beg+1;

    for(int j = beg+1; j <= end; j++){
        if(myArray[j] < pivot){
            int temp = myArray[i];
            myArray[i] = myArray[j];
            myArray[j] = temp;

            i++;
        }
    }

    int sorted = myArray[beg];
    myArray[beg] = myArray[i-1];
    myArray[i-1] = sorted;

    return (i-1);
}

void quickSort(int myArray[], int beg, int end){
    if(beg < end){
        int partition = partitionFunction(myArray, beg, end);

        quickSort(myArray, beg, partition-1);
        quickSort(myArray, partition+1, end);        
    }
}


// MERGE SORT
void mergeFunction(int myArray[], int left, int mid, int right){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int leftSubArray[leftSize], rightSubArray[rightSize];

    // copying data into temporary arrays
    for(int i=0; i<leftSize; i++){
        leftSubArray[i] = myArray[left + i];
    }

    for(int j=0; j<rightSize; j++){
        rightSubArray[j] = myArray[mid+1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    // merging the temporary arrays
    while(i<leftSize && j<rightSize){
        if(leftSubArray[i] <= rightSubArray[j]){
            myArray[k] = leftSubArray[i];
            i++;
        }

        else{
            myArray[k] = rightSubArray[j];
            j++;
        }

        k++;
    }

    // copying remaining elements of left and right sub-arrays
    while(i < leftSize){
        myArray[k] = leftSubArray[i];
        i++;
        k++;
    }

    while(j < rightSize){
        myArray[k] = rightSubArray[j];
        j++;
        k++;
    }

}

void mergeSort(int myArray[], int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;

        mergeSort(myArray, left, mid);
        mergeSort(myArray, mid+1, right);

        mergeFunction(myArray, left, mid, right);
    }
}



// PRINT FUNCTION
void printArray(int myArray[], int size){
    printf("\nSorted array: ");
    for(int i=0; i<size; i++){
        printf("%d ", myArray[i]);
    }
}


// MAIN FUNCTION
int main() {
    int size, choice;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int myArray[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &myArray[i]);
    }

    do{
        printf("\n\nWhat do you want to perform?\n");
        printf("1. Insertion Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Merge Sort\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertionSort(myArray, size);
                printArray(myArray, size);
                break;
            case 2:
                quickSort(myArray, 0, size - 1);
                printArray(myArray, size);
                break;
            case 3:
                mergeSort(myArray, 0, size - 1);
                printArray(myArray, size);
                break;

            case 4:
                printf("\nExiting the program. Happy Coding!!\n");
                break;

            default:
                printf("Pls enter a valid choice.\n");
        }

    }while(choice != 4);

    return 0;
}