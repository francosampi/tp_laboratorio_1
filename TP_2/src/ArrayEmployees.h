/*
 * funciones.h
 *
 *  Created on: 22 sep. 2021
 *      Author: franc
 */
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPSIZE 1000
#define EMPNAME 51

typedef struct{
	int id;
	char name[EMPNAME];
	char lastName[EMPNAME];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int findEmployeeById(Employee* list, int len, int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
void printEmployees(Employee* list, int len);

#endif /* ARRAYEMPLOYEES_H_ */
