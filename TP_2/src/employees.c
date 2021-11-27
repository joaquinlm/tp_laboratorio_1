/*
 * employees.c
 *
 *  Created on: 16 oct. 2021
 *      Author: joq
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "employees.h"
#include "inputs_validados.h"
#include "menu.h"
#define QTY_EMPLOYEES 1000
#define ASC 1
#define DESC 0

int initEmployees(Employee *list, int len)
{
    int retorno = -1;
    if (list != NULL && len > 0)
    {
        for (int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}

int addEmployee(Employee *list, int len, int id, char *name, char lastName[], float salary, int sector)
{
    int todoOk = -1;
    int i;
    i = buscarPosicionLibre(list, QTY_EMPLOYEES);
    if (list != NULL && len >= 0)
    {
        strcpy(list[i].name, name);
        strcpy(list[i].lastName, lastName);
        list[i].id = id;
        list[i].sector = sector;
        list[i].salary = salary;
        list[i].isEmpty = 0;
        todoOk = 0;
    }

    return todoOk;
}
int findEmployeeById(Employee *list, int len, int id)
{
    int retorno = -1;
    if (list != NULL && len > 0)
    {
        for (int i = 0; i < len; i++)
        {

            if (list[i].id == id && list[i].isEmpty == 0)
            {
                retorno = i;

                break;
            }
        }
    }
    return retorno;
}
int sortEmployees(Employee *list, int len, int order)
{
    int todoOk = -1;
    Employee auxEmployeeContainer;
    if (list != NULL && len > 0)
    {
        if (order == 1)
        {
            for (int i = 0; i < len - 1; i++)
            {
                for (int j = i + 1; j < len; j++)
                {

                    if (((list[i].sector == list[j].sector) && strcmp(list[i].lastName, list[j].lastName) > 0) || list[i].sector > list[j].sector)
                    {
                        auxEmployeeContainer = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployeeContainer;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < len - 1; i++)
            {
                for (int j = i + 1; j < len; j++)
                {

                    if (((list[i].sector == list[j].sector) && strcmp(list[i].lastName, list[j].lastName) < 0) || list[i].sector < list[j].sector)
                    {
                        auxEmployeeContainer = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployeeContainer;
                    }
                }
            }
        }

        todoOk = 0;
    }

    return todoOk;
}

int removeEmployee(Employee *list, int len, int id)
{
    int todoOk = -1;
    int idRm;
    if (list != NULL && len > 0)
    {
        idRm = findEmployeeById(list, len, id);
        if (idRm == -1)
        {
            printf("no se encontro el id\n");

            todoOk = 1;
        }
        else
        {
            Employee empty;
            list[idRm] = empty;
            list[idRm].isEmpty = 1;
            printf("Baja realizada con exito\n");
            todoOk = 0;
        }
    }

    return todoOk;
}
int printEmployees(Employee *list, int len)
{
    int retorno = -1;
    if (list != NULL && len > 0)
    {
        printf("|  ID  |        Nombre        |      Apellido         |  Salario     |   Sector |\n");
        for (int i = 0; i < len; i++)
        {
            if (list[i].isEmpty == 0)
            {
                printOneEmployee(list[i], len);
            }
        }
        retorno = 0;
    }
    return retorno;
}
int printOneEmployee(Employee employee, int len)
{
    int retorno = -1;

    if (employee.isEmpty == 0)
    {

        printf("|   %-2d | %-20s | %-20s  |  %10.2f|  %5d |\n",
               employee.id,
               employee.name,
               employee.lastName,
               employee.salary,
               employee.sector);
        retorno = 0;
    }

    return retorno;
}

int modificarEmpleado(Employee *list, int len, int id)
{
    int todoOk = -1;
    int idMd = 0;
    if (list != NULL && len > 0)
    {
        idMd = findEmployeeById(list, len, id);
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
            char confirma;

            printf("\nconfirma que desea modificar el empleado? s/n");
            fflush(stdin);
            scanf("%1c", &confirma);

            if (confirma == 's')
            {
                int opcion = imprimirOpcionesModificacion();
                if (opcion != 5)
                {
                    switch (opcion)
                    {
                    case 1:
                        ingresarValidarCadena(nameBuffer, 21, "Ingrese el nuevo nombre (solo letras o espacios)", "Error. Reingrese el nuevo nombre (solo letras o espacios)", 3, 21);
                        strcpy(list[idMd].name, nameBuffer);
                        break;

                    case 2:
                        ingresarValidarCadena(lastNameBuffer, 21, "Ingrese el nuevo apellido (solo letras o espacios)", "Error. Reingrese el nuevo apellido (solo letras o espacios)", 3, 21);
                        strcpy(list[idMd].lastName, lastNameBuffer);
                        break;

                    case 3:
                        ingresarFlotantesRango(&salaryBuffer, "Ingrese el nuevo salario: entre 1000 y 100000", "Error, reingrese el nuevo salario: entre 1000 y 100000", 0.1, 100000);

                        list[idMd].salary = salaryBuffer;

                        break;
                    case 4:
                        ingresarEnterosRango(&sectorBuffer, "Ingrese el nuevo sector: entre 1 y 5", "Error, reingrese el nuevo sector: entre 1 y 5", 1, 5);

                        list[idMd].sector = sectorBuffer;

                        break;
                    }
                    printf("Modificacion realizada con exito\n");
                }
                else{
                    printf("Modificacion cancelada por el usuario\n");
                }
            }
        }
        todoOk = 0;
    }

    return todoOk;
}

/**
 * \brief funci�n para calcular el monto total de sueldos, el sueldo promedio y cu�ntos empleados cobran por encima del promedio.
 * \param list puntero a array de Employee.
 * \param len largo del vector
 * \param contadorEmpleados entero que recibe por valor desde main la cantidad de empleados al momento de la ejecuci�n. Se utiliza para calcular el promedio y la cantidad de empleados cobrando por encima del mismo.
 * \return retorna 0 en caso de �xito y -1 en caso de error(vector NULL).
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
