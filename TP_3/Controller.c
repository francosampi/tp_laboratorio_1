#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "inputs.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile = fopen(path, "r");

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		parser_EmployeeFromText(pFile, pArrayListEmployee);
		return 0;
	}
	return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile = fopen(path, "r");

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		return 0;
	}
	return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee!=NULL)
	{
		int auxId=ll_len(pArrayListEmployee);
		char auxIdParse[10];
		char auxNombre[128];
		int auxHorasTrabajadas;
		char auxHorasTrabajadasParse[10];
		int auxSueldo;
		char auxSueldoParse[10];

		sprintf(auxIdParse, "%d", auxId);

		getName(auxNombre, "Ingrese nombre de empleado: ",
			"El nombre es muy largo...\n",
			"El nombre no puede contener caracteres especiales...\n",
			"El nombre no puede estar en blanco...\n",
			128);

		auxHorasTrabajadas=getInt("Ingrese horas trabajadas: ", "Error. Ingrese horas trabajadas: ", 0, 99999);
		sprintf(auxHorasTrabajadasParse, "%d", auxHorasTrabajadas);

		auxSueldo=getInt("Ingrese sueldo: ", "Error. Ingrese sueldo: ", 20000, 999999);
		sprintf(auxSueldoParse, "%d", auxSueldo);

		printf("\nEmpleado a agregar:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
		printf("%-5s %-20s %-20s %-20s\n", auxIdParse, auxNombre, auxHorasTrabajadasParse, auxSueldoParse);
		printLine("");
		if(verify("Agregar empleado? ('s'): ")==0)
		{
			Employee* employee=employee_newParametros(auxIdParse, auxNombre, auxHorasTrabajadasParse, auxSueldoParse);
			ll_add(pArrayListEmployee, employee);
		}
		return 0;
	}
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee!=NULL)
	{
		Employee *empleadoAModificar=NULL;
		Employee *auxEmpleado=employee_new();

		int lltam=ll_len(pArrayListEmployee);
		int opcion=getInt("Ingrese ID del empleado a modificar: ", "Error. Ingrese ID del empleado a modificar: ", 0, lltam);

		//GET INDEX POR ID
		for(int i=0; i<lltam; i++)
		{
			empleadoAModificar=ll_get(pArrayListEmployee, i);
			if(empleadoAModificar->id==opcion)
			{
				auxEmpleado=empleadoAModificar;
				opcion=0;
				break;
			}
		}
		printf("\nEmpleado a modiifcar:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
		printf("%-5d %-20s %-20d %-20d\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);
		printLine("");

		//MODIFICAR
		do
		{
			printf("\nEmpleado a modificar:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
			printf("%-5d %-20s %-20d %-20d\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);
			printLine("");
			printf("1. Modificar nombre\n2. Modificar horas trabajadas\n3. Modificar sueldo\n4. Salir");
			printLine("");
			opcion=getInt("\nIngrese una opcion (1-4): ", "\nError. Ingrese una opcion (1-4): ", 1, 4);
			switch(opcion)
			{
				case 1:
					getName(auxEmpleado->nombre, "Ingrese nombre de empleado: ",
						"El nombre es muy largo...\n",
						"El nombre no puede contener caracteres especiales...\n",
						"El nombre no puede estar en blanco...\n",
						128);
					printf("\nEmpleado luego de la modificacion:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
					printf("%-5d %-20s %-20d %-20d\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);
					printLine("");
					if(verify("Confirmar cambios? ('s'): ")==0)
					{
						empleadoAModificar=auxEmpleado;
					}
				break;
				case 2:
					auxEmpleado->horasTrabajadas=getInt("Ingrese horas trabajadas: ", "Error. Ingrese horas trabajadas: ", 0, 99999);
					printf("\nEmpleado luego de la modificacion:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
					printf("%-5d %-20s %-20d %-20d\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);
					printLine("");
					if(verify("Confirmar cambios? ('s'): ")==0)
					{
						empleadoAModificar=auxEmpleado;
					}
				break;
				case 3:
					auxEmpleado->sueldo=getInt("Ingrese sueldo: ", "Error. Ingrese sueldo: ", 20000, 999999);
					printf("\nEmpleado luego de la modificacion:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
					printf("%-5d %-20s %-20d %-20d\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);
					printLine("");
					if(verify("Confirmar cambios? ('s'): ")==0)
					{
						empleadoAModificar=auxEmpleado;
					}
				break;
				case 4:
					printLine("");
					if(verify("Salir al menu principal? ('s'): ")==0)
					{
						printf("\nRegresando al menu principal...\n");
					}
					else
					{
						opcion=0;
					}
				break;
			}
		}while(opcion!=4);
		free(auxEmpleado);
		auxEmpleado=NULL;
		return 0;
	}
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

