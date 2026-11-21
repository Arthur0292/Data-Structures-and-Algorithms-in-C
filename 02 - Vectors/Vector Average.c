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

void destruir_vetor(vetor **v){
    free((*v)->dado);
    free(*v);
    *v = NULL;
}

void adicionar_elemento(vetor *v, int x){
    v->dado[v->tam] = x;
    (v->tam)++;
}

int media_vetor(vetor *v){
    int media, soma = 0;

    for(int i = 0; i<(v->tam); i++){
        soma += v->dado[i];
    }

    media = soma/(v->tam);
    return media;
}


int main(){

    vetor *v;

    int n, x, media;
    scanf("%d", &n);

    inicializar_vetor(&v, n);

    for(int i = 0; i<n; i++){
        scanf("%d", &x);

        adicionar_elemento(v, x);
    }

    media = media_vetor(v);

    printf("MEDIA: %d\n", media);


    return 0;
}
