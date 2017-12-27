#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/ioHandler.h"

char **readCharArray(char *url, int *length, int *size){
    
    //the string array to return
    char** fromRead = malloc(sizeof(char) * 0);
    
    //handle each word,
    char* word = malloc(sizeof(char) * 100);

    //count the total
    int count = 0;


    
    //create connection to file
    FILE *file = fopen(url, "r");
    
    //if file doesnt exist let the calling method know
    if(!file){
        
        return NULL;
        
    }
    
    //check for end of file
    while(!feof(file)){
        
        fgets(word, 99, file);
        
        //increase the total amount of chars
        *size+= strlen(word) + 1;
        
        //add the word to array
        fromRead = realloc(fromRead, sizeof(char) * (*size));
        fromRead[count] = shortenWordLength(word);
        
        count++;
        
    }
    
    *length = count;
    
    return fromRead;
    
}

char** increaseWords(char **fromRead, int *length, char *word, int *size){
    
    //get the sizeof the  word to add
   
    *size+= strlen(word) + 1;
    
    //add the word to array
    fromRead = realloc(fromRead, (sizeof(char) * (*size)));
           
    fromRead[*length] = shortenWordLength(word);
    
    //printf("ADDING WORD %s\n", fromRead[*length]);
    
    //increase the word count
    *length = *length + 1;
    
    return fromRead;
    
}

char* shortenWordLength(char *wordToShorten){
    
    int count = 0;
    char *after;
    
    //create memory thats the right size for the string
    count = strlen(wordToShorten) + 1;
    after = malloc(sizeof(char) * count);
 
    //return a new string the correct size,
    strncpy(after, wordToShorten, count);
    
    //remove trailing end character
    if(after[count - 2] == '\n'){
        
        after[count - 2] = '\0';
        after = realloc(after, sizeof(char) * count - 1);
        
    }
    
    return after;
    
}

int softenIntInput(){
    
    int *softenInt = malloc(sizeof(int));

    scanf("%d", softenInt);

    return *softenInt;
    
    
}

char* softenStringInput(){
    
    char *softenString = malloc(sizeof(char) * 100);
    
    scanf("%s", softenString);
    
    return shortenWordLength(softenString);
    
}
