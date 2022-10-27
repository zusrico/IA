/*******************************************/
/*             MAIN.C                      */
/*                                         */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//#include "puzzlito.h"
#include "listaia.h"
#include "busqueda.h"

int main(){
    int busca;
    printf("1.Busqueda en anchura.\n2.Busqueda en profundidad.\n3.Salir\nIntroduce el metodo de busqueda deseado:");
    scanf("%d", &busca);

    switch (busca)
    {
    case 1:
        solucionFin(busquedaAnchura());
        break;
    case 2:
        solucionFin(busquedaProfundidad());
    default:
        break;
    }

    return 0;
}
