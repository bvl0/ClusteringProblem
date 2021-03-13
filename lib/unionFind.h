#ifndef UNIONFIND_H_
#define UNIONFIND_H_

#include<stdlib.h>
#include<stdio.h>
#include"./distancia.h"

typedef struct capsulaUf{
  int posicaoVetOriginal;
  int tamanho;
  int raiz;
  char *nome;
}capsulaUf;

capsulaUf** UF_init(int tamanho, ponto** pontos);
capsulaUf* criaCapsula(int posicao, int tamanho, int raiz, char* nome);
int UF_find(int i, capsulaUf** vetorUf);
void UF_union(int p, int q, capsulaUf** vetorUf);
void UF_free(capsulaUf *capsula);
void tiraK(capsulaUf** vetorUf, int k, int tamanho);
capsulaUf*** testeSort(capsulaUf** vetorUf, int tamanho, int k);
int sortUF(const void *a, const void *b);
#endif // !UNIONFIND_H_