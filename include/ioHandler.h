/**
 * @file  ioHandler.h
 * @author Nicholas Florian
 * @date November 2017
 * @brief File containing the function definitions of the ioHandler
 */

#ifndef _IO_HANDLER_
#define _IO_HANDLER_

/**Function to read back an array of string from a file
 *@return string array (char**)
 *@param string that stores location of a file
 *@param the amount of strigns in the array
 *@param the total chars in the array now
 **/
char **readCharArray(char *url, int * length, int *size);

/**Function to add a string to an array of string
 *@return string array (char**)
 *@param string to modify
 *@param string that stores location of a file
 *@param the amount of strigns in the array
 *@param the total chars in the array now
 **/
char **increaseWords(char **fromRead, int *length, char *word, int *size);

/**Function to read back an array of string from a file
 *@return string array (char**)
 *@param string that stores location of a file
 *@param the amount of strigns in the array
 *@param the total chars in the array now
 **/
char *shortenWordLength(char *wordToShorten);

/**Function to read user input
 *@return user input int
 **/
int softenIntInput();

/**Function to read user input
 *@return user input string
 **/
char* softenStringInput();

#endif
