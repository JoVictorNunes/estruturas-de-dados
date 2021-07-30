#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct pilha
{
    float info[N];
    int n; // Armazena a próxima posição disponível para inserir.
} Pilha;

Pilha *criarPilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p != NULL)
    {
        p->n = 0;
        return p;
    }
    else
        return NULL;
}

int estaVazia(Pilha *p)
{
    return p->n == 0;
}

int estaCheia(Pilha *p)
{
    return p->n == N;
}

void push(Pilha *p, float v)
{
    if (!estaCheia(p))
    {
        p->info[p->n] = v;
        p->n++;
    }
    else
        printf("Pilha cheia!");
}

float pop(Pilha *p)
{
    if (!estaVazia(p))
    {
        p->n--;
        return p->info[p->n];
    }
}

void libera(Pilha *p)
{
    free(p);
}

void imprimePilha(Pilha *p)
{
    if (!estaVazia(p))
    {
        for (int c = p->n - 1; c >= 0; c--)
            printf("%.2f ", p->info[c]);
        printf("\n");
    }
    else
        printf("Lista vazia");
}

float verTopo(Pilha *p)
{
    if (!estaVazia(p))
        return p->info[p->n - 1];
}

int main()
{
    Pilha *p = criarPilha();
    push(p, 1);
    push(p, 2);
    push(p, 3);
    push(p, 4);
    push(p, 5);
    push(p, 6);
    push(p, 7);
    imprimePilha(p);
    printf("%.2f", verTopo(p));
    return 0;
}
