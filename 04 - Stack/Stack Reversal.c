#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int identificador;
    struct No *prox;
}No;

typedef struct pilha{
    int tamanho;
    No *topo;
}pilha;

pilha *inicializar_pilha(){
    pilha *novo;
    novo = malloc(sizeof(pilha));
    novo->tamanho = 0;
    novo->topo = NULL;
    return novo;
}

No *criar_no(int dado){
    No *novo;
    novo = malloc(sizeof(No));
    novo->identificador = dado;
    novo->prox = NULL;
    return novo;
}

pilha *push(pilha *p, int dado){
    No *novo = criar_no(dado);
    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
    return p;
}

void imprimir(No *no){
    printf("%d\n", no->identificador);
}

pilha *pop(pilha *p){
    if(p->topo == NULL){
        return p;
    }else{
        while(p->topo != NULL){
            imprimir(p->topo);
            No *aux = p->topo->prox;
            free(p->topo);
            p->topo = aux;
            p->tamanho--;
        }

        return p;
    }
}

int main(){

    int n, x;
    scanf("%d", &n);

    pilha *p = inicializar_pilha();

    for(int i = 0; i<n; i++){
        scanf("%d", &x);
        push(p, x);
    }

    pop(p);



    return 0;
}
