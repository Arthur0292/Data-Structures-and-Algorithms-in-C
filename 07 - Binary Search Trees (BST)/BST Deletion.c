p_no remover_no(p_no raiz, int x){

    if(raiz == NULL){
        return NULL;
    }
    
    if(raiz->dado > x){
        raiz->esq = remover_no(raiz->esq, x);
    }else if(raiz->dado < x){
        raiz->dir = remover_no(raiz->dir, x);
    }else{
        if(raiz->dir == NULL && raiz->esq == NULL){
            free(raiz);
            return NULL;
        }else if(raiz->dir == NULL){
            p_no aux = raiz->esq;
            free(raiz);
            return aux;
        }else if(raiz->esq == NULL){
            p_no aux = raiz->dir;
            free(raiz);
            return aux;
        }else{
            p_no aux = raiz->dir;

            while(aux->esq != NULL){
                aux = aux->esq;
            }

            raiz->dado = aux->dado;
            raiz->dir = remover_no(raiz->dir, aux->dado);

        }

    }

    return raiz;

}
