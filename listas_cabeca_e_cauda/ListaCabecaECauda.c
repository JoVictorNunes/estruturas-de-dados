#include <stdio.h>
#include <stdlib.h>
#include "ListaCabecaECauda.h"

void criar_lista(Lista *l)
{
    l->cabeca = (NoLista *)malloc(sizeof(NoLista));
    l->cauda = (NoLista *)malloc(sizeof(NoLista));
    if (l->cabeca != NULL && l->cauda != NULL)
    {
        l->cabeca->prox = l->cauda;
        l->cauda->prox = NULL;
    }
    else
    {
        printf("Não foi possível alocar espaço!");
        exit(1);
    }
}

int esta_vazia(Lista *l)
{
    return l->cabeca->prox == l->cauda;
}

void inserir_elemento_inicio(Lista *l, int v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL)
    {
        novo->info = v;
        novo->prox = l->cabeca->prox;
        l->cabeca->prox = novo;
    }
    else
    {
        printf("Não foi possível alocar espaço!");
        exit(1);
    }
}

void inserir_elemento_fim(Lista *l, int v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL)
    {
        if (esta_vazia(l))
            inserir_elemento_inicio(l, v);
        else
        {
            NoLista *ult = NULL;
            novo->info = v;
            for (NoLista *p = l->cabeca->prox; p != l->cauda; p = p->prox)
                ult = p;
            ult->prox = novo;
            novo->prox = l->cauda;
        }
    }
    else
        printf("Não foi possível alocar espaço!");
}

void remover(Lista *l, int v)
{
    NoLista *ant = l->cabeca, *p;
    for (p = l->cabeca->prox; p->info != v && p != l->cauda; p = p->prox)
        ant = p;
    if (p == l->cauda)
        printf("Elemento não encontrado!");
    else
    {
        ant->prox = p->prox;
        free(p);
    }
}

void liberar_lista(Lista *l)
{
    if (!esta_vazia(l))
    {
        NoLista *prox;
        for (NoLista *p = l->cabeca->prox; p != l->cauda; p = prox)
        {
            prox = p->prox;
            free(p);
        }
        l->cabeca->prox = l->cauda;
    }
    else
        return;
}

void imprimir_lista(Lista *l)
{
    if (!esta_vazia(l))
    {
        for (NoLista *p = l->cabeca->prox; p != l->cauda; p = p->prox)
        {
            printf("%d ", p->info);
        }
        printf("\n");
    }
    else
        printf("Lista vazia!");
}
