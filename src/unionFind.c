#include"../lib/unionFind.h"
//codigo baseadissimo no slide hehe


capsulaUf** UF_init(int tamanho, ponto** pontos) {
  capsulaUf** vetorUf = malloc(tamanho*sizeof(capsulaUf*));
  for (int i = 0; i < tamanho; i++) {
    vetorUf[i] = criaCapsula(i,1,i,pontos[i]->nome ); // Cada objeto comeca na sua propria componente.
  } // N acessos ao array.
  return vetorUf;
}

capsulaUf* criaCapsula(int posicao, int tamanho, int raiz, char* nome){
  capsulaUf* novaCapsula = malloc(sizeof(capsulaUf));
  novaCapsula->posicaoVetOriginal= posicao;
  novaCapsula->raiz= raiz;
  novaCapsula->tamanho = tamanho;
  novaCapsula->nome = strdup(nome);
}

int UF_find(int i, capsulaUf** vetorUf) {
 if(i ==-1)
     return -1;
  while (i != vetorUf[i]->raiz){
    // printf("raiz %i \n",vetorUf[i]->raiz);
    vetorUf[i]->raiz = vetorUf[vetorUf[i]->raiz]->raiz;
    // printf("raiz %i \n",vetorUf[i]->raiz);
    i = vetorUf[i]->raiz;
  }
  // printf(" saiu %i \n",vetorUf[i]->raiz);  // Buscar o pai ate a raiz.
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


int sortUFfirst(const void *a, const void *b){
  struct capsulaUf *subconjunto1 = **(capsulaUf***)a ;
  struct capsulaUf *subconjunto2 = **(capsulaUf***)b ;
  return strcmp(subconjunto1->nome, subconjunto2->nome);
}

int sortUF(const void *a, const void *b){
  struct capsulaUf *subconjunto1 = *(capsulaUf**)a;
  struct capsulaUf *subconjunto2 = *(capsulaUf**)b;
  return strcmp(subconjunto1->nome, subconjunto2->nome);

//  return distA->dist - distb->dist;
}



int lexo(const void *a, const void *b){
  struct capsulaUf *no1 = *(struct capsulaUf**)a;
  struct capsulaUf *no2 = *(struct capsulaUf**)b;

  return strcmp(no1->nome,no2->nome);
}
// int lexo2(const void *a, const void *b){
//   struct capsulaUf *no1 = *(struct capsulaUf**)a;
//   struct capsulaUf *no2 = *(struct capsulaUf**)b;

//   return strcmp(no1->nome,no2->nome);
// }

void sortnamao(capsulaUf*** matriz,int k, int* tamanhos){
int trocado =0;
while(trocado == 0){
trocado=1;
for(int i =0; i <k -1;i++){
  if(strcmp(matriz[i][0]->nome, matriz[i+1][0]->nome) > 0){
    capsulaUf** aux = matriz[i+1];
    int auxt = tamanhos[i+1];
    
    matriz[i+1]=matriz[i];
    tamanhos[i+1]= tamanhos[i];
    matriz[i] = aux;
    tamanhos[i]= auxt;
    trocado=0;
  }
  
}

}
}


capsulaUf*** testeSort(capsulaUf** vetorUf, int tamanho, int k, int *tamanhos){
  //  qsort(vetorUf,tamanho,sizeof(capsulaUf*),lexo);
  capsulaUf*** matriz = malloc(k*sizeof(capsulaUf**));
  int elementos = 0;
  int quantidade = 0;
  int *marcados = calloc(tamanho,sizeof(int));

 for(int i=0; i<tamanho ;i++){
    //sempre quando achar a raiz tranformar a raiz de todos nos em -1;
    if(marcados[UF_find(vetorUf[i]->raiz,vetorUf)] != 1 && UF_find(vetorUf[i]->raiz,vetorUf) == vetorUf[i]->raiz){
      int size= vetorUf[UF_find(vetorUf[i]->raiz,vetorUf)]->tamanho;
      matriz[elementos]= malloc(size*sizeof(capsulaUf*));
      quantidade = 0;
      for(int j = 0; j<tamanho;j++){
        if(vetorUf[j]->raiz == UF_find(vetorUf[i]->raiz,vetorUf)){
          matriz[elementos][quantidade]=criaCapsula(vetorUf[j]->posicaoVetOriginal,vetorUf[j]->tamanho,vetorUf[j]->raiz,vetorUf[j]->nome);
          quantidade++;
        }
      }
      for(int j = 0; j<tamanho;j++){

          if(vetorUf[j]->raiz == UF_find(vetorUf[i]->raiz,vetorUf)){
          marcados[j]=1;
          }
      }
    elementos++;
    tamanhos[elementos-1]= quantidade;
    }
  }
  for(int i = 0; i < k ; i++){
    int size = tamanhos[i];
    for(int x=0; x<size;x++){
      qsort(matriz[i],size,sizeof(capsulaUf*),lexo);
    }
  }
   sortnamao(matriz,k,tamanhos);
  return matriz;
}



  void destroiUf(capsulaUf **vetorUf, int quantLinhas){
    for(int i=0; i<quantLinhas; i++){
      free(vetorUf[i]->nome);
      free(vetorUf[i]);
    }
    free(vetorUf);
  }
  void destroiMatriz(capsulaUf*** matriz,int *tamanhos, int k){
    for(int i=0; i<k; i++){
      destroiUf(matriz[i],tamanhos[i]);
    }
    free(matriz);
  }