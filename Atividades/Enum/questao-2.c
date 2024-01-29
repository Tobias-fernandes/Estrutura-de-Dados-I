#include <stdio.h>

typedef enum tipo{
    ELETRONICO,
    ALIMENTO, 
    BEBIDA
} Tipo;

typedef struct produto{
    char nome[20];
    float preco;
    Tipo tipo;
} Produto;

void dados_produtos(Produto * produto){
    int escolha;

    printf("Insira o nome: \t");
    scanf(" %[^\n]", produto->nome);
    printf("Insira o preco: \t");
    scanf("%f", &produto->preco);
    printf("Tipo: \n\t -> Eletronico[1] \n\t -> Alimento[2] \n\t -> Bebida[3] \nOpcao: \t");
    scanf("%d", &escolha);
    switch (escolha){

    case 1:
        produto->tipo = ELETRONICO;
        break;
    case 2:
        produto->tipo = ALIMENTO;
        break;
    case 3:
        produto->tipo = BEBIDA;
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
        if(produto.tipo == ELETRONICO){
            printf("Tipo: Eletronico\n");
        }else if(produto.tipo == ALIMENTO){
            printf("Tipo: Alimento\n");
        }else if(produto.tipo == BEBIDA){
            printf("Tipo: Bebida\n");
        }else{
            printf("Tipo: invalido\n");
        }
}

int main(void){
    Produto produto;
    dados_produtos(&produto);
    imprime_dados(produto);
    return 0;
}