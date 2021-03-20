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
  return novaCapsula;
}
capsulaUf* copiaCapsula(capsulaUf* a, int posicao, int tamanho, int raiz, char* nome){
  a->posicaoVetOriginal= posicao;
  a->raiz= raiz;
  a->tamanho = tamanho;
  return a;
}

void preencheAux(out* a, capsulaUf*** matriz, int* tamanhos, int k){
  for(int j = 0; j<k; j++){
    a[j].nomePrimeiro = matriz[j][0]->nome;
    a[j].vetor = j;
  }
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
}


void UF_free(capsulaUf *capsula){
  if (capsula != NULL){
      free(capsula);
  }
}

int lexo(const void *a, const void *b){
  struct capsulaUf *no1 = *(struct capsulaUf**)a;
  struct capsulaUf *no2 = *(struct capsulaUf**)b;

  return strcmp(no1->nome,no2->nome);
}

int lexo2(const void *a, const void *b){
  struct out *no1 = (struct out*)a;
  struct out *no2 = (struct out*)b;
  return strcmp(no1->nomePrimeiro,no2->nomePrimeiro);
}


capsulaUf*** testeSort(capsulaUf** vetorUf, int tamanho, int k, int *tamanhos){
  capsulaUf*** matriz = malloc(k*sizeof(capsulaUf**)); //aloca uma matriz com 1 vetor pra cada subconjunto
  int elementos = 0;
  int quantidade = 0;
  int *marcados = calloc(tamanho,sizeof(int)); // pra n repetir o desmembramento em pontos repetidos

 for(int i=0; i<tamanho ;i++){
    //se o nó n estiver marcado verifica se ele é uma raiz
    if(marcados[UF_find(vetorUf[i]->raiz,vetorUf)] != 1 && UF_find(vetorUf[i]->raiz,vetorUf) == vetorUf[i]->raiz ){
      int size= vetorUf[vetorUf[i]->raiz]->tamanho;// tamanho do vetor = quantidades de nó na arvore
      matriz[elementos]= malloc(size*sizeof(capsulaUf*));
      quantidade = 0;
      for(int j = 0; j<tamanho;j++){
        //todos os nos com a mesma raiz são copiados pra matriz
        if(vetorUf[j]->raiz == UF_find(vetorUf[i]->raiz,vetorUf)){
          matriz[elementos][quantidade]=vetorUf[j];
          quantidade++;
          marcados[j]=1;
        }
      }

    tamanhos[elementos]= quantidade;//guarda a quantidade de elementos por subgconjunto
    elementos++;
    }
  }
  free(marcados);
  //ordena todos os subconjuntos
  for(int i = 0; i < k ; i++){
    int size = tamanhos[i];
    qsort(matriz[i],size,sizeof(capsulaUf*),lexo);
  }
  //ordena os subconjuntos pelos primeiros elementos

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
      free(matriz[i]);
    }
    free(matriz);
  }