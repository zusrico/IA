#define ABAJO_A 1
#define ABAJO_B 2
#define DERECHA_C 3
#define ABAJO_C 4
#define A 1
#define B 2
#define C 3
#define H 0
#define CENTRO_A 11
#define CENTRO_B 22
#define CENTRO_C 33
#define NUM_OPERADORES 4
#define N 6


#ifndef _tEstado_
#define _tEstado_
   typedef struct {
        int celdas[N][N];
        int fila[N*N], col[N*N];
   } tEstado;


static int puzle_inicial[N][N]=
{
  {-1, 0, 0, 3, 0, 0},
  {-1, 0, 0, 33, 0, 0},
  {0, 1, 0, 3, 0, 0},
  {1, 11, 1, -1, 2, 0},
  {-0, 1, 0, 2, 22, 2},
  {0, 0, 0, 0, 0, 0}
};


static int puzle_final[N][N]=
{
  {-1, 0, 0, 3, 0, 0},
  {-1, 0, 0, 33, 0, 0},
  {0, 0, 0, 3, 0, 0},
  {0, 1, 0, -1, 2, 0},
  {1, 11, 1, 2, 2, 2},
  {0, 1, 0, 0, 0, 0}
};


/* A partir de una configuración de fichas construye un estado válido para el problema
  de acuerdo al tipo de datos tEstado. */
tEstado *crearEstado(int celdas[N][N]);

/* Genera el estado inicial a partir de crearEstado y puzle_inicial. */
tEstado *estadoInicial();


/* Devuelve el coste de aplicar el operador. */
int coste(unsigned op, tEstado *estado);

/* Muestra el contenido del puzle. */
void dispEstado(tEstado *estado);

/* Muestra el nombre de cada operador: Arriba, Abajo, Izquierda, Derecha. */
void dispOperador(unsigned op);

/* Genera el estado final a partir de crearEstado y puzle_final. */
tEstado *estadoObjetivo();


/* Comprueba si es posible aplicar un operador a una configuración determinada para el puzle.
  Devuelve 1 si el movimiento es válido y 0 en otro caso. */
int esValido(unsigned op, tEstado* estado);

/* Aplica un operador a una configuración concreta del puzle.
  Devuelve la nueva configuración del tablero tras el movimiento. */
tEstado *aplicaOperador(unsigned op, tEstado *estado);

/* Devuelve 1 si dos estados son iguales y 0 en caso contrario. */
int iguales(tEstado *s, tEstado *t);

/* Devuelve 1 si un estado es igual al estado objetivo. */
int testObjetivo(tEstado *estado);

#endif
