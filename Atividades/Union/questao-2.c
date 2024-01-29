#include <stdio.h>
#include <string.h>


typedef union tipo{
    int eletronico[10];
    int alimento[8];
    int bebida[6];

}Tipo;

typedef struct produto{
    char nome[20];
    float preco;
    Tipo tipo;
}Produto;

void dados_produto(Produto * produto){
    int escolha;

    printf("Insira o nome: \t");
    scanf(" %[^\n]", produto->nome);
    printf("Insira o preco: \t");
    scanf("%f", &produto->preco);
    printf("Tipo: \n\t -> Eletronico[1] \n\t -> Alimento[2] \n\t -> Bebida[3] \nOpcao: \t");
    scanf("%d", &escolha);
    switch (escolha){

    case 1:
        strcpy(produto->tipo.eletronico, "Eletronico");
        break;
    case 2:
        strcpy(produto->tipo.alimento, "Alimento");
        break;
    case 3:
        strcpy(produto->tipo.bebida, "Bebida");
        break;
    default:
        printf("\nOpcao invalida, execute o programa novamente");
        break;
    }
}

void imprime_dados(Produto produto){

    printf("=====================================\n");
    printf("\t Dados do produto\n");
    printf("=====================================\n");
    printf("Nome: %s\n", produto.nome);
    printf("Preco: %.2f\n", produto.preco);
    printf("Tipo: %s\n", produto.tipo.eletronico);
}

int main(){
    Produto produto;
    dados_produto(&produto);
    imprime_dados(produto);
    return 0;
}