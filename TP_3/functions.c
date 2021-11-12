#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

/**
 * @fn Employee employee_getById*(LinkedList*, int, int)
 * @brief Esta funcion accede al linked list, y con su tamaño, recorrerlo y retornar un puntero al index encontrado a traves de un ID
 *
 * @param pArrayListEmployee
 * @param tam
 * @param id
 * @return empleado (ok) o NULL (error)
 */
Employee* employee_getById(LinkedList* pArrayListEmployee, int tam, int id)
{
	if(pArrayListEmployee!=NULL)
	{
		Employee *empleado=NULL;
		for(int i=0; i<tam; i++)
		{
			empleado=ll_get(pArrayListEmployee, i);
			if(empleado->id==id)
			{
				return empleado;
			}
		}
	}
	return NULL;
}

/**
 * @fn int employee_orderById(void*, void*)
 * @brief Toma dos punteros a void, los castea a puntero a Empleado y los compara por id
 *
 * @param employeeA
 * @param employeeB
 * @return 1 (ID de A > ID de B), -1 (ID de B > ID de A), -2 (iguales o error)
 */
int employee_orderById(void* employeeA, void* employeeB)
{
	if(employeeA!=NULL && employeeB!=NULL)
	{
		int auxIdA, auxIdB;

		Employee *empA = (Employee*) employeeA;
		Employee *empB = (Employee*) employeeB;

		employee_getSueldo(empA, &auxIdA);
		employee_getSueldo(empB, &auxIdB);

		if(auxIdA>auxIdB)
		{
			return 1;
		}
		else
		{
			if (auxIdB>auxIdA)
			{
				return -1;
			}
		}
	}
	return -2;
}

/**
 * @fn int employee_orderByName(void*, void*)
 * @brief Toma dos punteros a void, los castea a puntero a Empleado y los compara por nombre
 *
 * @param employeeA
 * @param employeeB
 * @return retorno del strcmp, >0 (nombre de A > nombre de B), <0 (nombre de B > nombre de A), 0 (iguales), -2 (error)
 */
int employee_orderByName(void* employeeA, void* employeeB)
{
	if(employeeA!=NULL && employeeB!=NULL)
	{
		char auxNombreA[128], auxNombreB[128];

		Employee *empA = (Employee*) employeeA;
		Employee *empB = (Employee*) employeeB;

		employee_getNombre(empA, auxNombreA);
		employee_getNombre(empB, auxNombreB);

		return strcmp(auxNombreA, auxNombreB);
	}
	return -2;
}

/**
 * @fn int employee_orderBySalary(void*, void*)
 * @brief Toma dos punteros a void, los castea a puntero a Empleado y los compara por sueldo
 *
 * @param employeeA
 * @param employeeB
 * @return 1 (sueldo de A > sueldo de B), -1 (sueldo de B > sueldo de A), -2 (iguales o error)
 */
int employee_orderBySalary(void* employeeA, void* employeeB)
{
	if(employeeA!=NULL && employeeB!=NULL)
	{
		int auxSueldoA, auxSueldoB;

		Employee *empA = (Employee*) employeeA;
		Employee *empB = (Employee*) employeeB;

		employee_getSueldo(empA, &auxSueldoA);
		employee_getSueldo(empB, &auxSueldoB);

		if(auxSueldoA>auxSueldoB)
		{
			return 1;
		}
		else
		{
			if (auxSueldoB>auxSueldoA)
			{
				return -1;
			}
		}
	}
	return -2;
}

/**
 * @fn void employee_listOne(Employee*)
 * @brief muestra un empleado recibiendo su puntero
 *
 * @param employee
 */
void employee_listOne(Employee* employee)
{
	int auxId, auxHoras, auxSueldo;
	char auxNombre[128];

	employee_getId(employee, &auxId);
	employee_getNombre(employee, auxNombre);
	employee_getHorasTrabajadas(employee, &auxHoras);
	employee_getSueldo(employee, &auxSueldo);

	printf("%-5d %-20s %-20d %-20d\n", auxId, auxNombre, auxHoras, auxSueldo);
}

