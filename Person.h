#pragma once
#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED


/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "General.h"
#include "Menu.h"

/**************************** CONSTANTES *********************************************************/
#define PERSON_EMPTY 1
#define PERSON_OCCUPIED 0
#define PERSON_EMPTY_LEGEND "Vacio"
#define PERSON_OCCUPIED_LEGEND "Ocupado"
#define TRUE "true"
#define FALSE "false"
#define PERSON_PRINT_PAGESIZE 1000

/**************************** LIMITES ************************************************************/
#define PERSON_LARGO_NAME 51
#define PERSON_LARGO_LAST_NAME 51
#define PERSON_ID_MIN 1
#define PERSON_ID_MAX 1000000
#define PERSON_LARGO_RESERVAS 10

/**************************** MASCARAS ***********************************************************/
#define PERSON_PRINT_MASK "\n%d \t %-20s \t %-20s \t %s"
#define PERSON_PARSE_MASK "%[^,],%[^,],%[^,],%[^\n]\n"
#define PERSON_LISTADO_RECUENTO "\n%d registros."

/**************************** TITULOS ************************************************************/
#define PERSON_ALTA_TITULO "ALTA DE EMPLOYEE"
#define PERSON_BAJA_TITULO "BAJA DE EMPLOYEE"
#define PERSON_MODIFICACION_TITULO "MODIFICACION DE EMPLOYEE"
#define PERSON_LISTADO_TITULO "LISTADO DE EMPLOYEES"
#define PERSON_LISTADO_RANGO_TITULO "LISTADO DE EMPLOYEES POR RANGO"
#define PERSON_PARSEO_TITULO "PARSEO ARCHIVO CSV DE EMPLOYEES"

/**************************** MENSAJES ERROR *****************************************************/
#define PERSON_MSJ_ID_NO_EXISTE "\nEl ID de Person ingresado no existe"
#define PERSON_MSJ_LISTA_VACIA "\n\nLa lista de Persons esta vacia o todos los registros se dieron de baja"
#define PERSON_MSJ_NO_MAS_LUGAR "\nNo hay mas lugares disponibles para altas de Person"
#define PERSON_MSJ_REINGRESE_ID "\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: "
#define PERSON_MSJ_REINGRESE_NOMBRE "\nNombre no valido. Reingrese por favor hasta 50 caracteres: "
#define PERSON_MSJ_REINGRESE_APELLIDO "\nApellido no valido. Reingrese por favor hasta 50 caracteres: "

/**************************** MENSAJES INFO ******************************************************/
#define PERSON_MSJ_ALTA_OK "\nLa Person se dio de alta"
#define PERSON_MSJ_BAJA_OK "\nLa Person se dio de baja"
#define PERSON_MSJ_MODIFICACION_SIN_CAMBIOS "\nNo hubo cambio alguno"
#define PERSON_MSJ_MODIFICACION_OK "\nLa Person se modifico"
#define PERSON_MSJ_REGISTRO_ACTUAL "\n\nREGISTRO DE EMPLOYEE ACTUAL:\n----------------------------"
#define PERSON_MSJ_REGISTRO_MODIFICADO "\n\nREGISTRO MODIFICADO:\n--------------------"
#define PERSON_MSJ_ORDEN_OK "\n\nSe ordeno listado por nombre"
#define PERSON_LISTADO_RANGO_INGRESO "\n\nSe deben ingresar los ID desde y hasta\n--------------------------------------"

/**************************** MENSAJES INPUT *****************************************************/
#define PERSON_MSJ_CONFIRMAR_BAJA "Confirma que desea dar de baja dicha Person?"
#define PERSON_MSJ_INGRESE_ID "\n\nIngrese el ID de Person: "
#define PERSON_MSJ_INGRESE_NOMBRE "\nIngrese Nombre: "
#define PERSON_MSJ_INGRESE_APELLIDO "\nIngrese Apellido: "

/**************************** LISTADOS ***********************************************************/
#define PERSON_PRINT_MASK_CABECERA "\nID \t NOMBRE \t\t APELLIDO \t\t ES VACIO\n-- \t ------ \t\t -------- \t\t --------"

/**************************** ORDENAMIENTO *******************************************************/
#define PERSON_ORDEN_ASC 1
#define PERSON_ORDEN_DESC 0

/**************************** MENUS **************************************************************/
#define PERSON_MENU_MODIFICAR_UNO_TITULO "Que desea modificar?"
#define PERSON_MENU_MODIFICAR_UNO_CANT 8
#define PERSON_MENU_MODIFICAR_UNO_DETALLE1 "1. Titulo"
#define PERSON_MENU_MODIFICAR_UNO_DETALLE2 "2. Genero"
#define PERSON_MENU_MODIFICAR_UNO_DETALLE3 "3. Duracion"
#define PERSON_MENU_MODIFICAR_UNO_DETALLE4 "4. Descripcion"
#define PERSON_MENU_MODIFICAR_UNO_DETALLE5 "5. Puntaje"
#define PERSON_MENU_MODIFICAR_UNO_DETALLE6 "6. Link a imagen"
#define PERSON_MENU_MODIFICAR_UNO_DETALLE9 "9. Finalizar modificacion"
#define PERSON_MENU_MODIFICAR_UNO_DETALLE0 "0. Cancelar"


/**************************** ESTRUCTURAS ********************************************************/
struct
{
    int id;
    char name[PERSON_LARGO_NAME];s
    char lastName[PERSON_LARGO_LAST_NAME];
    int isEmpty;

}typedef ePerson;


/**************************** GET ****************************************************************/
int ePerson_getIsEmpty(ePerson* this);
char* ePerson_getIsEmptyLegend(ePerson* this);
int ePerson_getId(ePerson* this);
int ePerson_getDni(ePerson* this);
int ePerson_getStats(ePerson* this);
char* ePerson_getName(ePerson* this);
char* ePerson_getLastName(ePerson* this);


/**************************** SET ****************************************************************/
int ePerson_setIsEmpty(ePerson* this, int isEmpty);
int ePerson_setId(ePerson* this, int id);
int ePerson_setDni(ePerson* this, int dni);
int ePerson_setName(ePerson* this, char* name);
int ePerson_setLastName(ePerson* this, char* lastName);



/**************************** INICIALIZACIONES ***************************************************/
void ePerson_initHardcode(ePerson* listadoPersons);

int ePerson_init(ArrayList* this);


/**************************** BUSQUEDA ***********************************************************/
int ePerson_estaVacio(ArrayList* this);

int ePerson_informarListadoVacio(ArrayList* this);

int ePerson_nextId(ArrayList* this);

ePerson* ePerson_getById(ArrayList* this, int id);

ePerson* ePerson_searchById(ArrayList* this);



/**************************** ENTRADA DE DATOS ***************************************************/
ePerson* ePerson_new(void);

ePerson* ePerson_newParam(int id, char* name, char* lastName, int isEmpty);

int ePerson_pedirId();

char* ePerson_pedirName();

char* ePerson_pedirLastName();

ePerson* ePerson_pedirIngreso(ArrayList* this);


/**************************** LISTADO DE DATOS ***************************************************/
void ePerson_print(ePerson* this);

void ePerson_printList(ArrayList* this, int pageSize);

void ePerson_printListFromTo(ArrayList* this, int idFrom, int idTo, int pageSize);

void ePerson_printListWithEmpty(ArrayList* this);



/**************************** GESTION DE DATOS ***************************************************/
void ePerson_delete(ePerson* this);

void ePerson_gestionParsear(ArrayList* this);

void ePerson_gestionListar(ArrayList* this);

void ePerson_gestionListarDesdeHasta(ArrayList* this);

void ePerson_gestionOrdenar(ArrayList* this);

int ePerson_gestionAlta(ArrayList* this);

int ePerson_gestionBaja(ArrayList* this);



/**************************** ORDENAMIENTO *******************************************************/
int ePerson_compareByName(void* pPersonA,void* pPersonB);

int ePerson_sort(ArrayList* this);

#endif // PERSON_H_INCLUDED
