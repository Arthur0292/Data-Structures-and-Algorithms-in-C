#include <stdio.h>
#include <string.h>

int main(){

    int idade;
    char classificacao[30];
    char acompanhado;

    printf("Informe a idade: ");
    scanf("%d", &idade);
    printf("Informe a classificação: ");
    scanf("%s", classificacao);
    printf("Quantos acompanhantes (s/n): ");
    scanf(" %c", &acompanhado);

    if(strcmp(classificacao, "livre") == 0 || idade >= 16){
        printf("Sim\n");
    }else if(strcmp(classificacao, "violento") != 0){
        if(idade >= 16){
            printf("Sim\n");
        }else if(acompanhado == 's' || acompanhado == 'S'){
            printf("Sim\n");
        }else{
            printf("Não\n");
        }
    }else if((acompanhado == 's' || acompanhado == 'S') && idade < 14){
        printf("Sim\n");
    }else{
        printf("Não\n");
    }


    return 0;
}
