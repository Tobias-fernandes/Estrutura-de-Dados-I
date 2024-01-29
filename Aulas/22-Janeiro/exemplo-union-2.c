#include <stdio.h>
#include <stdlib.h>

typedef union documentos{
    char rg[13];
    char cpf[15];
} Documentos;

typedef struct pessoa{
    char nome[20]; 
    int idade;
    Documentos doc;
}Pessoa;

void dados_pessoa(Pessoa * p){

    int escolha;
    printf("Informe o nome: \t");
    scanf(" %[^\n]", p->nome);
    printf("Informe a idade: \t");
    scanf("%d", &p->idade);
    printf("CPF[1] ou RG[2]");
    scanf("%d", &escolha);
    switch (escolha)
    {
    case 1:
        printf("Digite o CPF: \t");
        scanf(" %[^\n]", p->doc.cpf);
        break;
    case 2:
        printf("Digite o rg: \t");
        scanf(" %[^\n]", p->doc.rg);
        break;
    default:
        printf("\nOpção incorreta, inicie o programa novamente");
        break;
    }

}

int main(){
    Pessoa * pessoa = (Pessoa *) malloc(sizeof(Pessoa));
    dados_pessoa(pessoa);
    printf("Documento: %s", pessoa->doc.cpf);
    free(pessoa);
    return 0;
}