//Faça um programa que conte o numero de 1’s que aparecem em um string. Exemplo:
//0011001 → 3

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i=0, cont=0;
    char string[10];
    printf("\nDigite seu numero: ");
    scanf("%s", string);
    while(string[i] != '\0'){
        if (string[i] == '1')    
            cont++;
        i++;
    }
    printf("\nNumeros '1' na sequencia: %d", cont);
}