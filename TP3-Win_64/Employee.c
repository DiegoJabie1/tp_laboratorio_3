#include "Employee.h"
#include "string.h"
#include "LinkedList.h"

Employee* employee_new()
{
    Employee * myEmployee;
    myEmployee = (Employee*) malloc(sizeof(Employee));

    if (myEmployee!=NULL)
    {
        myEmployee->id = 0;
        strcpy(myEmployee->nombre, " ");
        myEmployee->horasTrabajadas = 0;
        myEmployee->sueldo=0;
    }

    return myEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

    int id;
    int sueldo;
    int hours;

    Employee* newEmployee;

    newEmployee=employee_new();

    id=atoi(idStr);
    sueldo=atoi(sueldoStr);
    hours=atoi(horasTrabajadasStr);

    employee_setId(newEmployee,id);
    employee_setNombre(newEmployee, nombreStr);
    employee_setHorasTrabajadas(newEmployee,hours);
    employee_setSueldo(newEmployee,sueldo);

    return newEmployee;

}

void employee_delete(Employee* this)
{
if(this!=NULL)
    {
    free(this);
    }

}

int employee_setId(Employee* this,int id)
{
    int validation=-1;

    if(this!=NULL)
    {
        validation=0;
        this->id=id;
        validation=1;
    }

    return validation;
}

int employee_getId(Employee* this,int* id)
{
    int validation=-1;

    if(this!=NULL)
    {
        validation=0;
        *id=this->id;
        validation=1;
    }

    return validation;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int validation=-1;

    if(this!=NULL)
    {
      validation=0;
      strcpy(this->nombre,nombre);
      validation=1;
    }

    return validation;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int validation=-1;

    if(this!=NULL)
    {
        validation=0;
        strcpy(nombre,this->nombre);
        validation=1;
    }
    return validation;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int validation=-1;

    if(this!=NULL)
    {
        validation=0;
        this->horasTrabajadas=horasTrabajadas;
        validation=1;
    }

    return validation;

}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int validation=-1;
    if(this!=NULL)
    {
        validation=0;
        *horasTrabajadas=this->horasTrabajadas;
        validation=1;
    }

    return validation;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int validation=-1;

    if(this!=NULL)
    {
        validation=0;
        this->sueldo=sueldo;
        validation=1;
    }
    return validation;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int validation=-1;

    if(this!=NULL)
        {
            validation=0;
            *sueldo=this->sueldo;
            validation=1;
        }
    return validation;
}

int sortEmployees(void* employee, void* otherEmployee)
{

    Employee* aux = employee;
    Employee* aux2 = otherEmployee;

    return strcmp(aux->nombre,aux2->nombre);
}
