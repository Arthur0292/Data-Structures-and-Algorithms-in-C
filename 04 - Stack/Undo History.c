#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No *prox;
}No;

typedef struct pilha{
    int tamanho;
    No *topo;
}pilha;

pilha *inicializar_pilha(){
    pilha *novo;
    novo = malloc(sizeof(pilha));
    novo->topo = NULL;
    novo->tamanho = 0;

    return novo;
}

No *criar_no(int dado){
    No *novo;
    novo = malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;
    return novo;
}

pilha *push(pilha *pilha, int dado){
    No *novo = criar_no(dado);
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho++;
    return pilha;
}

pilha *pop(pilha *pilha){
    if(pilha->topo == NULL){
        return pilha;
    }else{
        No *novo = pilha->topo->prox;
        free(pilha->topo);
        pilha->topo = novo;
        pilha->tamanho--;
        
        return pilha;
    }
}


int main(){

    int n, x;
    scanf("%d", &n);

    pilha *p = inicializar_pilha();

    for(int i = 0; i<n; i++){
        scanf("%d", &x);
        if(x != -1){
            p = push(p, x);
        }else{
            p = pop(p);
        }
    }

    if(p->topo == NULL){
        printf("EMPTY\n");
    }else{
        printf("%d\n", p->topo->dado);
    }


    return 0;
}
