#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "functions.h"
#include "inputs.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *  Se abre el archivo en el path pasado por parametro (si existe) y se pasean los datos
 *
 * \param path char* el path del archivo data texto
 * \param pArrayListEmployee LinkedList* el puntero a la linked list
 * \return int 0 (OK) o 1 (error)
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

/** \brief Carga los datos de los empleados desde el archivo datab.csv (modo binario).
 * Se abre el archivo en el path pasado por parametro (si existe) y se pasean los datos
 *
 * \param path char* el path del archivo data binario
 * \param pArrayListEmployee LinkedList* el puntero a la linked list
 * \return int 0 (OK) o 1 (error)
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

/**
 * @brief Alta de empleados (decidi cambiar la firma de esta funcion para que tome el ultimo id y poder asignarlo incrementado)
 * se declaran variables por cada tipo de campo del empleado, luego su version parseada a char usando sprintf
 * se agrega un elemento a la linked list con estos campos
 *
 * @param pArrayListEmployee el puntero a la linked list
 * @param ultimoId ultimo ID ingresado por el usuario como puntero para incrementarlo
 * @return int 0 (OK) o 1 (error)
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* ultimoId)
{
	if(pArrayListEmployee!=NULL)
	{
		Employee* employee=NULL;

		int auxId=*ultimoId+1;
		char auxIdParse[10];
		char auxNombre[128];
		int auxHorasTrabajadas;
		char auxHorasTrabajadasParse[10];
		int auxSueldo;
		char auxSueldoParse[10];

		printLine("NUEVO EMPLEADO");

		sprintf(auxIdParse, "%d", auxId);

		getName(auxNombre, "Ingrese nombre de empleado: ",
			"El nombre es muy largo...\n",
			"El nombre no puede contener caracteres especiales...\n",
			"El nombre no puede estar en blanco...\n",
			128);

		auxHorasTrabajadas=getInt("Ingrese horas trabajadas: ", "Error. Ingrese horas trabajadas: ", 0, 9999);
		sprintf(auxHorasTrabajadasParse, "%d", auxHorasTrabajadas);

		auxSueldo=getInt("Ingrese sueldo: ", "Error. Ingrese sueldo: ", 1000, 9999999);
		sprintf(auxSueldoParse, "%d", auxSueldo);

		printf("\nEmpleado a agregar:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
		printf("%-5s %-20s %-20s %-20s\n", auxIdParse, auxNombre, auxHorasTrabajadasParse, auxSueldoParse);
		printLine("");
		if(verify("Agregar empleado? ('s'): ")==0)
		{
			employee=employee_newParametros(auxIdParse, auxNombre, auxHorasTrabajadasParse, auxSueldoParse);
			ll_add(pArrayListEmployee, employee);
			*ultimoId+=1;

			if(employee!=NULL)
			{
				free(employee);
				employee=NULL;
			}
			return 0;
		}
		if(employee!=NULL)
		{
			free(employee);
			employee=NULL;
		}
	}
    return 1;
}

/** \brief (cambie la firma para que tambien reciba el ultimo id para poder modificarlo)
 * creamos un puntero a empleado nuevo y reservamos en memoria. Este sera un auxiliar para ir comparando los datos del empleado que queremos modificar y este.
 * se listan todos los empleados y el usuario podra modificar cualquiera (del 0 al ultimo id ingresado) hace un get de todos los datos del empleado a modificar para rellenar los campos del auxiliar
 * por cada campo que se quiera modificar el menu se encarga de preguntar si guardar los cambios o no. Luego de todo el proceso de modificacion se libera el espacio reservado para el auxiliar
 *
 * \param ultimoId ultimo ID ingresado por el usuario
 * \param pArrayListEmployee LinkedList* el puntero a la linked list
 * \return int 0 (OK) o 1 (error)
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee, int ultimoId)
{
	if(pArrayListEmployee!=NULL)
	{
		int opcion=getInt("Ingrese ID del empleado a modificar: ", "Error. Ingrese ID del empleado a modificar: ", 0, ultimoId);

		Employee *empleadoAModificar=NULL;
		empleadoAModificar=employee_getById(pArrayListEmployee, opcion);

		Employee *auxEmpleado=NULL;
		auxEmpleado=employee_new();

		if(empleadoAModificar!=NULL && auxEmpleado!=NULL)
		{
			auxEmpleado=empleadoAModificar;

			char auxEmpleadoNombre[128];
			int auxEmpleadoId, auxEmpleadoHoras, auxEmpleadoSueldo;

			employee_getId(auxEmpleado, &auxEmpleadoId);
			employee_getNombre(auxEmpleado, auxEmpleadoNombre);
			employee_getHorasTrabajadas(auxEmpleado, &auxEmpleadoHoras);
			employee_getSueldo(auxEmpleado, &auxEmpleadoSueldo);

			printf("\nEmpleado a modificar:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
			employee_listOne(auxEmpleado);
			printLine("");

			do
			{
				printf("\nEmpleado a modificar:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
				employee_listOne(auxEmpleado);
				printLine("");
				printf("1. Modificar nombre\n2. Modificar horas trabajadas\n3. Modificar sueldo\n4. Salir");
				printLine("");
				opcion=getInt("\nIngrese una opcion (1-4): ", "\nError. Ingrese una opcion (1-4): ", 1, 4);
				switch(opcion)
				{
					case 1:
						getName(auxEmpleadoNombre, "Ingrese nombre de empleado: ",
							"El nombre es muy largo...\n",
							"El nombre no puede contener caracteres especiales...\n",
							"El nombre no puede estar en blanco...\n",
							128);
						printf("\nEmpleado luego de la modificacion:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
						printf("%-5d %-20s %-20d %-20d\n", auxEmpleadoId, auxEmpleadoNombre, auxEmpleadoHoras, auxEmpleadoSueldo);
						printLine("");

						if(verify("Confirmar cambios? ('s'): ")==0)
						{
							employee_setNombre(auxEmpleado, auxEmpleadoNombre);
							empleadoAModificar=auxEmpleado;
						}
					break;
					case 2:
						auxEmpleadoHoras=getInt("Ingrese horas trabajadas: ", "Error. Ingrese horas trabajadas: ", 0, 9999);
						printf("\nEmpleado luego de la modificacion:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
						printf("%-5d %-20s %-20d %-20d\n", auxEmpleadoId, auxEmpleadoNombre, auxEmpleadoHoras, auxEmpleadoSueldo);
						printLine("");
						if(verify("Confirmar cambios? ('s'): ")==0)
						{
							employee_setHorasTrabajadas(auxEmpleado, auxEmpleadoHoras);
							empleadoAModificar=auxEmpleado;
						}
					break;
					case 3:
						auxEmpleadoSueldo=getInt("Ingrese sueldo: ", "Error. Ingrese sueldo: ", 1000, 9999999);
						printf("\nEmpleado luego de la modificacion:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
						printf("%-5d %-20s %-20d %-20d\n", auxEmpleadoId, auxEmpleadoNombre, auxEmpleadoHoras, auxEmpleadoSueldo);
						printLine("");
						if(verify("Confirmar cambios? ('s'): ")==0)
						{
							employee_setSueldo(auxEmpleado, auxEmpleadoSueldo);
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

			if(auxEmpleado!=NULL)
			{
				free(auxEmpleado);
				auxEmpleado=NULL;
			}
			return 0;
		}
	}
    return 1;
}

/** \brief Baja de empleado (cambie la firma para que tambien reciba el ultimo id para poder removerlo)
 * creamos un puntero a empleado, el usuario accede a la lista de empleados e ingresara un id (del 0 al ultimo id ingresado) si lo encuentra, se listara y apuntara a ese empleado
 * liberamos la memoria de ese empleado y lo removemos de la linked list si el usuario guarda los cambios
 *
 * \param ultimoId ultimo id ingresado por el usuario
 * \param pArrayListEmployee LinkedList*
 * \return int 0 (OK) o 1 (error)
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee, int ultimoId)
{
	if(pArrayListEmployee!=NULL)
	{
		Employee *empleadoABorrar=NULL;

		int opcion=getInt("Ingrese ID del empleado a remover: ", "Error. Ingrese ID del empleado a remover: ", 0, ultimoId);
		int index;

		empleadoABorrar=employee_getById(pArrayListEmployee, opcion);
		index=ll_indexOf(pArrayListEmployee, empleadoABorrar);

		if(empleadoABorrar!=NULL)
		{
			printf("\nEmpleado a remover:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
			employee_listOne(empleadoABorrar);
			printLine("");
			if(verify("Confirmar baja? ('s'): ")==0)
			{
				ll_remove(pArrayListEmployee, index);
				return 0;
			}
		}
	}
    return 1;
}

/** \brief toma el puntero a la linked list y la utilizara para el tamaño, tomara el index desde 0 al tamaño para mostrar en consola todos los empleados de la lista.
 * Para eso creara un auxiliar de puntero a empleado, tomara uno por uno para luego hacer un free (liberar la memoria) al terminar
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 0 (OK) o 1 (error)
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
			empleado=(Employee*) ll_get(pArrayListEmployee, i);
			employee_listOne(empleado);
		}
		printLine("");

		if(empleado!=NULL)
		{
			free(empleado);
			empleado=NULL;
		}
		return 0;
	}
    return 1;
}

/** \brief declara un puntero a la funcion de criterio para su ordenamiento. Crea un menu para que el usuario decida ordenar por ID, nombre, sueldo, cualquiera de los campos
 * de manera ascendente o descendente.
 *
 * \param pArrayListEmployee LinkedList* puntero a la linked list
 * \return int 0 (OK) o 1 (error)
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee!=NULL)
	{
		int option;
		int (*compareFunction)(void*, void*) = NULL;

		do{
			printLine("ORDENAR EMPLEADOS");
			printf("1. Por Legajo (ascendente)\n2. Por Legajo (descendente)\n3. Por nombre (ascendente)\n4. Por nombre (descendente)\n5. Por sueldo (ascendente)\n6. Por sueldo (descendente)\n7. Atras");
			printLine("");
			option=getInt("\nIngrese una opcion (1-7): ", "Error. Ingrese una opcion valida (1-7): ", 1, 7);

			switch(option)
			{
				case 1:
					compareFunction=employee_orderById;
					printLine("");
					printf("\nEspere un momento mientras se realiza el ordenamiento...\n...\n");
					if(ll_sort(pArrayListEmployee, compareFunction, 1)==0)
					{
						printf("\nLa lista fue ordenada de manera exitosa...\n");
					}
					else
					{
						printf("\nError. La lista no pudo ser ordenada...\n");
					}
					break;
				case 2:
					compareFunction=employee_orderById;
					printLine("");
					printf("\nEspere un momento mientras se realiza el ordenamiento...\n...\n");
					if(ll_sort(pArrayListEmployee, compareFunction, 0)==0)
					{
						printf("\nLa lista fue ordenada de manera exitosa...\n");
					}
					else
					{
						printf("\nError. La lista no pudo ser ordenada...\n");
					}
					break;
				case 3:
					compareFunction=employee_orderByName;
					printLine("");
					printf("\nEspere un momento mientras se realiza el ordenamiento...\n...\n");
					if(ll_sort(pArrayListEmployee, compareFunction, 1)==0)
					{
						printf("\nLa lista fue ordenada de manera exitosa...\n");
					}
					else
					{
						printf("\nError. La lista no pudo ser ordenada...\n");
					}
					break;
				case 4:
					compareFunction=employee_orderByName;
					printLine("");
					printf("\nEspere un momento mientras se realiza el ordenamiento...\n...\n");
					if(ll_sort(pArrayListEmployee, compareFunction, 0)==0)
					{
						printf("\nLa lista fue ordenada de manera exitosa...\n");
					}
					else
					{
						printf("\nError. La lista no pudo ser ordenada...\n");
					}
					break;
				case 5:
					compareFunction=employee_orderBySalary;
					printLine("");
					printf("\nEspere un momento mientras se realiza el ordenamiento...\n...\n");
					if(ll_sort(pArrayListEmployee, compareFunction, 1)==0)
					{
						printf("\nLa lista fue ordenada de manera exitosa...\n");
					}
					else
					{
						printf("\nError. La lista no pudo ser ordenada...\n");
					}
					break;
				case 6:
					compareFunction=employee_orderBySalary;
					printLine("");
					printf("\nEspere un momento mientras se realiza el ordenamiento...\n...\n");
					if(ll_sort(pArrayListEmployee, compareFunction, 0)==0)
					{
						printf("\nLa lista fue ordenada de manera exitosa...\n");
					}
					else
					{
						printf("\nError. La lista no pudo ser ordenada...\n");
					}
					break;
				case 7:
					if(verify("\nDesea salir al menu principal? ('s'): ")==0)
					{
						printf("\nVolviendo al menu principal...\n");
						return 0;
					}
					else
					{
						option=0;
					}
					break;
			}
		}while(option!=7);
	}
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * se abre el archivo con el path pasado por parametro (si existe) y declaramos un puntero a empleado
 * se toma el tamaño de la lista y por cada elemento leido en el archivo (menos el encabezado) se guardan los campos de los empleados cargados en la aplicacion (usando getters)
 *
 * \param path char* el path al archivo de data texto
 * \param pArrayListEmployee LinkedList* el puntero a la linked list
 * \return int 0 (OK) o 1 (error)
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		FILE* pFile = fopen(path, "w");
		Employee *empleado=NULL;

		char auxNombre[128];
		int auxId, auxHoras, auxSueldo;

		int lltam=ll_len(pArrayListEmployee);

		fprintf(pFile, "%s\n", "id,nombre,horasTrabajadas,sueldo");
		for(int i=0; i<lltam; i++)
		{
			empleado=(Employee*) ll_get(pArrayListEmployee, i);

			employee_getId(empleado, &auxId);
			employee_getNombre(empleado, auxNombre);
			employee_getHorasTrabajadas(empleado, &auxHoras);
			employee_getSueldo(empleado, &auxSueldo);

			fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxNombre, auxHoras, auxSueldo);
		}
		if (empleado!=NULL)
		{
			free(empleado);
			empleado=NULL;
		}
		fclose(pFile);
		pFile=NULL;
		return 0;
	}
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 * se abre el archivo con el path pasado por parametro (si existe) y declaramos un puntero a empleado
 * se toma el tamaño de la lista y por cada elemento leido en el archivo se guardan los campos de los empleados cargados en la aplicacion (usando getters)
 *
 * \param path char* el path al archivo de data binario
 * \param pArrayListEmployee LinkedList* el puntero a la linked list
 * \return int 0 (OK) o 1 (error)
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
			empleado=(Employee*) ll_get(pArrayListEmployee, i);
			fwrite(empleado, sizeof(Employee), 1, pFile);
		}
		if (empleado!=NULL)
		{
			free(empleado);
			empleado=NULL;
		}
		fclose(pFile);
		pFile=NULL;
		return 0;
	}
    return 1;
}

