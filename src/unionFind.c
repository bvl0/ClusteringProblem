#include"../lib/unionFind.h"
//codigo baseadissimo no slide hehe


capsulaUf** UF_init(int tamanho) {
  capsulaUf** vetorUf = malloc(tamanho*sizeof(capsulaUf*));
  for (int i = 0; i < tamanho; i++) {
    vetorUf[i] = criaCapsula(i,0,i); // Cada objeto comeca na sua propria componente.
  } // N acessos ao array.
  return vetorUf;
}

capsulaUf* criaCapsula(int posicao, int tamanho, int raiz){
  capsulaUf* novaCapsula = malloc(sizeof(capsulaUf));
  novaCapsula->posicaoVetOriginal= posicao;
  novaCapsula->raiz= raiz;
  novaCapsula->tamanho = tamanho;
}

int UF_find(int i, capsulaUf** vetorUf) {
  while (i != vetorUf[i]->raiz){
    vetorUf[i]->raiz = vetorUf[vetorUf[i]->raiz]->raiz;
    i = vetorUf[i]->raiz;
  }  // Buscar o pai ate a raiz.
  return i; // Profundidade de i acessos.
}

void UF_union(int p, int q, capsulaUf** vetorUf) {
  int i = UF_find(p,vetorUf); // Modifique raiz de p para a raiz de q.
  int j = UF_find(q,vetorUf); // Profundidade de p+q acessos.

  if (i == j) return;
  if (vetorUf[i]->tamanho < vetorUf[j]->tamanho) { 
    vetorUf[i]->raiz = j; 
    vetorUf[j]->tamanho += vetorUf[i]->tamanho; 
    }
  else { 
    vetorUf[j]->raiz = i; 
    vetorUf[i]->tamanho += vetorUf[j]->tamanho; 
  }
};


void UF_free(capsulaUf *capsula){
  if (capsula != NULL){
      free(capsula);
  }
}

void tiraK(capsulaUf** vetorUf, int k, int tamanho){
  for(int i=0;i<k;i++){
    capsulaUf *maior;
    for(int j=0; j<tamanho;j++){
        maior = vetorUf[j];
      if(vetorUf[j]->tamanho > maior->tamanho ){
        maior = vetorUf[j];
      }
    UF_free(maior);
    }
  }
}

// void UF_print(capsulaUf **capsulas, ponto** pontos,int tamanho)
// {
//     for (int i = 0; i < tamanho; i++)
//     {
//         printf("Ponto: %s Raiz: %s\n", capsulas[i]->raiz, pontos[capsulas[i]->posicaoVetOriginal]->nome;
//     }
// }


int raizUf(capsulaUf)