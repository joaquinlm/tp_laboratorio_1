#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "inputsValidados.h"
#include "menus.h"
#include <string.h>

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee)
{
  int todoOk = 0;
  char confirma;
  FILE *f;

  f = fopen(path, "r");
  if (f == NULL)
  {
    printf("No se pudo abrir el archivo\n");
    if (pArrayListEmployee == NULL)
    {
      printf("null\n");
      system("pause");
    }
  }
  else
  {

    if (ll_len(pArrayListEmployee) > 0)
    {
      printf("Desea sobreescribir los empleados cargados?");
      fflush(stdin);
      scanf("%1c", &confirma);
    }
    if (confirma == 's' || ll_len(pArrayListEmployee) == 0)
    {
      ll_clear(pArrayListEmployee);
      if (pArrayListEmployee == NULL)
      {
        printf("No se pudo leer la lista de empleados\n");
      }
      else if (parser_EmployeeFromText(f, pArrayListEmployee))
      {
        printf("Datos cargados desde el archivo %s\n", path);
        todoOk = 1;
      }
    }
  }
  fclose(f);
  return todoOk;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee)
{
  int todoOk = 0;
  char confirma;
  FILE *f;

  f = fopen(path, "rb");
  if (f == NULL)
  {
    printf("No se pudo abrir el archivo\n");
  }
  else
  {

    if (ll_len(pArrayListEmployee) > 0)
    {
      printf("Desea sobreescribir los empleados cargados?");
      fflush(stdin);
      scanf("%1c", &confirma);
    }
    if (confirma == 's' || ll_len(pArrayListEmployee) == 0)
    {
      ll_clear(pArrayListEmployee);
      if (pArrayListEmployee == NULL)
      {
        printf("No se pudo leer la lista de empleados\n");
      }
      else
      {
        if (parser_EmployeeFromBinary(f, pArrayListEmployee))
        {
          printf("Datos cargados desde el archivo %s\n", path);
          todoOk = 1;
        }
      }
    }
  }
  fclose(f);
  return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee, int *nextId)
{

  int todoOk = 0;
  Employee *auxEmployee = NULL;
  char strAuxId[20];
  char auxNombre[20];
  char strAuxHorasTrabajadas[20];
  char strauxSueldo[20];
  if (pArrayListEmployee != NULL)
  {
    controller_buscarMayorId(pArrayListEmployee, nextId);
    sprintf(strAuxId, "%d", *nextId);

    printf("           ***ALTA DE EMPLEADO***\n\n");
    ingresarValidarCadena(auxNombre, 20, "Ingrese el nombre: ", "Error. Reingrese el nombre (solo caracteres alfabeticos o espacios)\n", 3, 20);
    ingresarEnterosRangoToString("Ingrese las horas: ", "Error\n", 1, 10000, strAuxHorasTrabajadas);
    ingresarEnterosRangoToString("Ingrese el sueldo: ", "Error\n", 1, 500000, strauxSueldo);

    auxEmployee = employee_newParametros(strAuxId, auxNombre, strAuxHorasTrabajadas, strauxSueldo);

    if (auxEmployee != NULL)
    {
      ll_add(pArrayListEmployee, auxEmployee);
      todoOk = 1;
    }
    else
    {
      printf("No se pudo dar de alta\n");
    }
  }

  return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee)
{
  int todoOk = -1;
  int index;
  char auxNuevoNombre[20];
  int auxNuevasHoras;
  int auxNuevoSueldo;
  char confirma;
  Employee *auxEmployee;
  int id;
  controller_ListEmployee(pArrayListEmployee);
  id = ingresarEnterosRango("Ingrese el ID del empleado a modificar:", "Formato no valido, solo se permiten ingresar numeros enteros entre 1 y 5000\n", 1, 5000);
  index = controller_findEmployeById(pArrayListEmployee, id);
  if (index != -1)
  {

    auxEmployee = ll_get(pArrayListEmployee, index);
    printf("  ID      Nombre    Horas trabajadas  Sueldo\n");
    mostrarUnEmpleado(auxEmployee);

    printf("\nconfirma que desea modificar el empleado? s/n");
    fflush(stdin);
    scanf("%1c", &confirma);

    if (confirma == 's')
    {
      int opcion = imprimirOpcionesModificacion();
      if (opcion != 4)
      {
        switch (opcion)
        {
        case 1:
          ingresarValidarCadena(auxNuevoNombre, 20, "Ingrese el  nuevo nombre: ", "Error. Reingrese el nuevo nombre (solo caracteres alfabeticos o espacios)\n", 3, 20);
          if (employee_setNombre(auxEmployee, auxNuevoNombre))
          {
            printf("Nombre modificado con exito\n");
          }
          break;

        case 2:
          auxNuevasHoras = ingresarEnterosRango("Ingrese la nueva cantidad de horas trabajadas: ", "Error\n", 1, 10000);
          if (employee_setHorasTrabajadas(auxEmployee, auxNuevasHoras))
          {
            printf("Horas modificadas con exito\n");
          }
          break;

        case 3:
          auxNuevoSueldo = ingresarEnterosRango("Ingrese el sueldo: ", "Error\n", 1, 500000);
          if (employee_setSueldo(auxEmployee, auxNuevoSueldo))
          {
            printf("Sueldo modificado con exito\n");
          }
          break;
        }
        auxEmployee = ll_get(pArrayListEmployee, index);
        printf("  ID      Nombre    Horas trabajadas  Sueldo\n");
        mostrarUnEmpleado(auxEmployee);
      }
    }
    todoOk = 1;
  }

  return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee)
{
  int todoOk = -1;
  int index;
  char confirma;
  Employee *auxEmployee;
  if (pArrayListEmployee != NULL)
  {
    system("cls");
    int id;
    controller_ListEmployee(pArrayListEmployee);
    id = ingresarEnterosRango("Ingrese el ID del empleado a dar de baja:", "Formato no valido, solo se permiten ingresar numeros enteros entre 1 y 5000\n", 1, 5000);
    index = controller_findEmployeById(pArrayListEmployee, id);
    if (index != -1)
    {

      auxEmployee = ll_get(pArrayListEmployee, index);
      printf("  ID      Nombre    Horas trabajadas  Sueldo\n");
      mostrarUnEmpleado(auxEmployee);

      printf("\nconfirma que desea dar de baja al empleado? s/n");
      fflush(stdin);
      scanf("%1c", &confirma);

      if (confirma == 's')
      {
        if (ll_remove(pArrayListEmployee, index) == 0)
        {
          printf("Baja realizada con exito\n");
        }
        else
        {
          printf("No se pudo realizar la baja\n");
        }
      }
    }
    todoOk = 1;
  }
  return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee)
{
  int retorno = -1;
  Employee *auxEmployeePuntero = NULL;
  if (pArrayListEmployee != NULL)
  {
    system("cls");
    printf("           ***NOMINA DE EMPLEADOS***\n");
    printf("  ID      Nombre    Horas trabajadas  Sueldo\n");
    for (int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
      auxEmployeePuntero = (Employee *)ll_get(pArrayListEmployee, i);
      mostrarUnEmpleado(auxEmployeePuntero);
      auxEmployeePuntero = NULL;
    }
    printf("\n");
    retorno = 0;
  }
  return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee)
{
  int todoOk = 0;
  int opcion = imprimirMenuOrdenamiento();
  if (pArrayListEmployee != NULL)
  {
    if (opcion != 7)
    {
      switch (opcion)
      {

      case 1:
        ll_sort(pArrayListEmployee, compararId, 1);
        break;
      case 2:
        ll_sort(pArrayListEmployee, compararId, 0);
        break;
      case 3:
        ll_sort(pArrayListEmployee, compararHoras, 1);
        break;
      case 4:
        ll_sort(pArrayListEmployee, compararHoras, 0);
        break;
      case 5:
        ll_sort(pArrayListEmployee, compararSueldo, 1);
        break;
      case 6:
        ll_sort(pArrayListEmployee, compararSueldo, 0);
        break;
      }
      todoOk = 1;
    }
  }
  return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee)
{
  int todoOk = 0;
  char confirma;
  Employee *auxEmployee = NULL;
  FILE *f;

  if (pArrayListEmployee != NULL)
  {
    if ((f = fopen(path, "r")))      
    {
      fclose(f); // cierro el archivo que se abrio al evaluar en el  if
      printf("El archivo ya existe. Desea sobreescribirlo?\n");
      fflush(stdin);
      scanf("%1c", &confirma);
      printf("%c confirmaste", confirma);
    }

    if (!(f = fopen(path, "r")) || confirma == 's')
    {
      fclose(f); // cierro el archivo que se abrio al evaluar en el  if
      f = fopen(path, "w");
      if (f == NULL)
      {
        printf("No se pudo abrir el archivo\n");
        if (pArrayListEmployee == NULL)
        {
          printf("No se pudo cargar la lista de empleados\n");
          system("pause");
        }
      }
      else
      {
        fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");
        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
          auxEmployee = ll_get(pArrayListEmployee, i);
          if (auxEmployee != NULL)
          {
            fprintf(f, "%d,%s,%d,%d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
            auxEmployee = NULL;
          }
        }
        printf("Se guardaron los datos en el archivo %s\n", path);
      }
      fclose(f);
      todoOk = 1;
    }
  }
  return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee)
{
  int todoOk = 0;
  char confirma;
  Employee *auxEmployee;
  FILE *f;
  if (path != NULL && pArrayListEmployee != NULL)
  {
    if ((f = fopen(path, "rb")))
    {
      fclose(f); // cierro el archivo que se abrio al evaluar en el if
      printf("El archivo ya existe. Desea sobreescribirlo?\n");
      fflush(stdin);
      scanf("%1c", &confirma);
    }

    if (!(f = fopen(path, "rb")) || confirma == 's')
    {
      fclose(f); // cierro el archivo que se abrio al evaluar en el  if
      f = fopen(path, "wb");
      if (f == NULL)
      {
        printf("No se pudo abrir el archivo\n");
        if (pArrayListEmployee == NULL)
        {
          printf("No se pudo cargar la lista de empleados\n");
          system("pause");
        }
      }
      else
      {
        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
          auxEmployee = ll_get(pArrayListEmployee, i);
          if (auxEmployee != NULL)
          {
            fwrite(auxEmployee, sizeof(Employee), 1, f);
            auxEmployee = NULL;
          }
          /* code */
        }
        printf("Se guardaron los datos en el archivo %s\n", path);
      }
    }
    fclose(f);
    todoOk = 1;
  }
  return todoOk;
}

/** \brief Busca el id mas alto
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int*
 * \return int
 *
 */
int controller_buscarMayorId(LinkedList *pArrayListEmployee, int *id)
{
  int retorno = -1;
  Employee *auxEmployeePuntero = NULL;
  int idMayor = *id;
  if (pArrayListEmployee != NULL)
  {
    if (ll_len(pArrayListEmployee) == 0)
    {
      *id = *id;
    }
    else
    {
      for (int i = 0; i < ll_len(pArrayListEmployee); i++)
      {

        auxEmployeePuntero = (Employee *)ll_get(pArrayListEmployee, i);
        if (auxEmployeePuntero->id > idMayor)
        {
          idMayor = auxEmployeePuntero->id;
        }
      }
      *id = idMayor + 1;
    }
    retorno = 1;
  }
  return retorno;
}
/** \brief funcion para cargar la cadena que se pasa como parametro a las funciones de apertura de archivo. 
 * Verifica que la extension de archivo solo pueda ser .csv
 * \param pPath char*
 * \return todoOk = 1 en caso de exito
 *
 */

int controller_seleccionarPathCsv(char *pPath)
{
  int todoOk = 0;
  if (pPath != NULL)
  {
    char auxExt[4];
    printf("Ingrese el nombre de archivo: ");
    fflush(stdin);
    scanf("%20[a-zA-Z0-9]%[.csv]", pPath, auxExt);
    if (strcmp(auxExt, ".csv") != 0)
    {
      printf("extension de archivo incorrecta. Solo se admiten archivos .csv\n");
    }
    else
    {
      strcat(pPath, auxExt);
      todoOk = 1;
    }
  }
  return todoOk;
}
/** \brief funcion para cargar la cadena que se pasa como parametro a las funciones de apertura de archivo. 
 * Verifica que la extension de archivo solo pueda ser .bin
 * \param pPath char*
 * \return todoOk = 1 en caso de exito
 *
 */

int controller_seleccionarPathBin(char *pPath)
{
  int todoOk = 0;
  if (pPath != NULL)
  {
    printf("Ingrese el nombre de archivo: ");
    fflush(stdin);
    char auxExt[4];
    scanf("%20[a-zA-Z0-9]%[.bin]", pPath, auxExt);
    if (strcmp(auxExt, ".bin") != 0)
    {
      printf("extension de archivo incorrecta. Solo se admiten archivos .bin\n");
    }
    else
    {
      strcat(pPath, auxExt);
      todoOk = 1;
    }
  }
  return todoOk;
}

/** \brief busca un nodo de la linked list usando como criterio de busqueda el Id
 *
 * \param id id
 * \param pArrayListEmployee LinkedList*
 * \return index int indice del nodo que coincide con la busqueda en el caso de encontrarlo o -1 en caso
 *  contrario
 *
 */
int controller_findEmployeById(LinkedList *pArrayListEmployee, int id)
{
  int index = -1;
  int idCheck;
  Employee *auxEmployee = NULL;
  if (pArrayListEmployee != NULL)
  {

    for (int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
      auxEmployee = ll_get(pArrayListEmployee, i);
      employee_getId(auxEmployee, &idCheck);

      if (auxEmployee != NULL && idCheck == id)
      {
        index = i;
        break;
      }
    }
    if (index == -1)
    {
      printf("No se encontro el ID\n");
    }
  }
  return index;
}
