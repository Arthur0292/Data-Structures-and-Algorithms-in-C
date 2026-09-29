void matrizTransposta(int linhas, int colunas, double matriz[linhas][colunas], double matrizTransposta[colunas][linhas]){

    for(int i = 0; i<linhas; i++){
        for(int j = 0; j<colunas; j++){
            matrizTransposta[j][i] = matriz[i][j];
        }
    }

}
