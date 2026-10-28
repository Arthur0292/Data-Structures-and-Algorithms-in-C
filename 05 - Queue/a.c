#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    int senha;
    struct No *prox;
} No;

typedef struct No *p_no;

typedef struct{
    p_no ini, fim;
}Fila;

typedef Fila *p_fila;

p_fila criar_fila(){
    p_fila fila = malloc(sizeof(Fila));
    fila->ini = NULL;
    fila->fim = NULL;
    return fila;
}

void enfileira(){

}


int main(){

    int senha = 1;
    p_no lista = NULL;

    p_fila fila = criar_fila();

    char nome[20];
    while(scanf("%s", nome) == 1 && strcmp(nome, "fim") != 0){

        if(strcmp(nome, "novo") == 0){
            enfileira(fila, senha)
        }else if(strcmp(nome, "chamar") == 0){
            desenfileira(fila);
        }

        senha++;
    }




    return 0;
}
