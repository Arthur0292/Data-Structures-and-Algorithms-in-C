#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Pilha
{
    int tamanho;
    Node *topo;
} Pilha;

typedef Pilha *p_pilha;

void inicializar_pilha(Pilha **pilha, int x)
{
    *pilha = malloc(sizeof(Pilha));
    (*pilha)->topo = malloc(sizeof(Node) * x);
    (*pilha)->tamanho = 0;
}

void push(p_pilha pilha, int dado)
{
    pilha->topo[pilha->tamanho].data = dado;
    pilha->tamanho++;
}

void pop(p_pilha pilha)
{
    pilha->tamanho--;
}

void destruir_pilha(Pilha **pilha){
    free((*pilha)->topo);
    free(*pilha); 
}

int main()
{

    int n;
    scanf("%d", &n);

    p_pilha pilha;
    inicializar_pilha(&pilha, n);

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x != 19)
        {
            push(pilha, x);
        }
        else
        {
            if (pilha->tamanho > 0)
            {
                pop(pilha);
            }
        }
    }

    int soma = 0;
    if (pilha->tamanho > 0)
    {
        for (int i = 0; i<pilha->tamanho; i++)
        {
            soma += pilha->topo[i].data;
        }
    }

    printf("%d", soma);

    destruir_pilha(&pilha);
}
