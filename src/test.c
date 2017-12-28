#include <stdlib.h>
#include <stdio.h>

#include "../include/hashTable.h"
#include "../include/ioHandler.h"
#include "../include/stringArray.h"

void testIoHandler();
void testStringArray();

int main(int argc, char **argv){
    
    //SystemTesting
    testStringArray();
    
}

void testStringArray(){
    
    //very rough system test
    
    printf("Creating String Array\nThis should create all 20 words\n");
    StringArray* stringArray = createStringArray();
    
    printf("Reading array from file\n");
    stringArray = readCharArray("userTest.txt", stringArray);
    
    if(stringArray == NULL) printf("File Error\n");
    else{
        
        printf("File worked\n");
    
        printf("words read successfully :%d\n", stringArray->count);
        printf("total characters stored :%d\n", stringArray->size);
    
        for(int i = 0; i < stringArray->count - 1; i++){
        
            printf("%s\n", stringArray->array[i]);
        
        }
    
    }
    
}
