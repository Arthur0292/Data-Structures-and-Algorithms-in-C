void ehSimetrica(int matriz[linhas][colunas], int linhas, int colunas){
    
    if(linhas != colunas){
        printf("Não é simetrica\n");
        return;
    }
    
    int matrizTransposta[linhas][colunas];

    for(int i = 0; i<linhas; i++){
        for(int j = 0; j<colunas; j++){
            matrizTransposta[j][i] = matriz[i][j];
        }
    }

    for(int i = 0; i<linhas; i++){
        for(int j = 0; j<colunas; j++){
            if(matriz[i][j] != matrizTransposta[i][j]){
                printf("Não é simetrica\n");
                return;
            }
        }
    }

    printf("É simetrica\n");
    return;


}
