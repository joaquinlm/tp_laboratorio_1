
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void mostrarUnEmpleado(Employee* this);

int compararSueldo(void *pEmpleadoUno, void *pEmpleadodos);
int compararHoras(void *pEmpleadoUno, void *pEmpleadodos);
int compararId(void *pEmpleadoUno, void *pEmpleadodos);

int filterIdUpTo500(void * e);
int filterIdOver500(void * e);
int filterHoursUpTo160(void * e);
int filterHoursOver160(void * e);
int filterSalaryUpTo25000(void * e);
int filterSalaryOver25000(void * e);

#endif // employee_H_INCLUDED
