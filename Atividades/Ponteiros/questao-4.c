#include <stdio.h>
#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro)
{
    *area = (3 * pow(2,l) * sqrt(3)) /2;
    *perimetro = 6 * l;
}

int main()
{
    float area, perimetro, l;
    
    printf("Insira o lado do hexagono para calcular a area e o perimetro:\n");
    scanf("%f",&l);
   
    calcula_hexagono(l,&area,&perimetro);
   
    printf("Area do hexagono: %f\n",area);
    printf("Perimetro do hexagono: %f\n",perimetro);

    return 0;
}