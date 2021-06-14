#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

void criar_lista(NoLista **l)
{ // Cria uma lista vazia
    *l = NULL;
}

int esta_vazia(NoLista **l)
{ // Verifica se uma lista está vazia
    return *l == NULL;
}

void insere_elemento_inicio(NoLista **l, int v)
{ // Insere um elemento no início da lista
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL)
    {
        novo->info = v;
        novo->prox = *l;
        *l = novo;
    }
    else
    {
        printf("Não foi possível alocar espaço!");
        exit(1);
    }
}

void imprime_lista(NoLista **l)
{ // Imprime os elementos de uma lista
    if (!esta_vazia(l))
    {
        NoLista *p;
        for (p = *l; p != NULL; p = p->prox)
        {
            printf("%d ", p->info);
        }
        printf("\n");
    }
    else
        printf("Lista Vazia!");
}

NoLista *busca_elemento(NoLista **l, int v)
{ // Busca  retorna um elemento da lista passado como parâmetro
    NoLista *elemento;
    for (elemento = *l; elemento != NULL; elemento = elemento->prox)
    {
        if (elemento->info == v)
            return elemento;
    }
    return NULL;
}

void remover(NoLista **l, int v)
{ // Remove um elemento da lista passado como parâmetro
    NoLista *p;
    NoLista *ant = NULL;
    for (p = *l; p != NULL && p->info != v; p = p->prox)
    {
        ant = p;
    }
    if (p == NULL)
        printf("Elemento não encontrado!");
    else
    {
        if (ant == NULL)
            *l = p->prox;
        else
            ant->prox = p->prox;
        free(p);
    }
}

int conta_elementos(NoLista **l)
{
    NoLista *p = *l;
    int cont = 0;
    if (!esta_vazia(l))
    {
        for (p; p != NULL; p = p->prox)
            cont++;
        return cont;
    }
    else
        return 0;
}

void libera(NoLista **l)
{ // Destói todos os elementos da lista, deixando-a vazia
    NoLista *temp, *p;
    for (p = *l; p != NULL; p = temp)
    {
        temp = p->prox;
        free(p);
    }
    *l = NULL;
}

void insere_ordenado(NoLista **l, int v)
{ // Insere elementos na lista de forma crescente
    NoLista *p, *ant = NULL;
    for (p = *l; p != NULL && p->info < v; p = p->prox)
        ant = p;
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL)
    {
        novo->info = v;
        novo->prox = p;
        if (ant == NULL)
            *l = novo;
        else
            ant->prox = novo;
    }
    else
    {
        printf("Não foi possível alocar espaço!");
        exit(1);
    }
}
