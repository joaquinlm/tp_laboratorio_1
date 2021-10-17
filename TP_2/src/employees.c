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
#define QTY_EMPLOYEES 4
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
            if (list[i].id == id)
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
        int idRm = findEmployeeById(list, len, id);
        if (idRm == -1)
        {
            printf("no se encontro el id\n");
        }
        else
        {
            Employee empty;
            list[idRm] = empty;
            list[idRm].isEmpty = 1;
            printf("Baja realizada con exito\n");
        }
        todoOk = 0;
    }

    return todoOk;
}
int printEmployees(Employee *list, int len)
{
    int retorno = -1;
    if (list != NULL && len > 0)
    {
        printf("|  ID  |  Nombre | Apellido |  Salario   | Sector |\n");
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

        printf("|   %-2d | %-7s | %-7s  |  %10.2f|  %5d |\n",
               employee.id,
               employee.name,
               employee.lastName,
               employee.salary,
               employee.sector);
        retorno = 0;
    }

    return retorno;
}
