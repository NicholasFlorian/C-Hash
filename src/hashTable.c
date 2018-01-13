#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../include/hashTable.h"

HTable *createTable(size_t size,
                    int  (*hashFunction)(size_t tableSize, int key),
                    void (*destroyData)(void *data),
                    void (*printNode)(void *toBePrinted)){
    
    HTable* newTable = malloc(sizeof(HTable));
    
    if(newTable != NULL){
        
        newTable->size = size;
        newTable->table = malloc(sizeof(Node*) * newTable->size);
        
        newTable->hashFunction = hashFunction;
        newTable->destroyData = destroyData;
        newTable->printNode = printNode;
        
    }
    
    return newTable;
    
}

Node *createNode(int key, void *data){
    
    Node* newNode = malloc(sizeof(Node));
    
    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
    
}


void destroyTable(HTable *hashTable);

void insertDataWord(HTable *hashTable, void *data){
    
    int key = keyGenerator((char*)data);
    insertData(hashTable, key, data);
    
}

void insertData(HTable *hashTable, int key, void *data){
    
    int index = hashTable->hashFunction(hashTable->size, key);

    
    if(hashTable->table[index] == NULL){
        
        printf("OK.   INDEX <%d>\tKEY <%d>\tWORD <%s>\n", index, key, data);
        
        hashTable->table[index] = createNode(key,data);
        
        
        
    }
    else{
        
        printf("BUSY. INDEX <%d>\tKEY <%d>\tWORD <%s>\n", index, key, data);
        
        //rehash is generated based on key + 1, this will recurse until it finds
        //the right spot, should not be too computationally expensive
        insertData(hashTable, key -1 , data);
        
        
    }
    
}

int keyGenerator(char *word){
    
    // A B C D E F G H
    // A*      E+F+G+H
    
    //var
    int length = strlen(word);
    int backLength;
    int muls = 1;
    int sum  = 0;

    
    //Truncate hash
    backLength = (length - 1) - 9;
    if (backLength < 0) backLength = 0;
    
    //get multiplication value
    muls = (int)word[1];
    
    
    
    //ascii encoding
    for(int i = length -1 ; i >= backLength; i--){
        
        int ascii = 0;
        ascii = (int)word[i];
        
        //to lower case
        if(ascii >= 41 && ascii <= 90){
            
            ascii = ascii + 32;
            
        }
        
        //encode a = 0 z = 25
        ascii = ascii -97;
        sum = sum + ascii;
        
    }
    
    //printf("%d,\n", muls * sum);

    
    return ((muls * sum) * muls * 2 ) - sum;
    
}

//char wrapper
void removeDataWord(HTable *hashTable, char* key){
    
    int ikey = keyGenerator(key);
    
    removeData(hashTable, ikey, key);
    
}

void removeData(HTable *hashTable, int key, char* data){
    
    //get the data to delete
    void *foundData = lookupData(hashTable, key, data);
    
    if(data == NULL){
        
        return;
        
    }
    
    destroyNodeData(foundData);
    
}

//char Wrapper look up data
char *lookupDataWord(HTable *hashTable, char *key){
    
    int ikey = keyGenerator(key);
    return (char*)lookupData(hashTable, ikey, key);
    
}

void *lookupData(HTable *hashTable, int key, void *data){
    
    
    char* inData = (char*)data;
    
    //get the data based on the key
    int index = hashTable->hashFunction(hashTable->size, key);

    //return null if it doesnt exsist
    if(hashTable->table[index] == NULL){
        
        return NULL;
        
    }
    
    char* tableData = (char*)hashTable->table[index]->data;
    
    //check if a node has been deleted
    if(tableData[0] == '#'){
        
        return NULL;
        
    }//collision probing
    else if(!(strncasecmp(tableData, inData, strlen(inData) - 1) == 0 && key < hashTable->size - 1)){
        
        //printf("probing for + %s \n", inData);
        return lookupData(hashTable, key + 1, data);
        
    }
    else if( strncasecmp(tableData, inData, strlen(inData) - 1) == 0){
      
        //printf("found same data\n");
        
        return tableData;
        
    }
    
    //printf("null same data\n");
    return NULL;
    
}

int hashNode(size_t tableSize, int key){
    
    //hash division
    return key % tableSize ;
    
}

void destroyNodeData(void *data){
    
    //if null dont delete
    if(data == NULL){
        
        return;
        
    }
    
    //locate hash and reset value inside to #
    strncpy((char*)data, "#\0", 2); //TODO this 2 may cause an issue with an empty word
    
    return;
    
}

void printNodeData(void *toBePrinted){

    //print the data
    printf("%s\n", (char*)toBePrinted);
    
}

void betterPrintNodeData(HTable *hashTable, void* toBePrinted){
    
    int size = hashTable->size;//this is how

    printf("%d %d %s\n", hashNode((size_t)size, keyGenerator(toBePrinted)), keyGenerator(toBePrinted), (char*)toBePrinted);
    
}
