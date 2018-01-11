/**
 * @file stringArray.h
 * @author Nicholas
 * @date December 2017
 * @brief File containing the function definitions of a dynamic StringArray
 
 */

#ifndef _STRING_ARRAY_
#define _STRING_ARRAY_

#include <stdio.h>
#include <stdlib.h>

typedef struct stringArray{
    
    int size;
    int count;
    char** array;
    
} StringArray;

/**Function to create and allocate memory for a StringArray
 **/
StringArray *createStringArray();

/**Function to point the hash table to the appropriate functions.
 *@pre each word read as on a seperate line of the file
 *@param url is the url to the file you want to read
 
 **/
void readCharArray(char *url, StringArray* stringArray);

/**Function to add a word to the array
 *@pre each word read as on a seperate line of the file
 *@return array of strings read from file
 *@param url is the url to the file you want to read
 **/
void addString(StringArray* stringArray, char* stringToAdd);

/**Function to delete array
 *@return string with no extra memory
 *@param wordToShorten word with extra memory allocated
 **/
void deleteStringArray(StringArray* stringArray);

/**Exclusive strlen: Get length of string without including \n
 *@return string length
 *@param  stringToIndex, string to get length of
 **/
int strlenX(char *stringToIndex);

/**Function to return copy of string with smaller memory size
 *@return string with no extra memory
 *@param wordToShorten word with extra memory allocated
 **/
char *shortenWordLength(char* wordToShorten);

#endif

