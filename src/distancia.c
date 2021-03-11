#include"../lib/distancia.h"


distancia* criaDistancia(int posP, int posQ, double dist){
  distancia* novaDistancia= malloc(sizeof(distancia));
  novaDistancia->dist = dist;
  novaDistancia->posP = posP;
  novaDistancia->posQ = posQ;
  return novaDistancia;
}
distancia** calculaDistancias(ponto** pontos,int quantLinhas, int quantCoordenadas){
  distancia** vetorDistancia = malloc(quantCoordenadas *(quantCoordenadas - 1)/2);
  int distanciasCalculadas= 0;
  double distancia = 0;
  //percorre o vetor de pontos pegando um ponto
  for(int i =0 ; i < quantLinhas; i++){
    //percorre o vetor de pontos pegando o proximo
    for(int j = i+1; j < quantLinhas;j++){
      float somaCoordenadas=0;
      //percorre cada coordenada dos pontos subitraindo-as e elevando ao quadrado
      for(int k = 0; k < quantCoordenadas;k++){
        somaCoordenadas+= (coordenadas(pontos[j])[k] - coordenadas(pontos[i])[k]) * (coordenadas(pontos[j])[k] - coordenadas(pontos[i])[k]);
      }
      //faz a raiz quadrada das somas
      distancia = sqrt(somaCoordenadas);
      //coloca o resultado no vetor de distancias
      vetorDistancia[distanciasCalculadas] = criaDistancias(i,j,distancia);
      distanciasCalculadas++;
    }
  }
  return vetorDistancia;
}

distancia* calculaDistancia(double* coordenadas);