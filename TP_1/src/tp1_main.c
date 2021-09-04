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
#include "funciones.h"

int main()
{
	setbuf(stdout, NULL);

	int a;
	int b;

	a = ingresarDato('a');
	b = ingresarDato('b');

	printf("Calculo de todas las operaciones:\n(A=%d B=%d)", a, b);
	calcularSuma(a, b, "A+B");
	calcularResta(a, b, "A-B");
	calcularDivision(a, b, "A/B");
	calcularProducto(a, b, "A*B");
	printf("\nEl resultado de !A es %d", calcularFactorial(a));

	return 0;
}
