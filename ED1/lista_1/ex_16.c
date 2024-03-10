//Escreva um programa para converter uma cadeia de caracteres de letras maiúsculas em
//letras minúsculas


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i=0, tam=0;
    char palavra[51];
    printf("\n Digite sua palavra: ");
    fgets(palavra, 51, stdin);
    tam = strlen(palavra);
    
    printf("\nConvertendo para letras minusculas:\n");
    for (i=0; i<tam; i++)
        if (((int)palavra[i]) >= 65 && ((int)palavra[i]) <= 93)
            palavra[i] = palavra[i]+32;

    for (i=0; i<tam; i++)
        printf("%c", palavra[i]);

    return 0;


}