/*
 * Implementação de grafos não dirigidos utilizando uma
 * matriz de adjacências (apenas o triângulo inferior).
 */

#include <stdlib.h>

typedef struct grafo {
  int n;      /* Número de nós */
  int **mat;  /* Matriz (a ser alocada dinamicamente) */
} Grafo;

void cria_grafo(Grafo* g, int n)  { 
  int i;

  g->mat = calloc (n, sizeof(int*));
  g->mat[0] = NULL;
  for (i = 1; i < n; i++)
    g->mat = calloc (i, sizeof(int));
  g->n = n;
}

void destroi(Grafo *g) {
  int i;
  for (i = 1; i < g->n; i++)
    free(g->mat[i]);
  free(g->mat);
}

void adiciona_aresta(Grafo *g, int v1, int v2) {
  if (v1 > v2)
    g->mat[v1][v2] = 1;
  else
    g->mat[v2][v1] = 1;
}

int existe_aresta(Grafo *g, int v1, int v2) {
  return v1 > v2 ? g->mat[v1][v2] : g->mat[v2][v1];
}

void remove_aresta(Grafo *g, int v1, int v2) {
  if (v1 > v2)
    g->mat[v1][v2] = 0;
  else
    g->mat[v2][v1] = 0;
}


/* Deve imprimir grafos no seguinte formato:

  Grafo dirigido

    0 ----- 1 ---- 2
    |       |
    |       |
    4 ----- 3 ---- 5

    E = {(0,1),(1,0),(1,2),(2,1),(3,1),(3,4)
         (3,5),(4,0),(4,3),(5,3)} 

*/

void imprime_grafo(Grafo *g) {
}

int main() {
  Grafo g;
  cria_grafo(&g, 6);
  adiciona_aresta(&g,0,1);
  adiciona_aresta(&g,1,2);
  adiciona_aresta(&g,3,1);
  adiciona_aresta(&g,4,0);
  adiciona_aresta(&g,5,3);
  return 0;
}

