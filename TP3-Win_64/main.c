#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado.
     4. Modificar datos de empleado.
     5. Baja de empleado.
     6. Listar empleados.
     7. Ordenar empleados.
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir.
*****************************************************/


int main()
{
    int option;
    int flag=0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        printf("Menu:\n1. Cargar los datos de los empleados desde el archivo data.csv(modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv(modo binario).\n3. Alta de empleado.\n4. Modificar datos de empleado.\n5. Baja de empleado.\n6. Listar empleados.\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv(modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv(modo binario).\n10. Salir.\n\nElija una opcion: ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            if(flag==0)
            {
                controller_loadFromText("data.csv", listaEmpleados);
                flag=1;
            }
            else
            {
                printf("\n\nERROR. YA SE HA CARGADO LA LISTA.\n\n");
                system("pause");
                system("cls");
            }
            break;
        case 2:
            if(flag==0)
            {
                flag=1;
                if(controller_loadFromBinary("data.bin", listaEmpleados)==-1)
                {
                    printf("\nERROR. ALGUN PUNTERO SE ENCUENTRA EN ESTADO NULL.\n\n");
                    system("pause");
                    system("cls");
                }
            }
            else
            {
                printf("\n\nERROR. YA SE HA CARGADO LA LISTA.\n\n");
                system("pause");
                system("cls");
            }
            break;
        case 3:
            if(flag==1)
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\nCARGUE LOS EMPLEADOS PRIMERO PARA CARGAR UN EMPLEADO Y ASI EVITAR IDS REPETIDAS.\n\n");
                system("pause");
                system("cls");
            }
            break;
        case 4:
            if(flag==1)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\nCARGUE LOS EMPLEADOS PRIMERO PARA EDITAR UN EMPLEADOS.\n\n");
                system("pause");
                system("cls");
            }

            break;
        case 5:
            if(flag==1)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\nCARGUE LOS EMPLEADOS PRIMERO PARA ELIMINAR UN EMPLEADO DE LA LISTA.\n\n");
                system("pause");
                system("cls");
            }
            break;
        case 6:
            system("cls");
            printf("                        ----MOSTRAR LISTA----\n");
            controller_ListEmployee(listaEmpleados);
            printf("\n\n");
            system("pause");
            system("cls");
            break;
        case 7:
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:

            if(flag==1)
            {
                if(controller_saveAsText("data.csv",listaEmpleados))
                {
                    system("cls");
                    printf(":::::::::::::::::::::::::::::::\nGUARDADO EN TEXTO CON EXITO\n:::::::::::::::::::::::::::::::\n\n");
                    system("pause");
                    system("cls");

                }
                else
                {
                    system("cls");
                    printf(":::::::::::::::::::::::::::::::\nOCURRIO UN ERROR\n:::::::::::::::::::::::::::::::\n\n");
                    system("pause");
                    system("cls");
                }
            }
            else
            {
                printf("\n\nCARGUE LOS EMPLEADOS PRIMERO PARA GUARDAR LA LISTA.\n\n");
                system("pause");
                system("cls");
            }
            break;
        case 9:
            if(flag==1)
            {
                if(controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    system("cls");
                    printf(":::::::::::::::::::::::::::::::\nGUARDADO EN BINARIO CON EXITO\n:::::::::::::::::::::::::::::::\n\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    system("cls");
                    printf(":::::::::::::::::::::::::::::::\nOCURRIO UN ERROR.\n:::::::::::::::::::::::::::::::\n\n");
                    system("pause");
                    system("cls");
                }
            }
            else
            {
                printf("\n\nCARGUE LOS EMPLEADOS PRIMERO PARA GUARDAR LA LISTA.\n\n");
                system("pause");
                system("cls");
            }
            break;
        }
    }
    while(option != 10);
    return 0;
}
