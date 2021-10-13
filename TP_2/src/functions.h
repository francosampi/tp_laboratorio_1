/*
 * functions.h
 *
 *  Created on: 30 sep. 2021
 *      Author: franc
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void printLine(char *_msg);

void inputEmployeeData(char *nameProv, char *lastNameProv, float *salary, int *sector, int strLen);
int searchAvaliableSpace(Employee *list, int len);
void printEmployeeDataMenu(Employee* Employees, int len, int *employeesCounter);
int modifyEmployee(Employee *list, int len);
void printEmployee(Employee *emp);
int salaryEmployees(Employee *list, int len, float *totalSalary, float *avgSalary, int employeeCounter);
int printHighPaidEmployees(Employee *list, int len, float *avgSalary);

//VALIDATE STRING
int getString(char *_str, char *_msg, char *_errMsg, int _strMaxLen);
int isLetter(char *_str, char *_errMsg);
int isNotBlank(char *_str, char *_errMsg);
int getName(char *_str, char *_msg, char *_errMsgOnLen, char *_errMsgNotLetter, char *_errMsgIsBlank, int _strMaxLen);

//VALIDATE NUMBER/VERIFY
int getInt(char *_msg, char *_errMsg, int _min, int _max);
float getFloat(char *_msg, char *_errMsg, int _min, int _max);
int getCharacter(char *_character, char *_msg);
int verify(char *_msg);

#endif /* FUNCTIONS_H_ */
