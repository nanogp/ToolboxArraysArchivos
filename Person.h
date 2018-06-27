#pragma once
#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED


/**************************** INCLUSION DE EMPTYRIAS PERSONALES **********************************/
#include "ArrayList.h"
#include "General.h"
#include "Menu.h"

/**************************** CONSTANTES *********************************************************/
#define PERSON_EMPTY EMPTY
#define PERSON_OCCUPIED OCCUPIED
#define PERSON_EMPTY_LEGEND "Vacio"
#define PERSON_OCCUPIED_LEGEND "Ocupado"
#define TRUE "true"
#define FALSE "false"
#define PERSON_PRINT_PAGESIZE 1000

/**************************** LIMITES ************************************************************/
#define PERSON_LENGTH_NAME 51
#define PERSON_LENGTH_LAST_NAME 51
#define PERSON_ID_MIN 1
#define PERSON_ID_MAX 1000000
#define PERSON_DNI_MIN 1
#define PERSON_DNI_MAX 1000000
#define PERSON_STATS_MIN 1
#define PERSON_STATS_MAX 1000000
#define PERSON_LENGTH_RESERVAS 10

/**************************** MASCARAS ***********************************************************/
#define PERSON_PRINT_MASK "\n%d \t %d \t %-20s \t %-20s \t %s"
#define PERSON_PARSE_MASK "%[^,],%[^,],%[^,],%[^\n]\n"
#define PERSON_LISTADO_RECUENTO "\n%d registros."

/**************************** TITULOS ************************************************************/
#define PERSON_ALTA_TITULO "ALTA DE PERSON"
#define PERSON_BAJA_TITULO "BAJA DE PERSON"
#define PERSON_MODIFICACION_TITULO "MODIFICACION DE PERSON"
#define PERSON_LISTADO_TITULO "LISTADO DE PERSONS"
#define PERSON_LISTADO_RANGO_TITULO "LISTADO DE PERSONS POR RANGO"
#define PERSON_PARSER_TITULO "PARSER ARCHIVO CSV DE PERSONS"
#define PERSON_ORDEN_TITULO "ORDENAR LISTA DE PERSONS"

/**************************** MENSAJES INFO ******************************************************/
#define PERSON_MSJ_ALTA_OK "\nLa Person se dio de alta"
#define PERSON_MSJ_BAJA_OK "\nLa Person se dio de baja"
#define PERSON_MSJ_MODIFICACION_SIN_CAMBIOS "\nNo hubo cambio alguno"
#define PERSON_MSJ_MODIFICACION_OK "\nLa Person se modifico"
#define PERSON_MSJ_REGISTRO_ACTUAL "\n\nREGISTRO DE PERSON ACTUAL:\n----------------------------"
#define PERSON_MSJ_REGISTRO_MODIFICADO "\n\nREGISTRO MODIFICADO:\n--------------------"
#define PERSON_MSJ_ORDEN_OK "\n\nSe ordeno listado por nombre"
#define PERSON_LISTADO_RANGO_INGRESO "\n\nSe deben ingresar los ID desde y hasta\n--------------------------------------"

/**************************** MENSAJES INPUT *****************************************************/
#define PERSON_MSJ_CONFIRMAR_BAJA "Confirma que desea dar de baja dicha Person?"
#define PERSON_MSJ_INGRESE_ID "\n\nIngrese el ID de Person: "
#define PERSON_MSJ_INGRESE_DNI "\n\nIngrese el DNI de Person: "
#define PERSON_MSJ_INGRESE_STATS "\n\nIngrese stats de Person: "
#define PERSON_MSJ_INGRESE_NAME "\nIngrese Nombre: "
#define PERSON_MSJ_INGRESE_LAST_NAME "\nIngrese Apellido: "

/**************************** MENSAJES ERROR *****************************************************/
#define PERSON_MSJ_ID_NO_EXISTE "\nEl ID de Person ingresado no existe"
#define PERSON_MSJ_DNI_NO_EXISTE "\nEl DNI de Person ingresado no existe"
#define PERSON_MSJ_DNI_YA_EXISTE "\nEl DNI %d ya existe en la lista"
#define PERSON_MSJ_EMPTY_LIST "\n\nLa lista de Persons esta vacia o todos los registros se dieron de baja"
#define PERSON_MSJ_NO_MAS_LUGAR "\nNo hay mas lugares disponibles para altas de Person"
#define PERSON_MSJ_REINGRESE_ID "\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: "
#define PERSON_MSJ_REINGRESE_DNI "\nEl DNI debe ser un numero mayor que PERSON_DNI_MIN y menor que PERSON_DNI_MAX. Reingrese un DNI valido:"
#define PERSON_MSJ_REINGRESE_STATS "\nEl valor de stat debe ser un numero mayor que PERSON_STATS_MIN y menor que PERSON_STATS_MAX. Reingrese un stats valido:"
#define PERSON_MSJ_REINGRESE_NAME "\nNombre no valido. Reingrese por favor hasta 50 caracteres: "
#define PERSON_MSJ_REINGRESE_LAST_NAME "\nApellido no valido. Reingrese por favor hasta 50 caracteres: "

/**************************** LISTADOS ***********************************************************/
#define PERSON_PRINT_MASK_CABECERA "\nID \t DNI \t NAME \t\t LAST_NAME \t\t ES VACIO\n-- \t ------ \t\t -------- \t\t --------"

/**************************** ORDENAMIENTO *******************************************************/
#define PERSON_ORDEN_ASC 1
#define PERSON_ORDEN_DESC 0

/**************************** ESTRUCTURAS ********************************************************/
struct
{
   int id;
   int dni;
   int stats;
   char name[PERSON_LENGTH_NAME];
   char lastName[PERSON_LENGTH_LAST_NAME];
   int isEmpty;

   void (*print)();

    //getters
   int (*getIsEmpty)();
   int (*getId)();
   int (*getDni)();
   int (*getStats)();
   char* (*getName)();
   char* (*getLastName)();
   char* (*getIsEmptyLegend)();

    //setters
   int (*setIsEmpty)();
   int (*setId)();
   int (*setDni)();
   int (*setStats)();
   int (*setName)();
   int (*setLastName)();

}typedef ePerson;


/**************************** GET ****************************************************************/
int ePerson_getIsEmpty(ePerson* this);
int ePerson_getId(ePerson* this);
int ePerson_getDni(ePerson* this);
int ePerson_getStats(ePerson* this);
char* ePerson_getName(ePerson* this);
char* ePerson_getLastName(ePerson* this);
int ePerson_isEmpty(ePerson* this);
char* ePerson_getIsEmptyLegend(ePerson* this);


/**************************** SET ****************************************************************/
int ePerson_setIsEmpty(ePerson* this, int isEmpty);
int ePerson_setId(ePerson* this, int id);
int ePerson_setDni(ePerson* this, int dni);
int ePerson_setStats(ePerson* this, int stats);
int ePerson_setName(ePerson* this, char* name);
int ePerson_setLastName(ePerson* this, char* lastName);

/**************************** CONSTRUCTORES ******************************************************/
ePerson* ePerson_new(void);
ePerson* ePerson_newParam(int id,
                          int dni,
                          int stats,
                          char* name,
                          char* lastName,
                          int isEmpty);

/**************************** ENTRADA DE DATOS ***************************************************/
int ePerson_askId();
int ePerson_askDni();
int ePerson_askStats();
char* ePerson_askName();
char* ePerson_askLastName();
ePerson* ePerson_askInput();

/**************************** INICIALIZACIONES ***************************************************/
void ePerson_initHardcode(ArrayList* this);
int ePerson_init(ArrayList* this);

/**************************** BUSQUEDA ***********************************************************/
int ePerson_listIsEmptyLegend(ArrayList* this);
int ePerson_nextId(ArrayList* this);
ePerson* ePerson_getById(ArrayList* this, int id);
ePerson* ePerson_getByDni(ArrayList* this, int dni);
ePerson* ePerson_getByAskId(ArrayList* this);
ePerson* ePerson_getByAskDni(ArrayList* this);

/**************************** LISTADO DE DATOS ***************************************************/
void ePerson_printOne(ePerson* this);
int ePerson_printList(ArrayList* this, int pageSize);
int ePerson_printListFromTo(ArrayList* this, int idFrom, int idTo, int pageSize);

/**************************** GESTION DE DATOS ***************************************************/
void ePerson_delete(ePerson* this);
void ePerson_gestionParse(ArrayList* this);
void ePerson_gestionListar(ArrayList* this);
void ePerson_gestionListarDesdeHasta(ArrayList* this);
void ePerson_gestionOrdenar(ArrayList* this);
int ePerson_gestionAlta(ArrayList* this);
int ePerson_gestionBaja(ArrayList* this);

/**************************** ORDENAMIENTO *******************************************************/
int ePerson_compareByName(void* pPersonA, void* pPersonB);
int ePerson_compareByDni(void* pPersonA, void* pPersonB);
int ePerson_compareByStats(void* pPersonA, void* pPersonB);
int ePerson_sortByDni(ArrayList* this);
int ePerson_sortByName(ArrayList* this);

#endif // PERSON_H_INCLUDED
