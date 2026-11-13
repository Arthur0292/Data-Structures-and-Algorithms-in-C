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
    for(int i = 0; i<tamanho; i++){ //Adiciono +1 a posição do vetor que represneta o caracter na tabela ascii
        vet[texto[i]]++;
    }
}

void criar_lista(Lista *lista){
    lista->ini = NULL;  //Inicializo minha Lista
    lista->tamanho = 0;
}

void inserir_ordenado(Lista *lista, No *no){
    No *aux;
    if(lista->ini == NULL){     //Caso minha lista não contenha nenhum elemento coloco meu no no inicio
        lista->ini = no;
        lista->tamanho++;
    }else if(no->frequencia < lista->ini->frequencia){  //Se o primeiro elemento da minha lista tiver uma frequencia maior que meu no adiciono meu nó no inicio
        no->prox = lista->ini;
        lista->ini = no;
        lista->tamanho++;
    }else{  //Caso nenhuma é satisfeita procuro onde colocar o meu nó
        aux = lista->ini;   //Crio um no auxiliar para o começo da lista
        while(aux->prox != NULL && aux->prox->frequencia <= no->frequencia){    //Verifico o prox e comparo se for = Nulo ou a frequencia for maior paro de verificar
            if(aux->prox->frequencia == no->frequencia){
                if(aux->prox->caracter > no->caracter){ //Caso a frequencia for igual comparo o valores dos carcteres
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
    No *novo;       //Crio um no novo
    for(int i = 0; i<256; i++){
        if(vet[i] > 0){ //se a posição do vetor nao for == 0
            novo = malloc(sizeof(No));  //Atribuo as informacoes e guardo na minha lista
            novo->caracter = i;
            novo->frequencia = vet[i];
            novo->dir = NULL;
            novo->esq = NULL;
            novo->prox = NULL;
            inserir_ordenado(lista, novo);
        }
    }
}

No* remover_no(Lista *lista){       //Funcao para remover no da lista
    No *aux = NULL;

    if(lista->ini != NULL){     //Se o inici for diferente de nulo
        aux = lista->ini;   //Inicio da lista vai apontar para o prox no lista tamanho--
        lista->ini = aux->prox;
        aux->prox = NULL;
        lista->tamanho--;
    }

    return aux;
}


No* arvore(Lista *lista){
    No *primeiro, *segundo, *novo;      //No do primeiro segundo e construção da arvore
    while(lista->tamanho > 1){
        primeiro = remover_no(lista);   //removo o primeiro no
        segundo = remover_no(lista);    //removo o segundo no
        novo = malloc(sizeof(No));      //Crio um no para arvore
        novo->frequencia = primeiro->frequencia + segundo->frequencia; //frequencia = primeiro + segundo
        novo->esq = primeiro;
        novo->dir = segundo;
        novo->prox = NULL;

        inserir_ordenado(lista, novo);      //Coloco a subarvore dentro da lista
    }

    return lista->ini;
}

int altura(No *raiz){       //Funcao para calcular a altura da arvore binaria
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

char** aloca_codigo(int colunas){       //Alocar uma matriz de strings
    char **codigo;

    codigo = malloc(sizeof(char*) * 256);

    for(int i = 0; i<256; i++){
        codigo[i] = calloc(colunas, sizeof(char));  
    }

    return codigo;

}

void codigo_letra(char **codigo, No *raiz, char *caminho, int colunas){
    char esquerda[colunas], char direita[colunas];
    if(raiz->esq == NULL && raiz->dir == NULL){ //verificar se chegou em um no folha
        strcpy(codigo[raiz->caracter], caminho);
    }else{
        strcpy(esquerda, caminho);  //Continuo andando e adicionado a string de acordo com o caminho
        strcpy(direita, caminho);

        strcat(esquerda, "0");
        strcat(direita, "1");

        codigo_letra(codigo, raiz->esq, esquerda, colunas);
        codigo_letra(codigo, raiz->dir, direita, colunas);
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

    Lista lista;    //Crio a minha lista encadeada
    No *ab;
    criar_lista(&lista);
    
    char texto[100];    //Peco para o usuario digitar o texto
    scanf(" %[^\n]", texto);

    int tabela_frequencia[256] = {0};

    preenche_frequencia(texto, tabela_frequencia);  
    preenche_lista(tabela_frequencia, &lista);

    ab = arvore(&lista);

    return 0;
}
