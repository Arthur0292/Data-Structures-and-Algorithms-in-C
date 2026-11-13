void pre_ordem(ab_int *r){
    if(r == NULL){
        return;
    }else{
        printf("%d ", r->dado);
    }

    pre_ordem(r->esq);
    pre_ordem(r->dir);
}
