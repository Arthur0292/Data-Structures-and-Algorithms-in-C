int ocorrencia(p_no raiz, int x){
    int ocorrencia_esq, ocorrencia_dir, atual;
    if(raiz == NULL){
        return 0;
    }

    if(raiz->dado == x){
        atual = 1;
    }else{
        atual = 0;
    }

    ocorrencia_dir = ocorrencia(raiz->esq, x);
    ocorrencia_esq = ocorrencia(raiz->dir, x);

    return ocorrencia_esq + ocorrencia_dir + atual;
}
