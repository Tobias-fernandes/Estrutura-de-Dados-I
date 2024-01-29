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
    Disciplina * materias;
} Aluno;

int main(void){

    Aluno * aluno = (Aluno *) malloc(sizeof(Aluno));

    if (aluno == NULL){
        printf("Erro na alocacao de memoria\n");
        exit(1);
    }

    aluno->materias = (Disciplina *) malloc(2 * sizeof(Disciplina));

    if (aluno -> materias == NULL){
        printf("Erro na alocacao de memoria\n");
        exit(1);
    }

    printf("Informe os dados do aluno: nome, idade e matricula\n");
    scanf("%[^\n]s", aluno -> nome);	
    scanf("%d", &aluno->idade);
    scanf("%d", &aluno->matricula);

    int index;
    
    for (index = 0; index < 2; index++){
        printf("Cadastro da disciplina %d\n", index+1);
        scanf("%s", aluno->materias[index].nome); 
        scanf("%f", &aluno->materias[index].nota);
        scanf("%d", &aluno->materias[index].codigo);
    }

    free(aluno -> materias);
    free(aluno);
    return 0;
}