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
    printf("1.Anchura.\n2.Profundidad.\n3.Anchura Control de Estados Repetidos.\n4.Profundidad Control de Estados Repetidos.\n 5.Salir\nIntroduce el metodo de busqueda deseado:");
    scanf("%d", &busca);

    switch (busca)
    {
    case 1:
        solucionFin(busquedaAnchura());
        break;
    case 2:
        solucionFin(busquedaProfundidad());
        break;
    case 3:
        solucionFin(busquedaAnchuraControlEstados());
        break;
    case 4:
        solucionFin(busquedaProfundidadControlEstados());
        break;
    default:
        break;
    }

    return 0;
}