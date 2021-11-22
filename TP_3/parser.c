#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee)
{
  int retorno = 0;
  Employee *auxEmpleado = NULL;

  char auxId[20];
  char auxNombre[20];
  char auxHoras[20];
  char auxSueldo[20];

  fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHoras, auxSueldo);
  do
  {
    int cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHoras, auxSueldo);
    if (cant < 4)
    {
      break;
    }
    auxEmpleado = employee_newParametros(auxId, auxNombre, auxHoras, auxSueldo);
    if (auxEmpleado != NULL)
    {
      ll_add(pArrayListEmployee, auxEmpleado);
      retorno = 1;
    }

  } while (!feof(pFile));

  return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee)
{
  
  int retorno = 0;
  Employee *auxEmpleado =NULL;

  fread(auxEmpleado, sizeof(Employee), 1, pFile); //lectura fantasma
  if (pArrayListEmployee != NULL && pFile != NULL)
  {
    do
    {
      auxEmpleado = employee_new();
      int cant = fread(auxEmpleado, sizeof(Employee), 1, pFile);
      if (cant != 1)
      {
        break;
      }

      ll_add(pArrayListEmployee, auxEmpleado);
      auxEmpleado = NULL;

    } while (!feof(pFile));
    retorno = 1;
  }
  return retorno;
}
