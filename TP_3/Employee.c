#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

/**
 * @fn Employee employee_new*()
 * @brief Declara un puntero a empleado y reserva espacio en memoria
 *
 * @return el puntero a empleado
 */
Employee* employee_new(){
	Employee* employee = NULL;
	employee = (Employee*)malloc(sizeof(Employee));
	return employee;
}

/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief Declara un puntero a employee, reserva espacio en memoria, y con los parametros recibidos se llenan los campos con setters
 *
 * @param idStr ID del empleado
 * @param nombreStr Nombre del empleado
 * @param horasTrabajadasStr Horas trabajadas del empleado
 * @param sueldoStr Sueldo del empleado
 * @return retorna el puntero a empleado (NULL si no se pudo reservar memoria)
 */
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

/**
 * @fn void employee_delete(Employee*)
 * @brief Libera espacio en memoria del empleado
 *
 * @param this puntero a empleado
 */
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

/**
 * @fn int employee_setId(Employee*, int)
 * @brief Toma un puntero a empleado y un id, con el operador flecha accedemos al id y lo seteamos con el parametro
 *
 * @param this puntero a empleado
 * @param id el id deseado
 * @return 0 (ok) o -1 (error)
 */
int employee_setId(Employee* this,int id)
{
	if(this!=NULL)
	{
		this->id=id;
		return 0;
	}
	return -1;
}

/**
 * @fn int employee_getId(Employee*, int*)
 * @brief Toma un puntero a empleado y un puntero para guardar el id de ese empleado
 *
 * @param this puntero a empleado
 * @param id puntero de la variable en donde se guardara el id del empleado
 * @return 0 (ok) o -1 (error)
 */
int employee_getId(Employee* this,int* id)
{
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		return 0;
	}
	return -1;
}

/**
 * @fn int employee_setNombre(Employee* this,char* nombre)
 * @brief Toma un puntero a empleado y un puntero a char, con el operador flecha accedemos al nombre y lo seteamos con el puntero a char
 *
 * @param this puntero a empleado
 * @param nombre puntero a char con la cadena del nombre deseado
 * @return 0 (ok) o -1 (error)
 */
int employee_setNombre(Employee* this,char* nombre)
{
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre, nombre);
		return 0;
	}
	return -1;
}

/**
 * @fn int employee_getNombre(Employee* this,char* nombre)
 * @brief Toma un puntero a empleado y un puntero a char para guardar el nombre de ese empleado
 *
 * @param this puntero a empleado
 * @param nombre puntero de la variable, en este caso una cadena de caracteres, en donde se guardara el nombre del empleado
 * @return 0 (ok) o -1 (error)
 */
int employee_getNombre(Employee* this,char* nombre)
{
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombre);
		return 0;
	}
	return -1;
}

/**
 * @fn int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
 * @brief Toma un puntero a empleado y un int, con el operador flecha accedemos al campo de horas trabajadas y lo seteamos con el parametro entero
 *
 * @param this puntero a empleado
 * @param horasTrabajadas las horas que deseemos asignarle
 * @return 0 (ok) o -1 (error)
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	if(this!=NULL)
	{
		this->horasTrabajadas=horasTrabajadas;
		return 0;
	}
	return -1;
}

/**
 * @fn int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
 * @brief Toma un puntero a empleado y un puntero a entero para guardar las horas trabajadas de ese empleado
 *
 * @param this puntero a empleado
 * @param horasTrabajadas puntero de la variable en donde se guardaran las horas trabajadas del empleado
 * @return 0 (ok) o -1 (error)
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		return 0;
	}
	return -1;
}

/**
 * @fn int employee_setSueldo(Employee* this,int sueldo)
 * @brief Toma un puntero a empleado y un int, con el operador flecha accedemos al campo de sueldo y lo seteamos con el parametro entero
 *
 * @param this puntero a empleado
 * @param sueldo el sueldo que deseemos asignarle
 * @return 0 (ok) o -1 (error)
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	if(this!=NULL)
	{
		this->sueldo=sueldo;
		return 0;
	}
	return -1;
}

/**
 * @fn int employee_getSueldo(Employee* this,int* sueldo)
 * @brief Toma un puntero a empleado y un puntero a entero para guardar el sueldo de ese empleado
 *
 * @param this puntero a empleado
 * @param sueldo puntero de la variable en donde se guardara el sueldo del empleado
 * @return 0 (ok) o -1 (error)
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		return 0;
	}
	return -1;
}
