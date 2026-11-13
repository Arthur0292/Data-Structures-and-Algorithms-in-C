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

void criar_lista(Lista *lista){
    lista->ini = NULL;
    lista->tamanho = 0;
}

void inserir_ordenado(Lista *lista, No *no){
    No *aux;
    if(lista->ini = NULL){
        lista->ini = no;
        lista->tamanho++;
    }else if(lista->ini->frequencia > no->frequencia){
        no->prox = lista->ini;
        lista->ini = no->prox;
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

void preenche_lista(Lista *lista, int vet[]){
    No *novo;
    for(int i = 0; i<256; i++{
        if(vet[i] > 0){
            novo = malloc(sizeof(No));
            novo->caracter = i;
            novo->frequencia = vet[i];
            novo->dir = NULL;
            novo->esq = NULL;
            novo->prox = NULL;
            inserir_ordenado(&lista, novo);
        }
    }
}

No *remover_no(Lista *lista){
    No *temp = NULL;
    if(lista->ini != NULL){
        temp = lista->ini;
        lista->ini = temp->prox;
        temp->prox = NULL;
        lista->tamamanho = NULL;
    }
    
    return temp;
}

No *arvore(Lista *lista){
    No *primeiro, *segundo, *novo;
    while(lista->tamanho > 1){
        primeiro = remover_no(lista);
        segundo = remover_no(lista);
        novo = malloc(sizeof(No));
        novo->frequencia = primeiro->frequencia + segundo->frequencia;
        novo->esq = primeiro;
        novo->dir = segundo;
        novo->prox = NULL;
        
        inserir_ordenado(lista, novo);
        
        
    }
    
    return lista->ini;
}

int altura(No *raiz){
    int esq, dir;
    if(raiz == NULL){
        return -1;
    }else{
        esq = altura(raiz->esq);
        dir = altura(raiz->dir);
        if(esq > dir){
            return esq + 1;
        }else{
            return dir + 1;
        }
    }
}

char** aloca_codigo(int colunas){
    char **codigo;
    codigo = malloc(sizeof(char*));
    
    for(int i = 0; i<256; i++){
        codigo[i] = calloc(colunas, sizeof(char));
    }
    
    return codigo;
}

void codigo_letra(char **codigo, No *raiz, char *caminho, int colunas){
    char esquerda[colunas], direita[colunas];
    if(raiz->esq == NULL && raiz->dir == NULL){
        strcpy(codigo[raiz->caracter], caminho);
    }else{
        strcpy(esquerda, caminho);
        strcpy(direita, caminho);
        
        strcat(esquerda, "0");
        strcat(direita, "1");
        
        codigo_letra(codigo, raiz->esq, esquerda, colunas);
        codigo_letra(codigo, raiz->dir, direita, colunas);
    }
}

void soma_frequencia(char texto[], int vet[]){
    int tamanho = strlen(texto);
    for(int i = 0; i<tamanho; i++){
        vet[texto[i]]++;
    }
}

int main(){
    
    Lista lista;
    No *ab;
    criar_lista(&lista);
    char texto[1025];
    scanf(" %[^\n]", texto);
    
    int frequencia[256] = {0};
    
    soma_frequencia(texto, frequencia);
    preenche_lista(&lista, frequencia);
    
    ab = arvore(&lista);
    
    
    return 0;
}
