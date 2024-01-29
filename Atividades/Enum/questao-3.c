#include <stdio.h>
#include <string.h>

typedef enum meses{
    janeiro = 1,
    fevereiro,
    marco,
    abril,
    maio,
    junho,
    julho,
    agosto,
    setembro,
    outubro,
    novembro,
    dezembro
} Meses;

typedef struct data{
    int dia;
    Meses mes;
    int ano;
} Data;

int main(){
    Data data;
    char mes[11];
    printf("Insira o dia [numeros]:\t");
    scanf("%d", &data.dia);
    printf("Insira o mes [letras]:\t");
    scanf("%s", mes);
    printf("Insira o ano [numeros]:\t");
    scanf("%d", &data.ano);

    if(strcmp(mes, "janeiro") == 0){
        data.mes = janeiro;
    }else if(strcmp(mes, "fevereiro") == 0){
        data.mes = fevereiro;
    }else if(strcmp(mes, "marco") == 0){
        data.mes = marco;
    }else if(strcmp(mes, "abril") == 0){
        data.mes = abril;
    }else if(strcmp(mes, "maio") == 0){
        data.mes = maio;
    }else if(strcmp(mes, "junho") == 0){
        data.mes = junho;
    }else if(strcmp(mes, "julho") == 0){
        data.mes = julho;
    }else if(strcmp(mes, "agosto") == 0){
        data.mes = agosto;
    }else if(strcmp(mes, "setembro") == 0){
        data.mes = setembro;
    }else if(strcmp(mes, "outubro") == 0){
        data.mes = outubro;
    }else if(strcmp(mes, "novembro") == 0){
        data.mes = novembro;
    }else if(strcmp(mes, "dezembro") == 0){
        data.mes = dezembro;
    }else{
        printf("mes invalido\n");
        return 1;
    }

    printf("data: %02d/%02d/%d\n", data.dia, data.mes, data.ano);
    return 0;
}