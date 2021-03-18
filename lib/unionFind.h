#ifndef UNIONFIND_H_
#define UNIONFIND_H_

#include<stdlib.h>
#include<stdio.h>
#include"./distancia.h"
#include<string.h>

typedef struct capsulaUf{
  int posicaoVetOriginal;
  int tamanho;
  int raiz;
  char *nome;
}capsulaUf;

typedef struct out{
  int vetor;
  char *nomePrimeiro;
}out;

capsulaUf** UF_init(int tamanho, ponto** pontos);
capsulaUf* criaCapsula(int posicao, int tamanho, int raiz, char* nome);
capsulaUf* copiaCapsula(capsulaUf* a, int posicao, int tamanho, int raiz, char* nome);
void preencheAux(out* a, capsulaUf*** matriz, int* tamanhos, int k);
int UF_find(int i, capsulaUf** vetorUf);
void UF_union(int p, int q, capsulaUf** vetorUf);
void UF_free(capsulaUf *capsula);
void tiraK(capsulaUf** vetorUf, int k, int tamanho);
int sortUF(const void *a, const void *b);
int sortUFfirst(const void *a, const void *b);
// capsulaUf** lexo(capsulaUf** vetorUf, int i, int j);
int lexo(const void *a, const void *b);
int lexo2(const void *a, const void *b);

void sortnamao(capsulaUf*** matriz,int k, int* tamanhos);

capsulaUf*** testeSort(capsulaUf** vetorUf, int tamanho, int k, int *tamanhos);
void destroiUf(capsulaUf **vetorUf, int quantLinhas);
void destroiMatriz(capsulaUf*** matriz,int *tamanhos, int k);

#endif // !UNIONFIND_H_