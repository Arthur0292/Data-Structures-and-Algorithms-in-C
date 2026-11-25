#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    char caracter;
    struct No *prox;
}No;

typedef struct pilha{
    No *topo;
}pilha;

pilha *inicializar_pilha(){
    pilha *novo;
    novo = malloc(sizeof(pilha));
    novo->topo = NULL;
    return novo;
}

No *criar_no(char caracter){
    No *novo;
    novo = malloc(sizeof(No));
    novo->caracter = caracter;
    novo->prox = NULL;
    return novo;
}

pilha *push(pilha *p, char c){
    No *novo = criar_no(c);
    novo->prox = p->topo;
    p->topo = novo;
    
    return p;
}

pilha *pop(pilha *p){
    if(p->topo == NULL){
        return p;
    }else{
        No *aux = p->topo->prox;
        free(p->topo);
        p->topo = aux;

        return p;
    }
}

void imprimir(No *aux){
    if(aux == NULL){
        return;
    }   

    imprimir(aux->prox);
    printf("%c", aux->caracter);
}

int main(){

    int n;
    char caracter;
    scanf("%d", &n);

    pilha *p = inicializar_pilha();

    for(int i = 0; i<n; i++){
        scanf(" %c", &caracter);
        if(caracter != 'U'){
            p = push(p, caracter);
        }else{
            p = pop(p);
        }
    }

    imprimir(p->topo);

    printf("\n");



    return 0;
}
