#ifndef ENTRADAS_H_
#define ENTRADAS_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ponto.h"


ponto** leEntradas(FILE* file, ponto** pontos);
int contaCoordenada(FILE* file);
int contaLinhas(FILE* file);


#endif // !ENTRADAS_H_