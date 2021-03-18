#include"../lib/kruskall.h"

void kruskall(capsulaUf** vetorUf,int tamanho,distancia** distancias, int limite){
  int pontos=0;
  int contador=0;
  for(int i =0; contador < limite;i++){
    int ponto1 =distancias[i]->posP;
    int ponto2 =distancias[i]->posQ;
      pontos ++;
    if(UF_find(ponto1, vetorUf) != UF_find(ponto2, vetorUf)){
      UF_union(ponto1,ponto2,vetorUf);
      contador++;
    }
  }
}