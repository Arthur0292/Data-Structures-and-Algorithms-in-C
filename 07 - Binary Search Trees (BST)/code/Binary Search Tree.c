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

p_no inserir(p_no raiz, int x){     //Funcao de inserir um no
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

p_no remover_no(p_no raiz, int x){      //Funcao de remover um no
    if(raiz == NULL){
        return NULL;
    }

    if(raiz->dado > x){
        raiz->esq = remover_no(raiz->esq, x);
    }else if(raiz->dado < x){
        raiz->dir = remover_no(raiz->dir, x);
    }else{
        if(raiz->dir == NULL && raiz->esq == NULL){
            free(raiz);
            return NULL;
        }else if(raiz->dir != NULL){
            p_no aux = raiz->esq;
            free(raiz);
            return aux;
        }else if(raiz->esq != NULL){
            p_no aux = raiz->dir;
            free(raiz);
            return aux;
        }else{
            p_no aux = raiz->dir;

            while(aux->esq != NULL){
                aux = aux->esq;
            }

            raiz->dado = aux->dado;
            raiz->dir = remover_no(raiz->dir, aux->dado);
        }

    }
  return raiz;
}

p_no buscar(p_no raiz){     //Funcao de busca interativa
    p_no aux = raiz;

    while(raiz != NULL && raiz->dado != x){
        if(raiz->dado > x){
            aux = aux->esq;
        }else{
            aux = aux->dir;
        }
    }

    if(aux == NULL || aux->dado == x){
        return aux;
    }
}

p_no maximo(p_no raiz){     //Achar o maior valor
    if(raiz == NULL){
        return NULL;
    }

    p_no aux = raiz;
    while(aux != NULL){
        aux = aux->dir;
    }

    return aux;
}

p_no minimo(p_no raiz){     //Achar o menor valor
    if(raiz == NULL){
        return NULL;
    }

    p_no aux = raiz;
    while(aux != NULL){
        aux = aux->esq;
    }

    return aux;
}

void pre_ordem(p_no raiz){      //Imprimir pre ordem
    if(raiz == NULL){
        return;
    }else{
        printf("%d ", raiz->dado);
    }

    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
}

void em_ordem(p_no raiz){       //Imprimir em ordem
    if(raiz == NULL){
        return;
    }

    em_ordem(raiz->esq);
    printf("%d ",raiz->dado);
    em_ordem(raiz->dir);
}

int numero_nos(p_no raiz){      //Contar numero de nos na arvore
    if(raiz == NULL){
        return 0;
    }

    int esq = numero_nos(raiz->esq);
    int dir = numero_nos(raiz->dir);

    return esq + dir + 1;
}

int numero_folhas(p_no raiz){       //Contar numero de nos folha na arvore
    int esq, dir;
    if(raiz == NULL){
        return 0;
    }

    if(raiz->esq == NULL && raiz->dir == NULL){
        return 1;
    }else{
        esq = numero_folhas(raiz->esq);
        dir = numero_folhas(raiz->dir);
    }

    return esq + dir;
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




    return 0;
}
