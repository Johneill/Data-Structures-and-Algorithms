
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



// adjacency list node
struct AdjListNode {
    int dest; 
    int weight;
    struct AdjListNode* next; 
};

// adjacency list
struct AdjList { 
    struct AdjListNode *head;  
}; 
// A structure to represent a graph.
struct Graph { 
    int size_a; 
    struct AdjList **array; 
}; 
  
struct AdjListNode* newAdjListNode(int dest, int weight); 
struct Graph* createGraph(int size);
void addEdge(struct Graph* graph, int src, int dest, int weight);
void printGraph(struct Graph* graph); 
void djmethod(struct Graph* graph, int start, int end, int size,int distances[], int parent[]);
void printPath(int parent[], int end, int start);

  

int main() 
{ 
 
    int start=0;
    int size = 7; 
    struct Graph* graph = createGraph(size); 
    addEdge(graph, 0, 1, 1); 
    addEdge(graph, 0, 2, 3); 
    addEdge(graph, 0, 5, 10); 
    addEdge(graph, 1, 6, 2); 
    addEdge(graph, 1,3,7); 
    addEdge(graph, 1,0,1); 
    addEdge(graph, 1,4,5); 
    addEdge(graph, 1,2,1); 
    addEdge(graph, 2,0,3); 
    addEdge(graph, 2,1,1); 
    addEdge(graph, 2,3,9); 
    addEdge(graph, 2,4,3);
    addEdge(graph, 3,6,12); 
    addEdge(graph, 3,1,7); 
    addEdge(graph, 3,2,9); 
    addEdge(graph, 3,4,2); 
    addEdge(graph, 4,2,3); 
    addEdge(graph, 4,1,5); 
    addEdge(graph, 4,3,2); 
    addEdge(graph, 4,5,2); 
    addEdge(graph, 5,4,2); 
    addEdge(graph, 5,3,1); 
    addEdge(graph, 5,0,10);
    addEdge(graph, 6,1,2); 
    addEdge(graph, 6,3,12);

    int distances[size];
    int parent[size];
    for (int i = 0; i < size; ++i) {
        distances[i] = INT_MAX;
        parent[i] = 0;
    }

  
    
    printGraph(graph); 
    int k=4;
    djmethod(graph,start,k,size,distances,parent);
    

    for (int i = 0; i < size; ++i) {
    	printf("Vertex %c, Distance = %d, Path = A -> %c ", i+65, distances[i], i+65);
    	printf("Route = ");
    	printPath(parent, i, start);
    	printf("\n");
	}

    return 0; 
} 

struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
    newNode->dest = dest;
    newNode-> weight = weight; 
    newNode->next = NULL; 
    return newNode; 
} 
  

struct Graph* createGraph(int size) { 
    struct Graph* graph =  (struct Graph*) malloc(sizeof(struct Graph)); 
    graph->size_a = size; 
   
    graph->array =  (struct AdjList*) malloc(size * sizeof(struct AdjList)); 
    // Initialize each adjacency list as empty by  
  
    int i; 
    for (i = 0; i < size; ++i){ 
        graph->array[i] = NULL; 
    }
        
  
    return graph; 
}
void addEdge(struct Graph* graph, int src, int dest, int weight) { 
     
    struct AdjListNode* newNode = newAdjListNode(dest, weight); 
    newNode->next = graph->array[src]; 
    graph->array[src] = newNode; 

  
  
} 

int getMinVertex(int distances[], int visited[], int size)
{
	int min = INT_MAX, index = -1, i;

	for (i = 0; i < size; ++i) {
		if (visited[i] == 0 && min > distances[i]) {
			min = distances[i];
			index = i;
		}
	}

	return index;
}

void djmethod(struct Graph* graph, int start, int end, int size,int distances[], int parent[]){

    int i, visited[size];

    // Initially no routes to vertices are know, so all are infinity
    for (i = 0; i < size; ++i) {
        visited[i] = 0;
    }

    // Setting distance to source to zero
    distances[start] = 0;
    
    for (i = start; i <= end; ++i) {     // Untill there are vertices to be processed
        int minVertex = getMinVertex(distances, visited, size);
        // Greedily process the nearest vertex
		struct AdjListNode * trav = graph->array[minVertex];    // Checking all the vertices adjacent to 'min'
		visited[minVertex] = 1;

        while (trav != NULL) {
        	int u = minVertex;
        	int v = trav->dest;
        	int w = trav->weight;
            

            if (distances[u] != INT_MAX && distances[v] > distances[u] + w) {
                // We have discovered a new shortest route, make the neccesary adjustments in data
                distances[v] = distances[u] + w;
                parent[v] = u;	
            }

            trav = trav->next;
        }
        if(minVertex==end){
            break;
        }
    }
}

void printPath(int parent[], int end, int start){
    if (end == start) {	// reached the source vertex
        printf("%c ", start+65);
        return;
    } else if (parent[end] == 0) {	// current vertex has no parent
    	printf("%c ", end+65);
    	return;
	} else {	// go for the current vertex's parent
        printPath(parent, parent[end], start);
        printf("%c ", end+65);
    }
}



  
// A utility function to print the adjacency list  
// representation of graph 
void printGraph(struct Graph* graph) { 
     
    for (int v = 0; v < graph->size_a; ++v)  { 
        struct AdjListNode* pCrawl = graph->array[v]; 
        printf("\nlist ");
        if(v==0){
                printf("A is connected to:");
                printf("\n");
                printf("A-> ");
        }
        if(v==1){
                printf("B is connected to:");
                printf("\n");
                printf("B-> ");
        }
        if(v==2){
                printf("C is connected to:");
                printf("\n");
                printf("C-> ");;
        }
        if(v==3){
                printf("D is connected to:");
                printf("\n");
                printf("D-> ");
        }
        if(v==4){
                printf("E is connected to:");
                printf("\n");
                printf("E-> ");
        }
        if(v==5){
                printf("F is connected to:");
                printf("\n");
                printf("F-> ");
        }
        if(v==6){
                printf("G is connected to:");
                printf("\n");
                printf("G-> ");
        }
        
        while (pCrawl) { 
            
            if(pCrawl->dest==0){
                printf("A");
                printf("(%i)",pCrawl->weight);
            }
            if(pCrawl->dest==1){
                printf("/B");
                printf("(%i)",pCrawl->weight);
            }
            if(pCrawl->dest==2){
                printf("/C");
                printf("(%i)",pCrawl->weight);
            }
            if(pCrawl->dest==3){
                printf("/D");
                printf("(%i)",pCrawl->weight);
            }
            if(pCrawl->dest==4){
                printf("/E");
                printf("(%i)",pCrawl->weight);
            }
            if(pCrawl->dest==5){
                printf("/F");
                printf("(%i)",pCrawl->weight);
            }
            if(pCrawl->dest==6){
                printf("/G");
                printf("(%i)",pCrawl->weight);
            }
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    } 
}




