// Program for Binary Search (Iterative)

#include<stdio.h>
#include<stdlib.h>

void binarySearch(int arr[], int item, int size){
    int beg = 0;
    int end = size - 1;
    int found = 0;

    while(beg <= end){
        int mid = beg + (end - beg) / 2;
        if(arr[mid] == item){
            printf("\nSEARCH SUCCESSFUL!!\nElement: %d is at index %d.", item, mid);
            found = 1;
            break;
        }
        else if(arr[mid] < item){
            beg = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    if(!found){
        printf("\nSEARCH UNSUCCESSFUL!!\nElement: %d is not in the array.", item);
    }
}

int main(){
    int size;

    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    
    
    for(int i = 0; i < size; i++){
        printf("Enter element number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int item;

    printf("\nEnter the value you want to search: ");
    scanf("%d", &item);

    binarySearch(arr, item, size);

    return 0;
}




/*

NOTE 1: In C, once an array is passed to a function, it decays into a pointer, and we lose the information about its size 
Therefore, we can't calculate the size of an array directly inside the function without passing it as a separate parameter

This is the reason we can't calculate the size of the array inside the binaraySearch() function


NOTE 2: The behavior can be undefined or unpredictable when you create an array with a size determined at runtime, as you are doing with int arr[size]

So, it is better to determine the size at runtime like this:
int *arr = (int*)malloc(size * sizeof(int));
then free(arr) at the end of program

*/