/**
 * TP Nro 2
 *
 * \author Joaquín Lubo Millán | Division G - segundo cuatrimestre 2021
 * *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "employees.h"
#include "inputs_validados.h"
#define QTY_EMPLOYEES 1000
#define ASC 1
#define DESC 0

int main()
{
	setbuf (stdout, NULL);
    int contadorIds = 0;
    int contadorEmpleados = 0;

    Employee list[QTY_EMPLOYEES];
    initEmployees(list, QTY_EMPLOYEES);
    //Employee auxEmployee;
    char nameBuffer[21];
    char lastNameBuffer[21];
    int idBuffer = contadorIds++;
    float salaryBuffer;
    int sectorBuffer;
    char sigue = 's';

    do
    {
        int opcion = imprimirMenu();
        /**
         * switch para acceder a las distintas opciones del programa. Las opciones de modificación, baja y listado, están restringidas si el contador de empleados se encuentra en cero.
         */
        switch (opcion)
        {

        case 1:;
            int i;
            i = buscarPosicionLibre(list, QTY_EMPLOYEES);

            if (i >= 0 && i < QTY_EMPLOYEES)
            {
                ingresarValidarCadena(nameBuffer, 21, "Ingrese el nombre", "Error. Reingrese el nombre", 3, 21);
                ingresarValidarCadena(lastNameBuffer, 21, "Ingrese el apellido", "Error. Reingrese el apellido", 3, 21);
                ingresarFlotantesRango(&salaryBuffer, "Ingrese el salario", "Error\n", 0.1, 1000000);
                ingresarEnterosRango(&sectorBuffer, "Ingrese el sector", "Error\n", 1, 5);
                idBuffer = contadorIds++;

                addEmployee(list, QTY_EMPLOYEES, idBuffer, nameBuffer, lastNameBuffer, salaryBuffer, sectorBuffer);
                contadorEmpleados++;
                opcion = 0;
                break;
            }
            else
            {
                printf("Error, no hay posiciones libres\n");
            }
            opcion = 0;
            break;

        case 2:;
            if (contadorEmpleados == 0)
            {
                printf("No hay empleados que modificar.\n");
                opcion = 0;
                break;
            }
            int idMd;
            ingresarEnterosRango(&idMd, "ingrese el id del empleado a modificar", "Error\n", 1, QTY_EMPLOYEES);
            modificarEmpleado(list, QTY_EMPLOYEES, idMd);
            opcion = 0;
            break;

        case 3:;
            if (contadorEmpleados == 0)
            {
                printf("No hay empleados que dar de baja.\n");
                opcion = 0;
                break;
            }
            int idRm;
            ingresarEnterosRango(&idRm, "ingrese el numero de id\n", "Error\n", 0, INT_MAX);
            removeEmployee(list, QTY_EMPLOYEES, idRm);
            contadorEmpleados--;
            opcion = 0;
            break;

        case 4:
            if (contadorEmpleados == 0)
            {
                printf("No hay empleados que listar.\n");
                opcion = 0;
                break;
            }
            sortEmployees(list, QTY_EMPLOYEES, ASC);
            printEmployees(list, QTY_EMPLOYEES);
            calculosSalariales(list, QTY_EMPLOYEES, contadorEmpleados);
            /*   sortEmployees(list, QTY_EMPLOYEES, DESC);
              printEmployees(list, QTY_EMPLOYEES); */
            opcion = 0;
            break;

        case 5:
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

    return 0;
}
