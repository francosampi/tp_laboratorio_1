#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);

    int opcion = 0;
    int flagListaCargada = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        printLine("MENU");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
			  "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
			  "3. Alta de empleado\n"
			  "4. Modificar datos de empleado\n"
			  "5. Baja de empleado\n"
			  "6. Listar empleados\n"
			  "7. Ordenar empleados\n"
			  "8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
			  "9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
			 "10. Salir");
		printLine("");
		opcion=getInt("\nIngrese una opcion (1-10): ", "\nError. Ingrese una opcion (1-10): ", 1, 10);

        switch(opcion)
        {
            case 1:
            	if(flagListaCargada==0)
            	{
                    if(controller_loadFromText("data.csv",listaEmpleados)==0)
                    {
                    	printf("\nSe han cargado los datos exitosamente...\n");
                    	flagListaCargada=1;
                    }
                    else
                    {
                    	printf("\nError al cargar los datos...\n");
                    }
            	}
            	else
            	{
            		printf("\nLa lista ya ha sido cargada...\n");
            	}
                system("pause");
                break;
            case 2:
            	if(flagListaCargada==0)
            	{
                    if(controller_loadFromBinary("data.csv",listaEmpleados)==0)
                    {
                    	printf("\nSe han cargado los datos exitosamente...\n");
                    	flagListaCargada=1;
                    }
                    else
                    {
                    	printf("\nError al cargar los datos...\n");
                    }
            	}
            	else
            	{
            		printf("\nLa lista ya ha sido cargada...\n");
            	}
                system("pause");
                break;
            case 3:
            	if(flagListaCargada==1)
            	{
            		if(controller_addEmployee(listaEmpleados)==0)
            		{
            			printf("\nSe ha cargado al empleado exitosamente...\n");
            		}
            		else
					{
						printf("\nError al cargar al empleado...\n");
					}
            	}
            	else
            	{
            		printf("\nLa lista de empleados no fue cargada previamente...\n");
            	}
                system("pause");
                break;
            case 4:
            	if(flagListaCargada==1)
            	{
					if(controller_ListEmployee(listaEmpleados)==0)
					{
						if(controller_editEmployee(listaEmpleados)==0)
						{
							printf("\nSe ha modificado al empleado exitosamente...\n");
						}
						else
						{
							printf("\nError al abrir menu de modificacion...\n");
						}
					}
					else
					{
						printf("\nError al cargar la lista...");
					}
            	}
            	else
            	{
            		printf("\nLa lista de empleados no fue cargada previamente...\n");
            	}
                system("pause");
                break;
            case 5:
				if(flagListaCargada==1)
				{
					if(controller_ListEmployee(listaEmpleados)==0)
					{
						if(controller_removeEmployee(listaEmpleados)==0)
						{
							printf("\nSe ha dado de baja al empleado exitosamente...\n");
						}
						else
						{
							printf("\nError al abrir menu de bajas...\n");
						}
					}
					else
					{
						printf("\nError al cargar la lista...");
					}
				}
				else
				{
					printf("\nLa lista de empleados no fue cargada previamente...\n");
				}
				system("pause");
				break;
            case 6:
				if(flagListaCargada==1)
				{
					if(controller_ListEmployee(listaEmpleados)==1)
					{
						printf("\nError al cargar la lista...");
					}
				}
				else
				{
					printf("\nLa lista de empleados no fue cargada previamente...\n");
				}
				system("pause");
				break;
            case 10:
            	if(verify("\nDesea salir del programa? ('s'): ")==0)
            	{
            		printf("\nSaliendo del programa...\n");
            	}
            	break;
        }
    }while(opcion != 10);
    return 0;
}
