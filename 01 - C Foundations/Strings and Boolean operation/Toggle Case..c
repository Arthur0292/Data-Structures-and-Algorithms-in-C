#include <stdio.h>
#include <string.h>

int main() {

    char palavra[1000];
    char alfaMi[28];
    char alfaMa[28];
    scanf("%[^\n]", palavra);

    for(int i = 0; i<26; i++){
        alfaMi[i] = 'a' + i;
        alfaMa[i] = 'A' + i;
    }

    alfaMa[27] = '\0'; 
    alfaMi[27] = '\0'; 

    int tamanho = strlen(palavra);

    for(int i = 0; i<tamanho; i++){
        for(int j = 0; j<27; j++){
            if(palavra[i] == alfaMa[j]){
                palavra[i] = alfaMi[j];
            }else if(palavra[i] == alfaMi[j]){
                palavra[i] = alfaMa[j];
            }
        }
    }

    printf("%s\n", palavra);


    

    return 0;
}
