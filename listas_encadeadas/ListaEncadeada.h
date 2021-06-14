#ifndef LISTAENCADEADA
#define LISTAENCADEADA

typedef struct nolista
{
    int info;
    struct nolista *prox;
} NoLista;

int conta_elementos(NoLista **l);
int esta_vazia(NoLista **l);
void criar_lista(NoLista **l);
void insere_elemento_inicio(NoLista **l, int v);
void imprime_lista(NoLista **l);
void remover(NoLista **l, int v);
void libera(NoLista **l);
void insere_ordenado(NoLista **l, int v);
NoLista *busca_elemento(NoLista **l, int v);

#endif