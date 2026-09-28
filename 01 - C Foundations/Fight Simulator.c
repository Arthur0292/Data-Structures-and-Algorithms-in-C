typedef struct{
    char descricao[20];
} TipoPoder;

typedef struct{
    int id;
    char nome[20];
    float forca;
    TipoPoder poder;
}TipoLutador;

void fight(const TipoLutador* timeA, const TipoLutador* timeB, int n, TipoLutador* vencedores ){
    for(int i = 0; i<n; i++){
        if(timeA[i].forca > timeB[i].forca){
            vencedores[i] = timeA[i];
        }else if(timeA[i].forca <= timeB[i].forca){
            vencedores[i] = timeB[i];
        }
    }
}
