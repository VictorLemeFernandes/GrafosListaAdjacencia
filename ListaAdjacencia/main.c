#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main()
{
    Grafo gr;
    gr = cria_grafo(4, 3, 0);
    insereAresta(gr, 0, 1, 1, 0);
    insereAresta(gr, 0, 3, 1, 0);
    insereAresta(gr, 1, 3, 1, 0);
    imprimeGrafo(gr);
    libera_grafo(gr);

    return 0;
}
