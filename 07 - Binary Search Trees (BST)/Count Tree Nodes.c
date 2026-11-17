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

int quant_no(p_no raiz){
    if(raiz == NULL){
        return 0;
    }

    int esq = quant_no(raiz->esq);
    int dir = quant_no(raiz->dir);
    return esq + dir + 1;
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

    int quant = quant_no(ab);

    printf("%d\n", quant);

    return 0;
}
