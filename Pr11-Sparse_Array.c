// Program 11 : Implement Sparse Arrays

#include <stdio.h>
#define MAX_SIZE 10

// Sparse Matrix

#include <stdio.h>
#define SIZE 10

// Check for sparse matrix
int isSparseMatrix(int matrix[SIZE][SIZE], int row, int col){
     int totalElements = row*col;
    int sparseCount = 0;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(matrix[i][j] != 0){
                sparseCount++;
            }
        }
    }

    if(sparseCount <= totalElements/4){
        return sparseCount;
    }
    return 0;

}


// Create the sparse matrix
void createSparseMatrix(int matrix[SIZE][SIZE], int row, int col, int nonZeroCount){
    int sparseMatrix[nonZeroCount][3];          // Note: Sparse Matrix always have 3 columns
    int count = 0;
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(matrix[i][j] != 0){
                sparseMatrix[count][0] = i;
                sparseMatrix[count][1] = j;
                sparseMatrix[count][2] = matrix[i][j];
                count++;
            }
        }
    }


    printf("\nSparse Matrix: \n");
    printf("%d\t%d\t%d\n", row, col, nonZeroCount);

    for(int i = 0; i < nonZeroCount; i++){
        for(int j = 0; j < 3; j++){
            printf("%d\t", sparseMatrix[i][j]);
        }

        printf("\n");
    }
}


// MAIN PROGRAM
int main(){
    int row, col;
    
    printf("Enter the number of rows: ");
    scanf("%d", &row);

    printf("Enter the number of columns: ");
    scanf("%d", &col);


    if(row <= 0 || col <= 0 || row > SIZE || col > SIZE){
        printf("\nInvalid number of rows or columns.\n");
        return 1;
    }

    int matrix[SIZE][SIZE];
    printf("\nEnter the %dx%d matrix:\n", row, col);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("Enter the element at [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int sparseCount = isSparseMatrix(matrix, row, col);

    if(sparseCount > 0){
        printf("\nIt is a Sparse Matrix.\n");
        createSparseMatrix(matrix, row, col, sparseCount);
    }

    else{
        printf("\nIt is not a Sparse Matrix.\n");
    }
    
    return 0;
}