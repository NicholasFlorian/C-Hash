#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/spellCheck.h"
#include "../include/ioHandler.h"
#include "../include/hashTable.h"
#include "../include/stringArray.h"

//TODO MAKE ENDIFS AND START IFS FOR H File

int main(int argc, char **argv){
    
    //menu data
    int input = 0;
    
    printf("SETTING UP DICTIONARY\n");
    //dictionary string array
    StringArray *dictionary = createStringArray();
    readCharArray(argv[1], dictionary);
    
    printf("SETTING UP HASHMAP\n");
    //hashmap
    HTable *hashTable = createTable(222007, hashNode, destroyNodeData, printNodeData);
    
    printf("PARSING DICTIONARY INTO MAP\n");
    //load them all
    for(int i = 0; i < /*dictionary->count*/10000; i++){
        
      
        if(keyGenerator(dictionary->array[i]) > 0){
            
              insertDataWord(hashTable, dictionary->array[i]);
            
        }
        
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
                
                addString(dictionary, inputWord);
                insertDataWord(hashTable, dictionary->array[dictionary->count]);
                
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
                printf("What is the file you want to spell check: ");

                //get data from user file
                char *fileToCheck = softenStringInput();
                StringArray *toCheck = createStringArray();
                readCharArray(fileToCheck, toCheck);
                
                int correctCount = 0;
                int incorrectCount = 0;
                
                
                printf("File processed by spell check\n");
                
                for(int i = 0; i < toCheck->count; i++){
                    
                    if(lookupDataWord(hashTable, toCheck->array[i]) == NULL){
                        
                        printf("%s was not found in the dictionary.\n", toCheck->array[i]);
                        incorrectCount++;
                        
                    }else{
                        
                        correctCount++;
                        
                    }
                    
                }
                
                //free(fileToCheck);
                //free(toCheck);
                
                printf("Summary:\nCorrectly spelt words: %d\nIncorrectly spelt words: %d", correctCount, incorrectCount);
                
                break;
            
            case 4:
                //print words
            
                for(int i = 0; i < dictionary->count; i++){
                    
                    if(!(lookupDataWord(hashTable, dictionary->array[i]) == NULL)){
                        
                        betterPrintNodeData(hashTable,lookupDataWord(hashTable, dictionary->array[i]));
                        
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
