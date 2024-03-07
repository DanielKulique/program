// Ler nome, sexo e idade. Se sexo for feminino e idade menor que 25, imprime o nome da
//pessoa e a palavra “ACEITA”, caso contrário imprimir “NÃO ACEITA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char Nome[20], Sexo[5];
    int idade;

    printf("\nDigite seu nome:");
    scanf("%s", Nome);
    printf("\nDigite seu Sexo[F/M]:");
    scanf("%s", Sexo);
    printf("\nDigite sua idade:");
    scanf("%d", &idade);

    if (idade<25 && toupper(Sexo[0]) == 'F'){
        printf("[%s] Aceita!", Nome);
    }
    else
        printf("Não Aceito(a)!");
}