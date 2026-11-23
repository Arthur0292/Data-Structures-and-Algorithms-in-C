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

int ocorrencia(vetor *v, int x){
    int ocorrencia_po = -1;
    for(int i = 0; i<v->tam; i++){
        if(v->dado[i] == x){
            ocorrencia_po = i;
            break;
        }
    }


    return ocorrencia_po;
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

    int o;
    scanf("%d", &o);

    printf("Vetor[%d] = %d\n", ocorrencia(v, o), o);

    return 0;
}
