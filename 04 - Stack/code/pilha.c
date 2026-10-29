#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *v;
    int topo;
} Pilha;

typedef Pilha *p_pilha;

void iniciar_pilha(Pilha **pilha, int tam){
    *pilha = malloc(sizeof(Pilha));
    (*pilha)->v = malloc(sizeof(int)  * tam);
    (*pilha)->topo = 0;
}

void empilhar(p_pilha p, int i){
    p->v[p->topo] = i;
    p->topo++;
}

int desempilhar(p_pilha p){
    p->topo--;
    return p->v[p->topo];
}

void destruir_pilha(p_pilha p){
    free(p->v);
    free(p);
}

int main(){




    return 0;
}
