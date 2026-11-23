#include <stdio.h>
#include <stdlib.h>

typedef struct vetor{
    int *dado;
    int tam;
}vetor;


void inicializar_vetor(vetor **v, int n){
    *v = malloc(sizeof(vetor));
    (*v)->dado = malloc(sizeof(int) * n);
    (*v)->tam = 0;
}

void adicionar(vetor *v, int x){
    v->dado[v->tam] = x;
    (v->tam)++;
}

int pares(vetor *v){
    int quant = 0;
    for(int i = 0; i<v->tam; i++){
        if(v->dado[i] % 2 == 0){
            quant++;
        }
    }


    return quant;
}

int main(){

    vetor *v;

    int n, x;
    scanf("%d", &n);
    inicializar_vetor(&v, n);

    for(int i = 0; i<n; i++){
        scanf("%d", &x);
        adicionar(v, x);
    }

    printf("PARES: %d\n", pares(v));





    return 0;
}
