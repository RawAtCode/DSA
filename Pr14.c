// PROGRAM 14 - GRAPH TRAVERSALS (BFS AND DFS)

#include <stdio.h>
#define SIZE 10

int adjacencyMatrix[SIZE][SIZE];
int visited[SIZE];


//  BREADTH FIRST SEARCH FUNCTION
void breadthFirstSearch(int startingVertex, int vertices){
    for(int i=0; i<SIZE; i++){
        visited[i] = 0;
    }

    int queue[vertices];
    int front = 0;
    int rear = 0;

    visited[startingVertex] = 1;
    queue[rear] = startingVertex;
    rear++;

    while(front != rear){
        int currentVertex = queue[front];
        front++;

        printf("%d ", currentVertex);

        for(int i=0; i<vertices; i++){          // checking all adjacent vertices
            if(adjacencyMatrix[currentVertex][i] == 1 && visited[i] != 1){
                visited[i] = 1;
                queue[rear] = i;
                rear++;
            }
        }
    }
}


// DEPTH FIRST SEARCH FUNCTION
void depthFirstSearch(int startingVertex, int vertices){
    for(int i=0; i<SIZE; i++){
        visited[i] = 0;
    }

    int stack[vertices];
    int tos = -1;

    visited[startingVertex] = 1;
    tos++;
    stack[tos] = startingVertex;


    while(tos != -1){
        int currentVertex = stack[tos];
        tos--;

        printf("%d ", currentVertex);

        for(int i=0; i<vertices; i++){          // checking all adjacent vertices
            if(adjacencyMatrix[currentVertex][i] == 1 && visited[i] != 1){
                visited[i] = 1;
                tos++;
                stack[tos] = i;
            }
        }
    }
}


// CREATE AND PRINT ADJACENCY MATRIX FUNCTION
void createAdjacencyMatrix(int vertices, int edges){
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            adjacencyMatrix[i][j] = 0;
        }
    }

    printf("\nEnter the starting and ending vertex of :\n");
    int start, end;

    for(int i=0; i<edges; i++){
        printf("Edge %d : ", i+1);
        scanf("%d %d", &start, &end);

        adjacencyMatrix[start][end] = 1;
        adjacencyMatrix[end][start] = 1;
    }
}

void printAdjacencyMatrix(int vertices){
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}


// MAIN PROGRAM
int main(){
    int vertices, edges, choice, startingVertex;

    printf("Enter the number of Vertices : ");
    scanf("%d", &vertices);


    printf("\nEnter the number of Edges : ");
    scanf("%d", &edges);


    createAdjacencyMatrix(vertices, edges);

    printf("\n\nAdjacency matrix:\n");
    printAdjacencyMatrix(vertices);

    do{
        printf("\n\nMENU\n1. Breadth First Search\n2. Depth First Search\n3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the starting node for BFS: ");
                scanf("%d", &startingVertex);
                printf("\nBFS : ");
                breadthFirstSearch(startingVertex, vertices);
                break;
            case 2:
                printf("\nEnter the starting node for DFS: ");
                scanf("%d", &startingVertex);
                printf("\nDFS : ");
                depthFirstSearch(startingVertex, vertices);
                break;
            case 3:
                printf("\nGoodbye!!\n\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    }while(choice != 3);
   

    return 0;
}