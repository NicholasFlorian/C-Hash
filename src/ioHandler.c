#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/ioHandler.h"

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
    
    return softenString;
    
}
