/*******************************************/
/* 		      PUZLE.C                      */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tetris.h"



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
      case ABAJO_A:    printf("Movimiento ABAJO A:\n"); break;
      case ABAJO_B:     printf("Movimiento ABAJO B:\n"); break;
      case DERECHA_C: printf("Movimiento DERECHA C:\n"); break;
      case ABAJO_C:   printf("Movimiento ABAJO C:\n"); break;
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
        case ABAJO_A:
            valido = (estado->fila[11] + 1 < N-1) && (estado->celdas[estado->fila[11]+1][estado->col[11]+1]) == H && (estado->celdas[estado->fila[11]+1][estado->col[11]-1]) == H && (estado->celdas[estado->fila[11]+2][estado->col[22]]) == H;
            break;
        case ABAJO_B:
            valido = estado->fila[22] < N-1 && (estado->celdas[estado->fila[22]+1][estado->col[22]+1]) == 0 && (estado->celdas[estado->fila[22]+1][estado->col[22]-1]) == 0 && (estado->celdas[estado->fila[22]+1][estado->col[22]]) == 0 ;
            break;
        case DERECHA_C:
            valido = estado->col[33] < N-1 && (estado->celdas[estado->fila[33]-1][estado->col[33]+1])  == 0 && (estado->celdas[estado->fila[33]][estado->col[33]+1])  == 0 && (estado->celdas[estado->fila[33]+1][estado->col[33]+1])  == 0;
            break;
        case ABAJO_C:
            valido = estado->fila[33] + 1 < N-1 && (estado->celdas[estado->fila[33]+2][estado->col[33]])  == 0;
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



