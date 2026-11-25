#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct pilha{
    int tamanho;
    Node *topo;
}pilha;

Node *criar_no(int x){
    Node * novo;
    novo = malloc(sizeof(Node));
    novo->data = x;
    novo->next = NULL;
    return novo;
}

pilha *inicializar_pilha(){
    pilha *p;
    p = malloc(sizeof(pilha));
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

pilha *push(pilha *pilha, int dado){
    Node *novo = criar_no(dado);
    novo->next = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho++;
   

    return pilha;
}

pilha *pop(pilha *pilha){
    if(pilha->topo == NULL){
        return pilha;
    }else{
        Node *aux = pilha->topo->next;
        free(pilha->topo);
        pilha->topo = aux;

        pilha->tamanho--;

        return pilha;
    }
}

int soma(pilha *pilha){
    int soma = 0;
    if(pilha->topo == NULL){
        return 0;
    }else{
        Node * aux = pilha->topo;
        while(aux != NULL){
            soma += aux->data;
            aux = aux->next;
        }
    }

    return soma;
}



int main(){

    int n, x;
    scanf("%d", &n);

    pilha *p = inicializar_pilha();

    for(int i = 0; i<n; i++){
        scanf("%d", &x);
        if(x != 19){
            p = push(p, x);
        }else{
            p = pop(p);
        }
    }

    int a = soma(p);

    printf("%d\n", a);
 
    


    return 0;
}
