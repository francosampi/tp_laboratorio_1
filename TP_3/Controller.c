#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "functions.h"
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
	FILE* pFile = fopen(path, "rb");

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
		Employee* employee=NULL;
		int auxId=ll_len(pArrayListEmployee);

		char auxIdParse[10];
		char auxNombre[128];
		int auxHorasTrabajadas;
		char auxHorasTrabajadasParse[10];
		int auxSueldo;
		char auxSueldoParse[10];

		sprintf(auxIdParse, "%d", auxId+1);

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
			employee=employee_newParametros(auxIdParse, auxNombre, auxHorasTrabajadasParse, auxSueldoParse);
			ll_add(pArrayListEmployee, employee);
			free(employee);
			employee=NULL;
			return 0;
		}
		free(employee);
		employee=NULL;
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
		int lltam=ll_len(pArrayListEmployee);
		int opcion=getInt("Ingrese ID del empleado a modificar: ", "Error. Ingrese ID del empleado a modificar: ", 0, lltam);

		Employee *empleadoAModificar=NULL;
		empleadoAModificar=employee_getById(pArrayListEmployee, lltam, opcion);

		Employee *auxEmpleado=NULL;
		auxEmpleado=employee_new();

		if(empleadoAModificar!=NULL && auxEmpleado!=NULL)
		{
			auxEmpleado=empleadoAModificar;

			printf("\nEmpleado a modiifcar:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
			printf("%-5d %-20s %-20d %-20d\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);
			printLine("");

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
			return 0;
		}
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
	if(pArrayListEmployee!=NULL)
	{
		Employee *empleadoABorrar=NULL;
		int lltam=ll_len(pArrayListEmployee);
		int opcion=getInt("Ingrese ID del empleado a remover: ", "Error. Ingrese ID del empleado a remover: ", 0, lltam);
		int index;

		empleadoABorrar=employee_getById(pArrayListEmployee, lltam, opcion);
		index=ll_indexOf(pArrayListEmployee, empleadoABorrar);

		if(empleadoABorrar!=NULL)
		{
			printf("\nEmpleado a remover:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
			printf("%-5d %-20s %-20d %-20d\n", empleadoABorrar->id, empleadoABorrar->nombre, empleadoABorrar->horasTrabajadas, empleadoABorrar->sueldo);
			printLine("");
			if(verify("Confirmar baja? ('s'): ")==0)
			{
				ll_remove(pArrayListEmployee, index);
				free(empleadoABorrar);
				empleadoABorrar=NULL;
				return 0;
			}
		}
		free(empleadoABorrar);
		empleadoABorrar=NULL;
	}
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
	if(pArrayListEmployee!=NULL)
	{
		Employee *empleado=NULL;
		int lltam=ll_len(pArrayListEmployee);

		printLine("LISTA DE EMPLEADOS");
		printf("\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
		printLine("");
		for(int i=0; i<lltam; i++)
		{
			empleado=ll_get(pArrayListEmployee, i);
			if(empleado!=NULL)
			{
				printf("%-5d %-20s %-20d %-20d\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
			}
		}
		printLine("");
		free(empleado);
		empleado=NULL;
		return 0;
	}
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
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		FILE* pFile = fopen(path, "w");

		Employee *empleado=NULL;
		int lltam=ll_len(pArrayListEmployee);

		fprintf(pFile, "%s\n", "id,nombre,horasTrabajadas,sueldo");
		for(int i=0; i<lltam; i++)
		{
			empleado=ll_get(pArrayListEmployee, i);
			if(empleado!=NULL)
			{
				fprintf(pFile, "%d,%s,%d,%d\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
			}
		}
		fclose(pFile);
		path=NULL;
		return 0;
	}
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
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		FILE* pFile = fopen(path, "wb");

		Employee *empleado=NULL;
		int lltam=ll_len(pArrayListEmployee);

		for(int i=0; i<lltam; i++)
		{
			empleado=ll_get(pArrayListEmployee, i);
			if(empleado!=NULL)
			{
				fwrite(empleado, sizeof(empleado), 1, pFile);
			}
		}
		fclose(pFile);
		path=NULL;
		return 0;
	}
    return 1;
}

