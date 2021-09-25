/**
 * TP Nro 1
 *
 * \author Joaquín Lubo Millán | Division G - segundo cuatrimestre 2021
 * *
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

void ingresar(int *pInput, char mensaje[]);

int sumar(int *pPrimero, int *pSegundo, int *pSuma);
int restar(int *pPrimero, int *pSegundo, int *pResta);
int multiplicar(int *pPrimero, int *pSegundo, int *pMultiplicacion);
int dividir(int *pPrimero, int *pSegundo, float *pDivision, int *pDivisionOk);
int factorizar(int *pNumero, double *pFactorial, int *factorialOk);

int main(void)
{
  setbuf(stdout, NULL);
  int primerNumero;
  int segundoNumero;
  int suma;
  int resta;
  int multiplicacion;
  float division;
  int divisionOk;
  double factorialPrimero;
  int factorialPrimeroOk = 0;
  double factorialSegundo;
  int factorialSegundoOk = 0;
  int opcion;
  char sigue = 's';
  _Bool flagIngreso = 0;
  /* Flag para habilitar la opcion 'calcular'" */
  _Bool flagCalculo = 0;
  /* Flag para habilitar la opcion 'mostrar'" */

  /**
   * bucle do while que muestra en consola un menú de opciones.
   * Las opciones se van habilitando sólo si se cumplen los pasos previos, por ej: solo se puede calcular si se ingresaron los números.
   */
  do
  {
    fflush(stdin);
    system("cls");

    printf("CALCULADORA\n");
    printf("Menu de opciones\n\n");
    if (flagIngreso)
    {
      printf("1. Ingresar numeros nuevamente\n");
      printf("2. Calcular operaciones entre %d y %d\n", primerNumero, segundoNumero);
    }
    else
    {
      printf("1. Ingresar numeros \n");
      printf("2. Calcular operaciones\n");
    }
    printf("3. Mostrar resultados\n");
    printf("4. Salir\n");
    printf("Indique la opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      ingresar(&primerNumero, "cual es el primer numero");
      ingresar(&segundoNumero, "cual es el segundo numero");
      flagIngreso = 1;
      opcion = 0;
      /*
       * despues de cada case, opcion defaultea a 0. Esto es para prevenir la persistencia del mensaje de la anterior iteración en el caso de elegir una opción no válida.
       */
      break;

    case 2:
      if (!flagIngreso)
      {
        printf("Antes de calcular tenes que ingresar los numeros\n");
        opcion = 0;
        break;
      }
      else
      {
        sumar(&primerNumero, &segundoNumero, &suma);
        restar(&primerNumero, &segundoNumero, &resta);
        multiplicar(&primerNumero, &segundoNumero, &multiplicacion);
        dividir(&primerNumero, &segundoNumero, &division, &divisionOk);
        factorizar(&primerNumero, &factorialPrimero, &factorialPrimeroOk);
        factorizar(&segundoNumero, &factorialSegundo, &factorialSegundoOk);

        printf("Resultados listos...\n");
        flagCalculo = 1;
        opcion = 0;
      }
      break;

    case 3:
      if (!flagCalculo)
      {
        printf("Antes de mostrar los resultados tenes que calcularlos\n");
        opcion = 0;
        break;
      }
      else
      {
        printf("el resultado de la suma es: %d\n", suma);
        printf("el resultado de la resta es: %d\n", resta);
        printf("el resultado de la multiplicacion es: %d\n", multiplicacion);
        /**
         * el siguiente if evalúa si se pudo realizar la divión.
         */
        if (divisionOk == 1)
        {
          printf("la division es: %.2f\n", division);
        }
        else
        {
          printf("La division no se pudo calcular: error, no se puede dividir por 0\n");
        }
        /**
         * este if y el siguiente evalúan si se pudo realizar el factoreo de los correspondientes números.
         * el else contiene un aviso de los límites de precisión en el cálculo
         */
        if (factorialPrimeroOk ==0)
        {
          printf("No se pudo calcular el factorial de %d \n", primerNumero);
        }
        else
        {
          printf("El factorial de %d es %.0f\n", primerNumero, factorialPrimero);
          if (primerNumero > 20)
          {
            printf("ALERTA: el calculo de factoriales de numeros mayores a 20 podria no ser preciso\n");
          }
        }
        if (factorialSegundoOk ==0)
        {
          printf("No se pudo calcular el factorial de %d \n", segundoNumero);
        }
        else
        {
          printf("El factorial de %d es %.0f\n", segundoNumero, factorialSegundo);
          if (segundoNumero > 20)
          {
            printf("ALERTA: el calculo de factoriales de numeros mayores a 20 podria no ser preciso\n");
          }
        }

        opcion = 0;
        flagCalculo = 0;
      }
      break;

    case 4:
      sigue = 'n';
      break;

    default:
      printf("opcion invalida\n");
      opcion = 0;
      break;
    }
    fflush(stdin);
    system("pause");
  } while (sigue == 's');

}
