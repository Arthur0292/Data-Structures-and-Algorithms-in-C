int busca(p_no lista, int x){
    if(lista == NULL){
        return -1;
    }else{
        p_no atual = lista;
        for(atual; atual != NULL; atual = atual->prox){
            if(atual->dado == x){
                return 1;
            }
        }
    }
    return -1;

}
