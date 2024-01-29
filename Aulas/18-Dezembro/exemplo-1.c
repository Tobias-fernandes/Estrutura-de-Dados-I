#include <stdio.h>
#include <stdlib.h>

typedef struct disciplina{
    char nome[20];
    float nota;
    int codigo; 
} Disciplina;

typedef struct aluno{
    char nome[20];
    int idade;
    int matricula;
    Disciplina materias; 
} Aluno;

int main(void){

    Aluno aluno;

    aluno.idade = 19;
    aluno.matricula = 2023;
    aluno.materias.codigo = 98078;
   
    printf("Idade: %d\n", aluno.idade);
    printf("Matricula: %d\n", aluno.matricula);
    printf("Codigo da disciplina: %d\n", aluno.materias.codigo);
    return 0;
}