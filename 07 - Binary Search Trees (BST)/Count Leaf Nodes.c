#include <stdio.h>
#include <stdlib.h>

typedef struct No *p_no;

typedef struct No{
    int dado;
    p_no esq, dir;
}No;

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

int quant_folhas(p_no raiz){
    int esq, dir;
    if(raiz == NULL){
        return 0;
    }

    if(raiz->esq == NULL && raiz->dir == NULL){
        return 1;
    }else{
        esq = quant_folhas(raiz->esq);
        dir = quant_folhas(raiz->dir);
    }

    return esq + dir;
}


int main(){



    return 0;
}
