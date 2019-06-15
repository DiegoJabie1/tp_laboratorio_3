#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* archivo donde se guardan los datos
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si no pudo cargar los datos, 1 si funciono correctamente
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int returnAux;

    returnAux=parser_EmployeeFromText(path,pArrayListEmployee);

    return returnAux;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* archivo donde se guardan los datos
 * \param pArrayListEmployee LinkedList*
 * \return int int 0 si no pudo cargar los datos, 1 si funciono correctamente
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int returnAux=0;

    returnAux=parser_EmployeeFromBinary(path,pArrayListEmployee);

    return returnAux;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int idMax=-1;
    int flag=0;
    int returnAux=0;
    char auxName[128];
    int auxSalary;
    int auxHours;

    system("cls");
    printf("---MENU DE ALTA--\n\n");
    Employee* newEmployee=employee_new();
    Employee* aux;

    pedirCadena("nombre: ",auxName,128);
    primerLetraMayuscula(auxName);
    employee_setNombre(newEmployee,auxName);

    auxSalary=pedirEntero("sueldo: $",0,1215752190);
    employee_setSueldo(newEmployee,auxSalary);

    auxHours=pedirEntero("horas trabajadas: ",1,730);
    employee_setHorasTrabajadas(newEmployee,auxHours);

    for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            aux=ll_get(pArrayListEmployee,i);

            if(flag==0||aux->id>idMax)
                {
                    idMax=aux->id;
                }
        }

    employee_setId(newEmployee,aux->id+1);
    ll_add(pArrayListEmployee,newEmployee);

    returnAux=1;

    return returnAux;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    char auxNombre[128];
    int auxEntero;
    int flag=0;
    int index;
    int opcion;
    int opcionModificar;
    int i;

    system("cls");
    printf("--------------------MENU DE MODIFICACION---------------------\n");

    controller_ListEmployee(pArrayListEmployee);

    printf("\n\nIngrese ID del empleado a modificar: ");
    scanf("%d",&id);

    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        Employee* aux;
        aux=ll_get(pArrayListEmployee,i);
        if((id==aux->id))
        {
            flag=1;
            index=i;
            break;
        }
    }

    if(flag==0)
    {
        printf("\nNo se ha encontrado empleado con tal ID.\n\n");
        system("pause");
        system("cls");

    }
    else
    {
        printf("\nEmpleado con ID: %d\n1.Modificar nombre.\n2.Modificar horas trabajadas\n3.Modificar sueldo.\n",id);
        opcion=pedirEntero(":",1,3);

        Employee* aux;
        if(opcion==1)
        {
            pedirCadena("nuevo nombre:",auxNombre,50);
            printf("\nDESEA MODIFICAR:\n1.SI.\n2.NO\n");
            opcionModificar=pedirEntero(":",1,2);

            if(opcionModificar==1)
            {
                aux=ll_get(pArrayListEmployee,index);
                strcpy(aux->nombre,auxNombre);
                primerLetraMayuscula(aux->nombre);
                system("cls");
                printf("\n\n:::::::::::::::::::::::\nSE MODIFICO CON EXITO\n:::::::::::::::::::::::\n\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("\n\n:::::::::::::::::::::::\nSE CANCELO LA MODIFICACION\n:::::::::::::::::::::::\n\n");
                system("pause");
            }


        }
        else if(opcion==2)
        {
            aux=ll_get(pArrayListEmployee,index);

            printf("Ingrese nuevo sueldo:");

            scanf("%d",&auxEntero);
            printf("\nDESEA MODIFICAR:\n1.SI.\n2.NO\n");
            opcionModificar=pedirEntero(":",1,2);

            if(opcionModificar==1)
            {
                aux->sueldo=auxEntero;
                system("cls");
                printf("\n\n:::::::::::::::::::::::\nSE MODIFICO CON EXITO\n:::::::::::::::::::::::\n\n");
                system("pause");
            }
            else
            {

                system("cls");
                printf("\n\n:::::::::::::::::::::::\nSE CANCELO LA MODIFICACION\n:::::::::::::::::::::::\n\n");
                system("pause");
            }

        }
        else
        {
            aux=ll_get(pArrayListEmployee,index);

            printf("Ingrese nuevas horas trabajadas:");

            scanf("%d",&auxEntero);

            printf("\nDESEA MODIFICAR:\n1.SI.\n2.NO\n");

            opcionModificar=pedirEntero(":",1,2);

            if(opcionModificar==1)
            {
                aux->horasTrabajadas=auxEntero;

                system("cls");
                printf("\n\n:::::::::::::::::::::::\nSE MODIFICO CON EXITO\n:::::::::::::::::::::::\n\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("\n\n:::::::::::::::::::::::\nSE CANCELO LA MODIFICACION\n:::::::::::::::::::::::n\n");
                system("pause");
            }
        }
    }

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int flag=0;
    int index;
    int opcion;
    int i;

    system("cls");

    printf("----------------------MENU DE BAJA-----------------------\n");

    controller_ListEmployee(pArrayListEmployee);

    printf("\n\nIngrese ID del empleado a borrar: ");
    scanf("%d",&id);

    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        Employee* aux;
        aux=ll_get(pArrayListEmployee,i);
        if((id==aux->id))
            {
                flag=1;
                index=i;
                break;
            }
    }

    if(flag==0)
        {
            printf("No se ha encontrado empleado con tal ID.\n\n");
            system("pause");
            system("cls");

        }
    else
        {
            printf("SEGURO DESEA BORRAR EL EMPLEADO ID: %d\n1.SI.\n2.NO.\n",id);
            opcion=pedirEntero(":",1,2);
            if(opcion==1)
                {
                    ll_remove(pArrayListEmployee,index);
                    system("cls");
                    printf("\n\n::::::::::::::::::::::::\nEMPLEADO ELIMINADO CON EXITO.\n::::::::::::::::::::::::\n");
                    system("pause");
                    system("cls");
                }
            else
                {
                    system("cls");
                    printf("\n\n::::::::::::::::::::::::\nSE CANCELO LA ELIMINACION.\n::::::::::::::::::::::::\n");
                    system("pause");
                    system("cls");
                }
        }

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;

    Employee* pEmployee;

    printf("\n    ID    |,|           NOMBRE         |,|   HORAS  |,|     SUELDO\n");
    printf("          |,|                          |,|          |,|           \n");


    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        pEmployee=ll_get(pArrayListEmployee,i);
        printf("%10d|,|%26s|,|%10d|,| $%10d\n",pEmployee->id,pEmployee->nombre,pEmployee->horasTrabajadas,pEmployee->sueldo);
    }


   return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    system("cls");

    printf("\n--MENU ORDENAR--\n\n");
    printf("Ingrese una opcion:\n1)A a la Z.\n2)Z a la A.\n\n");

    opcion=pedirEntero(":",0,1);

    if(opcion==1)
    {
        opcion=0;
    }
    else
    {
        opcion=1;
    }

    printf("\n\nPor favor espere...\n\n");

    ll_sort(pArrayListEmployee,sortEmployees,opcion);

    printf("\nSE ORDENO LA LISTA CON EXITO\n\n");

    system("pause");

    system("cls");



    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int i;
    int returnAux=-1;
    int salary;
    int hours;
    int id;
    char name[50];

    FILE* pFile;

    pFile=fopen(path,"w");

    if(pFile!=NULL)
    {
        for(i=0;i<(ll_len(pArrayListEmployee));i++)
        {
            Employee* aux;

            aux=ll_get(pArrayListEmployee,i);

            id=aux->id;
            strcpy(name,aux->nombre);
            salary=aux->sueldo;
            hours=aux->horasTrabajadas;

            fprintf(pFile,"%d,%s,%d,%d\n",id,name,hours,salary);
        }
    }

    returnAux=1;

    fclose(pFile);

    return returnAux;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int i;
    int returnAux=-1;
    int salary;
    int hours;
    int id;
    char name[50];

    FILE* pFile;

    pFile=fopen(path,"wb");

    if(pFile!=NULL)
    {

        for(i=0;i<(ll_len(pArrayListEmployee));i++)
        {
            Employee* aux;

            aux=ll_get(pArrayListEmployee,i);

            id=aux->id;
            strcpy(name,aux->nombre);
            salary=aux->sueldo;
            hours=aux->horasTrabajadas;

            fprintf(pFile,"%d,%s,%d,%d\n",id,name,hours,salary);

        }
    }

    returnAux=1;

    fclose(pFile);

    return returnAux;
}

