#include "Employee.h"
#include "LinkedList.h"
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee, int *nextId);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_buscarMayorId(LinkedList *pArrayListEmployee, int* id);
int controller_seleccionarPathCsv(char *pPath);
int controller_seleccionarPathBin(char *pPath);
int controller_findEmployeById(LinkedList* pArrayListEmployee, int id);
LinkedList * controller_filter(LinkedList *pArrayListEmployee);
int controller_filterAndSaveBin(LinkedList *pArrayListEmployee);
int controller_filterAndSaveTxt(LinkedList *pArrayListEmployee);
int controller_ClearLinkedList(LinkedList *pArrayListEmployee);
void mostrarCsvsEnDirectorio();
void mostrarBinsEnDirectorio();
