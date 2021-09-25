/**
 * Archivo header para la biblioteca calculadora.
 *
 * \author Joaquín Lubo Millán | Division G - segundo cuatrimestre 2021
 * *
 */
#ifndef __CALCULADORA_H_
#define __CALCULADORA_H_

void ingresar(int *pInput, char *mensaje);
int sumar(int *pPrimero, int *pSegundo, int *pSuma);
int restar(int *pPrimero, int *pSegundo, int *pResta);
int multiplicar(int *pPrimero, int *pSegundo, int *pMultiplicacion);
int dividir(int *pPrimero, int *pSegundo, float *pDivision, int *pDivisionOk);
int factorizar(int *pNumero, double *pFactorial, int *factorialOk);


#endif
