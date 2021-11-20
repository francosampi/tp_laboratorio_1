#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"
#include "functions.h"

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
    int flagListaCargada=0;
    int ultimoIdIngresado;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        printLine("MENU");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
			  "2. Cargar los datos de los empleados desde el archivo datab.csv (modo binario)\n"
			  "3. Alta de empleado\n"
			  "4. Modificar datos de empleado\n"
			  "5. Baja de empleado\n"
			  "6. Listar empleados\n"
			  "7. Ordenar empleados\n"
			  "8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
			  "9. Guardar los datos de los empleados en el archivo datab.csv (modo binario)\n"
			 "10. Salir");
		printLine("");

		opcion=getInt("\nIngrese una opcion (1-10): ", "\nError. Ingrese una opcion (1-10): ", 1, 10);

        switch(opcion)
        {
            case 1:
            	if(flagListaCargada==0)
            	{
                    if(listaEmpleados!=NULL && controller_loadFromText("src//data.csv",listaEmpleados)==0)
                    {
                    	printf("\nSe han cargado los datos exitosamente...\n");
                    	ultimoIdIngresado=ll_getLastId(listaEmpleados);
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
                    if(listaEmpleados!=NULL && controller_loadFromBinary("src//datab.csv",listaEmpleados)==0)
                    {
                    	printf("\nSe han cargado los datos exitosamente...\n");
                    	ultimoIdIngresado=ll_getLastId(listaEmpleados);
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
            		if(listaEmpleados!=NULL && controller_addEmployee(listaEmpleados, &ultimoIdIngresado)==0)
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
					if(listaEmpleados!=NULL && controller_ListEmployee(listaEmpleados)==0)
					{
						if(controller_editEmployee(listaEmpleados, ultimoIdIngresado)==1)
						{
							printf("\nError al abrir menu de modificacion...\n");
						}
					}
					else
					{
						printf("\nError al cargar la lista...\n");
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
					if(listaEmpleados!=NULL && controller_ListEmployee(listaEmpleados)==0)
					{
						if(controller_removeEmployee(listaEmpleados, ultimoIdIngresado)==0)
						{
							printf("\nSe ha dado de baja al empleado exitosamente...\n");
						}
						else
						{
							printf("\nNo se ha dado de baja ningun empleado...\n");
						}
					}
					else
					{
						printf("\nError al cargar la lista...\n");
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
					if(listaEmpleados!=NULL && controller_ListEmployee(listaEmpleados)==1)
					{
						printf("\nError al cargar la lista...\n");
					}
				}
				else
				{
					printf("\nLa lista de empleados no fue cargada previamente...\n");
				}
				system("pause");
				break;
            case 7:
				if(flagListaCargada==1)
				{
					if(listaEmpleados!=NULL && controller_sortEmployee(listaEmpleados)==1)
					{
						printf("\nError ingresar al menu de ordenamiento...\n");
					}
				}
				else
				{
					printf("\nLa lista de empleados no fue cargada previamente...\n");
				}
				system("pause");
				break;
            case 8:
				if(flagListaCargada==1)
				{
					if(listaEmpleados!=NULL && controller_saveAsText("src//data.csv", listaEmpleados)==0)
					{
						printf("\nLa lista fue guardada en texto exitosamente...\n");
					}
					else
					{
						printf("\nError al guardar la lista en texto...\n");
					}
				}
				else
				{
					printf("\nLa lista de empleados no fue cargada previamente...\n");
				}
				system("pause");
				break;
            case 9:
				if(flagListaCargada==1)
				{
					if(listaEmpleados!=NULL && controller_saveAsBinary("src//datab.csv", listaEmpleados)==0)
					{
						printf("\nLa lista fue guardada en binario exitosamente...\n");
					}
					else
					{
						printf("\nError al guardar la lista en binario...\n");
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
            		if(listaEmpleados!=NULL)
            		{
            			ll_deleteLinkedList(listaEmpleados);
            		}
            		printf("\nSaliendo del programa...\n");
            	}
            	break;
        }
    }while(opcion != 10);
    return 0;
}
