int tamanho(p_no lista){
    int n = 1;
    if(lista == NULL){
        return 0;
    }
    p_no atual = lista;
    while(atual->prox != NULL){
        n++;
        atual = atual->prox;
    }

    return n;
}
