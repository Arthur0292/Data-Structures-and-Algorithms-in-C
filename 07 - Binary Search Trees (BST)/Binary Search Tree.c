#include <stdio.h>
#include <stdlib.h>

typedef struct No *abb_int;

typedef struct No{
    int dado;
    abb_int esq, dir;
}No;

abb_int criar_no(int x){
    abb_int novo;
    novo = malloc(sizeof(No));
    novo->dado = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

abb_int inserir(abb_int raiz, int x){
    abb_int novo;
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


void imprimir_arvore(abb_int raiz){
    if(raiz == NULL){
        printf("()");
        return;
    }else{
        printf("(%d", raiz->dado);
    }
    printf(" ");

    imprimir_arvore(raiz->esq);
   
    printf(" ");
    imprimir_arvore(raiz->dir);

    printf(")");
}

int main(){

    int n;
    scanf("%d", &n);

    abb_int ab = NULL;

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        ab = inserir(ab, x);
    }
        
    imprimir_arvore(ab);
    

    return 0;
}
