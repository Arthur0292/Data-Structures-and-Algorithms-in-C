typedef struct {
    int codigo;
    char titulo[100];
    char autor[100];
    int paginas;
} TipoLivro;

void lerLivros(TipoLivro *livros, int n){
    for(int i = 0; i<n; i++){
        scanf("%d %100s %100s %d", &livros[i].codigo, livros[i].titulo, livros[i].autor, &livros[i].paginas);
    }
}

TipoLivro* maiorLivro(TipoLivro *livros, int n){
    int maior, indice;
    for(int i = 0; i<n; i++){
        if(i == 0){
            maior = livros[i].paginas;
            indice = i;
        }else{
            if(maior < livros[i].paginas){
                maior = livros[i].paginas;
                indice = i;
            }
        }
    }

    return &livros[indice];
}
