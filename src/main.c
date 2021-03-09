#include<stdio.h>
#include<stdlib.h>

#include"../lib/ponto.h"
#include"../lib/entradas.h"
#include"../lib/distancia.h"

int main(int argc, char** argv){
  //definição da maioria das variaveis
  char *fileName = argv[1];
  FILE *file= fopen(fileName,"r");
  int quantLinhas,quantCoordenadas=0;
  ponto** pontos;

  //le as entradas do arquivo e retorna 
  pontos = leEntradas(file,pontos);
  int i=0;
  
  // quantCoordenadas = contaCoordenada(file);
  quantLinhas = contaLinhas(file);

  // for(int i=0; i< quantLinhas; i++){
  //   puts(pontos[i]->nome);
  //   printf("%lf \n", pontos[i]->coordenadas[0]);
  //   printf("%lf \n", pontos[i]->coordenadas[1]);

  // }

  for(int i=0; i< quantLinhas; i++){
      // printf("%lf \n", pontos[i]->coordenadas[0]);
    destroiPonto(pontos[i]);
    printf("%i \n", i);
  }


  free(pontos);
  fclose(file);
}