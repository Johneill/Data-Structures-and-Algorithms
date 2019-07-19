#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int swaps =0;
int comparsions=0;


void bubble(int l, int h, int array[]);
void insertionSort(int array[], int n); 
int swap(int i , int j, int array[]);
int swap2(int i , int j, int array[]);




int main (int argc, char *argv[]){
    int x;
    clock_t t;
    int j=0;
    int k=10000;
    int no_dup[10000]; 
    int dup[10000];    
    int asort[10000];
    int dsort[10000];
    int uniform[10000];

    
    for(int i =0; i<10000; i++){
        asort[i]=j;
        no_dup[i]=j;
        uniform[i]=4;
        dup[i]= rand()%5000;
        dsort[i]=k;
        j++;
        k--;
    }

    for(int i=0; i<10000; i++){

            swap2(i,(rand()%10000),no_dup);
    }
    t=clock();
    insertionSort(no_dup,9999);
    for (int i=0; i<=99; i++){
        printf("%i", no_dup[i]);
        printf("\n");

    }
    printf("Test : No Duplicates");
    printf("\n");
    printf("Sorted: Yes");
    printf("\n");
    printf("Swaps:");
    printf("%i", swaps);
    printf("\n");
    printf("Comparsions:");
    printf("%i", comparsions);
    printf("\n");
    t=clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf( "Took %f seconds to execute \n", time_taken); 
    printf("\n");
    printf("\n");
  

    swaps=0;
    comparsions=0;
    t=clock();
    //mergeSort(0,9999,dup);
    printf("Test : Duplicates");
    printf("\n");
    printf("Sorted: Yes");
    printf("\n");
    printf("Swaps:");
    printf("%i", swaps);
    printf("\n");
    printf("Comparsions:");
    printf("%i", comparsions);
    printf("\n");
    t=clock()-t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf( "Took %f seconds to execute \n", time_taken); 
    printf("\n");
    printf("\n");

    swaps=0;
    comparsions=0;
    t=clock();
    bubble(0,9999,asort);
    printf("Test : Asending");
    printf("\n");
    printf("Sorted: Yes");
    printf("\n");
    printf("Swaps:");
    printf("%i", swaps);
    printf("\n");
    printf("Comparsions:");
    printf("%i", comparsions);
    printf("\n");
    t=clock()-t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf( "Took %f seconds to execute \n", time_taken); 
    printf("\n");
    printf("\n");

    swaps=0;
    comparsions=0;
    t=clock();
    bubble(0,9999,dsort);
    printf("Test : Descending");
    printf("\n");
    printf("Sorted: Yes");
    printf("\n");
    printf("Swaps:");
    printf("%i", swaps);
    printf("\n");
    printf("Comparsions:");
    printf("%i", comparsions);
    printf("\n");
    t=clock()-t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf( "Took %f seconds to execute \n", time_taken); 
    printf("\n");
    printf("\n");

    swaps=0;
    comparsions=0;
    t=clock();
    bubble(0,9999,uniform);
    printf("Test : Uniform");
    printf("\n");
    printf("Sorted: Yes");
    printf("\n");
    printf("Swaps:");
    printf("%i", swaps);
    printf("\n");
    printf("Comparsions:");
    printf("%i", comparsions);
    printf("\n");
    t=clock()-t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf( "Took %f seconds to execute \n", time_taken); 
    printf("\n");
    printf("\n");









    return 0;
}

void bubble(int l, int h, int array[]){

for(int j=0; j<=9999; j++){
    for(int i=0; i<= h-1; i++){
        comparsions=comparsions+1;
        if(array[i]>array[i+1]){
            swap(i,(i+1), array);
        }
        
    }
}
}
/*void insertionSort(int array[], int n) 
{ 
   int i, pivot, j; 
   for (int i = 1; i < n; i++) 
   { 
       pivot = array[i]; 
       j = i-1; 

       while (j >= 0 && array[j] > pivot) 
       { 
           array[j+1] = array[j]; 
           j = j-1; 
       } 
       array[j+1] = pivot; 
   } 
} */






int swap(int i , int j, int array[]){

        swaps=swaps+1;
        //printf("%i", swaps);
        int x= array[i];
        int k =array[j];
       /* printf("swapping");
        printf("%i",x);
        printf("%i", k);
        printf("\n");*/

        

        array[j]=x;
        array[i]=k;

 return swaps;

}

int swap2(int i , int j, int array[]){

        //printf("%i", swaps);
        int x= array[i];
        int k =array[j];
        array[j]=x;
        array[i]=k;

 return swaps;

}