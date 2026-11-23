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

int ordenado(vetor *v){
    int ordenado = -1;
    for(int i = 1; i<v->tam; i++){
        if(v->dado[i] < v->dado[i - 1]){
            ordenado++;
            break;
        }
    }


    return ordenado;
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

    int temp = ordenado(v);

    if(temp == -1){
        printf("SIM\n");
    }else{
        printf("NÃo\n");
    }

    return 0;
}
