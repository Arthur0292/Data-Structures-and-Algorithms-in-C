#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int *v;
    int topo;
    int tempo;
    char nome[20];
} Pilha;

typedef Pilha * p_pilha;

void iniciar_pilha(Pilha **pilha, int tam){
    *pilha = malloc(sizeof(Pilha));
    (*pilha)->v = malloc(sizeof(int) * tam);
    (*pilha)->topo = 0;
    return pilha;
}

void adicionar(p_pilha pilha, char nome[20], int tempo){

}

int main(){

    p_pilha p;
    iniciar_pilha(&p, 100);

    while(){
        
    }
    

    return 0;
}
