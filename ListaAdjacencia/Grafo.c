#include "Grafo.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

Grafo cria_grafo(int nro_vertices, int grau_max, int eh_ponderado){
    Grafo gr = (Grafo) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0) ? 1 : 0;
        gr->grau = (int*) calloc(nro_vertices, sizeof(int));
        gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));
        for(i = 0; i < nro_vertices; i++)
            gr->arestas[i] = (int*) malloc(grau_max * sizeof(int));
        if(gr->eh_ponderado){
            gr->pesos = (float**)malloc(nro_vertices * sizeof(float*));
            for(i = 0; i < nro_vertices; i++)
                gr->pesos[i] = (float*)malloc(grau_max * sizeof(float));
        }
    }
    return gr;
}

void libera_grafo(Grafo gr){
    if(gr != NULL){
        int i;
        for(i = 0; i < gr->nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        if(gr->eh_ponderado){
            for(i = 0; i < gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

int insereAresta(Grafo gr, int origem, int destino, int eh_digrafo, float peso){
    if(gr == NULL)
        return 0;
    if(origem < 0 || origem >= gr->nro_vertices)
        return 0;
    if(destino < 0 || destino >= gr->nro_vertices);

    gr->arestas[origem][gr->grau[origem]] = destino;
    if(gr->eh_ponderado)
        gr->pesos[origem][gr->grau[origem]] = peso;
    gr->grau[origem]++;

    if(eh_digrafo == 0) //0 == FALSE and 1 == TRUE
        insereAresta(gr, destino, origem, 1, peso);

    return 1;
}

int removeAresta(Grafo gr, int origem, int destino, int eh_digrafo){
    if(gr == NULL)
        return 0;
    if(origem < 0 || origem >= gr->nro_vertices)
        return 0;
    if(destino < 0 || destino >= gr->nro_vertices);

    int i = 0;
    while(i < gr->grau[origem] && gr->arestas[origem][i] != destino)
        i++;

    //Elemento nao encontrado
    if(i == gr->grau[origem])
        return 0;

    gr->grau[origem]--;
    gr->arestas[origem][i] = gr->arestas[origem][gr->grau[origem]];
    if(gr->eh_ponderado)
        gr->pesos[origem][i] = gr->pesos[origem][gr->grau[origem]];
    if(eh_digrafo == 0)
        removeAresta(gr, destino, origem, 1);

    return 1;
}

void imprimeGrafo(Grafo gr){
    int i, j = 0;
    printf("Grafo - Resumo:\n");
    for(i = 0; i < gr->nro_vertices; i++){
        printf("%d:", i);
        for(j = 0; j < gr->grau[i]; j++)
            if(gr->grau[i] != 0)
                printf(" %d", gr->arestas[i][j]);
        printf("\n");
    }

}
