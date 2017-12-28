#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/stringArray.h"

StringArray *createStringArray(){
    
    StringArray *stringArray = malloc(sizeof(StringArray));
    
    //set defualt values
    stringArray->array = malloc(sizeof(char));
    stringArray->count = 0;
    stringArray->size = 0;
    
    return stringArray;
    
}

StringArray *readCharArray(char *url, StringArray* stringArray){
 
    //var
    
    //handle each word, allow up to 81 chars
    char* word = malloc(sizeof(char) * 81);
    
    //create connection to file
    FILE *file = fopen(url, "r");
    
    
    //if file doesnt exist let the calling method know
    if(!file){
        
        return NULL;
        
    }
    
    //check for end of file
    while(!feof(file)){
        
        //strclr(word); forgot dont have stackoverflow rn to check
        
        //get the word
        fgets(word, 80, file);
        printf("1,\n");
        addString(stringArray, word);
        printf("2,\n");
        
    }
    
    free(word);
    
    return stringArray;
    
}

void addString(StringArray* stringArray, char* stringToAdd){
    
    //increase the amount of chars
    stringArray->size += strlen(stringToAdd) + 1;
    
    printf("  >>Current size of charArray: %d<<  ", stringArray->size);
    
    printf("A, ");
    
    //increase the memory of the array
    stringArray->array = realloc(
        stringArray->array,
        sizeof(char) * (stringArray->size) );
   
    printf("B\n");

    //ORIGINAL LINE//fromRead[count] = shortenWordLength(word);
    
    //add word to stringArray
    stringArray->array[stringArray->count] = shortenWordLength(stringToAdd);
    
    stringArray->count++;
    
}

void deleteStringArray(StringArray* stringArray){

    //TODO
    
}

char* shortenWordLength(char *wordToShorten){
    
    //var
    int count = 0;
    char *after;
    
    //create memory thats the right size for the string
    count = strlen(wordToShorten) + 1;
    after = malloc(sizeof(char) * count);
    
    //return a new string the correct size,
    strncpy(after, wordToShorten, count);
    
    //remove trailing end character if present
    if(after[count - 2] == '\n'){
        
        after[count - 2] = '\0';
        after = realloc(after, sizeof(char) * count - 1);
        
    }
    
    //free old word and return new word
    //free(wordToShorten);
    return after;
    
}
