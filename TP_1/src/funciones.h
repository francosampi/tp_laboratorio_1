/*
 * funciones.h
 *
 *  Created on: 24 sep. 2021
 *      Author: franc
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

void iniciarMenu();
void mostrarInterfaz(int *_datoAIngresado, int *_datoBIngresado, float _datoA, float _datoB);
void ingresarDato(float *dato, char *_letra, int *_seHaIngresado, int *_sinCalcular);
void separador(void);
void mostrarResultado(char *_operacion, float _resultado);
int validarDatosAyB(int *_datoA, int *_datoB);
int validarOpcion(char *_mensaje, char *_mensajeError, int _min, int _max);

#endif /* FUNCIONES_H_ */
