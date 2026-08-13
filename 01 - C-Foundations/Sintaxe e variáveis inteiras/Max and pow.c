#include <stdio.h>

int maximo(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int potencia(int a, int b){
    int n = a;
    for(int i = 0; i<b; i++){
        a *= n;
    }
    return a;
}



int main() {

    int a, b;
    printf("Digite o numero A:\n");
    scanf("%d", &a);

    printf("Digite o numero B:\n");
    scanf("%d", &b);

    printf("O maior numero é %d\n", maximo(a, b));
    printf("A potencia de b sobre a é %d\n", potencia(a, b));
    

    return 0;
}
