#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		char id[10];
		char nombre[21];
		char horasTrabajadas[10];
		char sueldo[10];

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);
			if(feof(pFile))
			{
				break;
			}
			Employee* employee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
			ll_add(pArrayListEmployee, employee);
		}
		fclose(pFile);
		pFile=NULL;

		if(controller_ListEmployee(pArrayListEmployee)==1)
		{
			printf("\nError al cargar la lista...");
		}
		return 0;
	}
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		while(!feof(pFile))
		{
			Employee *pEmployee=employee_new();
			fread(pEmployee, sizeof(Employee), 1, pFile);
			if(feof(pFile))
			{
				break;
			}
		}
		fclose(pFile);
		pFile=NULL;
		return 0;
	}
    return 1;
}
