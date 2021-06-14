#include <stdio.h>
#include <stdlib.h>
#include "ListaDescritor.h"

void criar_lista(Descritor *d)
{
    d->n = 0;
    d->prim = d->ult = NULL;
}

int esta_vazia(Descritor *d)
{
    return d->n == 0;
}

void inserir_elemento_inicio(Descritor *d, int v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL)
    {
        novo->info = v;
        novo->prox = d->prim;
        d->prim = novo;
        if (d->n == 0)
            d->ult = novo;
        d->n++;
    }
    else
    {
        printf("Não foi possível alocar espaço!");
        exit(1);
    }
}

void insere_elemento_fim(Descritor *d, int v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL)
    {
        novo->info = v;
        novo->prox = NULL;
        if (!esta_vazia(d))
            d->ult->prox = novo;
        else
            d->prim = novo;
        d->ult = novo;
        d->n++;
    }
    else
    {
        printf("Não foi possível alocar espaço!");
        exit(1);
    }
}

void remove_elemento(Descritor *d, int v)
{
    NoLista *p, *ant = NULL;
    for (p = d->prim; p != NULL && p->info != v; p = p->prox)
        ant = p;
    if (p == NULL)
        printf("Elemento não encontrado!");
    else
    {
        if (ant == NULL)
        {
            d->prim = p->prox;
            if (d->prim == NULL)
                d->ult == NULL;
        }
        else
        {
            ant->prox = p->prox;
            if (p->prox == NULL)
                d->ult = ant;
        }
        d->n--;
        free(p);
    }
}

void imprime_lista(Descritor *d)
{
    if (!esta_vazia(d))
    {
        NoLista *temp;
        for (temp = d->prim; temp != NULL; temp = temp->prox)
            printf("%d ", temp->info);
        printf("\n");
    }
    else
        printf("Lista vazia!");
}

void liberar_lista(Descritor *d)
{
    if (!esta_vazia(d))
    {
        NoLista *p, *q;
        for (p = d->prim; p != NULL; p = q)
        {
            q = p->prox;
            free(p);
        }
        d->n = 0;
        d->prim = NULL;
        d->ult = NULL;
    }
    else
        printf("A lista já se encontra vazia!");
}
