#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char palavra[200];
}palavra;

typedef struct{
    palavra *v;
    int topo;
}Pilha;

typedef Pilha *p_pilha;

void iniciar_pilha(Pilha **pilha, int tam){
    *pilha = malloc(sizeof(Pilha));
    (*pilha)->v = malloc(sizeof(palavra) * tam);
    (*pilha)->topo = 0;
}

void empilhar(p_pilha p, char palavra[200]){
    strcpy(p->v[p->topo].palavra, palavra);
    p->topo++;
}

void desempilhar(p_pilha p){
    p->topo--;
}

void imprimir(p_pilha p){
    for(int i = 0; i<p->topo; i++){
        printf("%s\n", p->v[i].palavra);
    }
}

void destruir_pilha(Pilha **pilha){
    free((*pilha)->v); 
    free(*pilha);
}

int main(){

    p_pilha p;
    int cont = 0;
    char palavra[1000];
    char comando[1000];

    iniciar_pilha(&p, 100);

    while(scanf("%s", comando) == 1 && strcmp(comando, "fim") != 0){
        if(strcmp(comando, "digitar") == 0){
            scanf("%s", palavra);
            empilhar(p, palavra);
        }else if(strcmp(comando, "desfazer") == 0){
            if(p->topo > 0){
                desempilhar(p);
            }
        }
    }

    imprimir(p);
    destruir_pilha(&p);

    return 0;
}
