#include <stdlib.h>
#include <stdio.h>

#include "../include/hashTable.h"
#include "../include/ioHandler.h"

int main(int argc, char **argv){
    
    //create hash
    
    //dictionary
    int *length = malloc(sizeof(int));
    int *size = malloc(sizeof(int));
    char **dictionary = readCharArray("dictionaryTest.txt", length, size);
    
    //hashmap
    HTable *hashTable = createTable(97, hashNode, destroyNodeData, printNodeData);
    
    //load them all
    for(int i = 0; i < *length; i++){
        
        insertDataWord(hashTable, dictionary[i]);
        
    }
    
    //print hash
    
    for(int i = 0; i < *length; i++){
        
        if(!(lookupDataWord(hashTable, dictionary[i]) == NULL)){
            
            betterPrintNodeData(hashTable,lookupDataWord(hashTable, dictionary[i]));
            
        }
        
    }
    
    //add word to hash
    dictionary = increaseWords(dictionary, length, "caps", size);
    insertDataWord(hashTable, "caps");
    
    //print hash
    
    for(int i = 0; i < *length; i++){
        
        if(!(lookupDataWord(hashTable, dictionary[i]) == NULL)){
            
            betterPrintNodeData(hashTable,lookupDataWord(hashTable, dictionary[i]));
            
        }
        
    }
    
    //take away word from hash
    hashTable->destroyData(lookupDataWord(hashTable, "Purple"));

    //print hash
    for(int i = 0; i < *length; i++){
        
        if(!(lookupDataWord(hashTable, dictionary[i]) == NULL)){
            
            betterPrintNodeData(hashTable,lookupDataWord(hashTable, dictionary[i]));
            
        }
        
    }
    
    //spell check
    int *toCheckLength = malloc(sizeof(int));
    int *toCheckSize = malloc(sizeof(int));
    char** toCheck = readCharArray("userTest.txt", toCheckLength, toCheckSize);
    
    int correctCount = 0;
    int incorrectCount = 0;
    
    
    for(int i = 0; i < *toCheckLength; i++){
        
        if(lookupDataWord(hashTable, toCheck[i]) == NULL){
            
            printf("%s was not found in the dictionary.\n", toCheck[i]);
            incorrectCount++;
            
        }else{
            
            correctCount++;
            
        }
        
    }
    
    printf("Summary:\nCorrectly spelt words: %d\nIncorrectly spelt words: %d", correctCount, incorrectCount);
    
}
