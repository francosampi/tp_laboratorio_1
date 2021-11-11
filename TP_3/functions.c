#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

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

int employee_orderById(void* employeeA, void* employeeB)
{
	if(employeeA!=NULL && employeeB!=NULL)
	{
		Employee *empA = (Employee*) employeeA;
		Employee *empB = (Employee*) employeeB;

		if(empA->id>empB->id)
		{
			return 1;
		}
		else
		{
			if (empB->id>empA->id)
			{
				return -1;
			}
		}
	}
	return -2;
}

int employee_orderByName(void* employeeA, void* employeeB)
{
	if(employeeA!=NULL && employeeB!=NULL)
	{
		Employee *empA = (Employee*) employeeA;
		Employee *empB = (Employee*) employeeB;

		return strcmp(empA->nombre, empB->nombre);
	}
	return -2;
}

int employee_orderBySalary(void* employeeA, void* employeeB)
{
	if(employeeA!=NULL && employeeB!=NULL)
	{
		Employee *empA = (Employee*) employeeA;
		Employee *empB = (Employee*) employeeB;

		if(empA->sueldo>empB->sueldo)
		{
			return 1;
		}
		else
		{
			if (empB->sueldo>empA->sueldo)
			{
				return -1;
			}
		}
	}
	return -2;
}

