typedef struct{
    int *dado;
    int tam;
}pilha;

void inicializar_pilha(pilha **v, int tam){
    *v = malloc(sizeof(pilha));
    (*v)->dado = malloc(sizeof(int) * tam);
    (*v)->tam = 0;
}

void destruir_pilha(pilha **v){
    free((*v)->dado);
    free(*v);
    *v = NULL;
}

int push(pilha *v, int x){
    v->dado[v->tam] = x;
    (v->tam)++;
    return x;
}

int pop(pilha *v){
    int temp = v->dado[v->tam - 1];
    (v->tam)--;

    return temp;
}
