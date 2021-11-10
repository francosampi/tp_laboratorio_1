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

int employee_orderBy(void* employeeA, void* employeeB)
{
	Employee *empA = employeeA;
	Employee *empB = employeeB;

	return strcmp(empA->nombre, empB->nombre);
}
