#ifndef LISTADESCRITOR
#define LISTADESCRITOR

typedef struct nolista
{
    int info;
    struct nolista *prox;
} NoLista;

typedef struct descritor
{
    NoLista *prim;
    NoLista *ult;
    int n;
} Descritor;

int esta_vazia(Descritor *d);
void criar_lista(Descritor *d);
void inserir_elemento_inicio(Descritor *d, int v);
void insere_elemento_fim(Descritor *d, int v);
void remove_elemento(Descritor *d, int v);
void imprime_lista(Descritor *d);
void liberar_lista(Descritor *d);

#endif