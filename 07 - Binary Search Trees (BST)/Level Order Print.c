int altura(p_no raiz){
    if(raiz == NULL){
        return 0;
    }

    int esq = altura(raiz->esq);
    int dir = altura(raiz->dir);

    if(esq > dir){
        return esq + 1;
    }else{
        return dir + 1;
    }
}

void print_level(p_no raiz, int nivel){
    if(raiz == NULL){
        return;
    }

    if(nivel == 0){
        printf("%d ", raiz->dado);
        return;
    }

    print_level(raiz->esq, nivel - 1);
    print_level(raiz->dir, nivel - 1);
}

void print_tree(p_no raiz){
    int h = altura(raiz);

    for(int i = 0; i <= h; i++){
        print_level(raiz, i);
        printf("\n");
    }
}
