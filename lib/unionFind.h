#ifndef UNIONFIND_H_
#define UNIONFIND_H_

#include<stdlib.h>
#include<stdio.h>
#include"./distancia.h"

typedef struct capsulaUf{
  int posicaoVetOriginal;
  int tamanho;
  int raiz;
}capsulaUf;

capsulaUf** UF_init(int tamanho);
capsulaUf* criaCapsula(int posicao, int tamanho, int raiz);
int UF_find(int i, capsulaUf** vetorUf);
void UF_union(capsulaUf* p, capsulaUf* q, capsulaUf** vetorUf);

#endif // !UNIONFIND_H_