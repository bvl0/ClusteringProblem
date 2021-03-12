#include"../lib/distancia.h"


distancia* criaDistancia(int posP, int posQ, double dist){
  distancia* novaDistancia= malloc(sizeof(distancia));
  novaDistancia->dist = dist;
  novaDistancia->posP = posP;
  novaDistancia->posQ = posQ;
  return novaDistancia;
}
distancia** calculaDistancias(ponto** pontos,int quantLinhas, int quantCoordenadas){
  distancia** vetorDistancia = malloc(((quantLinhas*(quantLinhas - 1))/2 )* sizeof(distancia*));
  int distanciasCalculadas= 0;
  double distancia = 0;
  //percorre o vetor de pontos pegando um ponto
  for(int i =0 ; i < quantLinhas; i++){
    //percorre o vetor de pontos pegando o proximo
    for(int j = i+1; j < quantLinhas;j++){
      float somaCoordenadas=0;
      //percorre cada coordenada dos pontos subitraindo-as e elevando ao quadrado
      for(int k = 0; k < quantCoordenadas;k++){
        somaCoordenadas = somaCoordenadas + (coordenadas(pontos[j])[k] - coordenadas(pontos[i])[k]) * (coordenadas(pontos[j])[k] - coordenadas(pontos[i])[k]);
      }
      //faz a raiz quadrada das somas
      distancia = sqrt(somaCoordenadas);
      //coloca o resultado no vetor de distancias
      vetorDistancia[distanciasCalculadas] = criaDistancia(i,j,distancia);
      distanciasCalculadas++;
    }
  }
  return vetorDistancia;
}

int sort(const void *a, const void *b){
  struct distancia *distA = *(distancia**)a;
  struct distancia *distb = *(distancia**)b;
  
  if(distA->dist > distb->dist){
    return 1;
  }
  else if(distA->dist < distb->dist){
    return -1;
  }
  else{
  return 0;
  }

//  return distA->dist - distb->dist;
}





void destroiDistancias(distancia** distancias, int quantLinhas, int quantCoordenadas){
  int tamanho = ((quantLinhas*(quantLinhas - 1))/2 );
  for(int i=0; i < tamanho; i++){
    free(distancias[i]);
  }
  free(distancias);
}

void printaDistancias(distancia** distancias, int quantLinhas, int quantCoordenadas){
  int tamanho = ((quantLinhas*(quantLinhas - 1))/2 );
  for(int i=0; i < tamanho; i++){
    printf("distancia de a: %i ate b: %i :  %lf \n",distancias[i]->posP,distancias[i]->posQ,distancias[i]->dist);
  }
}

distancia* calculaDistancia(double* coordenadas);