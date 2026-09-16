#include <stdio.h>
#define MAX 100


int ehsimetrica(int n, int matriz[][MAX]){
    
    int matrizT[MAX][MAX];

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            matrizT[j][i] = matriz[i][j];
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(matriz[i][j] != matrizT[i][j]){
                return 0;
            }
        }
    }

    return 1;
}

int main(){

    int n;
    scanf("%d", &n);

    int matriz[MAX][MAX];

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    int temp = ehsimetrica(n, matriz);

    if(temp == 0){
        printf("Não é simetrica\n");
    }else{
        printf("É simetrica\n");
    }






    return 0;
}
