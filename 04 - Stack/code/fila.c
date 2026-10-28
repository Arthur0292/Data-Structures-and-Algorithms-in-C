#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No *prox;
} No;

typedef struct No *p_no;

typedef struct{
    p_no ini, fim;  
} Fila;

typedef Fila * p_fila;

p_fila criar_fila(){
    p_fila fila = malloc(sizeof(Fila));     //Aloco a fila
    fila->ini = NULL;   //Inicio e fim = NULL
    fila->fim = NULL;
    return fila;
}

void destruir_lista(p_no lista){
    if(lista != NULL){      //Se lista for vazia
        destruir_lista(lista->prox); //Destruo a lista recursivamente
        free(lista);
    }
}

void destruir_fila(p_fila fila){
    destruir_lista(fila->ini);  //Destruo a lista
    free(fila); //Libero a fila
}

void enfileira(p_fila fila, int x){
    p_no novo = malloc(sizeof(No)); //Aloco um novo no
    novo->dado = x;     //Guardo as informações do no
    novo->prox = NULL;
    if(fila->ini == NULL){  //Se a lista for vazia
        fila->ini = novo;   //Inicio = novo
    }else{  //Se a lista nao for vazia
            //Nao altero o inicio
        fila->fim->prox = novo; //O prox do no final aponta para o novo
    }
    fila->fim = novo;   //Fim da fila aponta para o novo
}

void desenfileira(p_fila fila){
    p_no primeiro = fila->ini;
    fila->ini = fila->ini->prox;
    if(fila->ini == NULL){
        fila->fim = NULL;
    }
    free(primeiro);
}



int main(){

    p_fila fila = criar_fila();

    destruir_fila(fila);

    return 0;
}
