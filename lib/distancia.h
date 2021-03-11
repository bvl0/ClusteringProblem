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


#endif // !DISTANCIA_H_