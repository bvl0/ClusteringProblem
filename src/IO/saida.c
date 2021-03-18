#include "../../lib/saida.h"

void escreveSaida(capsulaUf*** matriz, int* tamanhos, char* saida, int k, out* a ){
  //percorre a matriz printando as informações no arquivo de saida
  FILE *filesaida = fopen(saida, "w");
    for(int z =0; z<k;z++){
      int size = tamanhos[a[z].vetor];
      for(int x=0; x<size-1;x++){
        fprintf(filesaida, "%s,",matriz[a[z].vetor][x]->nome);
      }
    fprintf(filesaida, "%s \n",matriz[a[z].vetor][size-1]->nome);
  }
  fclose(filesaida);
}