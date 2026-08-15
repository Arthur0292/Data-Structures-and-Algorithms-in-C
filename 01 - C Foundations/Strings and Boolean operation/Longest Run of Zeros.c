#include <stdio.h>
#include <string.h>

int main(){

    char cadeia[1000];
    scanf("%s", &cadeia);

    int maiorAtual = 1, maior = 1;

    int tamanho = strlen(cadeia);

    for(int i = 0; i < tamanho - 1; i++){
        if(cadeia[i] == '0' && cadeia[i + 1] == '0'){
            maiorAtual++;
        }else{
            maiorAtual = 1;
        }
        
        if(maiorAtual > maior){
            maior = maiorAtual;
        }
    }

    printf("%d\n", maior);



    return 0;
}
