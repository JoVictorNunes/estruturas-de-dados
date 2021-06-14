#ifndef LISTALINEAR
#define LISTALINEAR

#define MAX 10

typedef struct lista
{
    int vet[MAX];
    int ultimo;
} Lista;

int estaVazia(Lista *l);
void criarLista(Lista *l);
void inserirElemento(Lista *l, int v);
void removerElemento(Lista *l, int i);
void imprimeLista(Lista *l);

#endif