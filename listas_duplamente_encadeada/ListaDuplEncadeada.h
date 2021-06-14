#ifndef LISTADUPLENCADEADA
#define LISTADUPLENCADEADA

typedef struct nolista
{
    int info;
    struct nolista *prox;
    struct nolista *ant;
} NoLista;

void criar_lista(NoLista **l);
void imprime_lista(NoLista **l);
void inserir_elemento(NoLista **l, int v);
void remover_elemento(NoLista **l, int v);
void imprime_ordem_inversa(NoLista **l);
void libera(NoLista **l);
int esta_vazia(NoLista **l);
NoLista *ultimo(NoLista **l);
NoLista *busca_elemento(NoLista **l, int v);

#endif