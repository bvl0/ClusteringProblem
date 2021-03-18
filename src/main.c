#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"../lib/ponto.h"
#include"../lib/entradas.h"
#include"../lib/distancia.h"
#include"../lib/unionFind.h"
#include"../lib/kruskall.h"
#include"../lib/saida.h"

int main(int argc, char** argv){
  //definição da maioria das variaveis
  char *fileName = argv[1];
  FILE *file= fopen(fileName,"r");
  int quantLinhas,quantCoordenadas=0;
  ponto** pontos;
  distancia** distancias;
  capsulaUf** vetorUf;
  int k = atoi(argv[2]);
  char *saida = argv[3];
  capsulaUf*** matriz;
  int *tamanhos = malloc(k*sizeof(int));
  //le as entradas do arquivo e retorna 
  clock_t tempo = clock();
  pontos = leEntradas(file,pontos);
  int i=0;
  quantCoordenadas = contaCoordenada(file);
  quantLinhas = contaLinhas(file);
  
  tempo = clock() - tempo;
  double tempoEntradas = ((double)tempo) / CLOCKS_PER_SEC;
  
  tempo = clock();
  distancias = calculaDistancias(pontos,quantLinhas,quantCoordenadas);
  tempo = clock() - tempo;
  double tempoCalcDist = ((double)tempo) / CLOCKS_PER_SEC;
  
  tempo = clock();
  int tamanho = ((quantLinhas*(quantLinhas - 1))/2 );
  qsort(distancias,tamanho,sizeof(distancia*),sort);
  tempo = clock()- tempo;
  double tempoOrdDist = ((double)tempo) / CLOCKS_PER_SEC;
  
  tempo = clock();
  vetorUf = UF_init(quantLinhas, pontos);
  int limite = quantLinhas - k; //pra tirar as k-1 arestas;
  kruskall(vetorUf,tamanho,distancias,limite);
  tempo = clock() - tempo;
  double tempokruskall = ((double)tempo) / CLOCKS_PER_SEC;

  destroiDistancias(distancias,quantLinhas,quantCoordenadas);
  int tamanhoSemK= quantLinhas-k;
  
  tempo = clock();
  matriz = testeSort(vetorUf,quantLinhas, k, tamanhos);
  destroiUf(vetorUf, quantLinhas);
  escreveSaida(matriz, tamanhos, saida, k);
  tempo = clock() -  tempo;
  double temposaida = ((double)tempo) / CLOCKS_PER_SEC;

  for(int i=0; i< quantLinhas; i++){
    destroiPonto(pontos[i]);
  }

  
  printf("Tempo entradas: %lf  | Tempo calculando distancia: %lf | Tempo ordenando distancia: %lf | tempo kruskall: %lf | tempo saida: %lf",tempoEntradas,tempoCalcDist,tempoOrdDist,tempokruskall,temposaida);
  
  destroiMatriz(matriz,tamanhos,k);
  free(tamanhos);
  free(pontos);
  fclose(file);
}