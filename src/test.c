#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../include/hashTable.h"
#include "../include/ioHandler.h"
#include "../include/stringArray.h"


/** Definitions are stored in file for testing ease **/

void testIoHandler();
void testStringArray();

void testHashTable();
void testHashTableCreate(size_t size);
void testHashTableDestroy(size_t size);
void testHashTableInsert(HTable *hashTable, char *data);

int main(int argc, char **argv){
    
    //SystemTesting
    
    testStringArray();
    
    testHashTable();

}

void testStringArray(){
    
    //very rough module test
    
    printf("STRING ARRAY\n\nCreating String Array\n\n");
    StringArray* stringArray = createStringArray();
    
    printf("\tReading array from file\n");
    readCharArray("userTest.txt", stringArray);
    
    if(stringArray == NULL) printf("File Error\n");
    else{
        
        printf("\tFile worked..\n");
    
        printf("\twords read successfully :%d\n", stringArray->count);
        printf("\ttotal characters stored :%d\n\n", stringArray->size);
    
        for(int i = 0; i < stringArray->count; i++){
        
            printf("\t\t%s\n", stringArray->array[i]);
        
        }
    
    }
    
    printf("\n\n\n");
    
}

void testHashTable(){
    
    printf("HASH\n\n");
    
    //testing with all prime numbers (for sizes)
    size_t testingNumbers[] = {1, 3, 7, 10, 29, 199, 541, 10007, 104743, 15485867, 2147483647};
    
    //testing with strings
    char* testingString[] = {"apple", "test", "word", "Happening", "Happen", "ZZZZZZZZZ"};
    
    
    /// unit testing with table sizes
    printf("Testing Creating a hash with multiple different sizes.\n\n");
    
    for(int i = 0; i < 11; i++){
        
        printf("\tTest Number <%d>\tSize <%zu>\n", (i + 1), testingNumbers[i]);
        testHashTableCreate(testingNumbers[i]);
        
    }
    
    printf("\n");
    
    
    /// unit testing with destroying
    printf("Testing Destroying a hash with multiple different sizes.\nTest unit seperatly with ValGrind.\n\n");
    
    for(int i = 0; i < 11; i++){
        
        printf("\tTest Number <%d> \tSize <%zu>\n", (i + 1), testingNumbers[i]);
        testHashTableDestroy((size_t)testingNumbers[i]);
        
    }
    
    printf("\n");
    
    
    /// general testing for insert + delete
    printf("Testing Inserting data(Strings) into hash.\n\n");
    
    HTable *insertTable = createTable(11, hashNode, destroyNodeData, printNodeData);
    
    for(int i = 0; i < 6; i++){
        
        printf("\tTest Number <%d> \tWord <%s>\n", (i + 1), testingString[i]);
        testHashTableInsert(insertTable, testingString[i]);
        
    }
    
    printf("\n");
    printMetaData(insertTable);
    printf("\n");
    
    printf("Testing Destroying a table with data.\n\n");
    
    /// hypothesis
    printf("\tHash Table should destroy without any errors.\n");
    
    /// test
    destroyTable(insertTable);
    
    /// results
    printf("\tNo seg fault!\n");
}

void testHashTableCreate(size_t size){
    
    /// hypothesis
    printf("\tHash Table should create without any errors.\n");
    
    /// test
    HTable *hashTable = createTable(size, hashNode, destroyNodeData, printNodeData);
    
    /// results
    printf("\t");
    printMetaData(hashTable);

    printf("\n");
    printf("\tNo seg fault!\n");
    
}

void testHashTableDestroy(size_t size){
    
    //timer
    clock_t start,end;
    
    /// hypothesis
    printf("\tHash Table should destroy without any errors. And within a decent amount of time.\n");
    
    /// test
    HTable *hashTable = createTable(size, hashNode, destroyNodeData, printNodeData);
    
    start = clock();
    destroyTable(hashTable);
    end = clock();
    
    /// results
    
    //if it makes it past destroy
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\tNo seg fault. Total time <%lf>\n", time);
    printf("\n");
    
}

void testHashTableInsert(HTable *hashTable, char *data){
    
    /// hypothesis
    printf("\tHash Table should insert without error.\n");
    
    /// test
    insertDataWord(hashTable, data);
    
    /// results
    printf("\t");
    
    if(lookupDataWord(hashTable, data) != NULL){
        
        printf("ERROR. Word not added.\n");
        
    }
    else {
        
        printf("Word added correctly.\n\t");
        
    }
    
    printf("\n");
    
    
}


