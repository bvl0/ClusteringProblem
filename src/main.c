#include<stdio.h>
#include<stdlib.h>

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
  pontos = leEntradas(file,pontos);
  int i=0;

  quantCoordenadas = contaCoordenada(file);
  quantLinhas = contaLinhas(file);

  distancias = calculaDistancias(pontos,quantLinhas,quantCoordenadas);

  int tamanho = ((quantLinhas*(quantLinhas - 1))/2 );
  qsort(distancias,tamanho,sizeof(distancia*),sort);


  vetorUf = UF_init(quantLinhas, pontos);
  int limite = quantLinhas - k; //pra tirar as k-1 arestas;
  kruskall(vetorUf,tamanho,distancias,limite);
  destroiDistancias(distancias,quantLinhas,quantCoordenadas);
  // tiraK(vetorUf,k,quantLinhas);
  int tamanhoSemK= quantLinhas-k;
  matriz = testeSort(vetorUf,quantLinhas, k, tamanhos);
  destroiUf(vetorUf, quantLinhas);
  escreveSaida(matriz, tamanhos, saida, k);
  
  for(int i=0; i< quantLinhas; i++){
    destroiPonto(pontos[i]);
  }

  
  destroiMatriz(matriz,tamanhos,k);
  
  free(tamanhos);
  free(pontos);
  fclose(file);
}