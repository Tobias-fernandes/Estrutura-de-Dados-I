#include <stdlib.h>
#include <stdio.h>

int main(void){

    int tamanho = 5, contador;
    int *vetor = malloc(tamanho*sizeof(int));
    int novo_tamanho;


    printf("\nO tamanho atual do vetor é de %d, digite um novo tamanho para ele: ", tamanho);
    scanf("%d", &novo_tamanho);

    vetor = realloc(vetor, novo_tamanho * sizeof(int));

    if (vetor == NULL){
        printf("Erro na alocação de memória.");
        exit(1);
    }
    else{
        printf("Alocação bem sucedida");
    }

    for(contador = 0; contador < tamanho; contador++){
        printf("\nDigite o valor %d do vetor: ", contador);
        scanf("%d", vetor+contador); 
    }

   
    free(vetor);
    return 0;
}