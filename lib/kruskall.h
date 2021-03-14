#ifndef KRUSKALL_H_
#define KRUSKALL_H_

#include<stdlib.h>
#include<stdio.h>
#include"./unionFind.h"


void kruskall(capsulaUf** vetorUf,int tamanho,distancia** distancias, int k);
#endif // !KRUSKALL_H_