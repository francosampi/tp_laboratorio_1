/*
 * operaciones.h
 *
 *  Created on: 3 sep. 2021
 *      Author: franc
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_
#include <stdio.h>

/**
 * @fn void calcularSuma(int, int, int*)
 * @brief Esta funcion realiza la operacion de la suma
 *
 * @param _a Primer numero flotante previamente ingresado
 * @param _b Segundo numero flotante previamente ingresado
 * @param _operacion En donde se guardara el resultado de la operacion
 */
void calcularSuma(float _a, float _b, float *_operacion);

/**
 * @fn void calcularResta(float, float, float*)
 * @brief Esta funcion realiza la operacion de la resta
 *
 * @param _a Primer numero flotante previamente ingresado
 * @param _b Segundo numero flotante previamente ingresado
 * @param _operacion En donde se guardara el resultado de la operacion
 */
void calcularResta(float _a, float _b, float *_operacion);

/**
 * @fn int calcularDivision(float, float, float*)
 * @brief Esta funcion realiza la operacion de la division (de ser posible) y a diferencia de las otras funciones, retorna su hubo o no un error
 *
 * @param _a Primer numero flotante previamente ingresado
 * @param _b Segundo numero flotante previamente ingresado
 * @param _operacion En donde se guardara el resultado de la operacion
 * @return De haber sido posible la operacion, se retorna el numero 1, caso contrario se retorna cero
 */
int calcularDivision(float _a, float _b, float *_operacion);

/**
 * @fn void calcularProducto(float, float, float*)
 * @brief Esta funcion realiza la operacion de la resta
 *
 * @param _a Primer numero flotante previamente ingresado
 * @param _b Segundo numero flotante previamente ingresado
 * @param _operacion En donde se guardara el resultado de la operacion
 */
void calcularProducto(float _a, float _b, float *_operacion);

/**
 * @fn long int calcularFactorial(int)
 * @brief Esta funcion realiza la operacion del factorial (si se trata de un numero positivo) y guardando el resultado a medida que se llama a si misma para resolver la operacion
 *
 * @param _num El numero al cual realizara el factorial
 * @return Luego de realizarse la operacion retornara el resultado final
 */
long int calcularFactorial(int _num);

#endif /* OPERACIONES_H_ */
