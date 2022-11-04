/*******************************************/
/* 		    BUSQUEDA.H                     */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include "puzzlito.h"

#ifndef _tNodo_
#define _tNodo_
typedef struct NodoBusqueda_{
    tEstado *estado;
    unsigned operador;
    int costeCamino;
    int profundidad;
    int valHeuristica;
    struct NodoBusqueda_ *padre;
} tNodo;

#endif

int busquedaAnchura(void);
int busquedaAnchuraControlEstados(void);
int busquedaProfundidad(void);
int busquedaProfundidadControlEstados(void);
int busquedaProfundidadLimitada(int);
int busquedaProfundidadLimitadaIterativa(int);
int EstadosRepetidos(LISTA, tNodo*);
void solucionFin(int res);