#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct {
    int id;
    int *vetor;
    int tamanho;
} ThreadArgs;

typedef struct {
    int id;
    long long soma;
} ThreadRetorno;

void *calcula_soma(void *arg) {
    ThreadArgs *dados = (ThreadArgs*)arg;

    long long soma_acumulada = 0;
    for (int i = 0; i < dados->tamanho; i++) {
        soma_acumulada += dados->vetor[i];
    }

    ThreadRetorno *resultado = malloc(sizeof(ThreadRetorno));
    resultado->id = dados->id;
    resultado->soma = soma_acumulada;

    return (void*)resultado;
}

int main() {
    int n = 4;
    int v = 8;

    srand(time(NULL));

    int *vetor_dados = malloc(v * sizeof(int));
    for (int i = 0; i < v; i++) {
        vetor_dados[i] = rand() % 50;
    }

    pthread_t *threads = malloc(n * sizeof(pthread_t));
    ThreadArgs *args = malloc(n * sizeof(ThreadArgs));

    for (int i = 0; i < n; i++) {
        args[i].id = i;
        args[i].vetor = vetor_dados;
        args[i].tamanho = v;

        pthread_create(&threads[i], NULL, calcula_soma, (void*)&args[i]);
    }

    for (int i = 0; i < n; i++) {
        ThreadRetorno *res;
        pthread_join(threads[i], (void**)&res);

        printf("Thread %d achou %lld como a soma do vetor.\n", res->id, res->soma);
        
        free(res);
    }

    free(vetor_dados);
    free(threads);
    free(args);

    return 0;
}