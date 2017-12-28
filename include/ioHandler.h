/**
 * @file  ioHandler.h
 * @author Nicholas Florian
 * @date November 2017
 * @brief File containing the function definitions of the ioHandler
 */

#ifndef _IO_HANDLER_
#define _IO_HANDLER_

/**read user input
 *@return user input int
 **/
int softenIntInput();

/**check if string can be a letter
 *@pre meant for selecting options from 0 and up
 *@return the int it becomes, or -1 if not
 *@param in is the string the user wants to check
 **/
int softenInt(char *in);

/**Function to read user input
 *@return user input string
 **/
char* softenStringInput();

#endif
