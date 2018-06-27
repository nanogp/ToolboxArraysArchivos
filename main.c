/**************************** INCLUSION DE EMPTYRIAS PERSONALES **********************************/
#include "General.h"
#include "Menu.h"
#include "ArrayList.h"


/**************************** INCLUSION DE EMPTYRIAS ESTANDAR ************************************/
#include <stdio.h>
#include <stdlib.h>

/**************************** MENUS **************************************************************/
#define MENU_MAIN_TITULO "MENU GENERICO"
#define MENU_MAIN_CANT 12

int main()
{
   eMenu menuPrincipal = {/*titulo del menu*/{MENU_MAIN_TITULO},
                          /*cantidad de opciones*/MENU_MAIN_CANT,
                          /*codigos*/{1,2,3,4,5,6,7,8,9,10,11,0},
                          /*descripciones*/"\n  1. Alta Person"
                                           "\n  2. Modificacion Person"
                                           "\n  3. Baja Person"
                                           "\n  4. Listado Persons"
                                           "\n  5. Alta Hijo"
                                           "\n  6. Modificacion Hijo"
                                           "\n  7. Baja Hijo"
                                           "\n  8. Listado Hijos"
                                           "\n  9. Listado Person Y Sus Hijos"
                                           "\n 10. Listado Estadistica Person"
                                           "\n 11. Baja Person Y Sus Hijos"
                                           "\n  0. Salir Del Programa"};
    int opcion;
    char salirDelPrograma = 'N';

    //ARRAYS DE ESTRUCTURAS

    //INCIALIZAR


    do
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        opcion = eMenu_pedirOpcion(&menuPrincipal);
        switch(opcion)
        {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:

                break;
            case 10:

                break;
            case 11:

                break;
            case 0:
                salirDelPrograma = pedirConfirmacion("Confirma que desea salir del programa?");
                break;
        }

    }
    while(salirDelPrograma == 'N');
    return 0;
}
