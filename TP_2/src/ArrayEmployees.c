/*
 * funciones.c
 *
 *  Created on: 22 sep. 2021
 *      Author: franc
 */
#include "ArrayEmployees.h"
#include "functions.h"

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
	if (list!=NULL)
	{
		int i;
		for(i=0; i<len; i++)
		{
			list[i].isEmpty=1;
		}
		return 0;
	}
	return -1;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	if (list!=NULL)
	{
		printf("\nEmpleado a agregar:\n\n%-5s %-20s %-20s %-20s %-5s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
		printf("%-5d %-20s %-20s %-20.2f %-5d\n", id, name, lastName, salary, sector);
		printLine("");
		if(verify("Agregar empleado? ('s'): ")==0)
		{
			list[id].id=id;
			strcpy(list[id].name, name);
			strcpy(list[id].lastName, lastName);
			list[id].salary=salary;
			list[id].sector=sector;
			list[id].isEmpty=0;

			return 0;
		}
	}
	return -1;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len, int id)
{
	if (list!=NULL)
	{
		int i;
		for(i=0; i<len; i++)
		{
			if(list[i].id==id && list[i].isEmpty==0)
			{
				return i;
			}
		}
	}
	return -1;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
	int index = findEmployeeById(list, len, id);

	if (index!=-1)
	{
		printf("\nEmpleado a eliminar:\n\n%-5s %-20s %-20s %-20s %-5s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
		printEmployee(&list[index]);
		printLine("");
		if(verify("Eliminar empleado? ('s'): ")==0)
		{
			list[index].isEmpty=1;
			return 0;
		}
	}
	return -1;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
	Employee auxEmployee;
	int i;
	int newLimit;
	int flagSwap;

	if(list!=NULL && len>-1)
	{
		if(order==1)
		{
			newLimit=len-1;
			do{
				flagSwap=0;
				for(i=0; i<newLimit; i++)
				{
					if(strcmp(list[i].lastName, list[i+1].lastName)==1 || list[i].sector>list[i+1].sector)
					{
						auxEmployee = list[i];
						list[i] = list[i+1];
						list[i+1] = auxEmployee;
						flagSwap = 1;
					}
				}
				newLimit--;
			}while(flagSwap);
			printf("Lista ordenada por apellido de manera ascendente...\n");
		}
		else if(order==2)
		{
			newLimit=len-1;
			do{
				flagSwap=0;
				for(i=0; i<newLimit; i++)
				{
					if(strcmp(list[i].lastName, list[i+1].lastName)==-1 || list[i].sector<list[i+1].sector)
					{
						auxEmployee = list[i];
						list[i] = list[i+1];
						list[i+1] = auxEmployee;
						flagSwap = 1;
					}
				}
				newLimit--;
			}while(flagSwap);
			printf("Lista ordenada por apellido de manera descendente...\n");
		}
		return 0;
	}
	return -1;
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
void printEmployees(Employee* list, int len)
{
	if (list!=NULL)
	{
		printf("\n%-5s %-20s %-20s %-20s %-5s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
		int i;
		for(i=0; i<len; i++)
		{
			if (list[i].isEmpty==0)
			{
				printEmployee(&list[i]);
			}
		}
	}
}
