/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "ArrayList.h"
#include "Person.h"
/**************************** INCLUSION DE LIBRERIAS ESTANDAR ************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**************************** BUSQUEDA ***********************************************************/
int ePerson_estaVacio(ArrayList* this)
{
   int returnAux = VERIFICAR_PUNTEROS;

   if(this != NULL)
   {
      returnAux = OCUPADO;
      for(int i=0 ; i<al_len(this); i++)
      {
         if(ePerson_getIsEmpty(al_get(this,i)) == EMPLOYEE_OCCUPIED)
         {
            returnAux = VACIO;
            break;
         }
      }

   }
   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_informarListadoVacio(ArrayList* this)
{
   int returnAux = VERIFICAR_PUNTEROS;

   if(this != NULL)
   {
      returnAux = ePerson_estaVacio(this);

      if(returnAux == 1)
      {
         imprimirEnPantalla(EMPLOYEE_MSJ_LISTA_VACIA);
      }
   }

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_nextId(ArrayList* this)
{
   ePerson* unEmpleado;
   int id = 0;

   for(int i=0; i<al_len(this); i++)
   {
      unEmpleado = al_get(this,i);

      if(ePerson_getIsEmpty(unEmpleado) == EMPLOYEE_OCCUPIED && ePerson_getId(unEmpleado) > id)
      {
         id = ePerson_getId(unEmpleado);
      }
   }

   return (id+1);
}
//-----------------------------------------------------------------------------------------------//
ePerson* ePerson_getById(ArrayList* this, int id)
{
   ePerson* unEmpleado;

   for(int i=0; i<al_len(this) ; i++)
   {
      unEmpleado = al_get(this, i);

      if(ePerson_getId(unEmpleado) == id)
      {
         break;
      }
      else
      {
         unEmpleado = NULL;
      }
   }
   return unEmpleado;
}
//-----------------------------------------------------------------------------------------------//
ePerson* ePerson_searchById(ArrayList* this)
{
   ePerson* unEmpleado;
   int id;

   do
   {
      imprimirTitulo(EMPLOYEE_LISTADO_TITULO);
      ePerson_printList(this, EMPLOYEE_PRINT_PAGESIZE);
      id = ePerson_pedirId();
      unEmpleado = ePerson_getById(this, id);

      if(unEmpleado == NULL)
      {
         imprimirEnPantalla(EMPLOYEE_MSJ_ID_NO_EXISTE);
         pausa();
      }
   }
   while(unEmpleado == NULL);

   return unEmpleado;
}
//-----------------------------------------------------------------------------------------------//


/**************************** GET Y SET **********************************************************/
int ePerson_getId(ePerson* this)
{
    int returnAux = VERIFICAR_PUNTEROS;
    if(this != NULL)
    {
        returnAux = this->id;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_getIsEmpty(ePerson* this)
{
    int returnAux = VERIFICAR_PUNTEROS;
    if(this != NULL)
    {
        returnAux = this->isEmpty;
    }
    return returnAux;
}//-----------------------------------------------------------------------------------------------//
char* ePerson_getIsEmptyLegend(ePerson* this)
{
    char* returnAux = NULL;

    returnAux = (char*)malloc(sizeof(char)*10);

    if(this != NULL && returnAux != NULL)
    {
        if(ePerson_getIsEmpty(this) == EMPLOYEE_EMPTY)
        {
            strcpy(returnAux, EMPLOYEE_EMPTY_LEGEND);
        }
        else
        {
           strcpy(returnAux, EMPLOYEE_OCCUPIED_LEGEND);
        }
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
int ePerson_setId(ePerson* this, int id)
{
    int returnAux = VERIFICAR_PUNTEROS;
    if(this != NULL)
    {
        returnAux = SIN_ERROR;
        this->id = id;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_setIsEmpty(ePerson* this, int isEmpty)
{
    int returnAux = VERIFICAR_PUNTEROS;
    if(this != NULL)
    {
        returnAux = SIN_ERROR;
        this->isEmpty = isEmpty;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_setName(ePerson* this, char* name)
{
    int returnAux = VERIFICAR_PUNTEROS;
    if(this != NULL)
    {
        returnAux = SIN_ERROR;
        strcpy(this->name, name);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_setLastName(ePerson* this, char* lastName)
{
    int returnAux = VERIFICAR_PUNTEROS;
    if(this != NULL)
    {
        returnAux = SIN_ERROR;
        strcpy(this->lastName, lastName);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

/**************************** ENTRADA DE DATOS ***************************************************/
ePerson* ePerson_new(void)
{
    ePerson* returnAux = NULL;

    returnAux = (ePerson*)malloc(sizeof(ePerson));

    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
ePerson* ePerson_newParam(int id, char* name, char* lastName, int isEmpty)
{
    ePerson* returnAux;

    returnAux = ePerson_new();

    ePerson_setId(returnAux,id);
    ePerson_setIsEmpty(returnAux,isEmpty);
    ePerson_setName(returnAux,name);
    ePerson_setLastName(returnAux,lastName);

    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePerson_pedirId()
{
   return pedirIntValido(EMPLOYEE_MSJ_INGRESE_ID, EMPLOYEE_MSJ_REINGRESE_ID, EMPLOYEE_ID_MIN, EMPLOYEE_ID_MAX);
}
//-----------------------------------------------------------------------------------------------//
char* ePerson_pedirName()
{
   char* returnAux = (char*)malloc(sizeof(char)*EMPLOYEE_LARGO_NAME);

   pedirStringValido(returnAux, EMPLOYEE_MSJ_INGRESE_NOMBRE, EMPLOYEE_MSJ_REINGRESE_NOMBRE, EMPLOYEE_LARGO_NAME);

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* ePerson_pedirLastName()
{
   char* returnAux = (char*)malloc(sizeof(char)*EMPLOYEE_LARGO_LAST_NAME);

   pedirStringValido(returnAux, EMPLOYEE_MSJ_INGRESE_APELLIDO, EMPLOYEE_MSJ_REINGRESE_APELLIDO, EMPLOYEE_LARGO_LAST_NAME);

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
ePerson* ePerson_pedirIngreso(ArrayList* this)
{
   ePerson* unEmpleado;

   unEmpleado = ePerson_new();

   ePerson_setId(unEmpleado, ePerson_nextId(this));

   ePerson_setName(unEmpleado, ePerson_pedirName());

   ePerson_setLastName(unEmpleado, ePerson_pedirLastName());

   ePerson_setIsEmpty(unEmpleado, EMPLOYEE_OCCUPIED);

   return unEmpleado;
}
//-----------------------------------------------------------------------------------------------//

/**************************** LISTADO DE DATOS ***************************************************/
void ePerson_print(ePerson* this)
{
   printf(EMPLOYEE_PRINT_MASK, this->id, this->name, this->lastName, ePerson_getIsEmptyLegend(this));
}
//-----------------------------------------------------------------------------------------------//
void ePerson_printList(ArrayList* this, int pageSize)
{
   ePerson* empleado;
   int contador = 0;

   imprimirEnPantalla(EMPLOYEE_PRINT_MASK_CABECERA);

   for(int i=0 ; i<al_len(this) ; i++)
   {
      empleado = al_get(this,i);

      if(ePerson_getIsEmpty(empleado) != EMPLOYEE_EMPTY)
      {
         ePerson_print(empleado);
         contador++;

         if(contador%pageSize == 0)
         {
            pausa();
            imprimirEnPantalla(EMPLOYEE_PRINT_MASK_CABECERA);
         }
      }
   }
   printf(EMPLOYEE_LISTADO_RECUENTO,contador);
}
//-----------------------------------------------------------------------------------------------//
void ePerson_printListFromTo(ArrayList* this, int idFrom, int idTo, int pageSize)
{
   ePerson* empleado;
   int contador = 0;

   imprimirEnPantalla(EMPLOYEE_PRINT_MASK_CABECERA);

   for(int i=0 ; i<al_len(this) ; i++)
   {
      empleado = al_get(this,i);

      if(ePerson_getIsEmpty(empleado) != EMPLOYEE_EMPTY &&
         ePerson_getId(empleado) > idFrom &&
         ePerson_getId(empleado) < idTo)
      {
         ePerson_print(empleado);
         contador++;

         if(contador%pageSize == 0)
         {
            pausa();
            imprimirEnPantalla(EMPLOYEE_PRINT_MASK_CABECERA);
         }
      }
   }
   printf(EMPLOYEE_LISTADO_RECUENTO,contador);
}
//-----------------------------------------------------------------------------------------------//
void ePerson_printListWithEmpty(ArrayList* this)
{
   ePerson* empleado;
   int contador = 0;

   limpiarPantallaYMostrarTitulo(EMPLOYEE_LISTADO_TITULO);
   imprimirEnPantalla(EMPLOYEE_PRINT_MASK_CABECERA);

   for(int i=0 ; i<al_len(this) ; i++)
   {
      empleado = al_get(this,i);

      ePerson_print(empleado);
      contador++;

      if(contador%EMPLOYEE_PRINT_PAGESIZE == 0)
      {
         pausa();
         limpiarPantallaYMostrarTitulo(EMPLOYEE_LISTADO_TITULO);
         imprimirEnPantalla(EMPLOYEE_PRINT_MASK_CABECERA);
      }
   }
   printf(EMPLOYEE_LISTADO_RECUENTO,contador);
}
//-----------------------------------------------------------------------------------------------//


/**************************** ALTA DE REGISTRO ***************************************************/
int ePerson_gestionAlta(ArrayList* this)
{
   int returnAux = VERIFICAR_PUNTEROS;
   ePerson* registro;
   char confirmacion;

   if(this != NULL)
   {
      returnAux = SIN_ERROR;
      limpiarPantallaYMostrarTitulo(EMPLOYEE_ALTA_TITULO);

      registro = ePerson_pedirIngreso(this);

      limpiarPantallaYMostrarTitulo(EMPLOYEE_ALTA_TITULO);
      imprimirEnPantalla(EMPLOYEE_PRINT_MASK_CABECERA);
      ePerson_print(registro);

      confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);

      if(confirmacion == 'S')
      {
         al_add(this, registro);
         imprimirEnPantalla(EMPLOYEE_MSJ_ALTA_OK);
      }
      else
      {
         imprimirEnPantalla(MSJ_CANCELO_GESTION);
      }
      pausa();
   }
   return returnAux;
}
//-----------------------------------------------------------------------------------------------//


/**************************** BAJA DE REGISTRO ****************************************************/
int ePerson_gestionBaja(ArrayList* this)
{
   int returnAux = VERIFICAR_PUNTEROS;
   ePerson* unEmpleado;
   char confirmacion;

   if(this != NULL)
   {
      returnAux = VERIFICAR_SI_ESTA_VACIO;
      limpiarPantallaYMostrarTitulo(EMPLOYEE_BAJA_TITULO);

      if(!ePerson_informarListadoVacio(this))
      {
         returnAux = SIN_ERROR;

         unEmpleado = ePerson_searchById(this);

         limpiarPantallaYMostrarTitulo(EMPLOYEE_BAJA_TITULO);

         imprimirEnPantalla(EMPLOYEE_PRINT_MASK_CABECERA);
         ePerson_print(unEmpleado);

         confirmacion = pedirConfirmacion(EMPLOYEE_MSJ_CONFIRMAR_BAJA);

         if(confirmacion == 'S')
         {
            ePerson_setIsEmpty(unEmpleado, EMPLOYEE_EMPTY);
            imprimirEnPantalla(EMPLOYEE_MSJ_BAJA_OK);
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
   limpiarPantallaYMostrarTitulo(EMPLOYEE_LISTADO_TITULO);

   if(!ePerson_informarListadoVacio(this))
   {
      ePerson_printList(this, EMPLOYEE_PRINT_PAGESIZE);
   }
   pausa();
}
//-----------------------------------------------------------------------------------------------//
void ePerson_gestionListarDesdeHasta(ArrayList* this)
{
   int desde;
   int hasta;

   limpiarPantallaYMostrarTitulo(EMPLOYEE_LISTADO_RANGO_TITULO);

   if(!ePerson_informarListadoVacio(this))
   {
      imprimirEnPantalla(EMPLOYEE_LISTADO_RANGO_INGRESO);
      pedirRangoIntValido(EMPLOYEE_MSJ_INGRESE_ID,
                          EMPLOYEE_MSJ_REINGRESE_ID,
                          EMPLOYEE_ID_MIN,
                          EMPLOYEE_ID_MAX,
                          &desde,
                          &hasta);

      limpiarPantallaYMostrarTitulo(EMPLOYEE_LISTADO_RANGO_TITULO);
      ePerson_printListFromTo(this, desde, hasta, EMPLOYEE_PRINT_PAGESIZE);
   }
   pausa();
}
//-----------------------------------------------------------------------------------------------//
void ePerson_gestionOrdenar(ArrayList* this)
{
   limpiarPantallaYMostrarTitulo(EMPLOYEE_ORDEN_TITULO);

   if(!ePerson_informarListadoVacio(this))
   {
      ePerson_sort(this);
      imprimirEnPantalla(EMPLOYEE_MSJ_ORDEN_OK);
   }
   pausa();
}
//-----------------------------------------------------------------------------------------------//


/**************************** ORDENAMIENTO *******************************************************/
int ePerson_compareByName(void* pPersonA,void* pPersonB)
{
   return strcmp(((ePerson*)pPersonA)->name, ((ePerson*)pPersonB)->name);
}
//-----------------------------------------------------------------------------------------------//
int ePerson_compareByLastName(void* pPersonA,void* pPersonB)
{
   return strcmp(((ePerson*)pPersonA)->lastName, ((ePerson*)pPersonB)->lastName);
}
//-----------------------------------------------------------------------------------------------//
int ePerson_sort(ArrayList* this)
{s
   int returnAux = VERIFICAR_PUNTEROS;

   if(this!=NULL)
   {
      returnAux = SIN_ERROR;
      al_sort(this, ePerson_compareByName, EMPLOYEE_ORDEN_ASC);
   }

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
