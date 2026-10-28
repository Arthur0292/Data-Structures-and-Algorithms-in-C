#ifndef VETOR_H
#define VETOR_H

typedef struct{
    int *dados;
    int n;  //Elelmentos dentro do meu vetor
} vetor;

void iniciar_vetor(vetor **v, int tam);

void destruir_vetor( vetor **v);

void adicionar_elemento(vetor *v, int x);

void remover_elemento(vetor *v, int x);

void imprime(vetor *v);

#endif
