#include "Employee.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Employee *employee_new()
{

  Employee *nuevoEmpleado = (Employee *)malloc(sizeof(Employee));

  if (nuevoEmpleado != NULL)
  {
    nuevoEmpleado->id = 0;
    strcpy(nuevoEmpleado->nombre, "");
    nuevoEmpleado->horasTrabajadas = 0;
    nuevoEmpleado->sueldo = 0;
  }
  return nuevoEmpleado;
}
Employee *employee_newParametros(char *idStr, char *nombreStr, char *horasTrabajadasStr, char *sueldoStr)
{

  Employee *nuevoEmpleado = employee_new();
  if (nuevoEmpleado != NULL)
  {
    if (
        !(employee_setId(nuevoEmpleado, atoi(idStr)) &&
          employee_setNombre(nuevoEmpleado, nombreStr) &&
          employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr)) &&
          employee_setSueldo(nuevoEmpleado, atoi(sueldoStr))))
    {

      nuevoEmpleado = NULL;
    }
  }
  return nuevoEmpleado;
}

int employee_setId(Employee *this, int id)
{
  int todoOk = 0;
  if (this != NULL && id > 0)
  {
    this->id = id;
    todoOk = 1;
  }
  return todoOk;
}

int employee_setNombre(Employee *this, char *nombre)
{
  int todoOk = 0;
  if (this != NULL && nombre != NULL && strlen(nombre) > 2 && strlen(nombre) < 20)
  {
    strcpy(this->nombre, nombre);
    todoOk = 1;
  }
  return todoOk;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas)
{
  int todoOk = 0;
  if (this != NULL && horasTrabajadas > 0)
  {
    this->horasTrabajadas = horasTrabajadas;
    todoOk = 1;
  }
  return todoOk;
}

int employee_setSueldo(Employee *this, int sueldo)
{
  int todoOk = 0;
  if (this != NULL && sueldo > 0)
  {
    this->sueldo = sueldo;
    todoOk = 1;
  }
  return todoOk;
}
int employee_getId(Employee *this, int *id)
{
  int todoOk = 0;
  if (this != NULL && id > 0)
  {
    *id = this->id;
    todoOk = 1;
  }
  return todoOk;
}
int employee_getNombre(Employee *this, char *nombre)
{
  int todoOk = 0;
  if (this != NULL && nombre != NULL)
  {
    strcpy(nombre, this->nombre);
    todoOk = 1;
  }
  return todoOk;
}
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas)
{
  int todoOk = 0;
  if (this != NULL && horasTrabajadas > 0)
  {
    *horasTrabajadas = this->horasTrabajadas;
    todoOk = 1;
  }
  return todoOk;
}
int employee_getSueldo(Employee *this, int *sueldo)
{
  int todoOk = 0;
  if (this != NULL && sueldo > 0)
  {
    *sueldo = this->sueldo;
    todoOk = 1;
  }
  return todoOk;
}

/** \brief funcion para mostrar un elemento empleado
 * \param this Employee* puntero a Employe
 * \return todoOk = 1 en caso de exito
 *
 */

void mostrarUnEmpleado(Employee *this)
{

  int auxId;
  char auxNombre[20];
  int auxHoras;
  int auxSueldo;

  if (this != NULL)
  {
    if (employee_getId(this, &auxId) && employee_getNombre(this, auxNombre) && employee_getHorasTrabajadas(this, &auxHoras) && employee_getSueldo(this, &auxSueldo))
    {
      printf("%4d  %10s      %10d     %d  \n", auxId, auxNombre, auxHoras, auxSueldo);
    }
  }
}

int compararSueldo(void *pEmpleadoUno, void *pEmpleadodos)
{
  if (((Employee *)pEmpleadoUno)->sueldo > ((Employee *)pEmpleadodos)->sueldo)
  {
    return 1;
  }
  if (((Employee *)pEmpleadoUno)->sueldo < ((Employee *)pEmpleadodos)->sueldo)
  {
    return -1;
  }
  return 0;
}
int compararHoras(void *pEmpleadoUno, void *pEmpleadodos)
{
  if (((Employee *)pEmpleadoUno)->horasTrabajadas > ((Employee *)pEmpleadodos)->horasTrabajadas)
  {
    return 1;
  }
  if (((Employee *)pEmpleadoUno)->horasTrabajadas < ((Employee *)pEmpleadodos)->horasTrabajadas)
  {
    return -1;
  }
  return 0;
}
int compararId(void *pEmpleadoUno, void *pEmpleadodos)
{
  if (((Employee *)pEmpleadoUno)->id > ((Employee *)pEmpleadodos)->id)
  {
    return 1;
  }
  if (((Employee *)pEmpleadoUno)->id < ((Employee *)pEmpleadodos)->id)
  {
    return -1;
  }
  return 0;
}