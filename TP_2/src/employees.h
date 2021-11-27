/*
 * employees.h
 *
 *  Created on: 16 oct. 2021
 *      Author: joq
 */

#ifndef EMPLOYEES_H_
#define EMPLOYEES_H_

typedef struct
{
    int id;
    char name[21];
    char lastName[21];
    float salary;
    int sector;
    int isEmpty;
} Employee;

int initEmployees(Employee *list, int len);
int findEmployeeById(Employee *list, int len, int id);
int printOneEmployee(Employee employee, int len);
int printEmployees(Employee *list, int len);
int addEmployee(Employee *list, int len, int id, char name[], char lastName[], float salary, int sector);
int removeEmployee(Employee *list, int len, int id);
int modificarEmpleado(Employee *list, int len, int id);
int calculosSalariales(Employee list[], int len, int contadorEmpleados);





int sortEmployees(Employee *list, int len, int order);



#endif /* EMPLOYEES_H_ */
