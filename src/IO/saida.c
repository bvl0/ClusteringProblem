#include "../../lib/saida.h"

void escreveSaida(capsulaUf*** matriz, int* tamanhos, char* saida, int k ){
  puts(saida);
  FILE *filesaida = fopen(saida, "w");
    for(int z =0; z<k;z++){
      int size = tamanhos[z];
      for(int x=0; x<size;x++){
        fprintf(filesaida, "%s, ",matriz[z][x]->nome);
      }
    fprintf(filesaida, "\n \n");
  }
  fclose(filesaida);
}