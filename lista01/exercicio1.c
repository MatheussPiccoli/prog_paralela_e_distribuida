#include <stdio.h> 
#include <unistd.h> 
#include <pthread.h> 

//Implemente um programa que crie N threads, leia e imprima uma posição P de 
//um vetor qualquer. O vetor deve ter sido previamente preenchido com N valores distintos. A 
//posição P é baseada no id único de cada thread, representado por um valor atribuído na sua 
//criação. Tanto o id quanto o ponteiro para o vetor devem ser partes de uma estrutura (args), 
//que deve ser passada como atributo para cada thread. A função de cada thread deve 
//manipular esta estrutura, imprimindo a mensagem: Sou a thread <ID>, acessei o vetor 
//li a letra <LETRA>. 

typedef struct {
    int id;
    char *vetor;
} ThreadArgs;

void *print_info(void *arg) {
  ThreadArgs* dados = (ThreadArgs*)arg;
  
  int id = dados->id;
  char letra = dados->vetor[id];

  printf("Sou a thread %d, acessei o vetor e li a letra %c \n", id, letra);

  return NULL;
}

int main() { 
  int numero, posicao;
  numero = 10;
  char vetor_caracteres[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  pthread_t threads[numero];
  ThreadArgs vetor_structs[numero];

  for (int i = 0; i < numero; i++) {
    vetor_structs[i].id = i;
    vetor_structs[i].vetor = vetor_caracteres;

    pthread_create(&threads[i], NULL, print_info, (void*)&vetor_structs[i]);
  }

  for (int i = 0; i < numero; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("Fim da execução\n");
  return 0;

} 