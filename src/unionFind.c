#include"../lib/unionFind.h"
//codigo baseadissimo no slide hehe
typedef struct capsulaUf{
  int posicaoVetOriginal;
  int tamanho;
  int raiz;
}capsulaUf;

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

void UF_union(capsulaUf* p, capsulaUf* q, capsulaUf** vetorUf) {
  int i = UF_find(p->raiz,vetorUf); // Modifique raiz de p para a raiz de q.
  int j = UF_find(q->raiz,vetorUf); // Profundidade de p+q acessos.

  if (i == j) return;
  if (vetorUf[i]->tamanho < vetorUf[j]->tamanho) { 
    vetorUf[i]->raiz = j; 
    vetorUf[j]->tamanho += vetorUf[i]->tamanho; 
    }
  else { 
    vetorUf[j]->raiz = i; 
    vetorUf[i]->tamanho += vetorUf[j]->tamanho; 
  }
}