void mostra_arvore(ab_int *raiz){
    if(raiz == NULL){
        printf("()");
        return;
    }else{
        printf("(%d", raiz->dado);
    }
    printf(" ");
    mostra_arvore(raiz->esq);
    printf(" ");
    mostra_arvore(raiz->dir);
    printf(")\n");
}
