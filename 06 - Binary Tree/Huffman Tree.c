#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{  //Estruturas para o no e arvore
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

int vem_antes(No *a, No *b){    //Verifico a frequencia
    if(a->frequencia != b->frequencia)
        return a->frequencia < b->frequencia;
    return(unsigned char)a->caracter < (unsigned char)b->caracter;
}

void inserir_ordenado(Lista *lista, No *no){
    if(lista->ini == NULL || vem_antes(no, lista->ini)){    //Se for nulo ou menor
        no->prox = lista->ini;   
        lista->ini = no;         
    }else{
        No *aux = lista->ini;
        while(aux->prox != NULL && !vem_antes(no, aux->prox)){  //procura ate achar posicao
            aux = aux->prox;
        }
        no->prox = aux->prox;
        aux->prox = no;
    }
    lista->tamanho++;
}

void preenche_lista(Lista *lista, int vet[]){
    No *novo;
    for(int i = 0; i<256; i++){
        if(vet[i] > 0){ //Aloca e guarda na lista
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

No *remover_no(Lista *lista){
    No *temp = NULL;
    if(lista->ini != NULL){ 
        temp = lista->ini;
        lista->ini = temp ->prox;
        temp->prox = NULL;
        lista->tamanho--;
    }
    
    return temp;
}

No *arvore(Lista *lista){
    No *primeiro, *segundo, *novo;
    while(lista->tamanho > 1){
        primeiro = remover_no(lista);
        segundo = remover_no(lista);
        novo = malloc(sizeof(No));
        
        
        if((unsigned char)primeiro->caracter < (unsigned char) segundo->caracter){
            novo->caracter = primeiro->caracter;
        }else{
            novo->caracter = segundo->caracter;
        }
        novo->frequencia = primeiro->frequencia + segundo->frequencia;
        novo->esq = primeiro;   
        novo->dir = segundo;
        novo->prox = NULL;
        
        inserir_ordenado(lista, novo);
        
        
    }
    
    return lista->ini;
}

int altura(No *raiz){       //funcao para altura da arvore
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
    char **codigo;  //Matriz de strigs para os codigos
    codigo = malloc(sizeof(char*) * 256);
    
    for(int i = 0; i<256; i++){
        codigo[i] = calloc(colunas, sizeof(char));
    }
    
    return codigo;
}

void codigo_letra(char **codigo, No *raiz, char *caminho, int colunas){
    char esquerda[colunas], direita[colunas];
    if(raiz->esq == NULL && raiz->dir == NULL){ //se chegar em um no folha
        strcpy(codigo[(unsigned char)raiz->caracter], caminho);
    }else{
        strcpy(esquerda, caminho); //senao atribuo o caminho com 0 ou 1
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
        vet[(unsigned char)texto[i]]++;
    }
}

void imprimir_letras(char **tabela_codigo){
    int cont = 0;
    int caracteres[256];    //vetores auxiliares para ordenacao
    char codigos[256][256];

    for(int i = 0; i < 256; i++){
        if(strlen(tabela_codigo[i]) > 0){  
            caracteres[cont] = i;
            strcpy(codigos[cont], tabela_codigo[i]);
            cont++;
        }
    }

    for(int i = 0; i<cont; i++){
        for(int j = 0; j< cont - i -  1; j++){  //compara o tamanho e as strings
            if(strlen(codigos[j]) > strlen(codigos[j + 1]) || (strlen(codigos[j]) == strlen(codigos[j + 1]) && strcmp(codigos[j], codigos[j + 1]) > 0 )){
                char aux[256];
                int aux1;
                strcpy(aux, codigos[j]);
                strcpy(codigos[j], codigos[j + 1]);
                strcpy(codigos[j + 1], aux);
                
                aux1 = caracteres[j];
                caracteres[j] = caracteres[j + 1];
                caracteres[j + 1] = aux1;
            }
        }
    }

    for(int i = 0; i<cont; i++){
        printf("'%c' : %s\n", caracteres[i], codigos[i]);
    }
  
}


int main(){
    
    Lista lista;
    No *ab;
    criar_lista(&lista);
    char texto[1025];
    scanf("%[^\n]", texto);
    
    int frequencia[256] = {0};
    
    soma_frequencia(texto, frequencia);
    preenche_lista(&lista, frequencia);
    
    ab = arvore(&lista);
    
    
    int colunas = altura(ab) + 2;
    char **tabela_codigo = aloca_codigo(colunas);
    if(ab->esq == NULL && ab->dir == NULL){ //caso se toodas forem repetidas
        strcpy(tabela_codigo[(unsigned char)ab->caracter], "0");
    }else{
        codigo_letra(tabela_codigo, ab, "", colunas);
    }
    
    imprimir_letras(tabela_codigo);
    
    
    return 0;
}
