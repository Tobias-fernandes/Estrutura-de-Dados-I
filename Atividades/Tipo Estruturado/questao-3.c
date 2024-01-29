#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct retangulo {
    float base;
    float altura;
} Retangulo;

typedef struct circulo {
    float raio;
} Circulo;

Retangulo* ret_circunscrito(Circulo* circ, float h) {
    Retangulo* ret = (Retangulo*)malloc(sizeof(Retangulo));

    float lado = sqrt(pow(2 * circ->raio, 2) - pow(h, 2));

    ret->base = lado;
    ret->altura = h;

    return ret;
}

Circulo* circ_interno(Retangulo* ret) {
    Circulo* circ = (Circulo*)malloc(sizeof(Circulo));

    circ->raio = (ret->base < ret->altura) ? ret->base / 2 : ret->altura / 2;

    return circ;
}

void Preenchercirculo(Circulo *CirculoRaio)
{
    printf("Digite o raio do círculo: ");
    scanf("%f", &CirculoRaio->raio);
}

void preencherRetangulo(float h)
{
    printf("Insira a altura do retângulo circunscrito: ");
    scanf("%f", &h);
}

int main() {
    Retangulo* retangulo;
    Circulo* circulo;

    circulo = (Circulo*)malloc(sizeof(Circulo));
    retangulo = (Retangulo*)malloc(sizeof(Retangulo));

    if (circulo == NULL || retangulo == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    float h = 0.0;

    Preenchercirculo(&circulo);

    preencherRetangulo(h);

    retangulo = ret_circunscrito(circulo, h);

    printf("O maior retângulo circunscrito posui uma base de %.2f e altura %.2f.\n", retangulo->base, retangulo->altura);

    circulo = circ_interno(retangulo);

    printf("O maior círculo interno possui um raio de %.2f.\n", circulo->raio);

    free(circulo);
    free(retangulo);

    return 0;
}