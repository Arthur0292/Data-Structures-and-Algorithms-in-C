#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char caracter;
    int frequencia;
    struct No *prox;
    struct No *esq, *dir;
}No;

typedef struct{
    No *ini;
    int tamanho;
}Lista;

void preenche_frequencia(char texto[], int vet[]){
    int tamanho = strlen(texto);
    for(int i = 0; i<tamanho; i++){
        vet[texto[i]]++;
    }
}

void criar_lista(Lista *lista){
    lista->ini = NULL;
    lista->tamanho = 0;
}

void inserir_ordenado(Lista *lista, No *no){
    No *aux;
    if(lista->ini == NULL){
        lista->ini = no;
        lista->tamanho++;
    }else if(no->frequencia < lista->ini->frequencia){
        no->prox = lista->ini;
        lista->ini = no;
        lista->tamanho++;
    }else{
        aux = lista->ini;
        while(aux->prox != NULL && aux->prox->frequencia <= no->frequencia){
            if(aux->prox->frequencia == no->frequencia){
                if(aux->prox->caracter > no->caracter){
                    break;
                }
            }
            aux = aux->prox;
        }

        no->prox = aux->prox;
        aux->prox = no;
        lista->tamanho++;
    }
}

void preenche_lista(int vet[], Lista *lista){
    No *novo;
    for(int i = 0; i<256; i++){
        if(vet[i] > 0){
            novo = malloc(sizeof(No));
            novo->caracter = i;
            novo->frequencia = vet[i];
            novo->dir = NULL;
            novo->esq = NULL;
            novo->prox = NULL;
            inserir_ordenado(lista, novo);
        }
    }
}

void imprimir(Lista *lista){
    No *aux = lista->ini;
    for(int i = 0; i<lista->tamanho; i++){
        printf("%c - %d\n", aux->caracter, aux->frequencia);
        aux = aux->prox;
    }
}

int main(){

    Lista lista;
    criar_lista(&lista);
    
    char texto[100];
    scanf(" %[^\n]", texto);

    int tabela_frequencia[256] = {0};

    preenche_frequencia(texto, tabela_frequencia);
    preenche_lista(tabela_frequencia, &lista);

    imprimir(&lista);

    return 0;
}
