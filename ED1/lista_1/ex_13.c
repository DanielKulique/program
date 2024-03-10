//.Ler uma frase e contar quantos caracteres são brancos. Lembre-se que uma frase é um
//conjunto de caracteres (vetor). 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i=0, contador = 0;
    char frase[100];
    printf("\nDigite sua frase: ");
    fgets(frase, 100, stdin);

    while(frase[i] != '\0'){
        if (frase[i] == ' ')
            contador++;
        i++;
    }

    printf("\nAo todo temos [%d] espaços na frase!", contador);
}