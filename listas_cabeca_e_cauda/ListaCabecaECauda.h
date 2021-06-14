#ifndef LISTACABECAECAUDA_H
#define LISTACABECAECAUDA_H

typedef struct nolista
{
    int info;
    struct nolista *prox;
} NoLista;

typedef struct lista
{
    NoLista *cabeca;
    NoLista *cauda;
} Lista;

void criar_lista(Lista *l);
int esta_vazia(Lista *l);
void inserir_elemento_inicio(Lista *l, int v);
void inserir_elemento_fim(Lista *l, int v);
void remover(Lista *l, int v);
void liberar_lista(Lista *l);
void imprimir_lista(Lista *l);

#endif