#include <stdlib.h>
#include <stdio.h>
#include "inputsValidados.h"
#include "menus.h"

int imprimirMenuPrincipal()
{
  system("cls");
  int opcion;
  printf("                         ****MENU PRINCIPAL****                             \n\n");
  printf("1. Cargar los datos de los empleados desde un archivo .csv (modo texto).\n");
  printf("2. Cargar los datos de los empleados desde un archivo .bin (modo binario).\n");
  printf("3. Alta de empleado\n");
  printf("4. Modificar datos de empleado\n");
  printf("5. Baja de empleado\n");
  printf("6. Listar empleados\n");
  printf("7. Ordenar empleados\n");
  printf("8. Guardar los datos de los empleados en un archivo .csv (modo texto).\n");
  printf("9. Guardar los datos de los empleados en un archivo .bin (modo binario).\n");
  printf("10. Salir\n\n");
  opcion = ingresarEnterosRango("Seleccione una opcion\n", "Error. El rango valido de opciones es: 1-10\n", 1, 10);

  return opcion;
}

/** \brief Imprime el menu con las opciones para modificar empleados
 * \return opcion int para usar con el case dentro de la funcion controller_editEmployee
 *
 */

 int imprimirOpcionesModificacion() 
{
  printf("1-Modificar nombre\n");
  printf("2-Modificar horas trabajadas\n");
  printf("3-Modificar sueldo\n");
  printf("4-Cancelar\n");
  int opcion = ingresarEnterosRango("Seleccione una opcion\n", "Error. El rango valido de opciones es: 1-4\n", 1, 4);

  return opcion;
}

/** \brief Imprime el menu con las opciones para ordenar empleados
 * \return opcion int para usar con el case dentro de la funcion controller_sortEmployee
 *
 */
int imprimirMenuOrdenamiento()
{
  system("cls");
  printf("                         ****MENU DE ORDENAMIENTO****                             \n\n");
  printf("1-Ordenar por ID ascendente\n");
  printf("2-Ordenar por ID descendente\n\n");
  printf("3-Ordenar por horas trabajadas ascendente\n");
  printf("4-Ordenar por horas trabajadas descendente\n\n");
  printf("5-Ordenar por sueldo ascendente\n");
  printf("6-Ordenar por sueldo descendente\n\n");  
  printf("7-Cancelar\n");
  int opcion = ingresarEnterosRango("Seleccione una opcion\n", "Error. El rango valido de opciones es: 1-7\n", 1, 7);

  return opcion;
}