//Crie um vetor de N números inteiros aleatórios e utilize M threads para procurar 
//determinado número informado pelo usuário. Cada thread deverá pesquisar somente uma 
//parte do vetor. Quando encontrar o número, deverá imprimir: 
//Thread <ID> encontrou o valor <VALOR> na posição <POSICAO> 
//Caso o número apareça várias vezes, todas as ocorrências poderão ser apresentadas. Não 
//é necessário impedir que múltiplas threads imprimam simultaneamente

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct {
  int id;
  int *vetor;
}

void *procura_numero(void *args) {

}

int main() {

  srand(time(NULL));

  int tamanho_vetor = rand() % 100;
  int numero_threads = rand() % 8;
  int numero_procurado = rand() % 100;

  int vetor_dados[tamanho_vetor];

  for (int i = 0; i < tamanho_vetor; i++) {
    vetor_dados[i] = rand() % 100;
  }

}