p_no buscar(p_no raiz, int x){

    if(raiz != NULL && raiz->dado != x){
        if(raiz->dado > x){
            return buscar(raiz->esq,x); //Volta retornando um valor
        }else{
            return buscar(raiz->dir, x);
        }
    }else{
        return raiz;
    }

}
