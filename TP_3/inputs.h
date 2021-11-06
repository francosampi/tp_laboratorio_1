/*
 * inputs.h
 *
 *  Created on: 7 oct. 2021
 *      Author: franc
 */

#ifndef INPUTS_H_
#define INPUTS_H_

//VALIDATE STRING

/**
 * @fn int getString(char*, char*, char*, int)
 * @brief
 *
 * @param _str pointer to string
 * @param _msg the message that will show up
 * @param _errMsg the message that will show up if the string is too long
 * @param _strMaxLen length that the string cant surpass
 * @return (-1) if error (character variable is null or if string too long) - (0) if ok
 */
int getString(char *_str, char *_msg, char *_errMsg, int _strMaxLen);

/**
 * @fn int isLetter(char*, char*)
 * @brief this validates if a string has only letters as characters
 *
 * @param _str pointer to string
 * @param _errMsg the message that will show up if the string has special characters
 * @return (-1) if error (character variable is null or if there is a special character on string) - (0) if ok
 */
int isLetter(char *_str, char *_errMsg);

/**
 * @fn int isNotBlank(char*, char*)
 * @brief this validates if a string has characters and is not blank
 *
 * @param _str pointer to string
 * @param _errMsg the message that will show up if the string is empty
 * @return (-1) if error (character variable is null or string is empty) - (0) if ok
 */
int isNotBlank(char *_str, char *_errMsg);

/**
 * @fn int getName(char*, char*, char*, char*, char*, int)
 * @brief this will get a string and validates if it has correct length, is not empty and it has only letters
 *
 * @param _str pointer to string
 * @param _msg the message that will show up
 * @param _errMsgOnLen the message that will show up if there was an error with the length
 * @param _errMsgNotLetter the message that will show up if there was an error with the characters
 * @param _errMsgIsBlank the message that will show up if there was an empty string
 * @param _strMaxLen the maximum length of the string
 * @return (-1) if error (character variable is null or something is wrongly validated) - (0) if ok
 */
int getName(char *_str, char *_msg, char *_errMsgOnLen, char *_errMsgNotLetter, char *_errMsgIsBlank, int _strMaxLen);

//VALIDATE NUMBERS/CONFIRM
/**
 * @fn int getInt(char*, char*, int, int)
 * @brief this ask the user to enter an int number and validates it
 *
 * @param _msg the message that will show up
 * @param _errMsg the message that will show up if there was an error with the input (< min or > max)
 * @param _min the minimum possible number
 * @param _max the maximum possible number
 * @return returns the int number entered
 */
int getInt(char *_msg, char *_errMsg, int _min, int _max);

/**
 * @fn float getFloat(char*, char*, int, int)
 * @brief this ask the user to enter a float number and validates it
 *
 * @param _msg the message that will show up
 * @param _errMsg the message that will show up if there was an error with the input
 * @param _min the minimum possible number
 * @param _max the maximum possible number
 * @return returns the float number entered
 */
long int getlong(char *_msg, char *_errMsg, long int _min, long int _max);

float getFloat(char *_msg, char *_errMsg, int _min, int _max);

double getDouble(char *_msg, char *_errMsg, double _min, double _max);

/**
 * @fn int getCharacter(char*, char*)
 * @brief this asks the user to enter a char and validates it
 *
 * @param _character where the char will be stored
 * @param _msg the message that will show up
 * @return (-1) if error (character variable is null or message not found) - (0) if ok
 */
int getCharacter(char *_char, char *_msg);

/**
 * @fn int verify(char*)
 * @brief this asks the user to enter a char and validates if its an 's' or an 'S'
 *
 * @param _msg the message that will show up
 * @return (-1) if error (character is not an 's' or an 'S') - (0) if ok
 */
int verify(char *_msg);

//HUD
/**
 * @fn void printLine(char*)
 * @brief This shows a separator with a message (or not)
 *
 * @param _msg the message that will be in the middle of the separator
 */
void printLine(char *_msg);

#endif /* INPUTS_H_ */
