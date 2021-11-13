#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * recibe el puntero al Archivo, se crean variables para los datos de los empleados que vendran al ser parseados.
 * Por cada lectura genera un empleado nuevo (se reserva memoria y se llenan los campos) para agregarlo a la linked list
 * Luego se cierra el archivo
 *
 * \param FILE* pFile el puntero al archivo
 * \param pArrayListEmployee LinkedList* el puntero a la linked list
 * \return int 0 (ok) o -1 (error)
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		char id[10];
		char nombre[21];
		char horasTrabajadas[10];
		char sueldo[10];

		Employee* pEmployee;

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);
			if(feof(pFile))
			{
				break;
			}
			pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
			ll_add(pArrayListEmployee, pEmployee);
		}
		if (pEmployee!=NULL)
		{
			free(pEmployee);
			pEmployee=NULL;
		}
		fclose(pFile);
		pFile=NULL;
		return 0;
	}
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo datab.csv (modo binario).
 * recibe el puntero al Archivo, y por cada lectura genera un empleado nuevo (se reserva memoria y se llenan los campos) para agregarlo a la linked list
 * Luego se cierra el archivo
 *
 * \param FILE* pFile el puntero al archivo
 * \param pArrayListEmployee LinkedList* el puntero a la linked list
 * \return int 0 (ok) o -1 (error)
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		Employee* pEmployee;

		while(!feof(pFile))
		{
			pEmployee=employee_new();
			fread(pEmployee, sizeof(Employee), 1, pFile);
			if(feof(pFile))
			{
				break;
			}
			ll_add(pArrayListEmployee, pEmployee);
		}
		if (pEmployee!=NULL)
		{
			free(pEmployee);
			pEmployee=NULL;
		}
		fclose(pFile);
		pFile=NULL;
		return 0;
	}
    return 1;
}
