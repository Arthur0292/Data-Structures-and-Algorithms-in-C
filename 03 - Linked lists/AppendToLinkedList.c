p_no adicionar_fim(p_no lista, int x){
    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = x;

    if(lista == NULL){
        lista = novo;
        novo->prox = NULL;
        return lista;
    }else{
        p_no atual = lista;
        for(atual; atual != NULL; atual = atual->prox){
            if(atual->prox == NULL){
                atual->prox = novo;
                novo->prox = NULL;
            }
        }
    }

    return lista;
}
