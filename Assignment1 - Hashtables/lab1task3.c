//
//  lab1task3.c
//  
//
//  Created by David Neill on 10/10/2018.
//

#include "lab1task3.h"
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 255
#define MAX_LENGTH 1500

struct people {
    char name[20];
    int count;
    int hash;
};

int hash( char*s);
int hash2(int x,int ha, int x1);
int next_field( FILE *f, char *buf, int max );
int store(char*s, int hash,int number, struct people p1[],int collisions);
int search(int hash, struct people p1[], char*s );

int main(){
    int x=0;
    struct people p1[55];
    int runningtotal=0;
    int col=0;
    int collisions=0;
    int hashvalue=0;
    int frequences=0;
    char s[20];
    int scan=0;
    FILE *f=fopen("names.csv", "r");;
    char buffer[MAX_BUFFER];
    
    for(int i =0; i<=54; i++){
        p1[i].hash=0;
        p1[i].count=0;
    }
    
    // Now read and print records until the end of the file
    while(!feof(f)) {
        int eor = next_field( f, buffer, MAX_BUFFER );
        //printf("%s%c", buffer, ((eor)? '\n':' '));
        //printf("%s", buffer);
        hashvalue = hash(buffer);
        //printf("%i",hashvalue);
        //printf("\n");
        collisions=store(buffer,hashvalue, runningtotal,p1, collisions);
        
        // double newline if eor is not 0
    }
    
    
    
    printf("Collisions ");
    printf("%i",collisions);
    printf("\n");
    
   /* for(int i=0; i<55; i++){
        if(p1[i].count!=0){
            printf("%s",p1[i].name);
            printf("\n");
            printf("%i",i);
            printf("\n");
            printf("%i",p1[i].count);
            printf("\n");
        }
        
    }*/
    
    // User interface
    while(x==0){
        printf("Enter name to search for or quit to end: ");
        printf("\n");
        printf(">>> ");
        scanf("%s", s);
        if(strcmp(s,"quit")==0){
            fclose(f);
            return 0;
        }
        printf("%s", s);
        printf(" ");
        scan= hash(s);
        //printf("%d",scan);
        search(scan,p1,s);
        /* if(frequences==0){
         //printf("%s", s);
         printf(" word not in the table");
         }
         else {
         printf("%d", frequences);
         }*/
        
        
        
        printf("\n");
    }
    
    fclose(f);
    return 0;
}

int search(int hash, struct people p1[],char*s){
    int ha=hash%53;
    int k=0;
    
    for(int i=ha; i<=55;i++){
        if(strcmp(p1[i].name,s)==0){
            printf("%i",p1[i].count);
            k=k+1;
            return ha;
        }
        
    }
    if(k==0){
        printf("Word was not found");
    }
    
    
    
    
    return ha;
    
}


int store(char*s, int hash, int number, struct people p1[], int collisions){
    int total=0;
    int j=0;
    int t=0;
    int x=0;
    int x1=0;
    int ha=hash;
    hash=hash%53;
    int number1 =0;
    int number2=0;
    
    
    for(int i=hash; i<=55; i++){
        if (strcmp(p1[i].name,s)==0){
            p1[i].count=p1[i].count+1;
            return collisions;
            
        }
    }
    
    if(p1[hash].hash!=0){
        x=hash;
        x1=1;
        collisions=collisions+1;
        while (p1[x].hash!=0){
           
            x=hash2(x,ha,x1);
            x=(hash+x)%53;
            x1++;
            
        }
        while(*s){
            p1[x].name[number2]=*s;
            number2=number2+1;
            s++;
        }
        p1[x].hash=ha;
        p1[x].count=p1[x].count+1;
        
        
        return collisions;
    }
    
    if(p1[hash].hash==0){
        p1[hash].hash=ha;
        
        while(*s){
            p1[hash].name[number2]=*s;
            number2=number2+1;
            s++;
        }
        number2=0;
        p1[hash].count=p1[hash].count+1;
    }
    
    
    
    return collisions;
}


int hash(char* s){
    int hash = 0;
    int k=1;
    while(*s){
        hash = hash + (*s*k);
        s++;
        k++;
    }
    hash=hash*123;
    return hash;
}

int hash2(int x,int ha, int x1){
    
    int hash=x;
    
    x=hash+x1*(ha%53);
    x=x%53;
    
    return x;
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


