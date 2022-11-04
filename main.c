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
    int busca, limite = 0, aux = 0;
    printf("1.Anchura.\n2.Profundidad.\n3.Anchura Control de Estados Repetidos.\n4.Profundidad Control de Estados Repetidos.\n5.Profundidad Limitada\n6.Profundidad Limitada Iterativa\n\nIntroduce el metodo de busqueda deseado:");
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
    case 5:
        printf("Introduce el limite: ");
        scanf("%d", &limite);
        solucionFin(busquedaProfundidadLimitada(limite));
        break;
    case 6:
        printf("Introduce el limite: ");
        scanf("%d", &limite);

        while(busquedaProfundidadLimitada(aux) != 1 && aux < limite){
            solucionFin(busquedaProfundidadLimitada(aux));
            aux++;
        }
        break;
    default:
        break;
    }

    return 0;
}