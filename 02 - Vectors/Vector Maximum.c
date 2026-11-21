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

void destruir_vetor(vetor **v){
    free(((*v)->dado));
    free(*v);
    *v = NULL;
}

void adicionar_elemento(vetor *v, int x){
    v->dado[v->tam] = x;
    (v->tam)++;
}

int maior(vetor *v){
    int maior;
    for(int i = 0; i<(v->tam); i++){
        if(i == 0){
            maior = v->dado[i];
        }else{
            if(v->dado[i] > maior){
                maior = v->dado[i];
            }
        }
    }

    return maior;
}


int main(){

    vetor *v;

    int n, x, m;

    scanf("%d", &n);

    inicializar_vetor(&v, n);

    for(int i = 0; i<n; i++){
        scanf("%d", &x);
        adicionar_elemento(v, x);
    }

    m = maior(v);

    printf("MAIOR: %d\n", m);



    return 0;
}
