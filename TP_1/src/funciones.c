/*
 * operaciones.c
 *
 *  Created on: 3 sep. 2021
 *      Author: franc
 */

#include "funciones.h"

int ingresarDato(char letra)
{
	int dato;

	printf("Ingrese valor: ");
	fflush(stdin);
	scanf("%d", &dato);

	return dato;
}

void calcularSuma(int _a, int _b, char* operacion)
{
	int resultado;

	resultado = _a + _b;

	printf("\nEl resultado de %s es: %d", operacion, resultado);
}

void calcularResta(int _a, int _b, char* operacion)
{
	int resultado;

	resultado = _a - _b;

	printf("\nEl resultado de %s es: %d", operacion, resultado);
}

void calcularDivision(int _a, int _b, char* operacion)
{
	int resultado;

	if (_b!=0)
	{
		resultado = _a / _b;
		printf("\nEl resultado de %s es: %d", operacion, resultado);
	}
	else
		printf("\nNo es posible dividir por cero");
}

void calcularProducto(int _a, int _b, char* operacion)
{
	int resultado;

	resultado = _a * _b;

	printf("\nEl resultado de %s es: %d", operacion, resultado);
}

int calcularFactorial(int _a)
{
	int resultado;

	if(_a == 0)
	{
		resultado = 1;
	}
	else
	{
		resultado = _a * calcularFactorial(_a-1);
	}

	return resultado;
}
