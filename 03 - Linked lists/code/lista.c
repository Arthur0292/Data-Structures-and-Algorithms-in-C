#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No *prox;
}No;

typedef struct No * p_no;    //Ponteiro para nó

void destruir_lista(p_no lista){
    if(lista != NULL){      //Se lista for vazia
        destruir_lista(lista->prox); //Destruo a lista recursivamente
        free(lista);
    }
}

p_no adicionar_elemento(p_no lista, int x){     //Criar uma nova lista com o novo elemento
    p_no novo;
    novo = malloc(sizeof(No)); //Crio um novo no
    novo->dado = x;     //Guardo int x no dado
    novo->prox = lista; //Aponto para a lista ou seja adiciono no começo
    return novo;    //Retorno a nova lista
}

void imprimir_lista(p_no lista){
    p_no atual;     //Crio uma lista atual
    for(atual = lista; atual != NULL; atual = atual->prox){     //Atual começa = lista se atual->prox == NULL atual = atual->prox
        printf("%d\n", atual->dado);
    }
}

int main(){

    p_no lista = NULL;  //Criar Lista

    lista = adicionar_elemento(lista, 5);
    imprimir_lista(lista);

    destruir_lista(lista);







    return 0;
}
