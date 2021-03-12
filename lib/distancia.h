#ifndef DISTANCIA_H_
#define DISTANCIA_H_

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"ponto.h"

typedef struct distancia{
  //posição dos pontos no vetor de pontos
  int posP,posQ;
  double dist;
}distancia;

distancia* criaDistancia(int posP, int posQ, double dist);
distancia** calculaDistancias(ponto** pontos,int quantLinhas, int quantCoordenadas);
void destroiDistancias(distancia** distancias, int quantlinhas, int quantCoordenadas);
void printaDistancias(distancia** distancias, int quantLinhas, int quantCoordenadas);
int sort(const void *a, const void *b);

#endif // !DISTANCIA_H_