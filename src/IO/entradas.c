#include"../../lib/entradas.h"
extern ponto *criaPonto(char* nome,double *coordenadas);


ponto** leEntradas(FILE* file, ponto** pontos){
  // definição da maioria das variaveis
  ponto** novosPontos;
  int quantCoordenadas,quantPontos = 0;
  char *linha= malloc(1000*sizeof(char));
  size_t tamanho = 1000;
  char buffer[1000];
  memset(buffer,'\0',1000);
  double *coordenadas; 
  
  //conta quantas linhas tem no arquivo e da rewind no mesmo
  quantPontos = contaLinhas(file);

  //conta a quantidade de coordenas e da rewind
  quantCoordenadas = contaCoordenada(file);
  
  //aloca um vetor de pontos e um vetor de coordenadas 
     
  novosPontos = malloc(quantPontos*sizeof(ponto));
  rewind(file);
  //percorre o arquivo coletando as informações do ponto e guardando no devido lugar
  for(int i =0;i<quantPontos;i++){
    //pega uma linha
    getline(&linha,&tamanho,file);
    
    //aloca uma string pra guardar as informaçoes da linha e um vetor de string pra guardar as informações separadinhas
    char *dataBruta = strtok(linha, ",");
    char **data = malloc((quantCoordenadas +1) *sizeof(char*)); 
    coordenadas = malloc(quantCoordenadas*sizeof(double)); 
    //percorre a String da linha inteira separando em palavras
    int k = 0;
    while(dataBruta != NULL){
      strcpy(buffer,dataBruta);
      data[k] = strdup(buffer);
      memset(buffer,'\0',1000);
      dataBruta =strtok(NULL, ",");
      k++;
    }
    
    //coloca um \0 no ultimo caractere da ultima string(que é sempre um /n);
    size_t tamanhoString = strlen(data[quantCoordenadas]);
    data[quantCoordenadas][tamanhoString-1] = '\0';
    
    //coloca os dados das cordenadas num vetor pra posteriormente ser adicionado ao ponto
    for(int j=1;j<quantCoordenadas + 1 ;j++){
      coordenadas[j-1] = atof(data[j]);
    }
    
    //cria o ponto com o nome e suas respectivas coordenadas
    novosPontos[i] = criaPonto(data[0],coordenadas);

    //libera as strings
    for(int j=0;j<quantCoordenadas+1;j++){
      free(data[j]);
    }
    free(data);
    free(dataBruta);
  }
  //termina os frees e retorna os pontos do arquivo

  free(linha);
  rewind(file);
  return novosPontos;
}

int contaCoordenada(FILE* file){
  //função que percorre a linha e conta quantas coordenadas tem na mesma  
  char *linha= malloc(1000*sizeof(char));
  size_t tamanho = 1000;
  getline(&linha,&tamanho,file);
  
  int quantidade = 0;
  for(int i = 0; linha[i] != '\0';i++){
    if(linha[i]==','){
      quantidade++;
    }
  }
  rewind(file);
  free(linha);
  //retorna a ocorrencia
  return quantidade;
}

int contaLinhas(FILE* file){
  //função que conta as linhas do arquivo

  char *linha= malloc(1000*sizeof(char));
  size_t tamanho = 1000;
  int quantPontos=0;
  
  while(!feof(file)){
    getline(&linha,&tamanho,file);
    quantPontos++;
  }
  
  free(linha);
  rewind(file);
  
  return quantPontos-1;
}