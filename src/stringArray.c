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

void readCharArray(char *url, StringArray* stringArray){
 
    //var
    
    //handle each word, allow up to 81 chars
    char* word = malloc(sizeof(char) * 81);
    
    //create connection to file
    FILE *file = fopen(url, "r");
    
    
    //if file doesnt exist let the calling method know
    if(!file){
        
        stringArray = NULL;
        
    }
    
    //check for end of file
    while(!feof(file)){
        
        //strclr(word); forgot dont have stackoverflow rn to check
        
        //get the word
        fgets(word, 80, file);
 
        addString(stringArray, word);
        
    }
    
    free(word);
    
}

void addString(StringArray* stringArray, char* stringToAdd){
    
    //var
    int length = 0;
    
    //increase the amount of chars
    length = strlenX(stringToAdd) + 1; //1 for trailing end /0
    stringArray->size+= length;
    
    //printf("Current size of charArray: %d\n", stringArray->size);
    
    //printf("A, ");
    
    //increase the memory of the array
    stringArray->array = realloc(
        stringArray->array,
        sizeof(char*) * (stringArray->count + 1) );
   
    //printf("B\n");
    
    //add word to stringArray
    
    stringArray->array[stringArray->count] = malloc(sizeof(char) * length);
    strcpy(stringArray->array[stringArray->count], shortenWordLength(stringToAdd));
    
    printf("array at index <%d>, <%s>\n", stringArray->count, stringArray->array[stringArray->count]);
    
    
    stringArray->count++;
    
}

void deleteStringArray(StringArray* stringArray){

    //TODO
    
}

int strlenX(char *stringToIndex){
    
    int length = strlen(stringToIndex);
    
    //ignore getting the length of the word if the \n is within
    if(stringToIndex[length - 1] == '\n'){
        
        return length -1;
        
    }
    
    return length;
    
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
    else{
        
        
        
    }
    
    printf("AFTER = %s\n",after);
    
    //free old word and return new word
    //free(wordToShorten);
    return after;
    
}
