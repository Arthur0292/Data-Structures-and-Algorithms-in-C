#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *v;
    int topo;
}Pilha;

typedef Pilha *p_pilha;

void iniciar_pilha(Pilha **pilha, int tam){
    *pilha = malloc(sizeof(Pilha));
    (*pilha)->v = malloc(sizeof(char) * tam);
    (*pilha)->topo = 0;
}

void destruir(Pilha **pilha){
    free((*pilha)->v);
    free(*pilha);
}

void empilhar(p_pilha p, char letra){
    p->v[p->topo] = letra;
    p->topo++;
}

char desempilhar(p_pilha p){
    p->topo--;
    return p->v[p->topo];
}

int comparar(p_pilha p, char palavra[1000]){
    int ehpalindromo = 1;
    int n = p->topo;
    for(int i = 0; i<n; i++){
        if(desempilhar(p) != palavra[i]){
            ehpalindromo = -1;
        }
    }

    return ehpalindromo;
}

int main(){

    p_pilha p;
    iniciar_pilha(&p, 1000);

    char palavra[1000];
    scanf("%s", palavra);

    int tamanho = strlen(palavra);

    for(int i = 0; i<tamanho; i++){
        empilhar(p, palavra[i]);
    }

    int x = comparar(p, palavra);

    if(x == 1){
        printf("Sim\n");
    }else{
        printf("Não\n");
    }

    destruir(&p);

    return 0;
}
