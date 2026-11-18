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
    novo->dir = NULL;
    novo->esq = NULL;
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

p_no busca(p_no raiz, int x){
    if(raiz == NULL || raiz->dado == x){
        return raiz;
    }

    if(raiz->dado > x){
        return busca(raiz->esq, x);
    }else{
        return busca(raiz->dir, x);
    }
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

    int aux;
    printf("Digite um valor que deseje buscar:\n");

    scanf("%d", &aux);
    p_no valor_busca = busca(ab, aux);

    if(valor_busca == NULL){
        printf("NÃO ENCONTRADO\n");
    }else{
        printf("ENCONTRADO\n");
    }



    return 0;
}
