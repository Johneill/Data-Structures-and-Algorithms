#include <stdio.h>
#include <time.h> 

int swaps =0;
int comparsions=0;

int partition(int array[], int l, int h);
void quicksort2(int l, int h, int array[]);
int swap(int i , int j, int array[]);



int main (int argc, char *argv[]){
    int x;
    clock_t t;
    int no_dup[10]= {2,1,3,6,8,0,9,5,4,7};
    int dup[10]=    {3,3,2,1,1,4,5,7,7,9};
    int asort[10]=  {0,1,2,3,4,5,6,7,8,9};
    int dsort[10]=  {9,8,7,6,5,4,3,2,1,0};
    int uniform[10]={3,3,3,3,3,3,3,3,3,3};

    
    /*quicksort2(0,9,dsort);
    for (int i=0; i<=9; i++){
    printf("%i", dsort[i]);
    }
    printf("\n");
    printf("Swaps:");
    printf("%i", swaps);
    printf("\n");
    printf("Comparsions:");
    printf("%i", comparsions);
    printf("\n");*/

    t=clock();
    quicksort2(0,9,no_dup);
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
   
  

    swaps=0;
    comparsions=0;
    t=clock();
    quicksort2(0,9,dup);
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
    

    swaps=0;
    comparsions=0;
    t=clock();
    quicksort2(0,9,asort);
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


    swaps=0;
    comparsions=0;
    t=clock();
    quicksort2(0,9,dsort);
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


    swaps=0;
    comparsions=0;
    t=clock();
    quicksort2(0,9,uniform);
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
    


    return 0;
}


int partition(int array[], int l , int h){
    int i = h - 1;
    int piv = array[h] ;            //make the last element as pivot element.
    for(int j =h-1; j >= l ; j-- )  {
   
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
        

        

        array[j]=x;
        array[i]=k;

 return swaps;

//printf("hjhjhjh");
}