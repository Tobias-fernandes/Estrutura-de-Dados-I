#include <stdio.h>

typedef enum bool{
    true,
    false
}Bool;

int main(void){
    Bool resposta;

    printf("Voce gosta de algoritmos? \n\t 0 - True\n\t 1 - False");
    scanf("%d", &resposta);

    if (resposta == true){
        printf("Boa escolha!\n");
    }else if(resposta == false){
        printf("Que pena!\n");
    }else{
        printf("Opcao inexistente!\n");
    }

    return 0;

}