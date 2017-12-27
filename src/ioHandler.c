#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/ioHandler.h"

char **readCharArray(char *url, int *length, int *size){
    
    //REPLACE WITH Seperate API
    
    
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
   
    //Replace with seperate API
    
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
    
    //var
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
    
    //var
    
    //allow up to 30 digit long numbers
    char *in = malloc(sizeof(char) * 31);
    int softInt = 0;
    
    //get user input as a string
    fgets(in, 30, stdin);
    
    //use atof in order to convert
    softInt = atof(in);
    
    //return a flag for incorrect data
    
    /*
     * atof defualts to a value of 0 if the string
     * is not a valid number. If the user doesnt
     * enter 0 as the first character then it
     * returns -1.
     */
    
    if((int)in[0] != 0 && softInt == 0){
     
        //softenIntInput returns -1 for incorrect numbers
        free(in);
        return -1;
     
    }
    
    free(in);
    return softInt;
    
    
}

int softenInt(char* in){
    
    //var
    int softInt = 0;
    
    //use atof in order to convert
    softInt = atof(in);
    
    //return a flag for incorrect data
    
    /*
     * atof defualts to a value of 0 if the string
     * is not a valid number. If the user doesnt
     * enter 0 as the first character then it
     * returns -1.
     */
    
    if((int)in[0] != 0 && softInt == 0){
        
        //softenInt returns -1 for incorrect numbers
        free(in);
        return -1;
        
    }
    
    return softInt;
    
}

char* softenStringInput(){
    
    //var
    
    //allow up to 80 character words
    char *softenString = malloc(sizeof(char) * 81);
    
    //get input
    fgets(softenString, 80, stdin);
    
    softenString = shortenWordLength(in);
    
    return softenString;
    
}
