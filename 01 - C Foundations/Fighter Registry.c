typedef struct{
    char descricao[24];
} TipoPoder;

typedef struct{
    int id;
    char nome[20];
    float forca;
    TipoPoder poder;
}TipoLutador;

void preenchaVetorLutadores(TipoLutador* lutadores, int n){
    for(int i = 0; i < n; i++){
        scanf("%d %19s %f %23s", &lutadores[i].id, lutadores[i].nome, &lutadores[i].forca, lutadores[i].poder.descricao);
    }
}
