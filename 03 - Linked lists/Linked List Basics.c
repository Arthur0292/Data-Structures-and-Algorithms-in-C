#include <stdio.h>
#include <stdlib.h>

typedef struct no *p_no;

typedef struct no{
    int dado;
    p_no prox;
}no;

typedef struct lista *p_lista;

typedef struct lista{
    p_no inicio;
    int tam;
}lista;

p_no criar_no(int dado){
    p_no novo = malloc(sizeof(no));
    novo->dado = dado;
    novo->prox = NULL;
    return novo;
}

p_lista iniciar_lista(){
    p_lista novo;
    novo = malloc(sizeof(lista));
    novo->inicio = NULL;
    novo->tam = 0;
    return novo;
}

p_lista adicionar_inicio(p_lista lista, int x){
    p_no no = criar_no(x);
    no->prox = lista->inicio;
    lista->inicio = no;

    lista->tam++;
 
    return lista;
}

p_lista adicionar_fim(p_lista lista, int x){
    p_no no = criar_no(x);
    p_no novo = lista->inicio;

    if(lista->inicio == NULL){
        lista->inicio = no;
    }else{
        while(novo->prox != NULL){
            novo = novo->prox;
        }

        novo->prox = no;   
    }

    lista->tam++;

    return lista;

}

int tamanho(p_lista lista){
    int soma = 0;
    p_no novo = lista->inicio;
    
    if(lista == NULL){
        return 0;
    }

    while(novo != NULL){
        soma++;
        novo = novo->prox;
    }
    
    return soma;
}

int soma(p_lista lista){
    int soma = 0;
    p_no novo = lista->inicio;
    
    if(lista == NULL){
        return 0;
    }

    while(novo != NULL){
        soma+= novo->dado;
        novo = novo->prox;
    }
    
    return soma;
}

int main(){



    return 0;
}
