#include <stdio.h>
#include <stdlib.h>
#include "ListaLinear.h"
#define MAX 10

void criarLista(Lista *l)
{
	l->ultimo = 0;
}

int estaVazia(Lista *l)
{
	if (l->ultimo == 0)
		return 1;
	else
		return 0;
}

void inserirElemento(Lista *l, int v)
{
	if (l->ultimo < MAX)
	{
		l->vet[l->ultimo] = v;
		l->ultimo++;
	}
	else
		printf("Impossível armazenar o valor. Lista cheia!");
}

void removerElemento(Lista *l, int i)
{ // Remove o i-ésimo elemento da lista
	if (!estaVazia(l))
	{
		for (i; i < MAX - 1; i++)
			l->vet[i] = l->vet[i + 1];
		l->ultimo--;
	}
}

void imprimeLista(Lista *l)
{
	if (!estaVazia(l))
	{
		for (int c = 0; c < l->ultimo; c++)
			printf("%d ", l->vet[c]);
		printf("\n");
	}
	else
		printf("Lista vazia!");
}
