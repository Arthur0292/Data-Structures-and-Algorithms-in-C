int soma(ab_int *r){
    if(r == NULL){
        return 0;
    }

    int soma_esq = soma(r->esq);
    int soma_dir = soma(r->dir);

    return soma_esq + soma_dir + r->dado;
}
