#include"../lib/ponto.h"

ponto *criaPonto(char* nome,double *coordenadas){
  //aloca um novo ponto
  ponto* novoPonto = malloc(sizeof(ponto));
  
  //confere se as entradas sao validas, se sim, as insere no ponto
  if(nome != NULL){
    novoPonto -> nome = strdup(nome);
    novoPonto -> coordenadas = coordenadas;
  }else{
    puts("nome invalido");
    exit(1);
  }

  return novoPonto;
}

void destroiPonto(ponto* ponto){
  free(ponto -> nome);
  free(ponto -> coordenadas);
  free(ponto);
}

double* coordenadas(ponto* ponto){
  return ponto->coordenadas;
}
