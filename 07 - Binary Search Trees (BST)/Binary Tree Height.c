#include <stdio.h>
#include <stdlib.h>

typedef struct No *p_no;

typedef struct No{
    int dado;
    p_no esq, dir;
}No;

int altura_ab(p_no raiz){
    if(raiz != NULL){
        int dir = altura_ab(raiz->dir);
        int esq = altura_ab(raiz->esq);

        if(dir > esq){
            return dir + 1;
        }else{
            return esq + 1;
        }
    }else{
        return -1;
    }
}

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


int main(){

    int n;
    scanf("%d", &n);

    p_no ab = NULL;

    for(int i = 0; i<n; i++){
        int x;
        scanf("%d", &x);
        ab = inserir(ab, x);
    }

    int altura = altura_ab(ab);

    printf("%d\n", altura);






    return 0;
}
