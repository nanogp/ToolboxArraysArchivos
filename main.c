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
                          /*descripciones*/"\n  1. Alta Padre"
                                           "\n  2. Modificacion Padre"
                                           "\n  3. Baja Padre"
                                           "\n  4. Listado Padres"
                                           "\n  5. Alta Hijo"
                                           "\n  6. Modificacion Hijo"
                                           "\n  7. Baja Hijo"
                                           "\n  8. Listado Hijos"
                                           "\n  9. Listado Padre Y Sus Hijos"
                                           "\n 10. Listado Estadistica Padre"
                                           "\n 11. Baja Padre Y Sus Hijos"
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
                pausa();
                break;
            case 2:
                pausa();
                break;
            case 3:
                pausa();
                break;
            case 4:
                pausa();
                break;
            case 5:
                pausa();
                break;
            case 6:
                pausa();
                break;
            case 7:
                pausa();
                break;
            case 8:
                pausa();
                break;
            case 9:
                pausa();
                break;
            case 10:
                pausa();
                break;
            case 11:
                pausa();
                break;
            case 0:
                salirDelPrograma = pedirConfirmacion("Confirma que desea salir del programa?");
                break;
        }

    }
    while(salirDelPrograma == 'N');
    return 0;
}
