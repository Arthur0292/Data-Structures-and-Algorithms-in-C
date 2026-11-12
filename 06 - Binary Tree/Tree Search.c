ab_int* busca(ab_int *r, int x){
    if(r == NULL || r->dado == x){
        return r;
    }

    ab_int *esq = busca(r->esq, x);
    if(esq != NULL){
        return esq;
    }

    return busca(r->dir, x);
}
