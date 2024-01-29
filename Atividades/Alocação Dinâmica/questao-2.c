#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//Função que irar determinar quantas questões a prova terar;
void quantidade_questoes(int *quantidade)
{
    printf("Digite a quantidade de questões que terar na prova:\n");
    scanf("%d",&*quantidade);
}

//Função que irar salvar as respostas do gabarito no progama;
void gabarito_prova(int *quantidade, char ***gabarito)
{
    *gabarito = (char**)malloc((*quantidade) * sizeof(char*));//aloquei o espaço para a resposta de acordo com o tanto de questoes;
    for(int numero = 0; numero < *quantidade; numero++)
    { 
        printf("digite a resposta para a questão %d\n", numero + 1);
        (*gabarito)[numero] = (char*)malloc(10 * sizeof(char));//Cada vez que ocorre o loop é alocado em cada vetor um espaço de 10 bytes ou cada resposta pode armazenar 10 letras;
        scanf("%s",(*gabarito)[numero]);
    }
    system("clear");
    printf("Gabarito Final\n");
    for(int numero = 0; numero < *quantidade; numero++)
    { 
        printf("Resposta da questao %d = %s.\n ", numero + 1,(*gabarito)[numero]);
    }
    printf("aguarde 3 segundos.\n");
    sleep(1);//Função para pausar o progama durante um periodo definido pelo usuario;
    printf("aguarde 2 segundos.\n");
    sleep(1);
    printf("aguarde 1 segundos.\n");
    sleep(1);
}

//Função para mostrar a porcentagem de aprovação;
void porcentagem_aprovados(int *valor_da_porcentagem, int *resultado)
{
    int total = 0;
    
    printf("Quantos alunos fizeram a prova: \n");
    scanf("%d",&total);

    *resultado = ((*valor_da_porcentagem) * 100) / total;  
    
    printf("A porcentagem dos alunos aprovados foran de: %d por cento\n",*resultado);
}
//Estrutura para guardar o dado de cada aluno; 
typedef struct aluno
{
    char nome[21];
    char respostas[10][2];
    int nota;
}dados;


int main()
{
    // Primeira etapa, meta: definir a quantidade de questões e montar um gabarito - CONCLUIDA
   
    int quantidade = 0;//criei uma variavel que irar guardar o valor de quantas questões terão na prova;
    
    int aprovados = 0;//variavel criada para calcular a quantidade de pessoas aprovadas na sala;
    int resultados = 0;//variavel criada para mostrar a porcentagens de aprovados;

    int numero = 0;
    int ordem = 0; 

    dados aluno[2];

    quantidade_questoes(&quantidade);
    
    char **gabarito;
   
    gabarito_prova(&quantidade, &gabarito);
    
    system("clear");

    for(numero = 0; numero < 2; numero++)
    {
        printf("---HORA DA PROVA---\n");
        printf("digite seu nome:\n");
        scanf("%s",aluno[numero].nome);
        
        for(int ordem = 0; ordem < quantidade; ordem++)//
        {
            printf("Digite a resposta para a questao %d\n", ordem + 1);
            scanf("%s",aluno[numero].respostas[ordem] );
        }
        
        system("clear");
        
        printf("Nome: %s\n", aluno[numero].nome);
        for(int ordem = 0; ordem < quantidade; ordem ++)
        {
            
            printf("questão %d = %s\n",ordem + 1, aluno[numero].respostas[ordem]);
        }
        system("clear");
    }

    for(numero = 0; numero < 2; numero++)
    {
        aluno[numero].nota = 0;
        for(ordem = 0; ordem < quantidade; ordem++)
        { 
            if(strcmp(aluno[numero].respostas[ordem], gabarito[ordem]) == 0)
            {
                aluno[numero].nota = aluno[numero].nota + 10/quantidade;
            }
        }
        printf("nota do aluno %s: %d\n\n", aluno[numero].nome, aluno[numero].nota);
    }

    for(numero = 0; numero < 2; numero ++)
    { 
        if(aluno[numero].nota > 6)
        {
            aprovados++;
        }
    }

    porcentagem_aprovados(&aprovados, &resultados);

    return 0;
}