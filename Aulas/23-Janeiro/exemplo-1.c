#include <stdio.h>

#define TRUE 0
#define FALSE 1

int main(void){
    int resposta;

    printf("Voce gosta de algoritmos? \n\t 0 - True\n\t 1 - False");
    scanf("%d", &resposta);
    
    if(resposta == TRUE){
        printf("Boa escolha!\n");
    }else if(resposta == FALSE){
        printf("Que pena!\n");
    }else{
        printf("Opcao inexistente!\n");
    }

    return 0;
}