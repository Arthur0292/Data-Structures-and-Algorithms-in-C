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

void em_ordem(p_no raiz){
    if(raiz == NULL){
        return;
    }

    em_ordem(raiz->esq);
    printf("%d ", raiz->dado);
    em_ordem(raiz->dir);
}

int main(){

    int n;
    scanf("%d", &n);

    p_no ab = NULL;

    for(int i = 0; i<n; i++){
        int x;
        scanf("%d", &x);
        ab = inserir(ab, x);
    }

    em_ordem(ab);

    


    return 0;
}
