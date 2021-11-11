#include "Employee.h"
#include "LinkedList.h"

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

Employee* employee_getById(LinkedList* pArrayListEmployee, int tam, int id);
int employee_orderById(void* employeeA, void* employeeB);
int employee_orderByName(void* employeeA, void* employeeB);
int employee_orderBySalary(void* employeeA, void* employeeB);

#endif /* FUNCTIONS_H_ */
