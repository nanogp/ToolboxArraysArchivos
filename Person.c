/**************************** INCLUSION DE EMPTYRIAS PERSONALES **********************************/
#include "ArrayList.h"
#include "Person.h"
/**************************** INCLUSION DE EMPTYRIAS ESTANDAR ************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**************************** GET ****************************************************************/
int ePerson_getIsEmpty(ePerson* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = this->isEmpty;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_getId(ePerson* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = this->id;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_getDni(ePerson* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = this->dni;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_getStats(ePerson* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = this->stats;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* ePerson_getName(ePerson* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = this->name;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* ePerson_getLastName(ePerson* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = this->lastName;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_isEmpty(ePerson* this)
{
   int returnAux = CHECK_POINTER;

   if(this != NULL)
   {
      returnAux = 0;

      if(this->getIsEmpty(this) == PERSON_EMPTY)
      {
         returnAux = 1;
      }
   }

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* ePerson_getIsEmptyLegend(ePerson* this)
{
    char* returnAux = NULL;

    returnAux = (char*)malloc(sizeof(char)*10);

    if(this != NULL && returnAux != NULL)
    {
        if(ePerson_isEmpty(this))
        {
           strcpy(returnAux, PERSON_EMPTY_LEGEND);
        }
        else
        {
           strcpy(returnAux, PERSON_OCCUPIED_LEGEND);
        }
    }
    return returnAux;
}
/**************************** SET ****************************************************************/
int ePerson_setIsEmpty(ePerson* this, int isEmpty)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = OK;
        this->isEmpty = isEmpty;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_setId(ePerson* this, int id)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = OK;
        this->id = id;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_setDni(ePerson* this, int dni)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = OK;
        this->dni = dni;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_setStats(ePerson* this, int stats)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = OK;
        this->stats = stats;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_setName(ePerson* this, char* name)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = OK;
        strcpy(this->name, name);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_setLastName(ePerson* this, char* lastName)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = OK;
        strcpy(this->lastName, lastName);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

/**************************** CONSTRUCTORES ******************************************************/
ePerson* ePerson_new(void)
{
   ePerson* newPerson;

   newPerson = (ePerson*)malloc(sizeof(ePerson));
   if(newPerson != NULL)
   {
      newPerson->print            = ePerson_printOne;

       //getters
      newPerson->getIsEmpty       = ePerson_getIsEmpty;
      newPerson->getId            = ePerson_getId;
      newPerson->getDni           = ePerson_getDni;
      newPerson->getStats         = ePerson_getStats;
      newPerson->getName          = ePerson_getName;
      newPerson->getLastName      = ePerson_getLastName;
      newPerson->getIsEmptyLegend = ePerson_getIsEmptyLegend;

       //setters
      newPerson->setIsEmpty       = ePerson_setIsEmpty;
      newPerson->setId            = ePerson_setId;
      newPerson->setDni           = ePerson_setDni;
      newPerson->setStats         = ePerson_setStats;
      newPerson->setName          = ePerson_setName;
      newPerson->setLastName      = ePerson_setLastName;
   }

   return newPerson;
}
//-----------------------------------------------------------------------------------------------//
ePerson* ePerson_newParam(int id,
                          int dni,
                          int stats,
                          char* name,
                          char* lastName,
                          int isEmpty)
{
    ePerson* newPerson;

    newPerson = ePerson_new();

    if(newPerson != NULL)
   {
      newPerson->setId(newPerson, id);
      newPerson->setDni(newPerson, dni);
      newPerson->setStats(newPerson, stats);
      newPerson->setName(newPerson, name);
      newPerson->setLastName(newPerson, lastName);
      newPerson->setIsEmpty(newPerson, isEmpty);
   }

    return newPerson;
}
//-----------------------------------------------------------------------------------------------//


/**************************** ENTRADA DE DATOS ***************************************************/
int ePerson_askId()
{
   return pedirIntValido(PERSON_MSJ_INGRESE_ID, PERSON_MSJ_REINGRESE_ID, PERSON_ID_MIN, PERSON_ID_MAX);
}
//-----------------------------------------------------------------------------------------------//
int ePerson_askDni()
{
   return pedirIntValido(PERSON_MSJ_INGRESE_DNI, PERSON_MSJ_REINGRESE_DNI, PERSON_DNI_MIN, PERSON_DNI_MAX);
}
//-----------------------------------------------------------------------------------------------//
int ePerson_askStats()
{
   return pedirIntValido(PERSON_MSJ_INGRESE_STATS, PERSON_MSJ_REINGRESE_STATS, PERSON_STATS_MIN, PERSON_STATS_MAX);
}
//-----------------------------------------------------------------------------------------------//
char* ePerson_askName()
{
   char* returnAux = (char*)malloc(sizeof(char)*PERSON_LENGTH_NAME);

   pedirStringValido(returnAux, PERSON_MSJ_INGRESE_NAME, PERSON_MSJ_REINGRESE_NAME, PERSON_LENGTH_NAME);

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* ePerson_askLastName()
{
   char* returnAux = (char*)malloc(sizeof(char)*PERSON_LENGTH_LAST_NAME);

   pedirStringValido(returnAux, PERSON_MSJ_INGRESE_LAST_NAME, PERSON_MSJ_REINGRESE_LAST_NAME, PERSON_LENGTH_LAST_NAME);

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
ePerson* ePerson_askInput()
{
   ePerson* newPerson;

   newPerson = ePerson_newParam(ePerson_askId(),
                                ePerson_askDni(),
                                ePerson_askStats(),
                                ePerson_askName(),
                                ePerson_askLastName(),
                                PERSON_OCCUPIED);

   return newPerson;
}
//-----------------------------------------------------------------------------------------------//


/**************************** INICIALIZACIONES ***************************************************/
//hardcodeo


/**************************** BUSQUEDA ***********************************************************/
int ePerson_listIsEmpty(ArrayList* this)
{
   int returnAux = CHECK_POINTER;

   if(this != NULL)
   {
      returnAux = this->isEmpty();
   }
   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_listIsEmptyLegend(ArrayList* this)
{
   int returnAux = CHECK_POINTER;

   if(this != NULL)
   {
      returnAux = ePerson_listIsEmpty(this);

      if(returnAux == EMPTY)
      {
         imprimirEnPantalla(PERSON_MSJ_EMPTY_LIST);
      }
   }

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_nextId(ArrayList* this)
{
   ePerson* onePerson;
   int id = 0;

   for(int i=0; i<this->len(this); i++)
   {
      onePerson = this->get(this, i);

      if(onePerson->getIsEmpty(onePerson) == PERSON_OCCUPIED && onePerson->getId(onePerson) > id)
      {
         id = onePerson->getId(onePerson);
      }
   }

   return (id+1);
}
//-----------------------------------------------------------------------------------------------//
ePerson* ePerson_getById(ArrayList* this, int id)
{
   ePerson* onePerson;
   ePerson* returnPerson = NULL;

   for(int i=0; i<this->len(this) ; i++)
   {
      onePerson = this->get(this, i);

      if(onePerson->getId(onePerson) == id)
      {
         returnPerson = onePerson;
         break;
      }
   }
   return returnPerson;
}
//-----------------------------------------------------------------------------------------------//
ePerson* ePerson_getByDni(ArrayList* this, int dni)
{
   ePerson* onePerson;
   ePerson* returnPerson = NULL;

   for(int i=0; i<this->len(this) ; i++)
   {
      onePerson = this->get(this, i);

      if(onePerson->getDni(onePerson) == dni)
      {
         returnPerson = onePerson;
         break;
      }
   }
   return returnPerson;
}
//-----------------------------------------------------------------------------------------------//
ePerson* ePerson_getByAskId(ArrayList* this)
{
   ePerson* onePerson;
   int id;

   do
   {
      imprimirTitulo(PERSON_LISTADO_TITULO);
      ePerson_printList(this, PERSON_PRINT_PAGESIZE);
      id = ePerson_askId();
      onePerson = ePerson_getById(this, id);

      if(onePerson == NULL)
      {
         imprimirEnPantalla(PERSON_MSJ_ID_NO_EXISTE);
         pausa();
      }
   }
   while(onePerson == NULL);

   return onePerson;
}
//-----------------------------------------------------------------------------------------------//
ePerson* ePerson_getByAskDni(ArrayList* this)
{
   ePerson* onePerson;
   int dni;

   do
   {
      imprimirTitulo(PERSON_LISTADO_TITULO);
      ePerson_printList(this, PERSON_PRINT_PAGESIZE);
      dni = ePerson_askDni();
      onePerson = ePerson_getByDni(this, dni);

      if(onePerson == NULL)
      {
         imprimirEnPantalla(PERSON_MSJ_DNI_NO_EXISTE);
         pausa();
      }
   }
   while(onePerson == NULL);

   return onePerson;
}
//-----------------------------------------------------------------------------------------------//



/**************************** LISTADO DE DATOS ***************************************************/
void ePerson_printOne(ePerson* this)
{
   printf(PERSON_PRINT_MASK,
          this->getId(this),
          this->getDni(this),
          this->getName(this),
          this->getLastName(this),
          this->getIsEmptyLegend(this));
}
//-----------------------------------------------------------------------------------------------//
int ePerson_printList(ArrayList* this, int pageSize)
{
   ePerson* onePerson;
   int count = 0;

   imprimirEnPantalla(PERSON_PRINT_MASK_CABECERA);

   for(int i=0 ; i<this->len(this) ; i++)
   {
      onePerson = this->get(this,i);

      if(!ePerson_isEmpty(onePerson))
      {
         onePerson->print(onePerson);
         count++;

         if(count%pageSize == 0)
         {
            pausa();
            imprimirEnPantalla(PERSON_PRINT_MASK_CABECERA);
         }
      }
   }
   return count;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_printListFromTo(ArrayList* this, int idFrom, int idTo, int pageSize)
{
   ePerson* onePerson;
   int count = 0;

   imprimirEnPantalla(PERSON_PRINT_MASK_CABECERA);

   for(int i=0 ; i<this->len(this) ; i++)
   {
      onePerson = this->get(this,i);

      if(!ePerson_isEmpty(onePerson) &&
         onePerson->getId(onePerson) >= idFrom &&
         onePerson->getId(onePerson) <= idTo)
      {
         onePerson->print(onePerson);
         count++;

         if(count%pageSize == 0)
         {
            pausa();
            imprimirEnPantalla(PERSON_PRINT_MASK_CABECERA);
         }
      }
   }
   return count;
}
//-----------------------------------------------------------------------------------------------//

/**************************** ALTA ***************************************************************/
int ePerson_gestionAlta(ArrayList* this)
{
   int returnAux = CHECK_POINTER;
   ePerson* registro;
   char confirmacion;

   if(this != NULL)
   {
      returnAux = OK;
      limpiarPantallaYMostrarTitulo(PERSON_ALTA_TITULO);

      registro = ePerson_askInput();

      if(!ePerson_getByDni(this, registro->getDni(registro)))
      {
        printf(PERSON_MSJ_DNI_YA_EXISTE, registro->getDni(registro));
      }
      else
      {
         limpiarPantallaYMostrarTitulo(PERSON_ALTA_TITULO);
         imprimirEnPantalla(PERSON_PRINT_MASK_CABECERA);
         registro->print(registro);

         confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);

         if(confirmacion == 'S')
         {
           this->add(this, registro);
           ePerson_sortByDni(this);
           imprimirEnPantalla(PERSON_MSJ_ALTA_OK);
         }
         else
         {
           imprimirEnPantalla(MSJ_CANCELO_GESTION);
         }
      }
      pausa();
   }
   return returnAux;
}
//-----------------------------------------------------------------------------------------------//


/**************************** BAJA DE REGISTRO ****************************************************/
int ePerson_gestionBaja(ArrayList* this)
{
   int returnAux = CHECK_POINTER;
   ePerson* onePerson;
   char confirmacion;

   if(this != NULL)
   {
      returnAux = CHECK_IS_EMPTY;
      limpiarPantallaYMostrarTitulo(PERSON_BAJA_TITULO);

      if(!ePerson_listIsEmptyLegend(this))
      {
         returnAux = OK;

         onePerson = ePerson_getByAskId(this);

         limpiarPantallaYMostrarTitulo(PERSON_BAJA_TITULO);
         imprimirEnPantalla(PERSON_PRINT_MASK_CABECERA);
         onePerson->print(onePerson);

         confirmacion = pedirConfirmacion(PERSON_MSJ_CONFIRMAR_BAJA);

         if(confirmacion == 'S')
         {
            onePerson->setIsEmpty(onePerson, PERSON_EMPTY);
            imprimirEnPantalla(PERSON_MSJ_BAJA_OK);
         }
         else
         {
            imprimirEnPantalla(MSJ_CANCELO_GESTION);
         }
      }

   }
   pausa();
   return returnAux;
}
//-----------------------------------------------------------------------------------------------//


/**************************** GESTION DE DATOS ***************************************************/
void ePerson_delete(ePerson* this)
{
    free(this);
}
//-----------------------------------------------------------------------------------------------//
void ePerson_gestionListar(ArrayList* this)
{
   limpiarPantallaYMostrarTitulo(PERSON_LISTADO_TITULO);

   if(!ePerson_listIsEmptyLegend(this))
   {
      ePerson_printList(this, PERSON_PRINT_PAGESIZE);
   }
   pausa();
}
//-----------------------------------------------------------------------------------------------//
void ePerson_gestionListarDesdeHasta(ArrayList* this)
{
   int desde;
   int hasta;

   limpiarPantallaYMostrarTitulo(PERSON_LISTADO_RANGO_TITULO);

   if(!ePerson_listIsEmptyLegend(this))
   {
      imprimirEnPantalla(PERSON_LISTADO_RANGO_INGRESO);
      pedirRangoIntValido(PERSON_MSJ_INGRESE_ID,
                          PERSON_MSJ_REINGRESE_ID,
                          PERSON_ID_MIN,
                          PERSON_ID_MAX,
                          &desde,
                          &hasta);

      limpiarPantallaYMostrarTitulo(PERSON_LISTADO_RANGO_TITULO);
      ePerson_printListFromTo(this, desde, hasta, PERSON_PRINT_PAGESIZE);
   }
   pausa();
}
//-----------------------------------------------------------------------------------------------//
void ePerson_gestionOrdenar(ArrayList* this)
{
   limpiarPantallaYMostrarTitulo(PERSON_ORDEN_TITULO);

   if(!ePerson_listIsEmptyLegend(this))
   {
      ePerson_sortByDni(this);
      //ePerson_sortByName(this);
      imprimirEnPantalla(PERSON_MSJ_ORDEN_OK);
   }
   pausa();
}
//-----------------------------------------------------------------------------------------------//


/**************************** ORDENAMIENTO *******************************************************/
int c(void* pPersonA, void* pPersonB)
{
   int returnAux = 0;

   if((ePerson*)pPersonA->getDni(pPersonA) > (ePerson*)pPersonB->getDni(pPersonB))
   {
      returnAux = 1;
   }
   else if((ePerson*)pPersonA->getDni(pPersonA) < (ePerson*)pPersonB->getDni(pPersonB))
   {
      returnAux = -1;
   }

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_compareByName(void* pPersonA,void* pPersonB)
{
   return strcmp(((ePerson*)pPersonA)->name, ((ePerson*)pPersonB)->name);
}
//-----------------------------------------------------------------------------------------------//
int ePerson_sortByDni(ArrayList* this)
{s
   int returnAux = CHECK_POINTER;

   if(this!=NULL)
   {
      returnAux = OK;
      this->sort(this, ePerson_compareByDni, PERSON_ORDEN_ASC);
   }

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_sortByName(ArrayList* this)
{s
   int returnAux = CHECK_POINTER;

   if(this!=NULL)
   {
      returnAux = OK;
      this->sort(this, ePerson_compareByName, PERSON_ORDEN_ASC);
   }

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
