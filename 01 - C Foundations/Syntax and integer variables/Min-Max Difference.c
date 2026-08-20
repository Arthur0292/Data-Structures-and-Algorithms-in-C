#include <stdio.h>


int main() {

    int lista[10000];
    int cont = 0;
    int maior;
    int menor;

    while(scanf("%d", &lista[cont]) != EOF){
        
        if(cont == 0){
            menor = lista[cont];
            maior = lista[cont];
        }

        if(lista[cont] > maior){
            maior = lista[cont];
        }
        if(lista[cont] < menor){
            menor = lista[cont];
        }
        cont++;
    }

    int distancia;

    distancia = maior - menor;
    printf("%d\n", distancia);
    

    return 0;
}
