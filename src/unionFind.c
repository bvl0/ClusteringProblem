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

void tiraK(capsulaUf** vetorUf, int k, int tamanho){
  for(int i=1;i<k;i++){
    free(vetorUf[tamanho-i]->nome);
    free(vetorUf[tamanho-i]);
    }
}

void sortMatriz(capsulaUf*** matrizUf, int tamanho, int k){
  for(int i =0; i<k;i++){
    //mudar dps pois a raiz vai ser 0 sempre
    printf("%i \n",matrizUf[i][0]->raiz);
    int pai = UF_find(matrizUf[i][0]->raiz, matrizUf[i]);
    printf("%i \n",matrizUf[i][pai]->tamanho);
    int tamanho = matrizUf[i][pai]->tamanho;
    qsort(matrizUf[i], tamanho,sizeof(capsulaUf*),sortUF);
  }
  // qsort(matrizUf,k,sizeof(matrizUf),sortUFfirst);
  // qsort(matrizUf, k,sizeof(capsulaUf**),sortUFfirst);
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

// capsulaUf*** testeSort(capsulaUf** vetorUf, int tamanho, int k){
//   capsulaUf*** matrizUf = malloc(k*sizeof(capsulaUf**));
  
//   int const1=0;
//   for(int f = 0; f< k ; f++){
//     for(int i=0; i< tamanho; i++){
//       capsulaUf *aux;
//       int const2 = 0;
//       printf("raiz %i",vetorUf[i]->raiz);
//       if(vetorUf[i]->raiz == i){
//         capsulaUf** matrizUf[const1] = malloc(vetorUf[i]->tamanho * sizeof(capsulaUf*));
//         aux=vetorUf[i];
//         matrizUf[const1][const2] =  vetorUf[i];
//         puts("salve");
//       }
      
//       // for(int j =0; j<tamanho;j++){
//       //   if(UF_find(vetorUf[j]->raiz, vetorUf) == aux->raiz && vetorUf[j] != aux);
//       //   matrizUf[const1][const2]= vetorUf[j];
//       //   const2++;
//       // }
//       if(vetorUf[i]->raiz == i)
//         const1= const1 + 1;
      
//       puts("muito animal");
//     }
//   }
//   // sortMatriz(matrizUf, tamanho, k);
//   return matrizUf;
// }

int lexo(const void *a, const void *b){
  struct capsulaUf *no1 = *(struct capsulaUf**)a;
  struct capsulaUf *no2 = *(struct capsulaUf**)b;

  if (strcmp(no1->nome, no2->nome) > 0){
    int aux=0;
    printf("no 1: %i no 2: %i\n", no1->raiz,no2->raiz);
    
    aux = no1->raiz;
    no1->raiz = no2->raiz;
    no2->raiz = aux;
    printf("no 1: %i no 2: %i\n", no1->raiz,no2->raiz);
    return 1; 
  }
  else if(strcmp(no1->nome, no2->nome) < 0){
    // int aux=0;
    // printf("no 1: %i no 2: %i\n", no1->raiz,no2->raiz);
    // aux = no1->raiz;
    // no1->raiz = no2->raiz;
    // no2->raiz = aux;
    // printf("no 1: %i no 2: %i\n", no1->raiz,no2->raiz);
    return -1; 
  }
  else{
    return 0;
  }
}

void testeSort(capsulaUf** vetorUf, int tamanho, int k){
  qsort(vetorUf,tamanho,sizeof(capsulaUf*),lexo);

}



// void UF_print(capsulaUf **capsulas, ponto** pontos,int tamanho)
// {
//     for (int i = 0; i < tamanho; i++)
//     {
//         printf("Ponto: %s Raiz: %s\n", capsulas[i]->raiz, pontos[capsulas[i]->posicaoVetOriginal]->nome;
//     }
// }


// int raizUf(capsulaUf);