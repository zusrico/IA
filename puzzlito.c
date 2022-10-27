/*******************************************/
/* 		      PUZLE.C                      */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "puzzlito.h"



tEstado *crearEstado(int puzle[N][N])
{
   tEstado *estado = (tEstado *) malloc(sizeof(tEstado));
   int i, j, ficha;

   for (i=0;i<N;i++)
      for (j=0;j<N;j++)
      {
         ficha=puzle[i][j];
         estado->celdas[i][j]=ficha;
         estado->fila[ficha]=i;
         estado->col[ficha]=j;
      }
   return estado;
}


tEstado *estadoInicial()
{
   return crearEstado(puzle_inicial);
}


tEstado *estadoObjetivo()
{
   return crearEstado(puzle_final);
}

int coste(unsigned op, tEstado *estado)
{
   return 1;
}

/* VISUALIZACIÓN DE ESTADOS Y OPERADORES*/


void dispEstado(tEstado *estado)
{
   int i,j;

   for (i=0; i<N; i++)
   {
      for (j=0; j<N; j++)
         printf("%d",estado->celdas[i][j]);
      printf("\n");
   }
   printf("\n");
}


void dispOperador(unsigned op)
{
   switch(op)
   {
      case ARRIBA:    printf("Movimiento ARRIBA:\n"); break;
      case ABAJO:     printf("Movimiento ABAJO:\n"); break;
      case IZQUIERDA: printf("Movimiento IZQUIERDA:\n"); break;
      case DERECHA:   printf("Movimiento DERECHA:\n"); break;
   }
}

// FUNCIONES QUE SE HAN DE IMPLEMENTAR EN LA PRACTICA 1

// Función auxiliar para comprobar si dos puzles tienen las fichas colocadas en el mismo orden en el tablero
int iguales(tEstado *s, tEstado *t)  //
{
    int i, j, same = 1;

    i = 0;
    while(same && i<N){
        j = 0;
        while(same && j<N){
            same = (s->celdas[i][j] == t->celdas[i][j]); //será falso cuando 2 fichas no coincidan 
            j++;
        }
        i++;
    }
return same; //devolverá 0 en caso de falso 
}


int testObjetivo(tEstado *estado)
{
    tEstado *final;
    final = estadoObjetivo();
    return (iguales(estado, final));
return 0;
}


int esValido(unsigned op, tEstado *estado)
{
    int valido = 0;
    switch(op){
        case ARRIBA:
            valido = estado->fila[0] > 0;
            break;
        case ABAJO:
            valido = estado->fila[0] < N-1;
            break;
        case IZQUIERDA:
            valido = estado->col[0] > 0;
            break;
        case DERECHA:
            valido = estado->col[0] < N-1;
            break;
        default: valido = 0;
    }
    return valido;
} //esValido


tEstado *aplicaOperador(unsigned op, tEstado *estado)
{
    int ficha;
    tEstado *nuevo= (tEstado *) malloc(sizeof(tEstado));
    memcpy(nuevo, estado,sizeof(tEstado));  
    switch (op)
    {
    case ARRIBA:
        ficha = nuevo->celdas[nuevo->fila[0]-1][nuevo->col[0]];
        nuevo->fila[0]--;
        nuevo->fila[ficha]++;
        break;
    case ABAJO:
        ficha = nuevo->celdas[nuevo->fila[0]+1][nuevo->col[0]];
        nuevo->fila[0]++;
        nuevo->fila[ficha]--;
        break;
    case IZQUIERDA:
        ficha = nuevo->celdas[nuevo->fila[0]][nuevo->col[0]-1];
        nuevo->col[0]--;
        nuevo->col[ficha]++;
        break;
     case DERECHA:
        ficha = nuevo->celdas[nuevo->fila[0]][nuevo->col[0]+1];
        nuevo->col[0]++;
        nuevo->col[ficha]--;
        break;
    default:
        break;
    }

    nuevo->celdas[nuevo->fila[0]][nuevo->col[0]] = 0;
    nuevo->celdas[nuevo->fila[ficha]][nuevo->col[ficha]] = ficha;

return nuevo;
}



