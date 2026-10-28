#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

void iniciar_vetor(vetor **v, int tam){ //Recebe um ponteiro para vetor por referencia
    *v = malloc(sizeof(vetor));
    (*v)->dados = malloc(sizeof(int) * tam);
    (*v)->n = 0;
}

void destruir_vetor(vetor **v){
    free((*v)->dados);  //Libera os dados
    free(*v);   //Libera a struct
    *v = NULL;
}

void adicionar_elemento(vetor *v, int x){
    v->dados[v->n] = x; //Guardo o valor
    (v->n)++;   //Adciona mais um ao n
}

void remover_elemento(vetor *v, int x){
    v->dados[x] = v->dados[v->n - 1];   //Atribuo o ultimo valor a posição de remoção
    (v->n)--;   //Diminuo a quant de elementos
}

void imprime(vetor *v){
    for(int i = 0; i<(v->n); i++){
        printf("%d\n", v->dados[i]);
    }
}


int main(){

    vetor *v;   //Ponteiro para o meu vetor
    iniciar_vetor(&v, 100);
    
    int n;

    while(scanf("%d", &n) == 1 && n != 3){
        int x;
        if(n == 1){
            scanf("%d", &x);
            adicionar_elemento(v, x);
        }else if(n == 2){
            scanf("%d", &x);
            remover_elemento(v, x);
        }
    }

    imprime(v);

    destruir_vetor(&v); //Destruir o vetor

    return 0;
}
