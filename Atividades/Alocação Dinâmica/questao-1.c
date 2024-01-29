#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verificar_quantidade(int *quantidade)
{
    *quantidade = 0;
    printf("Digite quantas pessoas vão fazer a entrevista:\n");
    scanf("%d", &*quantidade);
}

void porcentagemF(int *valor_total, int *valor_da_porcentagem, int *resultado)
{
    *resultado = ((*valor_da_porcentagem) * 100) / *valor_total;  
    printf("A porcentagem das mulheres que gostaram do produto foi de: %d por cento\n",*resultado);
}

void porcentagemH(int *valor_total, int *valor_da_porcentagem, int *resultado)
{
    *resultado = ((*valor_da_porcentagem) * 100) / *valor_total;  
    printf("A porcentagem dos homens que nao gostaram do produto foi de: %d por cento\n",*resultado);
}

int  main()
{
    
    int quantidade = 0;
    int numero = 0;
    verificar_quantidade(&quantidade);

    char **sexo = (char**)malloc(quantidade * sizeof(char*));
    char **opiniao = (char**)malloc(quantidade * sizeof(char*));

    for(numero = 0; numero < quantidade; numero++)
    {
        sexo [numero] = (char*)malloc(2 * sizeof(char));
        opiniao [numero] = (char*)malloc(2 * sizeof(char));

        if( sexo[numero] == NULL || opiniao[numero] == NULL)
        {
            exit(1);
        }
    }    

    for(numero = 0; numero < quantidade; numero++)
    {
        printf("Insira seu sexo [M/F]:\n");
        scanf("%s",sexo[numero]);

        printf("Qual sua opiniao em relacao ao produto[G/N]:\n");
        scanf("%s",opiniao[numero]);
    }
   

    printf("lista\n");

    for (numero = 0; numero < quantidade; numero++) {
        printf("Pessoa %d: Sexo: %s, Opiniao: %s\n", numero + 1, sexo[numero], opiniao[numero]);
    }

    int mulheres_gostaram = 0;
    int resultadoo;
    int totalf = 0;
    
    for (numero = 0; numero < quantidade; numero++) {
        
        if (sexo[numero][0] == 'F' && opiniao[numero][0] == 'G') {
            
            mulheres_gostaram++;
        }
        if (sexo[numero][0] == 'F')
        {
            totalf ++;
        }
    }
    printf("quantas mulheres gostaram: %d\n", mulheres_gostaram);
    
    porcentagemF(&totalf, &mulheres_gostaram, &resultadoo);
    resultadoo = 0;
    
    int homens_naogostaram= 0;
    int totalm = 0;
    
    for (numero = 0; numero < quantidade; numero++) {
        
        if (sexo[numero][0] == 'M' && opiniao[numero][0] == 'N') 
        {
            homens_naogostaram++;
        }
        if(sexo[numero][0] == 'M')
        {
            totalm++;
        }
        
    }
    printf("quantos homens nao gostaram: %d\n", homens_naogostaram);
    
    porcentagemH(&totalm, &homens_naogostaram, &resultadoo);
   
    for (numero = 0; numero < quantidade; numero++) 
    {
    free(sexo[numero]);
    free(opiniao[numero]);
    }

    free(sexo);
    free(opiniao);
    return 0;
}