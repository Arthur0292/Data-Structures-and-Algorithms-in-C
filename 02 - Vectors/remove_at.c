void remove_vector(vetor *v, int pos){
    if(v == NULL || pos < 0 || pos >= v->n){
        return;
    }

    for(int i = pos; i < v->n - 1; i++){
        v->dado[i] = v->dado[i + 1];
    }

    v->n--;
}
