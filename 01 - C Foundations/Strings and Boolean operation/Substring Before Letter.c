#include <stdio.h>
#include <string.h>

int main() {

    char palavra[1000];
    char caracter;
    scanf("%[^\n]", palavra);
    scanf(" %c", &caracter);

    int tamanho = strlen(palavra);

    for(int i = 0; i<tamanho; i++){
        if(palavra[i] != caracter){
            printf("%c", palavra[i]);
        }else{
            break;
        }
    }

    printf("\n");
 
    return 0;
}
