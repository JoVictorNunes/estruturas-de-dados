#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"

// definição do tipo hash
struct hash
{
  int qtd, TABLE_SIZE;
  struct aluno **itens;
};

Hash *criaHash(int TABLE_SIZE)
{
  Hash *ha;
  ha = (Hash *)malloc(sizeof(Hash));

  if (ha != NULL)
  {
    int i;
    ha->TABLE_SIZE = TABLE_SIZE;
    ha->itens = (struct aluno **)malloc(TABLE_SIZE * sizeof(struct aluno *));

    if (ha->itens == NULL)
    {
      free(ha);
      return NULL;
    }

    ha->qtd = 0;

    for (i = 0; i < ha->TABLE_SIZE; i++)
    {
      ha->itens[i] = NULL;
    }
  }

  return ha;
}

void liberaHash(Hash *ha)
{
  if (ha != NULL)
  {
    int i;

    for (i = 0; i < ha->TABLE_SIZE; i++)
    {
      if (ha->itens[i] != NULL)
      {
        free(ha->itens[i]);
      }
    }

    free(ha->itens);
    free(ha);
  }
}

int chaveDivisao(int chave, int TABLE_SIZE)
{
  return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

int chaveMultiplicacao(int chave, int TABLE_SIZE)
{
  float A = 0.6180339887;
  float val = chave * A;
  val = val - (int)val;

  return (int)(TABLE_SIZE * val);
}

int valorString(char *str)
{
  int i, valor = 7;
  int tam = strlen(str);

  for (i = 0; i < tam; i++)
  {
    valor = 31 * valor + (int)str[i];
  }

  return valor;
}

int insereHash_SemColisao(Hash *ha, struct aluno al)
{
  if (ha == NULL || ha->qtd == ha->TABLE_SIZE)
  {
    return 0;
  }

  int chave = al.matricula;
  // int chave = valorString(al.nome);
  int pos = chaveDivisao(chave, ha->TABLE_SIZE);
  struct aluno *novo;
  novo = (struct aluno *)malloc(sizeof(struct aluno));

  if (novo == NULL)
  {
    return 0;
  }

  *novo = al;
  ha->itens[pos] = novo;
  ha->qtd++;
  return 1;
}

int buscaHash_SemColisao(Hash *ha, int mat, struct aluno *al)
{
  if (ha == NULL)
  {
    return 0;
  }

  int pos = chaveDivisao(mat, ha->TABLE_SIZE);

  if (ha->itens[pos] == NULL)
  {
    return 0;
  }

  *al = *(ha->itens[pos]);
  return 1;
}

// continuar em HASHING UNIVERSAL

int main(int argc, char const *argv[])
{
  Hash *ha;
  struct aluno al;
  ha = criaHash(1427);
  // liberaHash(ha);
  int x = insereHash_SemColisao(ha, al);
  return 0;
}
