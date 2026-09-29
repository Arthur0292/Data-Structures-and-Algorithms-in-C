#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    int matriz[n][n];

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    int somaPrin = 0, somaSec = 0, prin = 0, sec = n - 1;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == prin && j == prin){
                somaPrin += matriz[i][j];
                prin++;
            }
        }
    }

    prin = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == prin && j == sec){
                somaSec += matriz[i][j];
                sec--;
            }
        }
    }

    if(somaPrin == somaSec){
        printf("A soma das diagonais principal e secundaria é igual\n");
    }else{
        printf("A soma das diagonais principal e secundaria não é igual\n");
    }


    return 0;
}
