#include <stdio.h>
#include <stdlib.h>
#include "ListaDuplEncadeada.h"

void criar_lista(NoLista **l)
{
    *l = NULL;
}

int esta_vazia(NoLista **l)
{
    return *l == NULL;
}

void imprime_lista(NoLista **l)
{
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

void inserir_elemento(NoLista **l, int v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL)
    {
        novo->info = v;
        novo->ant = NULL;
        novo->prox = *l;
        if (!esta_vazia(l))
            (*l)->ant = novo;
        *l = novo;
    }
    else
        printf("Não foi possível alocar espaço!");
}

NoLista *ultimo(NoLista **l)
{
    if (esta_vazia(l))
        return NULL;
    else
    {
        NoLista *p;
        for (p = *l; p->prox != NULL; p = p->prox)
            ;
        return p;
    }
}

void imprime_ordem_inversa(NoLista **l)
{
    NoLista *aux = ultimo(l);
    if (aux != NULL)
    {
        for (aux; aux != NULL; aux = aux->ant)
            printf("%d ", aux->info);
        printf("\n");
    }
    else
        printf("Lista vazia!");
}

NoLista *busca_elemento(NoLista **l, int v)
{
    NoLista *elemento;
    for (elemento = *l; elemento != NULL; elemento = elemento->prox)
    {
        if (elemento->info == v)
            return elemento;
    }
    return NULL;
}

void remover_elemento(NoLista **l, int v)
{
    NoLista *aux = busca_elemento(l, v);
    if (aux != NULL)
    {
        if (aux->ant == NULL)
            *l = aux->prox;
        else
            aux->ant->prox = aux->prox;
        if (aux->prox != NULL)
            aux->prox->ant = aux->ant;
        free(aux);
    }
    else
        printf("Elemento não encontrado!");
}

void libera(NoLista **l)
{
    NoLista *temp, *p;
    for (p = *l; p != NULL; p = temp)
    {
        temp = p->prox;
        free(p);
    }
    *l = NULL;
}
