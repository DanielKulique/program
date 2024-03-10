//Leia uma cadeia de caracteres e converta todos os caracteres para maiúscula. Dica:
//subtraia 32 dos caracteres cujo código ASCII está entre 65 e 90 (97 - 122)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i=0, tam=0;
    char palavra[51];
    printf("\n Digite sua palavra: ");
    fgets(palavra, 51, stdin);
    tam = strlen(palavra);
    
    printf("\nConvertendo para letras maiusculas:\n");
    for (i=0; i<tam; i++)
        if (((int)palavra[i]) >= 97 && ((int)palavra[i]) <= 122)
            palavra[i] = palavra[i]-32;

    for (i=0; i<tam; i++)
        printf("%c", palavra[i]);

    return 0;


}