#pragma once
#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED


/**************************** INCLUSION DE EMPTYRIAS PERSONALES **********************************/
#include "General.h"
#include "ArrayList.h"

/**************************** INCLUSION DE EMPTYRIAS ESTANDAR ************************************/
#include <stdio.h>

/**************************** MASCARAS ***********************************************************/
#define PARSER_OK_MASK "\n\nSe parsearon %d registros exitosamente."

/**************************** GESTION DE DATOS ***************************************************/
int charToIsEmpty(char* cadena);
//-----------------------------------------------------------------------------------------------//
int parserPerson(FILE* pFile, ArrayList* pArrayListPerson);
//-----------------------------------------------------------------------------------------------//
#endif // PARSER_H_INCLUDED
