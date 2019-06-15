#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int -1 si algun puntero viene en estado NULL, 0 si los punteros no están en NULL pero no pudo hacer el parseo, 1 si todo funciono correctamente
 *
 */
int parser_EmployeeFromText(char* pFile, LinkedList* pArrayListEmployee)
{
    int read;
    int returnAux=-1;
    char auxId[10];
    char auxName[128];
    char auxSalary[10];
    char auxHours[10];

    Employee* aux;

    FILE* data;

    data=fopen(pFile,"r");

    if(pFile!=NULL&&pArrayListEmployee!=NULL&&data!=NULL)
    {
        returnAux=0;

        do
        {
            read=fscanf(data,"%[^,],%[^,],%[^,],%[^\n]",auxId,auxName,auxHours,auxSalary);

            if(read==4)
            {
                aux=employee_newParametros(auxId,auxName,auxHours,auxSalary);
                ll_add(pArrayListEmployee, aux);

            }

        }while(!feof(data));

        fclose(data);

        returnAux=1;

        printf("\n\nDATOS CARGADOS CORRECTAMENTE EN TEXTO\n");

        printf("Cantidad de datos cargados: %d\n",ll_len(pArrayListEmployee));

        printf("\n\n");

        system("pause");

        system("cls");

    }

    return returnAux;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(char* pFile , LinkedList* pArrayListEmployee)
{
    int read;
    int returnAux=-1;
    char auxId[10];
    char auxName[35];
    char auxSalary[10];
    char auxHours[10];

    Employee* aux;

    FILE* data;

    data=fopen(pFile,"rb");

    if(pFile!=NULL&&pArrayListEmployee!=NULL&&data!=NULL)
        {
        returnAux=0;

        do{read=fscanf(data,"%[^,],%[^,],%[^,],%[^\n]",auxId,auxName,auxSalary,auxHours);

        if(read==4)
            {
                aux=employee_newParametros(auxId,auxName,auxHours,auxSalary);
                ll_add(pArrayListEmployee,aux);
            }
        }while(!feof(data));

        returnAux=1;

        fclose(data);

        printf("\n\nDATOS CARGADOS CORRECTAMENTE EN BINARIO\n");

        printf("Cantidad de datos cargados: %d\n",ll_len(pArrayListEmployee));

        printf("\n\n");

        system("pause");

        system("cls");
        }

    return returnAux;
}
