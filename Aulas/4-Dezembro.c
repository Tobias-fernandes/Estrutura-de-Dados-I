#include <stdio.h>
#include <math.h>

int calcula(int primeiroNumero, int segundoNumero, int(*operacao)(int, int)){
    return (operacao(primeiroNumero, segundoNumero));
}

int soma(int primeiroNumero, int segundoNumero){
    return (primeiroNumero + segundoNumero);
}

int subtracao(int primeiroNumero, int segundoNumero){
    return (primeiroNumero - segundoNumero);
}

int multiplicacao(int primeiroNumero, int segundoNumero){
    return (primeiroNumero * segundoNumero);
}

int divisao(int primeiroNumero, int segundoNumero){
    return (primeiroNumero / segundoNumero);
}


int main(void){
    int primeiroNumero, segundoNumero, resultado;

    printf("\nDigite o primeiro número: ");
    scanf("%i", &primeiroNumero);

    printf("Digite o segundo número: ");
    scanf("%i", &segundoNumero);

    printf("\n======= calculadora =========\n");

    resultado = calcula(primeiroNumero, segundoNumero, soma);
    printf("SOMA          = %i\n", resultado);

    resultado = calcula(primeiroNumero, segundoNumero, subtracao);
    printf("SUBTRACAO     = %i\n", resultado);

    resultado = calcula(primeiroNumero, segundoNumero, multiplicacao);
    printf("MULTIPLICACAO = %i\n", resultado);

    resultado = calcula(primeiroNumero, segundoNumero, divisao);
    printf("DIVISAO       = %i\n", resultado);

    printf("=============================\n");
}