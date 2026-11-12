int conta_nos(ab_int *r){
    if(r == NULL){
        return 0;
    }
    int esq = conta_nos(r->esq);
    int dir = conta_nos(r->dir);
    return esq + dir + 1;
}
