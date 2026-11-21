#include <stdio.h>
#include <stdlib.h>

typedef struct vetor{
    int *dado;      
    int n;      //Tamanho do meu vetor
}vetor;

void inicializar_vetor(vetor **v, int n){
    *v = malloc(sizeof(vetor));
    (*v)->dado = malloc(sizeof(int) * n);
    (*v)->n = 0;
}

void destruir_vetor(vetor **v){
    free((*v)->dado);
    free(*v);
    *v = NULL; 
}

void adicionar_elemento(vetor *v, int x){
    v->dado[v->n] = x;
    (v->n)++;
}

int soma(vetor *v){
    int soma = 0;
    for(int i = 0; i<v->n; i++){
        soma += v->dado[i];
    }

    return soma;
}

int main(){

    vetor *v;

    int n, x, s;
    scanf("%d", &n);

    inicializar_vetor(&v, n);

    for(int i = 0; i<n; i++){
        scanf("%d", &x);
        adicionar_elemento(v, x);
    }

    s = soma(v);

    printf("SOMA: %d\n", s);


    

    return 0;
}
