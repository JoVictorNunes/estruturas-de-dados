#include <stdio.h>
#include <stdlib.h>

typedef struct nolista
{
    float info;
    struct nolista *prox;
} NoLista;

typedef struct pilha
{
    NoLista *topo;
} Pilha;

Pilha *criarPilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p != NULL)
    {
        p->topo = NULL;
        return p;
    }
    else
        return NULL;
}

int estaVazia(Pilha *p)
{
    return p->topo == NULL;
}

void push(Pilha *p, float v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    novo->info = v;
    novo->prox = p->topo;
    p->topo = novo;
}

float pop(Pilha *p)
{
    if (p->topo != NULL)
    {
        NoLista *q = p->topo;
        p->topo = q->prox;
        float info = q->info;
        free(q);
        return info;
    }
}

void liberaPilha(Pilha *p)
{
    NoLista *prox;
    for (NoLista *q = p->topo; q != NULL; q = prox)
    {
        prox = q->prox;
        free(q);
    }
    free(p);
    p = NULL;
}

void imprimePilha(Pilha *p)
{
    if (!estaVazia(p))
        for (NoLista *q = p->topo; q != NULL; q = q->prox)
            printf("%.2f ", q->info);
    else
        printf("Lista vazia!");
    printf("\n");
}

void verTopo(Pilha *p)
{
    printf("%.2f\n", p->topo->info);
}

void concatenaPilhas1(Pilha *p1, Pilha *p2)
{
    if (!estaVazia(p1) && !estaVazia(p2))
    {
        NoLista *aux1 = p1->topo, *aux2 = p2->topo;
        Pilha *pAux = criarPilha();
        if (pAux != NULL)
        {
            while (!estaVazia(p2))
                push(pAux, pop(p2));
            while (!estaVazia(p1))
                push(pAux, pop(p1));
        }
        while (!estaVazia(pAux))
            push(p1, pop(pAux));
        liberaPilha(pAux);
    }
}

void concatenaPilhas2(Pilha *p1, Pilha *p2)
{
    if (!estaVazia(p1) && !estaVazia(p2))
    {
        NoLista *last = p2->topo;
        for (last; last->prox != NULL; last = last->prox)
            ;
        last->prox = p1->topo;
        *p1 = *p2;
        p2 = criarPilha();
    }
}

int main()
{
    Pilha *pilha = criarPilha();
    Pilha *pilha2 = criarPilha();
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);
    push(pilha, 4);
    imprimePilha(pilha);
    push(pilha2, 2);
    push(pilha2, 1);
    push(pilha2, 6);
    push(pilha2, 9);
    imprimePilha(pilha2);
    concatenaPilhas2(pilha, pilha2);
    imprimePilha(pilha);
    return 0;
}
