typedef struct {
    int matricula;
    char nome[50];
    float salario;
    int idade;
} TipoFuncionario;

float media(TipoFuncionario* funcionarios, int n){
    float soma = 0;
    for(int i = 0; i<n; i++){
        soma += funcionarios[i].salario;
    }

    return soma/n;
}

void acimaDaMedia(TipoFuncionario* funcionarios, int n, float media){
    for(int i = 0; i<n; i++){
        if(funcionarios[i].salario > media){
            printf("%s\n", funcionarios[i].nome);
        }
    }
}
 
