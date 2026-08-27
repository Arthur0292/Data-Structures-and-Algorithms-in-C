#include <stdio.h>

int ehPermutacao(int n, int matriz[n][n]){

    int contLinhas = 0, contColunas = 0;

    for(int i = 0 ; i<n; i++){
        contColunas = 0;
        for(int j = 0; j<n; j++){
            if(matriz[i][j] == 1){
                contLinhas++;
            }else if(matriz[i][j] != 0){
                return 1;
            }

            if(matriz[j][i] == 1){
                contColunas++;
            }else if(matriz[j][i] != 0){
                return 1;
            }
        }
        
        if(contLinhas > 1 || contLinhas == 0 || contColunas > 1|| contColunas == 0){
            return 1;
        }
        
        contLinhas = 0; 

    }

    return 2;


}

void lerMatriz(int n, int matriz[n][n]){

    for(int i = 0 ; i<n; i++){
        for(int j = 0; j<n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

}


int main() {

    int n;
    scanf("%d", &n);

    int matriz[n][n];

    lerMatriz(n, matriz);
    int resultado = ehPermutacao(n, matriz);

    if(resultado == 1){
        printf("Não é permutação\n");
    }else{
        printf("É permutação\n");
    }




    return 0;
}
