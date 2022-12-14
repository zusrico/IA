/*******************************************/
/* 		    BUSQUEDA.C                     */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//#include "puzzlito.h"
#include "listaia.h"
#include "busqueda.h"

void solucionFin(int res){
   printf("\nFin de la busqueda\n");
    if (res)
      printf("Se ha llegado al objetivo\n");
   else
      printf("No se ha llegado al objetivo\n");
}
void dispNodo(tNodo *nodo){
    dispEstado(nodo->estado);
    printf("\n");
}
void dispCamino(tNodo *nodo){
    if (nodo->padre==NULL){
        printf("\n Desde el inicio\n");
        dispEstado(nodo->estado);
    }
    else {
        dispCamino(nodo->padre);
         dispOperador(nodo->operador);
        dispEstado(nodo->estado);
    }
}

void dispSolucion(tNodo *nodo){
   printf("Profundidad=%d\n",nodo->profundidad);
   printf("Coste=%d\n",nodo->costeCamino);
   dispCamino(nodo);
}


/* Crea el nodo ra�z. */
tNodo *nodoInicial(){
   tNodo *inicial=(tNodo *) malloc(sizeof(tNodo));
   inicial->estado=estadoInicial();
   inicial->padre=NULL;
   inicial->costeCamino=0;
   inicial->profundidad=0;
   return inicial;
}

LISTA expandir(tNodo *nodo){
    unsigned op;
    LISTA sucesores=VACIA;
    tNodo *nuevo=calloc(1,sizeof(tNodo));
    tEstado *s;
    for (op=1; op<=NUM_OPERADORES;op++){
      if (esValido(op,nodo->estado)){
                        //s=(tEstado *)calloc(1,sizeof(tEstado));
          s=aplicaOperador(op,nodo->estado);
          nuevo->estado=s;
          nuevo->padre=nodo;
          nuevo->operador=op;
          nuevo->costeCamino=nodo->costeCamino + coste(op,nodo->estado);
          nuevo->profundidad=nodo->profundidad+1;
          InsertarUltimo(&sucesores,  (tNodo *) nuevo, (sizeof (tNodo)));
      }
  }
return sucesores;
}

int busquedaAnchura(){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();
    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    LISTA Cerradas = VACIA;

    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));

    while (!esVacia(Abiertos) && !objetivo && Actual->costeCamino != 15){
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        visitados++;
        EliminarPrimero(&Abiertos);
        objetivo=testObjetivo(Actual->estado);
        if (!objetivo){
            Sucesores = expandir(Actual);
            Abiertos=Concatenar(Abiertos,Sucesores);
        }
   }//while

    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

int busquedaAnchuraControlEstados(){
    int objetivo=0, visitados=0, repe = 0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();
    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    LISTA Cerradas = VACIA;

    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));

    while (!esVacia(Abiertos) && !objetivo){
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        visitados++;
        EliminarPrimero(&Abiertos);
        if(!EstadosRepetidos(Cerradas, Actual)){
            visitados++;
            objetivo=testObjetivo(Actual->estado);
            if (!objetivo){
                Sucesores = expandir(Actual);
                InsertarPrimero(&Cerradas, Actual, sizeof(tNodo));
                Abiertos=Concatenar(Abiertos,Sucesores);
            }
        }
   }//while

    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

int busquedaProfundidad(){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();
    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;

    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));

    while (!esVacia(Abiertos) && !objetivo){
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        visitados++;
        EliminarPrimero(&Abiertos);
        objetivo=testObjetivo(Actual->estado);
        if (!objetivo){
            Sucesores = expandir(Actual);
            Abiertos=Concatenar(Sucesores,Abiertos);
        }
   }//while

    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

int busquedaProfundidadControlEstados(){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();
    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    LISTA Cerradas = VACIA;

    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));

    while (!esVacia(Abiertos) && !objetivo){
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        visitados++;
        EliminarPrimero(&Abiertos);
        if(!EstadosRepetidos(Cerradas, Actual)){
            objetivo=testObjetivo(Actual->estado);
            if (!objetivo){
                Sucesores = expandir(Actual);
                InsertarPrimero(&Cerradas, Actual, sizeof(tNodo));
                Abiertos=Concatenar(Sucesores,Abiertos);
            }
        }
   }//while

    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

int busquedaProfundidadLimitada(int lim){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();
    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    LISTA Cerradas = VACIA;

    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));

    while (!esVacia(Abiertos) && !objetivo && Actual->profundidad != lim){
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        visitados++;
        EliminarPrimero(&Abiertos);
        if(!EstadosRepetidos(Cerradas, Actual)){
            objetivo=testObjetivo(Actual->estado);
            if (!objetivo){
                Sucesores = expandir(Actual);
                InsertarPrimero(&Cerradas, Actual, sizeof(tNodo));
                Abiertos=Concatenar(Sucesores,Abiertos);
            }
        }
   }//while

    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}



int EstadosRepetidos(LISTA Cerradas, tNodo *n){
    int repetido = 0;
    tNodo *n_aux;
    LISTA listaux = VACIA;

    listaux = Cerradas; //quizas mejor que mempcpy, investigar

    while(!repetido && listaux != NULL){
        n_aux = (tNodo *)listaux->nodo;
        repetido = iguales(n_aux->estado, n->estado); //si son iguales, repetido = 1;
        listaux = listaux->next;
    }

    return repetido; 
}
