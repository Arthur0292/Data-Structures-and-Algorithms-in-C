#include <stdio.h>
#include <stdlib.h>

typedef struct No *p_no;

typedef struct No{
    int dado;
    p_no prox;
}No;

typedef struct Lista{
    p_no ini;
    int tamanho;
}Lista;

void criar_lista(Lista *lista){
    lista->ini = NULL;
    lista->tamanho = 0;
}

void adicionar_inicio(Lista *lista, int dado){
    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = lista->ini;

    lista->ini = novo;
    lista->tamanho++;
}

int main(){

    Lista lista;
    criar_lista(&lista);
    adicionar_inicio(&lista, 10);



    return 0;
}
