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

  // for(int i=0; i< quantLinhas; i++){
  //   puts(pontos[i]->nome);
  //   printf("%lf \n", pontos[i]->coordenadas[0]);
  //   printf("%lf \n", pontos[i]->coordenadas[1]);

  // }

  // printaDistancias(distancias,quantLinhas,quantCoordenadas);
  int tamanho = ((quantLinhas*(quantLinhas - 1))/2 );
  qsort(distancias,tamanho,sizeof(distancia*),sort);

  // printaDistancias(distancias,quantLinhas,quantCoordenadas);

  vetorUf = UF_init(quantLinhas, pontos);
  int limite = quantLinhas - k; //pra tirar as k-1 arestas;
  kruskall(vetorUf,tamanho,distancias,limite);
  // tiraK(vetorUf,k,quantLinhas);
  int tamanhoSemK= quantLinhas-k;
    for(int g =0 ; g < tamanhoSemK; g++){
        puts(vetorUf[g]->nome);
        printf("%i\n",UF_find( vetorUf[g]->raiz ,vetorUf));
    }
  matriz = testeSort(vetorUf,quantLinhas, k, tamanhos);
  escreveSaida(matriz, tamanhos, saida, k);

  
  
  //free pontos
  //free distancias
  //free vetoruf
  //free matriz
  
  
  for(int i=0; i< quantLinhas; i++){
      // printf("%lf \n", pontos[i]->coordenadas[0]);
    destroiPonto(pontos[i]);
    printf("%i \n", i);
  }

  // destroiUf(vetorUf, quantLinhas);
  // destroiMatriz(matriz,tamanhos,k);
  // destroiDistancias(distancias,quantLinhas,quantCoordenadas);
  free(tamanhos);
  free(pontos);
  fclose(file);
}