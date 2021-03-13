#include"../lib/kruskall.h"

void kruskall(capsulaUf** vetorUf,int tamanho,distancia** distancias){
  for(int i =0; i<tamanho;i++){
    int ponto1 =distancias[i]->posP;
    int ponto2 =distancias[i]->posQ;
    if(UF_find(vetorUf,ponto1) != UF_find(vetorUf,ponto2)){
      UF_union(UF_find(vetorUf,ponto1),UF_find(vetorUf,ponto2),vetorUf);
    }
  }
}