#include <stdio.h>
#include <stdlib.h>

typedef struct vetor{
    int *dado;
    int tam;
}vetor;

void inicializar_vetor(vetor **v, int tam){
    *v = malloc(sizeof(vetor));
    (*v)->dado = malloc(sizeof(int) * tam);
    (*v)->tam = 0;
}

void adicionar(vetor *v, int x){
    v->dado[v->tam] = x;
    (v->tam)++;
}

void imprimir_contrario(vetor *v){
    for(int i = v->tam - 1; i >= 0; i--){
            printf("%d\n", v->dado[i]);
    }
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

    imprimir_contrario(v);



    return 0;
}
