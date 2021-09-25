/**
 * Biblioteca con funciones de carga y calculo
 *
 * \author Joaquín Lubo Millán | Division G - segundo cuatrimestre 2021
 *
 * Descripcion:  esta biblioteca cuenta con una función de ingreso de enteros y cuatro funciones de opercaciones matemáticas
 */
#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * \brief función para ingreso y validacion de enteros. La validación se realiza a través de un loop do while que verifica el retorn de la función scanf.
 * scanf retorna el número de campos correctamente leidos y asignados, en este caso 1 si se ingresa un entero.
 *
 * \param pInput puntero al entero a asignar
 * \param mensaje array de caracteres. En main se le pasan mensajes distintos para el primer ingreso y para el segundo.
 */
void ingresar(int *pInput, char *mensaje)
{
  int input;
  int intCheck;
  do
  {
    fflush(stdin);
    printf("%s \n", mensaje);
    intCheck = scanf("%d", &input);
  } while (intCheck == 0);

  *pInput = input;
}
/**
 * \brief realiza la suma entre los dos punteros a entero pasados como argumento y asigna el resultado de la misma en un puntero a entero (pSuma)
 *
 * \param pPrimero puntero al primer entero
 * \param pSegundo puntero al segundo entero
 * \param pSuma puntero a la variable "suma"
 * \return
 */
int sumar(int *pPrimero, int *pSegundo, int *pSuma)
{

  *pSuma = *pPrimero + *pSegundo;

  return 1;
}
/**
 * \brief realiza la resta entre los dos punteros a entero pasados como argumento y asigna el resultado de la misma en un puntero a entero (pResta)
 *
 * \param pPrimero puntero al primer entero
 * \param pSegundo puntero al segundo entero
 * \param pResta puntero a la variable "resta"
 * \return
 */
int restar(int *pPrimero, int *pSegundo, int *pResta)
{
  *pResta = *pPrimero - *pSegundo;
  return 1;
}
/**
 * \brief realiza la multiplicación entre los dos punteros a entero pasados como argumento y asigna el resultado de la misma en un puntero a entero (pMultiplicacion)
 *
 * \param pPrimero puntero al primer entero
 * \param pSegundo puntero al segundo entero
 * \param pMultiplicacion puntero a la variable "multiplicacion"
 * \return
 */
int multiplicar(int *pPrimero, int *pSegundo, int *pMultiplicacion)
{

  *pMultiplicacion = *pPrimero * *pSegundo;

  return 1;
}
/**
 * \brief realiza la division entre los dos punteros a entero pasados como argumento y asigna el resultado de la misma en un puntero a entero (pDivision)
 *
 * \param pPrimero puntero al primer entero
 * \param pSegundo puntero al segundo entero
 * \param pDivision puntero a la variable de resultado "division"
 * \param pDivisionOk puntero a una variable en main, a modo de bandera, para poder verificar si la operación es valida y se puede mostrar el resultado
 * \return
 */
int dividir(int *pPrimero, int *pSegundo, float *pDivision, int *pDivisionOk)
{

  *pDivisionOk = 0;
  if (*pSegundo == 0)
  {
    return 0;
  }
  else
  {
    *pDivision = (float)*pPrimero / *pSegundo;
    *pDivisionOk = 1;
    return 1;
  }
}
/**
 * \brief
 *
 * \param pNumero puntero entero
 * \param pFactorial puntero a la variable de resultado "factorial"
 * \param factorialOk puntero a una variable en main, a modo de bandera, para poder verificar si la operación es valida y se puede mostrar el resultado
 * \return
 */
int factorizar(int *pNumero, double *pFactorial, int *factorialOk)
{

  int operacionOk = 0;
  if (*pNumero >= 0)
  {
    *pFactorial = 1;
    for (int i = 2; i <= *pNumero; i++)
    {
      *pFactorial *= i;
    }
    *factorialOk = 1;
    operacionOk = 1;
  }
  else
  {
    *factorialOk = 0;
  }
  return operacionOk;
}


