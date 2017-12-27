#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/ioHandler.h"
#include "../include/hashTable.h"
#include "../include/spellCheck.h"


//TODO MAKE ENDIFS AND START IFS FOR H File

int main(int argc, char **argv){
    
    //menu data
    int input = 0;
    
    //variables for the dictionary
    int *length = malloc(sizeof(int));
    int *size = malloc(sizeof(int));
    char **dictionary = readCharArray(argv[1], length, size);
    
    //hashmap
    HTable *hashTable = createTable(97, hashNode, destroyNodeData, printNodeData);
    
    //load them all
    for(int i = 0; i < *length; i++){
        
        insertDataWord(hashTable, dictionary[i]);
        
    }
    
    //start the menu
    printf("Welcome to the Main Menu\n");
    
    
    while(1){
        
        input = menu();
        
        switch(input){
            
            case 1:
                //add
                printf("Type the word you want to add: ");
                
                char* inputWord = softenStringInput();
                
                dictionary = increaseWords(dictionary, length, inputWord, size);
                insertDataWord(hashTable, dictionary[*length -1]);
                
                free(inputWord);
                
                break;
            
            case 2:
                //remove
                printf("Type the word you want to remove: ");
                
                char* removeWord = softenStringInput();
                
                hashTable->destroyData(lookupDataWord(hashTable, removeWord));
            
                free(removeWord);
                
                break;
            
            case 3:
                //spell check
                printf("What is the file you want to spellcheck: ");

                char *fileToCheck = softenStringInput();
                
                int *toCheckLength = malloc(sizeof(int));
                int *toCheckSize = malloc(sizeof(int));
                char** toCheck = readCharArray(fileToCheck, toCheckLength, toCheckSize);
                
                int correctCount = 0;
                int incorrectCount = 0;
                
                
                printf("File processed by Spell Check\n");
                for(int i = 0; i < *toCheckLength; i++){
                    
                    if(lookupDataWord(hashTable, toCheck[i]) == NULL){
                        
                        printf("%s was not found in the dictionary.\n", toCheck[i]);
                        incorrectCount++;
                        
                    }else{
                        
                        correctCount++;
                        
                    }
                    
                }
                
                free(fileToCheck);
                free(toCheckLength);
                free(toCheckSize);
                free(toCheck);
                
                
                printf("Summary:\nCorrectly spelt words: %d\nIncorrectly spelt words: %d", correctCount, incorrectCount);
                
                break;
            
            case 4:
                //print words
            
                for(int i = 0; i < *length; i++){
                    
                    if(!(lookupDataWord(hashTable, dictionary[i]) == NULL)){
                        
                        betterPrintNodeData(hashTable,lookupDataWord(hashTable, dictionary[i]));
                        
                    }
                    
                }
                
                break;
            
            case 5:
                //quit
            
                //TODO deallocate
                
                //end program
                return 0;
            
                break;
            
            default:
                
                printf("Invalid input\n");
            
                continue;
                
        }
   
        printf("\n");
        
    }
    
}

int menu(){

    printf("Please enter a menu option\n1) Add a word to Dictionary\n2) Remove a word from Dictionary\n3) Spell Check a file\n4) Show Dictionary words\n5) Quit\n");
   
    return softenIntInput();
    
}
