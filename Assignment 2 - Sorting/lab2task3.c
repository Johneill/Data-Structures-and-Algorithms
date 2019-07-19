#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct games {
    char title[100];
    char platform[1000];
    int score;
    int year;
};

int swaps =0;
int comparsions=0;
static struct games g1[19000] ;
static struct games g2007[10000] ;
#define MAX_BUFFER 255

int partition(struct games g1[], int l, int h);
void quicksort2(int l, int h, struct games g1[]);
int swap(int i , int j, struct games g1[]);
int next_field( FILE *f, char *buf, int max );


int main (int argc, char *argv[]){
    int x;
    int k=0;
    int l=0;
    char buffer[MAX_BUFFER];
    //struct games* g1 = malloc(sizeof(struct games) *18700 ) ;
    FILE *f=fopen("ign.csv", "r");

    for(int i =0; i<=18700; i++){
        g1[i].score=0;
        g1[i].year=0;
    }

    while(!feof(f)) {
        int eor = next_field( f, buffer, MAX_BUFFER );
        if(k%4==0){
            strcpy(g1[l].title,buffer);
              //("%s",g1[l].title);
              //printf("\n");
        }
         if(k%4==1){
             strcpy(g1[l].platform,buffer);
        }
         if(k%4==2){
             g1[l].score=atoi(buffer);
             
        }
         if(k%4==3){
             g1[l].year=atoi(buffer);
            l++;
        }
     
       k++;
        
        // double newline if eor is not 0
    }
  

   quicksort2(0,18626,g1);


printf("Game                                    Platfrom            Rating      Year");
printf("\n");
printf("----------------------------------------------------------------------------");
printf("\n");
for (int i=18626;i>=18626; i--){
    printf("%s",g1[i].title);
    printf("\t");
    printf("\t");
    printf("\t");
    printf("\t");
    printf("%s",g1[i].platform);
    printf("\t");
    printf("%i",g1[i].score);
    printf("\t");
    printf("%i",g1[i].year);
    printf("\n");
     
}
for (int i=18625;i>=18624; i--){
    printf("%s",g1[i].title);
    printf("\t");
    printf("%s",g1[i].platform);
    printf("\t");
    if(i==18624)
    printf("\t");
    printf("%i",g1[i].score);
    printf("\t");
    printf("%i",g1[i].year);
    printf("\n");
     
}
for (int i=18623;i>=18618; i--){
    printf("%s",g1[i].title);
    printf("\t");
    printf("\t");
    printf("\t");
    printf("\t");
    printf("%s",g1[i].platform);
    printf("\t");
    printf("\t");
    if(i==18623){
        printf("\t");
    }
     if(i==18621){
        printf("\t");
    }
     if(i==18620){
        printf("\t");
    }
     if(i==18619){
        printf("\t");
    }
    printf("%i",g1[i].score);
    printf("\t");
    printf("%i",g1[i].year);
    printf("\n");
     
}
for(int i=18617; i>=18617; i--){
    printf("%s",g1[i].title);
    printf("\t");
    printf("\t");
    printf("\t");
    printf("%s",g1[i].platform);
    printf("\t");
    printf("%i",g1[i].score);
    printf("\t");
    printf("%i",g1[i].year);
    printf("\n");
}
/*int j=0;
for(int i=0;i<=18626;i++){
    if(g1[i].year==2007){
        g2007[j]=g1[i];
        j++;
    }

}

for(int i=1604; i<=1609; i++){
    printf("%s",g2007[i].title);
    printf("\t");
    printf("\t");
    printf("\t");
    printf("%s",g2007[i].platform);
    printf("\t");
    printf("%i",g2007[i].score);
    printf("\t");
    printf("%i",g2007[i].year);
    printf("\n");
}*/


    return 0;
}


int partition(struct games g1[], int l , int h){
    int i = h - 1;
    int piv = g1[h].score ;            //make the last element as pivot element.
    for(int j =h -1; j >= l ; j-- )  {
   
            comparsions=comparsions+1;
          if ( g1[j].score > piv) {
                 swaps = swap ( i, j, g1);
            i -= 1;
        }
   }
   swaps = swap (h ,(i+1), g1) ;  //put the pivot element in its proper place.
   return i+1;                      //return the position of the pivot
}

void quicksort2(int l , int h , struct games g1[]){
        
        if(l<h){
                int x= partition(g1,l,h); // first orginal quicksort, x is value in array of partition
                //printf("%i", x);
                //printf("\n");
        
        // now need to partition it into its 2 halves so call quick sort
        quicksort2(l,x-1,g1); // minus one because we dont want last value to be used
        quicksort2(x+1,h,g1);
        }
        




}

int swap(int i , int j, struct games g1[]){

        struct games g2[2];
        swaps=swaps+1;
        //printf("%i", swaps);
    g2[1]= g1[i];
    g2[0] =g1[j];
       
        

        g1[j]=g2[1];
        g1[i]=g2[0];

 return swaps;


}

int next_field( FILE *f, char *buf, int max ) {
    int i=0, end=0, quoted=0;
    
    for(;;) {
        // fetch the next character from file
        buf[i] = fgetc(f);
        // if we encounter quotes then flip our state and immediately fetch next char
        if(buf[i]=='"') { quoted=!quoted; buf[i] = fgetc(f); }
        // end of field on comma if we're not inside quotes
        if(buf[i]==',' && !quoted) { break; }
        // end record on newline or end of file
        if(feof(f) || buf[i]=='\n') { end=1; break; }
        // truncate fields that would overflow the buffer
        if( i<max-1 ) { ++i; }
    }
    
    buf[i] = 0; // null terminate the string
    return end; // flag stating whether or not this is end of the line
}