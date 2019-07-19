#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int swaps =0;
int comparsions=0;

int partition(int array[], int l, int h);
void quicksort2(int l, int h, int array[]);
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
    quicksort2(0,9999,no_dup);
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
    quicksort2(0,9999,dup);
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
    quicksort2(0,9999,asort);
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
    quicksort2(0,9999,dsort);
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
    quicksort2(0,9999,uniform);
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


int partition(int array[], int l , int h){
    int i = h - 1;
    int piv = array[h] ;            //make the last element as pivot element.
    for(int j =h -1; j >= l ; j-- )  {
   
            comparsions=comparsions+1;
          if ( array[ j ] > piv) {
                 swaps = swap ( i, j, array);
            i -= 1;
        }
   }
   swaps = swap (h ,(i+1), array) ;  //put the pivot element in its proper place.
   return i+1;                      //return the position of the pivot
}
void quicksort2(int l , int h , int array[]){
        
        if(l<h){
                int x= partition(array,l,h); // first orginal quicksort, x is value in array of partition
                //printf("%i", x);
                //printf("\n");
        
        // now need to partition it into its 2 halves so call quick sort
        quicksort2(l,x-1,array); // minus one because we dont want last value to be used
        quicksort2(x+1,h,array);
        }
        




}
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