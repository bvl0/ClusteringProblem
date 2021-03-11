#ifndef PONTO_H_
#define PONTO_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ponto {
  char* nome;
  double *coordenadas;
}ponto;

ponto* criaPonto(char* nome,double *pontos);
void destroiPonto(ponto* ponto);
double* coordenadas(ponto* ponto);
#endif // !PONTO_H_