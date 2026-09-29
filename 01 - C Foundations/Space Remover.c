#include <stdio.h>
#include <string.h>

int main(){

    char palavra[100];
    char novapalavra[100];

    scanf(" %[^\n]", palavra);

    int tamanho = strlen(palavra);

    int cont = 0;

    for(int i = 0; i<tamanho; i++){
        if(palavra[i] != ' '){
            novapalavra[cont] = palavra[i];
            cont++;
        }
    }

    novapalavra[cont] = '\0';

    printf("%s\n", novapalavra);


    return 0;
}
