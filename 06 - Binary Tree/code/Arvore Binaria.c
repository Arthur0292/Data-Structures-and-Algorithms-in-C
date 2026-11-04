#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No *esq, *dir;
} No;

typedef struct No * p_no;

p_no criar_arvore(int x, p_no esq, p_no dir){
    p_no novo = malloc(sizeof(No)); //Aloco a struct de no
    novo->dado = x; //Coloco os dados
    novo->esq = esq;
    novo->dir = dir;
    return novo; //retorno o p_no novo
}

p_no procurar_no(p_no raiz, int x){
    p_no esq;
    if(raiz == NULL || raiz->dado == x)
        return raiz;    //Se não encontrar um nó ou o nó for == x então retorna a raiz
    esq = procurar_no(raiz->esq, x);
    if(esq != NULL)
        return esq;
    return procurar_no(raiz->dir, x);
}

int numero_nos(p_no raiz){
    if(raiz == NULL){
        return 0;
    }
    return numero_nos(raiz->esq) + numero_nos(raiz->dir) + 1;
}

int altura(p_no raiz){

    int h_esq, h_dir;
    if(raiz == NULL){
        return 0;
    }

    h_esq = altura(raiz->esq);
    h_dir = altura(raiz->dir);

    if(h_esq > h_dir){
        return h_esq + 1;
    }else{
        return h_dir + 1;
    }

}

int main(){




    return 0;
}
