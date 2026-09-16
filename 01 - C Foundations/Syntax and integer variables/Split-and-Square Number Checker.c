#include <stdio.h>


int main(){

    int n;
    scanf("%d", &n);

    int primeiro = n / 100;
    int ultimo = n % 100;

    int soma = primeiro + ultimo;

    int quadrado = soma * soma;

    if(quadrado == n){
        printf("Tem essa propriedade\n");
    }else{
        printf("Não tem essa propriedade\n");
    }

    
   

    






    return 0;
}
