#include <stdio.h>
#include <stdlib.h>

typedef struct No *ab_int;

typedef struct No{
    int dado;
    ab_int esq, dir;
}No;

ab_int criar_arvore(int x){
    ab_int r = malloc(sizeof(No));
    r->dado = x;
    r->esq = NULL;
    r->dir = NULL;
    return r;
}

void imprimir_no(ab_int *r){
    if(r != NULL){
        printf("%d", r->dado);
    }else{
        return;
    }

    imprimir_no(r->esq);
    imprimir_no(r->dir);
}

int main(){

    ab_int ab = criar_arvore(10);
    imprimir_no(&ab);


    return 0;
}
