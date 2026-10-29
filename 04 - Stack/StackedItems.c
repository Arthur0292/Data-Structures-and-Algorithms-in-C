#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[200];
    int tempo;
}coisa;

typedef struct{
    coisa *v;
    int topo;
}Pilha;

typedef Pilha *p_pilha;

void iniciar_pilha(Pilha **pilha, int tam){
    *pilha = malloc(sizeof(Pilha));
    (*pilha)->v = malloc(sizeof(coisa) * tam);
    (*pilha)->topo = 0;
}

void empilhar(p_pilha pilha, char nome[200], int tempo){
    strcpy(pilha->v[pilha->topo].nome, nome);
    pilha->v[pilha->topo].tempo = tempo;
    pilha->topo++;
}

void imprimir(p_pilha pilha){
    int soma = 0;
    for(int i = pilha->topo - 1; i>=0; i--){
        printf("%s\n", pilha->v[i].nome);
        soma += pilha->v[i].tempo;
    }
    printf("%d\n", soma);
}

void destruir_pilha(Pilha **pilha){
    free((*pilha)->v);
    free(*pilha);
}

int main(){

    char palavra[200];
    int tempo;
    p_pilha p;
    iniciar_pilha(&p, 100);

    while(scanf("%s", palavra) == 1 && strcmp(palavra, "end") != 0){
        scanf("%d", &tempo);
        empilhar(p, palavra, tempo);
    }

    imprimir(p);
    destruir_pilha(&p);





    return 0;
}
