#include<stdio.h>
#include<stdlib.h>
#define V 6
#define initial 1
#define waiting 2
#define visited1 3

int visited[V];
int state[V]; 
int q[V], front = 0,rear = 0;

void addEdge(int arr[][V],int src, int dest){
     arr[src][dest] = 1;
}
void printAdjMatrix(int arr[][V]){
     int i, j;

     for(i = 0; i < V; i++)
     {
         for(j = 0; j < V; j++)
         {
             if(j==0&& i==0){
                 printf("  A B C D E F \n");
             }
             if(j==0&& i==0){
                 printf("A ");
             }
             if(j==0&& i==1){
                 printf("B ");
             }
              if(j==0&& i==2){
                 printf("C ");
             }
             if(j==0&& i==3){
                 printf("D ");
             }
              if(j==0&& i==4){
                 printf("E ");
             }
             if(j==0&& i==5){
                 printf("F ");
             }

             printf("%d ", arr[i][j]);
         }
         printf("\n");
     }
}
void DFS(int start,int arr[][V]){
   
    if(start==0){
    printf("Visted %c", start+65);
    }
    else{ 
    printf(" %c", start+65);
    }
    visited[start]=1;

       for(int j=0;j<V;j++){
            if(!visited[j]&& arr[start][j]==1){
                DFS(j,arr);
            }
       }
}


void BFS(int start,int arr[][V]){
    int i;
        visited[start] = 1;
    
    q[rear] = start;
    rear++;
    while (rear != front)
    {
        
        int u = q[front];
        if(u==0){
             printf("Visted %c", u+65);
        }
        else{ 
            printf(" %c", u+65);
            }
        
        front++;
        // check adjacent nodes from u
        int i = 0;
        for (i = 0; i < V; i++) {
            // if there is adjacent vertex add to queue 
            if (!visited[i] && arr[u][i]) {
                q[rear] = i;
                rear++;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main(){
    int adjMatrix[V][V];
    

    int i,j;
    for(i = 0; i < V; i++){
        for(j = 0; j < V; j++){
            q[i]=0;
            adjMatrix[i][j] = 0;
        }
        visited[i]=0;
    }

    
    addEdge(adjMatrix, 0, 1); 
    addEdge(adjMatrix, 0, 3); 
    addEdge(adjMatrix, 0, 4); 
    addEdge(adjMatrix, 4, 3); 
    addEdge(adjMatrix, 3, 5); 
    addEdge(adjMatrix, 5, 2); 
    addEdge(adjMatrix, 2, 3); 
    addEdge(adjMatrix, 2, 1); 
    addEdge(adjMatrix, 1, 2); 
    addEdge(adjMatrix, 1, 3); 

    printAdjMatrix(adjMatrix);
    printf("\n");

    DFS(0, adjMatrix);
    printf("\n");
    for(int i=0; i<V; i++){
        visited[i]=0;
    }
    BFS(0,adjMatrix);
    return 0;
}

