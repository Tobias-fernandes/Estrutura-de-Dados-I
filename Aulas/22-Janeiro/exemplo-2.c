#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[20]; 
    int idade;
}Pessoa;

void dados_pessoa(Pessoa * p){

    printf("Informe o nome: \t");
    scanf(" %[^\n]", p->nome); 
    printf("Informe a idade: \t");
    scanf("%d", &p->idade);

}

int main(){
    Pessoa * pessoa = (Pessoa *) malloc(sizeof(Pessoa));
    dados_pessoa(pessoa);
    free(pessoa);
    return 0;
}