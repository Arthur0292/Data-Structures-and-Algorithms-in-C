#include <stdio.h>

int soma(int x, int y){
    int resultado = x + y;
    return resultado;
}

int subtracao(int x, int y){
    int resultado = x - y;
    return resultado;
}

int multiplicao(int x, int y){
    int resultado = x * y;
    return resultado;
}

int divisao(int x, int y){
    int resultado = x / y;
    return resultado;
}


int main() {

    int opcao, a , b;
    scanf("%d", &opcao);

    while(opcao != 5){
        if(opcao == 1){
            scanf("%d %d", &a, &b);
            printf("%d + %d = %d\n", a, b, soma(a, b));
        }else if(opcao == 2){
            scanf("%d %d", &a, &b);
            printf("%d - %d = %d\n", a, b, subtracao(a, b));
        }else if(opcao == 3){
            scanf("%d %d", &a, &b);
            printf("%d * %d = %d\n", a, b, multiplicao(a, b));
        }else if(opcao == 4){
            scanf("%d %d", &a, &b);
            printf("%d / %d = %d\n", a, b, divisao(a, b));
        }
    
        scanf("%d", &opcao);
    }
    

    return 0;
}
