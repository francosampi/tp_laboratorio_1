/*
 ============================================================================
 Name        : prueba_eclipse.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 31;

void iniciarMenu();
void mostrarInterfaz(int *_datoAIngresado, int *_datoBIngresado, float _datoA, float _datoB);
void ingresarDato(float *dato, char *_letra, int *_seHaIngresado, int *_sinCalcular);
void separador(void);
void mostrarResultado(char *_operacion, float _resultado);
int validarDatosAyB(int *_datoA, int *_datoB);
int validarOpcion(char *_mensaje, char *_mensajeError, int _min, int _max);

int main()
{
	setbuf(stdout, NULL);

	iniciarMenu();

	return 0;
}

void iniciarMenu()
{
	int opcion;
	float a;
	float b;
	int aIngresado=0; //0-Sin ingresar, 1-Ingresado
	int bIngresado=0; //0-Sin ingresar, 1-Ingresado
	int calculosRealizados=0; //0-Sin resolver, 1-Resueltos (Al re-ingresar A o B vuelve a 0)
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoProducto;
	int errorDivision;
	long int resultadoFactorialA;
	long int resultadoFactorialB;

	do
	{
		mostrarInterfaz(&aIngresado, &bIngresado, a, b);

		fflush(stdin);
		opcion=validarOpcion("Ingrese una opcion (1-5)", "Error. Ingrese una opcion valida (1-5)", 1, 5);

		switch(opcion)
		{
			case 1:
				ingresarDato(&a, "A", &aIngresado, &calculosRealizados);
			break;
			case 2:
				ingresarDato(&b, "B", &bIngresado, &calculosRealizados);
			break;
			case 3:
				if(validarDatosAyB(&aIngresado, &bIngresado)==1)
				{
					separador();
					printf("Se calcularon todas las operaciones...");

					calcularSuma(a, b, &resultadoSuma);
					calcularResta(a, b, &resultadoResta);
					errorDivision=calcularDivision(a, b, &resultadoDivision);
					calcularProducto(a, b, &resultadoProducto);
					resultadoFactorialA = calcularFactorial(a);
					resultadoFactorialB = calcularFactorial(b);

					calculosRealizados=1;
				}
			break;
			case 4:
				separador();
				if(validarDatosAyB(&aIngresado, &bIngresado)==1)
				{
					if (calculosRealizados==1)
					{
						mostrarResultado("A+B", resultadoSuma);
						mostrarResultado("A-B", resultadoResta);

						if(errorDivision==0)
						{
							printf("No es posible dividir por cero\n");
						}
						else
						{
							mostrarResultado("A/B", resultadoDivision);
						}

						mostrarResultado("A*B", resultadoProducto);

						if(a<0)
						{
							printf("No es posible realizar el factorial de A\n");
						}
						else
						{
							mostrarResultado("!A", (float) resultadoFactorialA);
						}

						if(b<0)
						{
							printf("No es posible realizar el factorial de B\n");
						}
						else
						{
							mostrarResultado("!B", (float) resultadoFactorialB);
						}
						separador();
						system("pause");
					}
					else
					{
						printf("Las operaciones no fueron realizadas previamente.");
					}
				}
			break;
		}
	}while(opcion!=5);
}

void mostrarInterfaz(int *_datoAIngresado, int *_datoBIngresado, float _datoA, float _datoB)
{
	separador();
	if(*_datoAIngresado==1)
	{
		printf("1. Ingresar 1er operando (A=%.2f)", _datoA);
	}
	else
	{
		printf("1. Ingresar 1er operando (A=X)");
	}
	if(*_datoBIngresado==1)
	{
		printf("\n2. Ingresar 2do operando (B=%.2f)", _datoB);
	}
	else
	{
		printf("\n2. Ingresar 2do operando (B=Y)");
	}
	printf("\n3. Calcular operaciones\n4. Mostrar resultados\n5. Salir");
	separador();
}

void ingresarDato(float *dato, char *_letra, int *_seHaIngresado, int *_sinCalcular)
{
	float valorIngresado;

	printf("Ingrese valor de %s: ", _letra);
	fflush(stdin);
	scanf("%f", &valorIngresado);

	*dato = valorIngresado;
	*_seHaIngresado=1;
	*_sinCalcular=0;
}

void separador()
{
	printf("\n-----------------------\n");
}

void mostrarResultado(char *_operacion, float _resultado)
{
	printf("El resultado de %s es: %.2f\n", _operacion, _resultado);
}

int validarDatosAyB(int *_datoA, int *_datoB)
{
	if(*_datoA==0 || *_datoB==0)
	{
		if(*_datoA==0)
		{
			printf("No se ha ingresado el dato A previamente\n");
		}
		if(*_datoB==0)
		{
			printf("No se ha ingresado el dato B previamente");
		}
		return 0;
	}
	return 1;
}

int validarOpcion(char *_mensaje, char *_mensajeError, int _min, int _max)
{
	int opcionIngresada;

	printf("%s", _mensaje);
	fflush(stdin);
	scanf("%d", &opcionIngresada);

	while(opcionIngresada < _min || opcionIngresada > _max)
	{
		printf("%s", _mensajeError);
		fflush(stdin);
		scanf("%d", &opcionIngresada);
	}
	return opcionIngresada;
}
