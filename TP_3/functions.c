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
