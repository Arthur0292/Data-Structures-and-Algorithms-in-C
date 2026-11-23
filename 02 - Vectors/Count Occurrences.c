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
    int ocorrencia_quant = 0;
    for(int i = 0; i<v->tam; i++){
        if(v->dado[i] == x){
            ocorrencia_quant++;
        }
    }


    return ocorrencia_quant;
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

    int quant = ocorrencia(v, o);
    if(quant == 0){
        printf("valor não encontrado no vetor\n");
    }else{
        printf("QUANTIDADE DE OCORRENCIAS: %d\n", quant);
    }

    return 0;
}
