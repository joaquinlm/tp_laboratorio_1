
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menus.h"
#include "parser.h"
// test
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main()
{
  setbuf(stdout, NULL);
  char path[50];
  char sigue = 's';
  LinkedList *listaEmpleados = ll_newLinkedList();
  int nextId = 1;

  if (listaEmpleados == NULL)
  {
    printf("No se pudo inicializar correctamente el programa (ll == NULL)");
    system("pause");
    exit(1);
  }
  do
  {
    int option = imprimirMenuPrincipal();
    switch (option)
    {
    case 1:
      if (controller_seleccionarPathCsv(path))
      {
        controller_loadFromText(path, listaEmpleados);
        //   controller_buscarMayorId(listaEmpleados, &nextId);
      }
      break;

    case 2:
      if (controller_seleccionarPathBin(path))
      {
        controller_loadFromBinary(path, listaEmpleados);
        //   controller_buscarMayorId(listaEmpleados, &nextId);
      }
      break;

    case 3:
      controller_addEmployee(listaEmpleados, &nextId);
      break;

    case 4:
      if (ll_len(listaEmpleados) == 0)
      {
        printf("No hay empleados para modificar\n");
      }
      else
      {
        controller_editEmployee(listaEmpleados);
      }
      break;

    case 5:
      if (ll_len(listaEmpleados) == 0)
      {
        printf("No hay empleados para dar de baja\n");
      }
      else
      {
        controller_removeEmployee(listaEmpleados);
      }
      break;

    case 6:
      if (ll_len(listaEmpleados) == 0)
      {
        printf("No hay empleados para mostrar\n");
      }
      else if(listaEmpleados!=NULL)
      {
        controller_ListEmployee(listaEmpleados);
      }
      break;

    case 7:
      if (ll_len(listaEmpleados) < 2)
      {
        printf("No hay suficientes empleados para ordenar\n");
      }
      else
      {
        controller_sortEmployee(listaEmpleados);
      }
      break;

    case 8:
      if (ll_len(listaEmpleados) < 2)
      {
        printf("No hay suficientes empleados para filtrar\n");
      }
      else
      {

        listaEmpleados = controller_filter(listaEmpleados);
      }
      break;
    case 9:
      if (ll_len(listaEmpleados) < 2)
      {
        printf("No hay suficientes empleados para filtrar\n");
      }
      else
      {
        controller_filterAndSaveTxt(listaEmpleados);
      }
      break;
    case 10:
      if (ll_len(listaEmpleados) < 2)
      {
        printf("No hay suficientes empleados para filtrar\n");
      }
      else
      {
        controller_filterAndSaveBin(listaEmpleados);
      }
      break;

    case 11:
      if (controller_seleccionarPathCsv(path))
      {
        controller_saveAsText(path, listaEmpleados);
      }
      break;

    case 12:
      if (controller_seleccionarPathBin(path))
      {
        controller_saveAsBinary(path, listaEmpleados);
      }
      break;

    case 13:
      controller_ClearLinkedList(listaEmpleados);
      break;

    case 14:;
      char sale;
      printf("Se perderan los cambios no guardados. Confirma que desea salir? s/n\n");
      fflush(stdin);
      scanf("%c", &sale);
      if (sale != 's')
      {
        printf("Cierre cancelado\n");

        break;
      }
      else
      {
        printf("Ha seleccionado salir.\n");
        sigue = 'n';
        break;
      }

    default:
      printf("Opcion incorrecta\n");

      break;
    }
    fflush(stdin);
    system("pause");
  } while (sigue == 's');

  return 0;
}
