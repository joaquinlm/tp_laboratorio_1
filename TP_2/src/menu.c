/*
 * menu.c
 *
 *  Created on: 25 nov. 2021
 *      Author: joq
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "inputs_validados.h"

/**
 * \brief Funci�n encargada de imprimir el menu de opciones en pantalla.
 * \return retorna un entero para uso en el switch de main,
 */
int imprimirMenu()
{
    int seleccion;
    system("cls");

    printf("MENU DE OPCIONESss\n\n");
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

/** \brief Imprime el menu con las opciones para modificar empleados
 * \return opcion int para usar con el case dentro de la funcion controller_editEmployee
 *
 */

 int imprimirOpcionesModificacion() 
{
  printf("1-Modificar nombre\n");
  printf("2-Modificar apellido\n");
  printf("3-Modificar salario\n");
  printf("4-Modificar sector\n");
  printf("5-Cancelar\n");
  int opcion;
  ingresarEnterosRango(& opcion, "Seleccione una opcion\n", "Error. El rango valido de opciones es: 1-5\n", 1, 5);

  return opcion;
}