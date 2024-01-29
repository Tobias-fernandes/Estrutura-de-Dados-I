#include <stdio.h>
#include <string.h>


typedef union genero{
    char masculino[9];
    char feminino[8];
    char neutro[6];
} Genero;

typedef struct pessoa{
    char nome[20];
    int idade;
    Genero genero;
} Pessoa;

void dados_pessoa(Pessoa * p){

    int escolha;

    printf("Insira o nome: \t");
    scanf(" %[^\n]", p->nome); 
    printf("Insira a idade: \t");
    scanf("%d", &p->idade); 
    printf("Informe o Genero: \n\t -> Masculino[1] \n\t ->Feminino[2] \n\t ->Neutro[3] \nOpcao: \t");
    scanf("%d", &escolha);
    
    switch (escolha){
    case 1:
        strcpy(p->genero.masculino, "Masculino");
        break;
    case 2:
        strcpy(p->genero.feminino, "Feminino");
        break;
    case 3:
        strcpy(p->genero.neutro, "Neutro");
        break;

    default:
        printf("\nOpcao invalida, genero definido como neutro");
        strcpy(p->genero.neutro, "Neutro");
        break;
    }

}

void imprime_dados(Pessoa pessoa){

    printf("=====================================\n");
    printf("\t Dados da pessoa\n");
    printf("=====================================\n");
    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    printf("Genero: %s\n", pessoa.genero.masculino);
}

int main(){
    Pessoa pessoa;
    dados_pessoa(&pessoa);
    imprime_dados(pessoa);
}