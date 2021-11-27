/*
 * inputs_validados.c
 *
 *  Created on: 16 oct. 2021
 *      Author: joq
 */


// Inputs y validaciones
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "employees.h"
#include "inputs_validados.h"

/**
 * \brief funci�n para ingreso y validacion de enteros dentro de un rango. La validaci�n se realiza a trav�s de un loop do while que verifica el retorn de la funci�n scanf.
 * scanf retorna el n�mero de campos correctamente leidos y asignados, en este caso 1 si se ingresa un entero.
 *
 * \param pInput puntero al entero a asignar
 * \param mensaje array de caracteres.
 * \param mensajeError array de caracteres.
 * \param lInf Entero para setear el limite inferior de la validacion.
 * \param lSup Entero para setear el limite superior de la validacion.
 */

void ingresarEnterosRango(int *pInput, char mensaje[], char mensajeError[], int lInf, int lSup)
{
    int input;
    int intCheck;
    do
    {

        printf("%s\n", mensaje);
        fflush(stdin);
        intCheck = scanf("%d", &input);

        if (intCheck == 0 || input < lInf || input > lSup)
        {
            printf("%s", mensajeError);
        }
    } while (intCheck == 0 || input < lInf || input > lSup);

    *pInput = input;
}

/**
 \brief funci�n para ingreso y validacion de cadenas. Permite setear una extension m�nima y una maxima. Antes de asignarse en destino, se guarda en un buffer para evitar overflow.
 * checkNum es una funcion filtro que impide que se guarden cadenas que contengan m�s que letras o espacios.
 * \param vec puntero a array de caracteres.
 * \param tam entero largo del array.
 * \param mensaje Mensaje seteable.
 * \param mensajeError mensaje seteable para casos de error.
 * \param minLen entero para setear el largo m�nimo
 * \param maxLen entero para setear el largo m�ximo
 * \return
 */
int ingresarValidarCadena(char *vec, int tam, char mensaje[], char mensajeError[], int minLen, int maxLen)
{
    int todoOk = 0;
    char charBuffer[100];
    if (vec != NULL && tam > 0)
    {
        printf("%s\n", mensaje);
        fflush(stdin);
        scanf("%20[^\n]",charBuffer);
        while (strlen(charBuffer) > maxLen || strlen(charBuffer) < minLen || checkNum(charBuffer) == -1|| charBuffer[0]==' '|| charBuffer[1]==' ')
        {
            printf("%s\n", mensajeError);
            fflush(stdin);
            scanf("%20[^\n]",charBuffer);
        }
        strcpy(vec, charBuffer);
        todoOk = 1;
    }
        return todoOk;
}

/**
 * \brief Funci�n para buscar posiciones libres en un array de estructuras.
 * \param list puntero al array de estructuras.
 * \param len largo del array.
 * \return indice libre en el array
 */
int buscarPosicionLibre(Employee list[], int len)
{
    int todoOk = -1;
    for (int i = 0; i < len; i++)
    {
        if (list[i].isEmpty == 1)
        {
            todoOk = i;
            break;
        }
    }
    return todoOk;
}

/**
 * brief funci�n para ingreso y validacion de floats dentro de un rango. La validaci�n se realiza a trav�s de un loop do while que verifica el retorn de la funci�n scanf.
 * scanf retorna el n�mero de campos correctamente leidos y asignados, en este caso 1 si se ingresa un float.
 *
 * \param pInput puntero a float de destino.
 * \param mensaje Mensaje seteable.
 * \param mensajeError mensaje seteable para casos de error.
 * \param lInf entero para setear el largo m�nimo
 * \param lSup entero para setear el largo m�ximo
 */
void ingresarFlotantesRango(float *pInput, char mensaje[], char mensajeError[], float lInf, float lSup)
{
    float input;
    int intCheck;
    do
    {

        printf("%s\n", mensaje);
        fflush(stdin);
        intCheck = scanf("%f", &input);

        if (intCheck == 0 || input < lInf || input > lSup)
        {
            printf("%s", mensajeError);
        }
    } while (intCheck == 0 || input < lInf || input > lSup);

    *pInput = input;
}

/**
 * \brief funci�n para modificar una instancia de Employee. Selecciona la instancia por id.
 * \param list puntero a Array de Employee.
 * \param len Largo del array.
 * \param id entero para seleccionar el id
 * \return retorna 0 en caso de �xito, -1 en caso de error.
 */

/**
 * \brief funci�n para chequear que una cadena contenga s�lo letras o espacios.
 * \param vec puntero a array de caracteres.
 * \return retorna -1 en caso de error (por ej: se encontr� un n�mero) y 0 en caso de �xito.
 */
int checkNum(char *vec)
{
    int todoOk;
    for (int i = 0; i < strlen(vec); i++)
    {
        if (isalpha(vec[i]) || vec[i] == ' ')
        {
            todoOk = 0;
        }
        else
        {

            todoOk = -1;
            break;
        }
    }

    return todoOk;
}


