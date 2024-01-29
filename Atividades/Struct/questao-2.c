#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[50];
    int numeroDocumento;
    int idade;
} Pessoa;

void divisoria(){
    printf("============================================================\n");
}

void preenche(Pessoa * pessoa){
    printf("Insira o nome da pessoa: ");
    scanf(" %s", pessoa->nome);
    printf("Insira o numero do documento da pessoa: ");
    scanf("%d", &pessoa->numeroDocumento);
    printf("Insira a idade da pessoa: ");
    scanf("%d", &pessoa->idade);
}

void imprime(Pessoa * pessoa){
    printf("Nome: %s\n", pessoa->nome);
    printf("Numero do documento: %d\n", pessoa->numeroDocumento);
    printf("Idade: %d\n", pessoa->idade);
} 

void atualizaIdade(Pessoa * pessoa, int novaIdade){
    pessoa->idade = novaIdade;
}

void pessoaMaisVelha(Pessoa * pessoa, int quantidadePessoas){
    int contador;
    int maiorIdade = pessoa[0].idade;
    int id = 0;
    for (contador = 0; contador < quantidadePessoas; contador++){
        if (pessoa[contador].idade > maiorIdade){
            maiorIdade = pessoa[contador].idade;
            id = contador;
        }
    }
    printf("\nA pessoa mais velha eh %s com %d anos\n", pessoa[id].nome, maiorIdade);
}

void pessoaMaisNova(Pessoa * pessoa, int quantidadePessoas){
    int contador;
    int id = 0;
    int menorIdade = pessoa[0].idade;
    for (contador = 0; contador < quantidadePessoas; contador++){
        if (pessoa[contador].idade < menorIdade){
            menorIdade = pessoa[contador].idade;
            id = contador;
        }
    }
    printf("\nA pessoa mais nova eh %s com %d anos\n", pessoa[id].nome, menorIdade);
}

int main(){
    int quantidadePessoas = 3;
    int contador;

    Pessoa * pessoa = (Pessoa *) malloc(quantidadePessoas * sizeof(Pessoa));
    
    for (contador = 0; contador < quantidadePessoas; contador++){
        preenche(&pessoa[contador]);
    }

    printf("Exibindo dados das pessoas:\n");
    for (contador = 0; contador < quantidadePessoas; contador++){
        imprime(&pessoa[contador]);
    }

    divisoria();
    pessoaMaisVelha(pessoa, quantidadePessoas);
    pessoaMaisNova(pessoa, quantidadePessoas);
    divisoria();

    free(pessoa);
    return 0;
}