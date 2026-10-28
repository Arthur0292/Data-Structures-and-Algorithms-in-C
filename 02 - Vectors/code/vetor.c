#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

void iniciar_vetor(vetor **v, int tam){
    *v = malloc(sizeof(vetor)); //reservo o tamanho da struct
    (*v)->dados = malloc(sizeof(int) * tam);    //Reservo o tamanho para os dados
    (*v)->n = 0;    //Numero de elementos dentro do vetor
}

void destruir_vetor(vetor **v){
    free((*v)->dados);  //Libero os dados
    free(*v);   //Libero a struct
    *v = NULL;
}

void adicionar_elemento(vetor *v, int x){
    v->dados[v->n] = x; //Adiciono ao ultimo espaco do vetor
    (v->n)++;
}

void remover_elemento(vetor *v, int x){
    v->dados[x] = v->dados[v-> n - 1];
    (v->n)--;
}

void imprime(vetor *v){
    for(int i = 0; i < (v->n); i++){
        printf("Elemento[%d] = %d\n", i, v->dados[i]);
    }
}

int main(){

    int n;
    printf("Digite o tamanho do vetor a ser alocado: \n");
    scanf("%d", &n);

    vetor *v;
    iniciar_vetor(&v, n);

    printf("--------------------------\n");
    printf("1 - Adicionar Elemento do vetor\n");
    printf("2 - Remover Elemento do vetor\n");
    printf("3 - Imprimir vetor\n");
    printf("--------------------------\n");

    int x;
    scanf("%d", &x);

    while(x != 3){
        int o;

        if(x == 1){
            printf("Digite o elemento a ser adicionado: \n");
            scanf("%d", &o);
            adicionar_elemento(v, o);
        }else if(x == 2){
            printf("Digite o a posição a ser removida: \n");
            scanf("%d", &o);
            remover_elemento(v, o);
        }

        printf("--------------------------\n");
        printf("1 - Adicionar Elemento do vetor\n");
        printf("2 - Remover Elemento do vetor\n");
        printf("3 - Imprimir vetor\n");
        printf("--------------------------\n");

        scanf("%d", &x);
    }

    imprime(v);

    return 0;
}
