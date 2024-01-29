#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int matricula;
	float notas[3], media;
	char nome[80];
	char turma;
} Aluno;

void menuprincipal();
void menuescolha(Aluno *alunos_declaracao, int Quant_aluno);
int voltarmenu();

void matricula(int QuantidadeAluno, Aluno **alunos);
void lanca_notas(int QuantidadeAluno, Aluno **alunos);
void imprime_tudo(int QuantidadeAluno, Aluno **alunos);
void imprime_turma(int QuantidadeAluno, Aluno **alunos, char turma);
void imprime_turma_aprovados(int QuantidadeAluno, Aluno **alunos, char turma);

void matricula(int QuantidadeAluno, Aluno **alunos)
{
	int i;
	alunos[QuantidadeAluno] = (Aluno *)malloc(sizeof(Aluno));
	printf("MATRICULA\n");
	printf("Digite o nome\n");
	scanf(" %s", alunos[QuantidadeAluno]->nome);
	printf("Digite a matricula\n");
	scanf("%d", &alunos[QuantidadeAluno]->matricula);
	printf("Digite a turma\n");
	scanf(" %c", &alunos[QuantidadeAluno]->turma);
	alunos[QuantidadeAluno]->media = 0.0;
	for (i = 0; i < 3; i++)
	{
		alunos[QuantidadeAluno]->notas[i] = 0.0;
	}
}

void lanca_notas(int QuantidadeAluno, Aluno **alunos)
{
	int j, i;
	for (j = 0; j < QuantidadeAluno; j++)
	{
		printf("Digite as notas do Aluno %d\n", j + 1);
		for (i = 0; i < 3; i++)
		{
			scanf("%f", &alunos[j]->notas[i]);
		}
		alunos[j]->media = (alunos[j]->notas[0] + alunos[j]->notas[1] + alunos[j]->notas[2]) / 3;
	}
}

void imprime_tudo(int QuantidadeAluno, Aluno **alunos)
{
	int i, j;
	for (j = 0; j < QuantidadeAluno; j++)
	{
		printf("Dados do aluno %d\n", j + 1);
		printf("Nome: %s\n", alunos[j]->nome);
		printf("Matricula: %d\n", alunos[j]->matricula);
		printf("turma: %c\n", alunos[j]->turma);
		printf("Notas: |");
		for (i = 0; i < 3; i++)
		{
			printf("%.2f |", alunos[j]->notas[i]);
		}
		printf("\nMedia: %.2f\n\n", alunos[j]->media);
	}
}

void imprime_turma(int QuantidadeAluno, Aluno **alunos, char turma)
{
	int i, j;
	for (j = 0; j < QuantidadeAluno; j++)
	{
		if (alunos[j]->turma == turma)
		{
			printf("Dados do aluno %d\n", j + 1);
			printf("Nome: %s\n", alunos[j]->nome);
			printf("Matricula: %d\n", alunos[j]->matricula);
			printf("turma: %c\n", alunos[j]->turma);
			printf("Notas: |");
			for (i = 0; i < 3; i++)
			{
				printf("%.2f |", alunos[j]->notas[i]);
			}
			printf("\nMedia: %.2f\n\n", alunos[j]->media);
		}
	}
}

void imprime_turma_aprovados(int QuantidadeAluno, Aluno **alunos, char turma)
{
	int ordem;
	for (ordem = 0; ordem < QuantidadeAluno; ordem++)
	{
		if (alunos[ordem]->turma == turma && (alunos[ordem]->media > 7))
		{
			printf("o aluno %s foi aprovado, com media igual %.2f\n", alunos[ordem]->nome, alunos[ordem]->media);
		}
	}
}

int main()
{
	menuprincipal();
	return 0;
}

void menuprincipal()
{
	int Quant_aluno, ordem, ordem_nota;
	printf("Digite a quantidade de Alunos que podem ser matriculados\n");
	scanf("%i", &Quant_aluno);

	Aluno *alunos_declaracao = (Aluno *)malloc(sizeof(Aluno) * Quant_aluno);
	if (alunos_declaracao == NULL)
	{
		exit(1);
	}

	for (ordem = 0; ordem < Quant_aluno; ordem++)
	{
		alunos_declaracao[ordem].matricula = 0;
		alunos_declaracao[ordem].media = 0.0;
		for(ordem_nota = 0; ordem_nota < 3; ordem_nota++)
		{
			alunos_declaracao[ordem].notas[ordem_nota] = 0.0;
		}
	}

	system("clear");
	menuescolha(alunos_declaracao, Quant_aluno);
}

void menuescolha(Aluno *alunos_declaracao, int Quant_aluno)
{
	int escolhamenu, QuantidadeAluno = 0, Menu = 0;
	char turma;
	Aluno **alunos = &alunos_declaracao;
	do
	{
		printf("MENU\n");
		printf("1. Matricular do aluno\n");
		printf("2. Cadastrar as notas dos alunos\n");
		printf("3. Imprimir dados dos alunos\n");
		printf("4. Imprimir dados de uma turma\n");
		printf("5. Imprimir lista aprovados de uma turma\n");
		printf("Escolha:");
		scanf("%d", &escolhamenu);
        printf("\n");

		switch (escolhamenu)
		{
		case 1:
			if (QuantidadeAluno == Quant_aluno)
			{
				system("clear");
				printf("Quantidade maxima de Alunos atingida\n\n");
				Menu = 1;
				break;
			}
			system("clear");
			matricula(QuantidadeAluno, alunos);
			QuantidadeAluno++;
			Menu = voltarmenu();
			break;
		case 2:
			if (QuantidadeAluno == 0)
			{
				system("clear");
				printf("Nenhum Aluno cadastrado\n\n");
				Menu = 1;
				break;
			}
			system("clear");
			lanca_notas(QuantidadeAluno, alunos);
			Menu = voltarmenu();
			break;
		case 3:
			if (QuantidadeAluno == 0)
			{
				system("clear");
				printf("Nenhum Aluno cadastrado\n\n");
				Menu = 1;
				break;
			}
			system("clear");
			imprime_tudo(QuantidadeAluno, alunos);
			Menu = voltarmenu();
			break;
		case 4:
			if (QuantidadeAluno == 0)
			{
				system("clear");
				printf("Nenhum Aluno cadastrado\n\n");
				Menu = 1;
				break;
			}
			system("clear");
			printf("Digite a turma:\n");
			scanf(" %c", &turma);
			imprime_turma(QuantidadeAluno, alunos, turma);
			Menu = voltarmenu();
			break;
		case 5:
			if (QuantidadeAluno == 0)
			{
				system("clear");
				printf("Nenhum Aluno cadastrado\n\n");
				Menu = 1;
				break;
			}
			system("clear");
			printf("Digite a turma:\n");
			scanf(" %c", &turma);
			imprime_turma_aprovados(QuantidadeAluno, alunos, turma);
			Menu = voltarmenu();
			break;
		default:
			exit(1);
			break;
		}
	}
	while (Menu == 1);
	free(alunos);
}

int voltarmenu()
{
	char voltarMenu;
	printf("Digite V para voltar para o menu.\n");
	scanf(" %c", &voltarMenu);
	if((voltarMenu == 'V') || (voltarMenu == 'v'))
	{
		system("clear");
		return 1;
	}
	else
	{
		system("clear");
		return 0;
	}
}