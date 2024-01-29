#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <string.h>


typedef struct dados
{
    char nome[23];
    int salario;
    int indentificador;
    char cargo[23];
}funcionarios;

void def_quantidade(int *numero)
{ 
    printf("Digite a quantidade de funcionarios: \n");
    scanf("%d", &*numero);    
}

void preencher_funcionario(funcionarios *dados)
{
    printf("Digite o nome do funcionario:\n");
    scanf("%s", &*dados->nome);
    printf("Digite o salario do funcionario:\n");
    scanf("%d", &dados->salario);
    printf("Digite o indentificador do funcionario:\n");
    scanf("%d", &dados->indentificador);
    printf("Digite o cargo do funcionario:\n");
    scanf("%s", &*dados->cargo);
    
}

void imprimirdados(funcionarios *dados)
{    
    printf("Funcionario: %s\n",dados->nome);
    printf("Salario: %d\n",dados->salario);
    printf("Indentificacao:%d\n",dados->indentificador);
    printf("Cargo:%s\n",dados->cargo);
    printf("\n");
}

void alterarsalario(funcionarios *dados)
{
    printf("Digite o novo salario do funcionario:\n");
    scanf("%d",&dados->salario);
}

void maior_menor(funcionarios vetor[], int tamanho) {
    
    int indiceMaiorSalario = 0;
    int indiceMenorSalario = 0;

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i].salario > vetor[indiceMaiorSalario].salario) {
            indiceMaiorSalario = i;
        }
        if (vetor[i].salario < vetor[indiceMenorSalario].salario) {
            indiceMenorSalario = i;
        }
    }

    printf("\nFuncionario com maior salário:\n");
    printf("Cargo: %s\n", vetor[indiceMaiorSalario].cargo);
    printf("Salário: %d\n", vetor[indiceMaiorSalario].salario);

    printf("\nFuncionario com menor salário:\n");
    printf("Cargo: %s\n", vetor[indiceMenorSalario].cargo);
    printf("Salário: %d\n", vetor[indiceMenorSalario].salario);
}

int main() 
{ 
    
    int quantidade = 0;
    def_quantidade(&quantidade);

    funcionarios dados[quantidade];
    for(int ordem = 0; ordem < quantidade; ordem++)
    { 
        preencher_funcionario(&dados[ordem]);
        system("clear");
    }

    for(int ordem = 0; ordem < quantidade; ordem++)
    { 
        imprimirdados(&dados[ordem]);
    }
    sleep(3);
    system("clear");

    int escolha;
    
    printf("Existe algum funcionario que voce deseja alterar o salario?\n");
    printf("Digite algum numero 1-Sim  2-Nao:\n");
    scanf("%d", &escolha);
   
   
    if(escolha == 1)
    {
        int indentificacao = 0;
        
        printf("Qual funcionario voce deseja alterar o salario?\n\n");
        
        for(int ordem = 0; ordem < quantidade; ordem++)
        { 
            imprimirdados(&dados[ordem]);
        }
       
        printf("Digite o indentificador do funcionario que voce deseja alterar o salario:\n");
        scanf("%d",&indentificacao);
        
        for(int ordem = 0; ordem < quantidade; ordem++)
        {
            if(dados[ordem].indentificador == indentificacao  )
            {
                alterarsalario(&dados[ordem]);
            }
        }

        system("clear"); 
    }
    else
    {
        printf("guardando os dados.\n");
        sleep(1);
        system("clear\n");
        printf("guardando os dados..\n");
        sleep(1);
        system("clear\n");
        printf("guardando os dados...\n");
        sleep(1);
        system("clear\n");
    }

    maior_menor(dados,quantidade);

    return 0;
}