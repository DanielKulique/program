//Faça um programa que receba uma palavra e calcule quantas vogais (a, e, i, o, u) possui
//essa palavra. Entre com um caractere (vogal ou consoante) e substitua todas as vogais
//da palavra dada por esse caractere.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i, tamanho, contador;
    char string[100], caracter;
    printf("\nDigite Sua String: ");
    fgets(string, 100, stdin);
    tamanho = strlen(string);
    
    for(i=0; i<tamanho; i++){
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u'){
            printf("%c", string[i]);
            contador++;
        }
    }
    printf("\n[%d] vogais achadas!", contador);
    printf("\nDigite um caracter para substituir as vogais calculadas:");
    scanf("%c", &caracter);
    for(i=0; i<tamanho; i++){
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u')
            string[i] = caracter;
    }
    printf("\nFrase Nova: {%s}", string);
}