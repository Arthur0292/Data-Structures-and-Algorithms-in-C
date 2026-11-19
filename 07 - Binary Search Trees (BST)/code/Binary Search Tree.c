#include <stdio.h>
#include <stdlib.h>

typedef struct No *p_no;

typedef struct No{
    int dado;
    p_no esq, dir;
}No;

p_no criar_no(int x){
    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

p_no inserir(p_no raiz, int x){
    p_no novo;
    if(raiz == NULL){
        novo = criar_no(x);
        return novo;
    }

    if(raiz->dado > x){
        raiz->esq = inserir(raiz->esq, x);
    }else{
        raiz->dir = inserir(raiz->dir, x);
    }

    return raiz;
}

p_no criar_arvore(p_no ab, int vet[], int tamanho){
    for(int i = 0; i<tamanho; i++){
        ab = inserir(ab, vet[i]);
    }

    return ab;
}

int quant_no(p_no raiz){
    if(raiz == NULL){
        return 0;
    }

    int esq = quant_no(raiz->esq);
    int dir = quant_no(raiz->dir);

    return  esq + dir + 1;
}

int quant_folhas(p_no raiz){
    int esq, dir;
    if(raiz == NULL){
        return 0;
    }

    if(raiz->dir == NULL && raiz->esq == NULL){
        return 1;
    }else{
        esq = quant_folhas(raiz->esq);
        dir = quant_folhas(raiz->dir);
    }

    return esq + dir;

}

int quant_nos_internos(p_no raiz){
    int esq, dir;
    if(raiz == NULL){
        return 0;
    }

    if(raiz->dir == NULL && raiz->esq == NULL){
        return 0;
    }
    
    esq = quant_nos_internos(raiz->esq);
    dir = quant_nos_internos(raiz->dir);
    

    return 1 + esq + dir;

}

int soma(p_no raiz){
    if(raiz == NULL){
        return 0;
    }

    int esq = soma(raiz->esq);
    int dir = soma(raiz->dir);

    return raiz->dado + esq + dir;
}

int altura(p_no raiz){
    if(raiz == NULL){
        return -1;
    }

    int esq = altura(raiz->esq);
    int dir = altura(raiz->dir);

    if(esq > dir){
        return esq + 1;
    }else{
        return dir + 1;
    }
}

p_no busca(p_no raiz, int x){
    if(raiz == NULL){
        return raiz;
    }

    p_no aux = raiz;

    while(aux != NULL && aux->dado != x){
        if(aux->dado > x){
            aux = aux->esq;
        }else{
            aux = aux->dir;
        }
    }

    return aux;

}

int soma_sub(p_no raiz){
    int soma_sub;
    if(raiz == NULL){
        return 0;
    }else{
        soma_sub = soma(raiz);
    }

    return soma;
}

void pre_ordem(p_no raiz){
    if(raiz == NULL){
        return;
    }else{
        printf("%d ", raiz->dado);
    }

    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
}

void em_ordem(p_no raiz){
    if(raiz == NULL){
        return;
    }
    em_ordem(raiz->esq);
    printf("%d ", raiz->dado);
    em_ordem(raiz->dir);
}

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

p_no remover_no(p_no raiz, int x){
    if(raiz == NULL){
        return NULL;
    }

    if(raiz->dado < x){
        raiz->dir = remover_no(raiz->dir, x);
    }else if(raiz->dado > x){
        raiz->esq = remover_no(raiz->esq, x);
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

int main(){



    return 0;
}
