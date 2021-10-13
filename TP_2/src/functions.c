/*
 * functions.c
 *
 *  Created on: 30 sep. 2021
 *      Author: franc
 */
#include "ArrayEmployees.h"
#include "functions.h"
#include <ctype.h>

/**
 * @fn void menu()
 * @brief displays the main menu and creates the main array of employees.
 * it contains the employee counter, the last id position used and the variables which contains the data of a new employee (in case the user wants to add a new one)
 * This is where the user will access to the main options of the program
 *
 */
void menu()
{
	Employee Employees[EMPSIZE];
	initEmployees(Employees, EMPSIZE);

	int employeesCounter=0;
	int lastIdEntered=0;
	int option;

	do{
		printLine("MENU");
		printf("1. ALTAS\n2. MODIFICAR\n3. BAJA\n4. INFORMAR\n5. SALIR");
		printLine("");
		option=getInt("Ingrese una opcion (1-5): ", "Error. Ingrese una opcion valida (1-5): ", 1, 5);

		int index;
		int id=lastIdEntered;
		char nameProv[EMPNAME];
		char lastNameProv[EMPNAME];
		float salaryProv;
		int sectorProv;

		switch(option)
		{
			case 1:
				printLine("CARGAR EMPLEADO");
				index=searchAvaliableSpace(Employees, EMPSIZE);

				if (index!=-1)
				{
					inputEmployeeData(nameProv, lastNameProv, &salaryProv, &sectorProv, EMPNAME);

					if(addEmployee(Employees, EMPSIZE, id, nameProv, lastNameProv, salaryProv, sectorProv)==0)
					{
						printf("\nEmpleado agregado con exito...");
						employeesCounter++;
						id++;
						lastIdEntered=id;
					}
					else
					{
						printf("\nNo se pudo cargar el empleado");
					}
				}
				else
				{
					printf("\nEspacio lleno. No se pudo cargar el empleado");
				}
			break;
			case 2:
				if (employeesCounter>0)
				{
					printLine("MODIFICAR EMPLEADO");
					if(modifyEmployee(Employees, EMPSIZE)==-1)
					{
						printf("\nEl empleado no fue encontrado bajo esa ID");
					}
				}
				else
				{
					printf("\nNo hay empleados para modificar...");
				}
			break;
			case 3:
				if (employeesCounter>0)
				{
					int idProv;

					printLine("REMOVER EMPLEADO");
					idProv=getInt("Ingrese ID del empleado a eliminar: ", "Error. Ingrese un ID valido: ", 0, EMPSIZE);
					if(removeEmployee(Employees, EMPSIZE, idProv)==0)
					{
						employeesCounter--;
						printf("\nEmpleado eliminado con exito...");
					}
					else
					{
						printf("\nEl empleado no fue encontrado bajo esa ID");
					}
				}
				else
				{
					printf("\nNo hay empleados para remover...");
				}
			break;
			case 4:
				if (employeesCounter>0)
				{
					printEmployeeDataMenu(Employees, EMPSIZE, &employeesCounter);
				}
				else
				{
					printf("\nNo hay empleados para mostrar...");
				}
			break;
			case 5:
				printLine("");
				if(verify("Desea salir del programa? ('s'): ")==0)
				{
					printf("\nNos vemos! vuelva pronto...");
				}
				else
				{
					option=0;
				}
			break;
		}
	}while(option!=5);
}

/**
 * @fn void printEmployeeDataMenu(Employee*, int, int*)
 * @brief If the user wants to see the employees, this menu displays.
 * You can modify the order of the shown employees, depending on the option selected
 *
 * @param list the main employee list
 * @param len the size of the employee list
 * @param employeesCounter how many employees the user added, this is used to show the average salary
 */
void printEmployeeDataMenu(Employee* list, int len, int *employeesCounter)
{
	int option;
	float totalSalary=0;
	float avgSalary=0;

	do{
		printLine("MOSTRAR INFORMACION");
		printf("1. ORDEN ASCENDENTE\n2. ORDEN DESCENDENTE\n3. TOTAL Y PROMEDIO DE SALARIOS\n4. ATRAS");
		printLine("");
		option=getInt("\nIngrese una opcion (1-4): ", "Error. Ingrese una opcion valida (1-4): ", 1, 4);

		switch(option)
		{
			case 1: case 2:
				printLine("");
				if(sortEmployees(list, EMPSIZE, option)==0)
				{
					printEmployees(list, EMPSIZE);
					printLine("");
					system("pause");
				}
				else
				{
					printf("\nNo se pudo ordenar la lista...");
				}
			break;
			case 3:
				if (salaryEmployees(list, EMPSIZE, &totalSalary, &avgSalary, *employeesCounter)==0)
				{
					printLine("");
					printf("SALARIO PROMEDIO: %.2f\n", avgSalary);
					printf("Mostrando empleados que superan el salario promedio...\n\n");
					if(printHighPaidEmployees(list, EMPSIZE, &avgSalary)==-1)
					{
						printf("\nNo hay empleados que superen el salario promedio...");
					}
					printLine("");
					system("pause");
				}
				else
				{
					printf("\nNo hay empleados para calcular el salario promedio...");
				}
			break;
			case 4:
				printLine("");
				if(verify("Desea regresar al menú principal? ('s'): ")==0)
				{
					printf("\nRegresando al menú principal...");
				}
				else
				{
					option=0;
				}
			break;
		}
	}while(option!=4);
}

/**
 * @fn int modifyEmployee(Employee*, int)
 * @brief If the user wants to modify an employee, this menu displays. You can modify any aspects of the selected employee, if it exists.
 *
 * @param list the employee list
 * @param len the size of the employee list
 * @return (-1) if error (not found employee or not found array) - (0) if ok
 */
int modifyEmployee(Employee* list, int len)
{
	int index;
	int inputId;
	int option;
	Employee auxEmployee;

	inputId=getInt("Ingrese el ID del empleado a modificar (0-1000): ", "Reingrese el ID del empleado a modificar (0-1000): ", 0, 1000);
	index = findEmployeeById(list, len, inputId);

	if(index!=-1)
	{
		do
		{
			printf("\nEmpleado a modificar:\n\n%-5s %-20s %-20s %-20s %-5s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
			printEmployee(&list[index]);
			printLine("");
			printf("1. MODIFICAR Nombre\n2. MODIFICAR Apellido\n3. MODIFICAR Salario\n4. MODIFICAR Sector\n5. ATRAS");
			printLine("");

			auxEmployee = list[index];
			option=getInt("Ingrese una opcion (1-5): ", "Ingrese una opcion valida (1-5): ", 1, 5);

			switch(option)
			{
				case 1:
					printf("\nEmpleado a modificar:\n\n%-5s %-20s %-20s %-20s %-5s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					printEmployee(&auxEmployee);
					getName(auxEmployee.name,
							"Ingrese nombre del empleado: ",
							"El nombre no debe superar los 50 caracteres\n",
							"El nombre no debe tener caracteres especiales\n",
							"El nombre no puede estar vacío\n",
							51);

					printLine("");
					printf("\nEmpleado luego de la modificación:\n\n%-5s %-20s %-20s %-20s %-5s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					printEmployee(&auxEmployee);
					printLine("");

					if(verify("Confirmar cambios: ('s'): ")==0)
					{
						strcpy(list[index].name, auxEmployee.name);
						printf("\nEmpleado %d modificado correctamente!\n\n", list[index].id);
					}
					system("pause");
				break;
				case 2:
					printf("\nEmpleado a modificar:\n\n%-5s %-20s %-20s %-20s %-5s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					printEmployee(&auxEmployee);
					getName(auxEmployee.lastName,
							"Ingrese apellido del empleado: ",
							"El nombre no debe superar los 50 caracteres\n",
							"El nombre no debe tener caracteres especiales\n",
							"El nombre no puede estar vacío\n",
							51);

					printLine("");
					printf("\nEmpleado luego de la modificación:\n\n%-5s %-20s %-20s %-20s %-5s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					printEmployee(&auxEmployee);
					printLine("");

					if(verify("Confirmar cambios: ('s'): ")==0)
					{
						strcpy(list[index].lastName, auxEmployee.lastName);
						printf("\nEmpleado %d modificado correctamente!\n\n", list[index].id);
					}
					system("pause");
				break;
				case 3:
					printf("\nEmpleado a modificar:\n\n%-5s %-20s %-20s %-20s %-5s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					printEmployee(&auxEmployee);
					auxEmployee.salary=getFloat("\nIngrese el nuevo salario (1000-999999): ", "Ingrese un salario valido (1000-999999): ", 1000, 999999);

					printLine("");
					printf("\nEmpleado luego de la modificación:\n\n%-5s %-20s %-20s %-20s %-5s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					printEmployee(&auxEmployee);
					printLine("");

					if(verify("Confirmar cambios: ('s'): ")==0)
					{
						list[index].salary=auxEmployee.salary;
						printf("\nEmpleado %d modificado correctamente!\n\n", list[index].id);
					}
					system("pause");
				break;
				case 4:
					printf("\nEmpleado a modificar:\n\n%-5s %-20s %-20s %-20s %-5s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					printEmployee(&auxEmployee);
					auxEmployee.sector=getInt("\nIngrese el nuevo sector (1-4): ", "Ingrese un sector valido (1-4): ", 1, 4);

					printLine("");
					printf("\nEmpleado luego de la modificación:\n\n%-5s %-20s %-20s %-20s %-5s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					printEmployee(&auxEmployee);
					printLine("");

					if(verify("Confirmar cambios: ('s'): ")==0)
					{
						list[index].sector=auxEmployee.sector;
						printf("\nEmpleado %d modificado correctamente!\n\n", list[index].id);
					}
					system("pause");
				break;
				case 5:
					printLine("");
					if(verify("Desea regresar al menú principal? ('s'): ")==0)
					{
						printf("\nRegresando al menú principal...");
					}
					else
					{
						option=0;
					}
				break;
			}
		}while(option!=5);

		return 0;
	}
	return -1;
}

/**
 * @fn void printLine(char*)
 * @brief This shows a separator with a message (or not)
 *
 * @param _msg the message that will be in the middle of the separator
 */
void printLine(char *_msg)
{
	printf("\n----------------%s----------------\n", _msg);
}

/**
 * @fn void inputEmployeeData(char*, char*, float*, int*, int)
 * @brief If the user wants to add an employee, this input form will show up.
 * This will validate all the data of a new employee and saves it into the variables passed as parameters
 *
 * @param nameProv name of the employee
 * @param lastNameProv last name of the employee
 * @param salary salary of the employee
 * @param sector sector of the employee
 * @param strLen size of characters allowed
 */
void inputEmployeeData(char *nameProv, char *lastNameProv, float *salary, int *sector, int strLen)
{
	getName(nameProv,
			"Ingrese nombre del empleado: ",
			"El nombre no debe superar los 50 caracteres\n",
			"El nombre no debe tener caracteres especiales\n",
			"El nombre no puede estar vacío\n",
			strLen);
	getName(lastNameProv,
			"Ingrese apellido del empleado: ",
			"El nombre no debe superar los 50 caracteres\n",
			"El nombre no debe tener caracteres especiales\n",
			"El nombre no puede estar vacío\n",
			strLen);
	*salary=getFloat("Ingrese sueldo del empleado (1000-999999): ", "Error. Ingrese un sueldo valido (1000-999999): ", 1000, 999999);
	*sector=getInt("Ingrese sector del empleado (1-4): ", "Error. Ingrese sector valido (1-4): ", 1, 4);
}

/**
 * @fn int searchAvaliableSpace(Employee*, int)
 * @brief In case that an empty space of the main array exists, it will return the first index found
 *
 * @param list the array that the function will travel
 * @param len the size of the array
 * @return (index) if found. (-1) if error
 */
int searchAvaliableSpace(Employee *list, int len)
{
	int i;
	if (list!=NULL)
	{
		for(i=0; i<len; i++)
		{
			if (list[i].isEmpty==1)
			{
				return i;
			}
		}
	}
	return -1;
}

/**
 * @fn void printEmployee(Employee*)
 * @brief prints the data of an employee
 *
 * @param emp the employee passed as parameter
 */
void printEmployee(Employee *emp)
{
	printf("%-5d %-20s %-20s %-20.2f %-5d\n", (*emp).id, (*emp).name, (*emp).lastName, (*emp).salary, (*emp).sector);
}

/**
 * @fn int salaryEmployees(Employee*, int, float*, float*, int)
 * @brief calculates the total and average salary of the employees
 *
 * @param list the employee list
 * @param len size of the list of the employees
 * @param totalSalary variable that stores the total salary
 * @param avgSalary variable that stores the average salary
 * @param employeesCounter
 * @return (-1) if error (not found list) - (0) if ok
 */
int salaryEmployees(Employee* list, int len, float *totalSalary, float *avgSalary, int employeesCounter)
{
	if (list!=NULL)
	{
		int i;
		for(i=0; i<len; i++)
		{
			if (list[i].isEmpty==0)
			{
				*totalSalary+=list[i].salary;
			}
		}
		*avgSalary=(float) *totalSalary/employeesCounter;
		return 0;
	}
	return -1;
}

/**
 * @fn int printHighPaidEmployees(Employee*, int, float*)
 * @brief This will print any employee which exceeds the average salary (passed as parameter)
 *
 * @param list the employee list
 * @param len size of the employee list
 * @param avgSalary the number that the salary have to exceed to show up the employee
 * @return (-1) if error (not found list or not high paid employees) - (0) if ok
 */
int printHighPaidEmployees(Employee* list, int len, float *avgSalary)
{
	int flagOneEmployee=0;
	if (list!=NULL)
	{
		printf("\n%-5s %-20s %-20s %-20s %-5s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
		int i;
		for(i=0; i<len; i++)
		{
			if (list[i].isEmpty==0 && list[i].salary>*avgSalary)
			{
				printEmployee(&list[i]);
				flagOneEmployee=1;
			}
		}
		if(flagOneEmployee==1)
		{
			return 0;
		}
	}
	return -1;
}

/**
 * @fn int getString(char*, char*, char*, int)
 * @brief
 *
 * @param _str pointer to string
 * @param _msg the message that will show up
 * @param _errMsg the message that will show up if the string is too long
 * @param _strMaxLen length that the string cant surpass
 * @return (-1) if error (character variable is null or if string too long) - (0) if ok
 */
int getString(char *_str, char *_msg, char *_errMsg, int _strMaxLen)
{
	char str[200];
	int len;

	if(_str!=NULL)
	{
		printf("%s", _msg);
		fflush(stdin);
		scanf("%[^\n]", str);
		len = strlen(str);

		if(len>_strMaxLen)
		{
			printf(_errMsg);
			return -1;
		}
		strcpy(_str, str);
		return 0;
	}
	return -1;
}

/**
 * @fn int isLetter(char*, char*)
 * @brief this validates if a string has only letters as characters
 *
 * @param _str pointer to string
 * @param _errMsg the message that will show up if the string has special characters
 * @return (-1) if error (character variable is null or if there is a special character on string) - (0) if ok
 */
int isLetter(char *_str, char *_errMsg)
{
    int i=0;

    if(_str!=NULL)
    {
		while(_str[i]!='\0')
		{
			if((_str[i]!=' ') && (_str[i]<'a'||_str[i]>'z') && (_str[i]<'A'||_str[i]>'Z'))
			{
				printf("%s", _errMsg);
				return -1;
			}
			i++;
		}
    }
    return 0;
}

/**
 * @fn int isNotBlank(char*, char*)
 * @brief this validates if a string has characters and is not blank
 *
 * @param _str pointer to string
 * @param _errMsg the message that will show up if the string is empty
 * @return (-1) if error (character variable is null or string is empty) - (0) if ok
 */
int isNotBlank(char *_str, char *_errMsg)
{
	int flagNotBlank=0;
    int i=0;

    if(_str!=NULL)
    {
        while(_str[i]!='\0')
        {
            if(_str[i]!=' ')
            {
            	flagNotBlank=1;
            }
            i++;
        }
        if (flagNotBlank==1)
        {
        	return 0;
        }
    }
    printf("%s", _errMsg);
    return -1;
}

/**
 * @fn int getName(char*, char*, char*, char*, char*, int)
 * @brief this will get a string and validates if it has correct length, is not empty and it has only letters
 *
 * @param _str pointer to string
 * @param _msg the message that will show up
 * @param _errMsgOnLen the message that will show up if there was an error with the length
 * @param _errMsgNotLetter the message that will show up if there was an error with the characters
 * @param _errMsgIsBlank the message that will show up if there was an empty string
 * @param _strMaxLen the maximum length of the string
 * @return (-1) if error (character variable is null or something is wrongly validated) - (0) if ok
 */
int getName(char *_str, char *_msg, char *_errMsgOnLen, char *_errMsgNotLetter, char *_errMsgIsBlank, int _strMaxLen)
{
	char str[_strMaxLen];

	if(_str!=NULL)
	{
		if(getString(str, _msg, _errMsgOnLen, _strMaxLen)==0 && isLetter(str, _errMsgNotLetter)==0 && isNotBlank(str, _errMsgIsBlank)==0)
		{
			strcpy(_str, str);
			return 0;
		}
	}
	getName(_str, _msg, _errMsgOnLen, _errMsgNotLetter, _errMsgIsBlank, _strMaxLen);
	return -1;
}

/**
 * @fn int getInt(char*, char*, int, int)
 * @brief this ask the user to enter an int number and validates it
 *
 * @param _msg the message that will show up
 * @param _errMsg the message that will show up if there was an error with the input (< min or > max)
 * @param _min the minimum possible number
 * @param _max the maximum possible number
 * @return returns the int number entered
 */
int getInt(char *_msg, char *_errMsg, int _min, int _max)
{
	int num;

	printf("%s", _msg);
	fflush(stdin);
	scanf("%d", &num);

	while(isdigit(num)==0 && (num < _min || num > _max))
	{
		printf("%s", _errMsg);
		fflush(stdin);
		scanf("%d", &num);
	}
	return num;
}

/**
 * @fn float getFloat(char*, char*, int, int)
 * @brief this ask the user to enter a float number and validates it
 *
 * @param _msg the message that will show up
 * @param _errMsg the message that will show up if there was an error with the input
 * @param _min the minimum possible number
 * @param _max the maximum possible number
 * @return returns the float number entered
 */
float getFloat(char *_msg, char *_errMsg, int _min, int _max)
{
	float num;

	printf("%s", _msg);
	fflush(stdin);
	scanf("%f", &num);

	while(num < _min || num > _max)
	{
		printf("%s", _errMsg);
		fflush(stdin);
		scanf("%f", &num);
	}
	return num;
}

/**
 * @fn int getCharacter(char*, char*)
 * @brief this asks the user to enter a char and validates it
 *
 * @param _character where the char will be stored
 * @param _msg the message that will show up
 * @return (-1) if error (character variable is null or message not found) - (0) if ok
 */
int getCharacter(char *_character, char *_msg)
{
	if(_character != NULL && _msg != NULL)
	{
		printf("%s", _msg);
		fflush(stdin);
		*_character = getchar();
		return 0;
	}
	return -1;
}

/**
 * @fn int verify(char*)
 * @brief this asks the user to enter a char and validates if its an 's' or an 'S'
 *
 * @param _msg the message that will show up
 * @return (-1) if error (character is not an 's' or an 'S') - (0) if ok
 */
int verify(char *_msg)
{
	char ver;

	getCharacter(&ver, _msg);
	if(ver == 's' || ver == 'S')
	{
		return 0;
	}
	return -1;
}
