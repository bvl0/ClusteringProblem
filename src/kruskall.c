#include"../lib/kruskall.h"

void kruskall(capsulaUf** vetorUf,int tamanho,distancia** distancias){
  for(int i =0; i<tamanho;i++){
    int ponto1 =distancias[i]->posP;
    int ponto2 =distancias[i]->posQ;
    if(UF_find(ponto1, vetorUf) != UF_find(ponto2, vetorUf)){
      UF_union(UF_find(ponto1, vetorUf),UF_find(ponto2, vetorUf),vetorUf);
    }
  }
}