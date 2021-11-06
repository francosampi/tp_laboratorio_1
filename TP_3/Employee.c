#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new(){
	Employee* employee = NULL;
	employee = (Employee*)malloc(sizeof(Employee));
	return employee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* employee = NULL;
	employee = employee_new();
	if(employee!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{
		employee_setId(employee, atoi(idStr));
		employee_setNombre(employee, nombreStr);
		employee_setHorasTrabajadas(employee, atoi(horasTrabajadasStr));
		employee_setSueldo(employee, atoi(sueldoStr));
	}
	return employee;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

int employee_setId(Employee* this,int id)
{
	if(this!=NULL)
	{
		this->id=id;
		return 0;
	}
	return -1;
}

int employee_getId(Employee* this,int* id)
{
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		return 0;
	}
	return -1;
}

int employee_setNombre(Employee* this,char* nombre)
{
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre, nombre);
		return 0;
	}
	return -1;
}

int employee_getNombre(Employee* this,char* nombre)
{
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombre);
		return 0;
	}
	return -1;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	if(this!=NULL)
	{
		this->horasTrabajadas=horasTrabajadas;
		return 0;
	}
	return -1;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		return 0;
	}
	return -1;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	if(this!=NULL)
	{
		this->sueldo=sueldo;
		return 0;
	}
	return -1;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		return 0;
	}
	return -1;
}
