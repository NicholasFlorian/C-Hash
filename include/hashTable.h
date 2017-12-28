/**
 * @file HashTable.h
 * @author Michael Ellis
 * @edited by Nicholas Florian
 * @date February 2017
 * @brief File containing the function definitions of a hash table
 
 * SEVERLY EDITED BY NICHOLAS FLORIAN
 */

#ifndef _HASH_API_
#define _HASH_API_

#include <stdio.h>
#include <stdlib.h>

/**
 *Node of the hash table.
 **/
typedef struct node{
    
    int key; ///< integer that represents a piece of data in the table (eg 35->"hello")
    void *data; ///< pointer to generic data that is to be stored in the hash table
    struct node *next; ///< pointer to the next Node if a collision is detected
    
} Node;

/**
 *Hash table structure
 **/
typedef struct hTable{
    size_t size; ///< number that represents the size of the hash table
    Node **table; ///< array that contains all of the table nodes
    void (*destroyData)(void *data); ///< function pointer to a function to delete a single piece of data from the hash table
    int (*hashFunction)(size_t tableSize, int key); ///< function pointer to a function to hash the data
    void (*printNode)(void *toBePrinted); ///< function pointer to a function that prints out a data element of the table
    void (*add) (struct hTable *hashTableToAdd, void *data); ///< function pointer for users to add a data element to the map.
} HTable;


/**Function to point the hash table to the appropriate functions. Allocates memory to the struct and table based on the size given.
 *@return pointer to the hash table
 *@param size size of the hash table
 *@param hashFunction function pointer to a function to hash the data
 *@param destroyData function pointer to a function to delete a single piece of data from the hash table
 *@param printNode function pointer to a function that prints out a data element of the table
 **/
HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, int key),void (*destroyData)(void *data),void (*printNode)(void *toBePrinted));

/**Function for creating a node for the hash table.
 *@pre Node must be cast to void pointer before being added.
 *@post Node is valid and able to be added to the hash table
 *@param key integer that represents the data (eg 35->"hello")
 *@param data is a generic pointer to any data type.
 *@return returns a node for the hash table
 **/
Node *createNode(int key, void *data);

/** Deletes the entire hash table and frees memory of every element.
 *@pre Hash Table must exist.
 *@param hashTable pointer to hash table containing elements of data
 **/
void destroyTable(HTable *hashTable);

/**Wrapper of insertData
 *@pre Hash table must exist and have memory allocated to it
 *@param hashTable pointer to the hash table struct
 *@param exact value the user wants to store
 **/
void insertDataWord(HTable *hashTable, void *data);

/**Inserts a Node in the hash table.
 *@pre hashTable type must exist and have data allocated to it
 *@param hashTable pointer to the hash table
 *@param key integer that represents the data (eg 35->"hello")
 *@param data pointer to generic data that is to be inserted into the list
 **/
void insertData(HTable *hashTable, int key, void *data);

/**Turns a string into a key for hash division
 *@pre should be wraped
 *@param word to convert to number
 **/
int keyGenerator(char *word);

/**Wrapper of removoeData
 *@pre Hash table must exist and have memory allocated to it
 *@post Node at key will be removed from the hash table if it exists.
 *@param hashTable pointer to the hash table struct
 *@param exact value the user wants to remove
 **/
void removeDataWord(HTable *hashTable, char* key);

/**Function to remove a node from the hash table
 *@pre Hash table must exist and have memory allocated to it
 *@post Node at key will be removed from the hash table if it exists.
 *@param hashTable pointer to the hash table struct
 *@param key integer that represents a piece of data in the table (eg 35->"hello")
 **/
void removeData(HTable *hashTable, int key, char* data);

/**Wrapper of lookupData
 *@pre Hash table must exist and have memory allocated to it
 *@param hashTable pointer to the hash table struct
 *@param exact value the user wants to find
 **/
char *lookupDataWord(HTable *hashTable, char *key);

/**Function to return the data from the key given.
 *@pre The hash table exists and has memory allocated to it
 *@param hashTable pointer to the hash table containing data nodes
 *@param key integer that represents a piece of data in the table (eg 35->"hello")
 *@return returns a pointer to the data in the hash table. Returns NULL if no match is found.
 **/
void *lookupData(HTable *hashTable, int key, void *data);

/**Function to hash based on division
 *@pre The hash table exists and has memory allocated to it
 *@param size of the hash table
 *@param the key the user wants to hash for index
 *@return returns a index generated based on hash division
 **/
int hashNode(size_t tableSize, int key);

/**Function to destroy node
 *@pre The hash table exists and has memory allocated to it
 *@post the node data is flagged to "#"
 *@param data you want to delete
 **/
void destroyNodeData(void *data);

/**Function to print data
 *@param data you want to print
 **/
void printNodeData(void *toBePrinted);

void betterPrintNodeData(HTable *hashTable, void *toBePrinted);

#endif
