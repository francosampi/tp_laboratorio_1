/*
 * operaciones.h
 *
 *  Created on: 3 sep. 2021
 *      Author: franc
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>

int ingresarDato(char letra);

void calcularSuma(int _a, int _b, char* operacion);
void calcularResta(int _a, int _b, char* operacion);
void calcularDivision(int _a, int _b, char* operacion);
void calcularProducto(int _a, int _b, char* operacion);
int calcularFactorial(int _a);

#endif /* FUNCIONES_H_ */
