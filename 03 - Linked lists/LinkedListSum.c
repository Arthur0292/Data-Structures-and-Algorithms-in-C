
int somar(p_no lista){
    int soma;
    if(lista == NULL){
        return 0;
    }else{
        soma = 0;
        p_no atual = lista;
        for(atual; atual != NULL; atual = atual->prox){
            soma += atual->dado;
        }
    }

    return soma;
}
