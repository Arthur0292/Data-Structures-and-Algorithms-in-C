#include <stdio.h>
#include <stdlib.h>

typedef struct No *p_no;

typedef struct No{
    int dado;
    p_no esq, dir;
}No;

typedef struct Fila *p_fila;

typedef struct Fila{
    p_no ini, fim;
}Fila;

typedef struct elemento *p_elemento;

typedef struct elemento{
    p_no arvore;
    p_elemento prox;
}elemento;


p_no criar_no(int x){
    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

p_no inserir(p_no raiz, int x){
    p_no novo;
    if(raiz == NULL){
        novo = criar_no(x);
        return novo;
    }

    if(raiz->dado > x){
        raiz->esq = inserir(raiz->esq, x);
    }else{
        raiz->dir = inserir(raiz->dir, x);
    }

    return raiz;
}

p_fila criar_fila(){
    p_fila novo;
    novo = malloc(sizeof(Fila));
    novo->ini = NULL;
    novo->fim = NULL;
    return novo;
}

void enfileira(p_fila fila, p_no ab){
    p_elemento novo;
    novo = malloc(sizeof(elemento));
    novo->arvore = ab;
    novo->prox = NULL;

    if(fila->ini == NULL){
        fila->ini = novo;
    }else{
        fila->fim->prox = novo;
    }

    fila->fim = novo;
}

void desenfileira(p_fila fila){
    if(fila == NULL){
        return;
    }else{
        
    }
}

int main(){

    int n;
    scanf("%d", &n);

    p_no ab = NULL;
    p_fila fila = criar_fila(fila);

    for(int i = 0; i<n; i++){
        int x;
        scanf("%d", &x);
        ab = inserir(ab, x);
    }


    


    return 0;
}
