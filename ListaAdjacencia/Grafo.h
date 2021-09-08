struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max; //Numero maximo de arestas
    int **arestas;
    float **pesos;
    int* grau;
};

typedef struct grafo *Grafo;

Grafo cria_grafo(int nro_vertices, int grau_max, int eh_ponderado);
void libera_grafo(Grafo gr);
int insereAresta(Grafo gr, int origem, int destino, int eh_digrafo, float peso);
int removeAresta(Grafo gr, int origem, int destino, int eh_digrafo);
void imprimeGrafo(Grafo gr);

