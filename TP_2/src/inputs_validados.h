/*
 * inputs_validados.h
 *
 *  Created on: 16 oct. 2021
 *      Author: joq
 */

#ifndef INPUTS_VALIDADOS_H_
#define INPUTS_VALIDADOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs_validados.h"
#include "employees.h"





void ingresarEnterosRango(int *pInput, char *mensaje, char *mensajeError, int lInf, int lSup);
int ingresarValidarCadena(char *vec, int tam, char mensaje[], char mensajeError[], int minLen, int maxLen);
void ingresarFlotantesRango(float *pInput, char mensaje[], char mensajeError[], float lInf, float lSup);
int buscarPosicionLibre(Employee list[], int len);
int checkNum(char vec[]);

#endif /* INPUTS_VALIDADOS_H_ */
