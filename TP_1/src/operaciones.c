/*
 * operaciones.c
 *
 *  Created on: 3 sep. 2021
 *      Author: franc
 */

#include "operaciones.h"


void calcularSuma(float _a, float _b, float *_operacion)
{
	*_operacion = _a + _b;
}


void calcularResta(float _a, float _b, float *_operacion)
{
	*_operacion = _a - _b;
}


int calcularDivision(float _a, float _b, float *_operacion)
{
	if(_b!=0)
	{
		*_operacion = _a / _b;
		return 1;
	}
	return 0;
}


void calcularProducto(float _a, float _b, float *_operacion)
{
	*_operacion = _a * _b;
}

long int calcularFactorial(int _num)
{
	long int resultado;

	if(_num < 1)
	{
		resultado = 1;
	}
	else
	{
		resultado = _num * calcularFactorial(_num-1);
	}
	return resultado;
}
