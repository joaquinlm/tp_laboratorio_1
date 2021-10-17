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
 * \brief función para ingreso y validacion de enteros dentro de un rango. La validación se realiza a través de un loop do while que verifica el retorn de la función scanf.
 * scanf retorna el número de campos correctamente leidos y asignados, en este caso 1 si se ingresa un entero.
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
 \brief función para ingreso y validacion de cadenas. Permite setear una extension mínima y una maxima. Antes de asignarse en destino, se guarda en un buffer para evitar overflow.
 * checkNum es una funcion filtro que impide que se guarden cadenas que contengan más que letras o espacios.
 * \param vec puntero a array de caracteres.
 * \param tam entero largo del array.
 * \param mensaje Mensaje seteable.
 * \param mensajeError mensaje seteable para casos de error.
 * \param minLen entero para setear el largo mínimo
 * \param maxLen entero para setear el largo máximo
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
        gets(charBuffer);
        while (strlen(charBuffer) > maxLen || strlen(charBuffer) < minLen || checkNum(charBuffer) == -1)
        {
            printf("%s\n", mensajeError);
            fflush(stdin);
            gets(charBuffer);
        }
        strcpy(vec, charBuffer);
        todoOk = 1;
    }
        return todoOk;
}
/**
 * \brief Función encargada de imprimir el menu de opciones en pantalla.
 * \return retorna un entero para uso en el switch de main,
 */
int imprimirMenu()
{
    int seleccion;
    system("cls");

    printf("MENU DE OPCIONES\n\n");
    printf("1. Alta de empleado\n");
    printf("2. Modificacion de empleado\n");
    printf("3. Baja de empleado\n");
    printf("4. Imprimir nomina de empleados\n");
    printf("5. Salir\n");
    printf("Indique la opcion: ");
    fflush(stdin);
    ingresarEnterosRango(&seleccion, "", "Error ingrese una opcion entre 1 y 5 ", 1, 5);
    return seleccion;
}
/**
 * \brief Función para buscar posiciones libres en un array de estructuras.
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
 * brief función para ingreso y validacion de floats dentro de un rango. La validación se realiza a través de un loop do while que verifica el retorn de la función scanf.
 * scanf retorna el número de campos correctamente leidos y asignados, en este caso 1 si se ingresa un float.
 *
 * \param pInput puntero a float de destino.
 * \param mensaje Mensaje seteable.
 * \param mensajeError mensaje seteable para casos de error.
 * \param lInf entero para setear el largo mínimo
 * \param lSup entero para setear el largo máximo
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
 * \brief función para modificar una instancia de Employee. Selecciona la instancia por id.
 * \param list puntero a Array de Employee.
 * \param len Largo del array.
 * \param id entero para seleccionar el id
 * \return retorna 0 en caso de éxito, -1 en caso de error.
 */
int modificarEmpleado(Employee *list, int len, int id)
{
    int todoOk = -1;
    int idMd = 0;
    if (list != NULL && len > 0)
    {
        int idMd = findEmployeeById(list, len, id);
        if (idMd == -1)
        {
            printf("no se encontro el ID\n");
        }
        else
        {
            char nameBuffer[21];
            char lastNameBuffer[21];
            float salaryBuffer;
            int sectorBuffer;

            ingresarValidarCadena(nameBuffer, 21, "Ingrese el nuevo nombre", "Error. Reingrese el nuevo nombre", 3, 21);
            ingresarValidarCadena(lastNameBuffer, 21, "Ingrese el nuevo apellido", "Error. Reingrese el nuevo apellido", 3, 21);
            ingresarFlotantesRango(&salaryBuffer, "Ingrese el nuevo salario", "Error, reingrese el nuevo salario", 0.1, 1000000);
            ingresarEnterosRango(&sectorBuffer, "Ingrese el nuevo sector", "Error, reingrese el nuevo sector", 1, 5);
            strcpy(list[idMd].name, nameBuffer);
            strcpy(list[idMd].lastName, lastNameBuffer);
            list[idMd].salary = salaryBuffer;
            list[idMd].sector = sectorBuffer;

            printf("Modificacion realizada con exito\n");
        }
        todoOk = 0;
    }


    return todoOk;
}
/**
 * \brief función para chequear que una cadena contenga sólo letras o espacios.
 * \param vec puntero a array de caracteres.
 * \return retorna -1 en caso de error (por ej: se encontró un número) y 0 en caso de éxito.
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

/**
 * \brief función para calcular el monto total de sueldos, el sueldo promedio y cuántos empleados cobran por encima del promedio.
 * \param list puntero a array de Employee.
 * \param len largo del vector
 * \param contadorEmpleados entero que recibe por valor desde main la cantidad de empleados al momento de la ejecución. Se utiliza para calcular el promedio y la cantidad de empleados cobrando por encima del mismo.
 * \return retorna 0 en caso de éxito y -1 en caso de error(vector NULL).
 */
int calculosSalariales(Employee *list, int len, int contadorEmpleados)
{

    int todoOk = -1;
    int empleadosSalarioArribaMedia = 0;
    float totalSalarios = 0;
    float promedioSalarios = 0;
    if (list != NULL && len > 0)
    {

        for (int i = 0; i < len; i++)
        {
            if (list[i].isEmpty == 0)
            {
                totalSalarios += list[i].salary;
            }
        }
        promedioSalarios = totalSalarios / contadorEmpleados;
        for (int i = 0; i < len; i++)
        {
            if (list[i].salary > promedioSalarios && list[i].isEmpty == 0)
            {
                empleadosSalarioArribaMedia++;
            }
        }
        printf("El monto total de salarios es de: %.2f \n", totalSalarios);
        if (contadorEmpleados > 1)
        {
            printf("El salario promedio es de: %.2f \n", promedioSalarios);
            printf("Un total de %d empleado/s cobra/n un sueldo por encima del promedio\n", empleadosSalarioArribaMedia);
        }
        else
        {
            printf("No se puede calcular el promedio, hay un solo empleado\n");
        }

        todoOk = 0;
    }

    return todoOk;
}
