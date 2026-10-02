#include <stdio.h>
#include <string.h>
#define MAX 1000

typedef struct{
    char pais[100];
    char local[100];
    int qtVisitas;
} TipoLocal;


int main(){

    int n;
    scanf("%d", &n);

    TipoLocal pais[MAX];

    int qtpais = 0;

    for(int i = 0; i<n; i++){

        int cont = 0;
        char palavra[100];
        char frase[100];

        scanf(" %[^\n]", frase);

        int tamanho = strlen(frase);

        for(int j = 0; j<tamanho; j++){
            if(frase[j] != ' '){
                palavra[cont] = frase[j];
                cont++;
            }else{
                break;
            }
        }

        palavra[cont] = '\0';

        if(i == 0){
            strcpy(pais[qtpais].pais, palavra);
            pais[qtpais].qtVisitas = 1;
            qtpais++;
        }else{
            int tem = 0;
            for(int j = 0; j<qtpais; j++){
                if(strcmp(pais[j].pais, palavra) == 0){
                    pais[j].qtVisitas++;
                    tem++;
                }
            }

            if(tem == 0){
                strcpy(pais[qtpais].pais, palavra);
                pais[qtpais].qtVisitas = 1;
                qtpais++;
            }
        }

    }

    for(int i = 0; i<qtpais; i++){
        printf("%s %d\n", pais[i].pais, pais[i].qtVisitas);
    }

    return 0;
}
